/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Mar 13, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"


static void (*SPI1_CallBackPtr)(uint8) = NULL_PTR;
static void (*SPI2_CallBackPtr)(uint8) = NULL_PTR;
static uint8 SPI_u8SlavePort = 0;
static uint8 SPI_u8SlavePin = 0;



void MSPI_voidInit(SPI_Regs *SPIx)
{
	/* Initialize SPIx Pins */
	if(SPIx == SPI1)
	{
		/* Enable RCC for SPI1 */
		RCC_voidEnableClock(RCC_APB2, 12);

		/* Set MOSI1 Pin(A7) as OUTPUT ALTERNATIVE FUNCTION 2MHZ */
		GPIO_voidSetPinDirection(GPIOA_ID, PIN7, OUTPUT_SPEED_2MHZ_AFPP);

		/* Set MISO1 Pin(A6) as INPUT FLOATING */
		GPIO_voidSetPinDirection(GPIOA_ID, PIN6, INPUT_FLOATING);

		/* SCK1 Pin (A5) as OUTPUT ALTERNATIVE FUNCTION 2MHZ */
		#if(SPI_MASTER_SLAVE == SLAVE)
		{
			GPIO_voidSetPinDirection(GPIOA_ID, PIN5, OUTPUT_SPEED_2MHZ_AFPP);
		}
		#endif
	}
	else if(SPIx == SPI2)
	{
		/* Enable RCC for SPI2 */
		RCC_voidEnableClock(RCC_APB1, 14);

		/* Set MOSI2 Pin(B15) as OUTPUT ALTERNATIVE FUNCTION 2MHZ */
		GPIO_voidSetPinDirection(GPIOB_ID, PIN15, OUTPUT_SPEED_2MHZ_AFPP);

		/* Set MISO2 Pin(B14) as INPUT FLOATING */
		GPIO_voidSetPinDirection(GPIOB_ID, PIN14, INPUT_FLOATING);

		/* SCK2 Pin (B13) as OUTPUT ALTERNATIVE FUNCTION 2MHZ */
		#if(SPI_MASTER_SLAVE == SLAVE)
		{
			GPIO_voidSetPinDirection(GPIOB_ID, PIN13, OUTPUT_SPEED_2MHZ_AFPP);
		}
		#endif
	}

	/* Clear the Whole CR1 register */
	SPIx->CR1 = 0;

	/* Set SSM bit for S.W Slave Select */
	SET_BIT(SPIx->CR1, 9);

	/* Insert the Baud Rate */
	SPIx->CR1 |= (SPI_BAUD_RATE << 3);

	/* Insert the Data Order */
	SPIx->CR1 |= (SPI_DATA_ORDER << 7);

	/* Select Master or Slave */
	SPIx->CR1 |= (SPI_MASTER_SLAVE << 2);

	/* Select Clock Polarity */
	SPIx->CR1 |= (SPI_CLOCK_POLARITY << 1);

	/* Select Clock Phase */
	SPIx->CR1 |= (SPI_CLOCK_PHASE << 0);

	/* Enable SPI */
	SET_BIT(SPIx->CR1, 6);
}

void MSPI_voidSendReceiveSynch(SPI_Regs *SPIx, uint8 copy_u8SlavePort, uint8 copy_u8SlavePin, uint8 copy_u8DataToTransmit, uint8 *copy_u8DataToReceive)
{
	/* Set the Slave Pin as OUTPUT PUSH PULL 2MHZ */
	GPIO_voidSetPinDirection(copy_u8SlavePort, copy_u8SlavePin, OUTPUT_SPEED_2MHZ_PP);
	/* Clear Slave Select pin */
	GPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, LOGIC_LOW);
	/* Send Data */
	SPIx->DR = copy_u8DataToTransmit;
	/* Wait for the Busy Flag to finish */
	while(CHECK_BIT(SPIx->SR, 7) == 1);
	/* Return the received Data */
	*copy_u8DataToReceive = SPIx->DR;
	/* Set Slave Select Pin */
	GPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, LOGIC_HIGH);
}

void MSPI_voidSendReceiveAsynch(SPI_Regs *SPIx, uint8 copy_u8SlavePort, uint8 copy_u8SlavePin, uint8 copy_u8DataToTransmit, void (*copy_voidPtr)(uint8))
{
	/* Set the callback function */
	SPI1_CallBackPtr = copy_voidPtr;
	/* Enable SPI Interrupt TX complete*/
	SET_BIT(SPIx->CR2, 7);
	/* Enable NVIC for SPI1 */
	MNVIC_voidEnableInterrupt(35);
	/* Enable NVIC for SPI2 */
	MNVIC_voidEnableInterrupt(36);
	/* Save the slave Port and Pin to be able to clear Slave select pin in ISR */
	SPI_u8SlavePort = copy_u8SlavePort;
	SPI_u8SlavePin = copy_u8SlavePin;
	/* Set the Slave Pin as OUTPUT PSUH PULL */
	GPIO_voidSetPinDirection(copy_u8SlavePort, copy_u8SlavePin, OUTPUT_SPEED_2MHZ_PP);
	/* Clear Slave Select pin */
	GPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, LOGIC_LOW);
	/* Send Data */
	SPIx->DR = copy_u8DataToTransmit;

}

void SPI1_IRQHandler(void)
{
	if(SPI1_CallBackPtr != NULL_PTR)
	{
		(*SPI1_CallBackPtr)(SPI1->DR);
	}
	CLEAR_BIT(SPI1->SR, 7); /* Clear the flag */
	/* Set Slave Select pin */
	GPIO_voidSetPinValue(SPI_u8SlavePort, SPI_u8SlavePin, LOGIC_HIGH);
}

void SPI2_IRQHandler(void)
{
	if(SPI2_CallBackPtr != NULL_PTR)
	{
		(*SPI2_CallBackPtr)(SPI2->DR);
	}
	CLEAR_BIT(SPI2->SR, 7); /* Clear the flag */
	/* Set Slave Select pin */
	GPIO_voidSetPinValue(SPI_u8SlavePort, SPI_u8SlavePin, LOGIC_HIGH);
}

