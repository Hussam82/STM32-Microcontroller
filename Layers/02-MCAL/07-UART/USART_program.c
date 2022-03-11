/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 23, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/


#include "STD_TYPES.h"
#include "common_macros.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"


static void (*USART1_CallBackPtr)(void) = NULL_PTR;
static void (*USART2_CallBackPtr)(void) = NULL_PTR;
static void (*USART3_CallBackPtr)(void) = NULL_PTR;
uint8 USART1_u8RxBuffer[20] = {0};
uint8 USART1_u8Count = 0;
uint8 USART2_u8RxBuffer[20] = {0};
uint8 USART2_u8Count = 0;
uint8 USART3_u8RxBuffer[20] = {0};
uint8 USART3_u8Count = 0;

void MUSART_voidInit(USART_Regs *USARTx)
{
	/* Calculate BRR value */
	uint32 local_u32Mantissa = (F_CPU / (16 * USARTX_BAUD_RATE));
	uint32 local_u32Fraction = ((F_CPU * 100 / (16 * USARTX_BAUD_RATE)) % 100) * 16;
	USARTx->BRR = (local_u32Mantissa << 4) | (local_u32Fraction / 100);

	/* Clear Status register */
	USARTx->SR = 0;

	/* Enable USART1
	 * Enable RX
	 * Enable TX
	 */
	SET_BIT(USARTx->CR1, 13);
	SET_BIT(USARTx->CR1, 2);
	SET_BIT(USARTx->CR1, 3);
	/* Enable RXNEIE */
	SET_BIT(USARTx->CR1, 5);


	/* Check for Parity */
	#if (USARTX_PARITY == PARITY_DISABLE)
	{
		CLEAR_BIT(USARTx->CR1, 10);
	}
	#elif (USARTX_PARITY == EVEN_PARITY)
	{
		SET_BIT(USARTx->CR1, 10);
		CLEAR_BIT(USARTx->CR1, 9);
	}
	#elif (USARTX_PARITY == ODD_PARITY)
	{
		SET_BIT(USARTx->CR1, 10);
		SET_BIT(USARTx->CR1, 9);
	}
	#endif

	/* Check for Data Length */
	#if(DATA_LENGTH == DATA_LENGTH_8)
	{
		CLEAR_BIT(USARTx->CR1, 12);
	}
	#elif(DATA_LENGTH == DATA_LENGTH_9)
	{
		SET_BIT(USARTx->CR1, 12);
	}
	#endif

	/* Check for Stop bits */
	#if(STOP_BITS == ONE_STOP_BIT)
	{
		CLEAR_BIT(USARTx->CR2, 12);
		CLEAR_BIT(USARTx->CR2, 13);
	}
	#elif(STOP_BITS == HALF_STOP_BIT)
	{
		SET_BIT(USARTx->CR2, 12);
		CLEAR_BIT(USARTx->CR2, 13);
	}
	#elif(STOP_BITS == TWO_STOP_BIT)
	{
		CLEAR_BIT(USARTx->CR2, 12);
		SET_BIT(USARTx->CR2, 13);
	}
	#elif(STOP_BITS == ONE_AND_HALF_STOP_BIT)
	{
		SET_BIT(USARTx->CR2, 12);
		SET_BIT(USARTx->CR2, 13);
	}
	#endif



	/* Baud rate 9600 ==> BRR 0x341= */
	//USART1->BRR = 0x341;
	/* Baud rate 115200 ==> BRR = 0x54 */

}





void MUSART_voidSendChar(USART_Regs *USARTx, uint8 copy_u8Char)
{
	USARTx->DR = copy_u8Char;
	while(!CHECK_BIT(USARTx->SR, 6)); /* Wait until transmission is complete */
	CLEAR_BIT(USARTx->SR, 6); 		  /* Clear TC flag */
}

uint8 MUSART_voidReceiveChar(USART_Regs *USARTx)
{
	while(!CHECK_BIT(USARTx->SR, 5)); /* Wait until the Receiving is complete */
	/* Return the first 8 bits only of the data register */
	return ((USARTx->DR) & 0xFF);
}

void MUSART_voidSendString(USART_Regs *USARTx, const uint8 *copy_u8String)
{
	uint8 local_u8Count = 0;
	while(copy_u8String[local_u8Count] != '\0')
	{
		MUSART_voidSendChar(USARTx, copy_u8String[local_u8Count]); /* Send Char */
		local_u8Count++;
	}
}


void MUSART_voidReceiveString(USART_Regs *USARTx, uint8 *copy_u8String)
{
	uint8 local_u8Count = 0;
	copy_u8String[local_u8Count] = MUSART_voidReceiveChar(USARTx);
	/* Receive until '@' is pressed */
	while(copy_u8String[local_u8Count] != '@')
	{
		local_u8Count++;
		copy_u8String[local_u8Count] = MUSART_voidReceiveChar(USARTx);
	}
	copy_u8String[local_u8Count] = '\0';
}

uint32 MUSART_u32ReceiveInteger(USART_Regs *USARTx, uint8 *copy_u8String)
{
	/* Get the Integer as an an array of characters (ASCII) */
	MUSART_voidReceiveString(USARTx, copy_u8String);
	/* Convert each element in the array into integer then form the entire number */
    uint32 local_u32Result = 0;
    for(uint8 i = 0; copy_u8String[i] != '\0'; i++)
    {
    	local_u32Result = local_u32Result * 10 + (copy_u8String[i] - '0');
    }
    return local_u32Result;
}

void USART1_IRQHandler(void)
{
	uint8 local_u8Temp = USART1->DR;
	if(local_u8Temp != '@')
	{
		USART1_u8RxBuffer[USART1_u8Count] = local_u8Temp;
		USART1_u8Count++;
	}
	else
	{
		//USART1_u8RxBuffer[USART2_u8Count] = '\0';
		USART1_u8Count = 0;
		(*USART1_CallBackPtr)();
	}
}

void USART2_IRQHandler(void)
{
	uint8 local_u8Temp = USART2->DR;
	if(local_u8Temp != '@')
	{
		USART2_u8RxBuffer[USART2_u8Count] = local_u8Temp;
		USART2_u8Count++;
	}
	else
	{
		USART2_u8RxBuffer[USART2_u8Count] = '\0';
		USART2_u8Count = 0;
		(*USART2_CallBackPtr)();
	}
}

void USART3_IRQHandler(void)
{
	uint8 local_u8Temp = USART3->DR;
	if(local_u8Temp != '@')
	{
		USART3_u8RxBuffer[USART3_u8Count] = local_u8Temp;
		USART3_u8Count++;
	}
	else
	{
		USART3_u8RxBuffer[USART2_u8Count] = '\0';
		USART3_u8Count = 0;
		(*USART3_CallBackPtr)();
	}
}

void MUSART1_voidSetCallBack(void (*copy_voidPtr)(void))
{
	USART1_CallBackPtr = copy_voidPtr;
}

void MUSART2_voidSetCallBack(void (*copy_voidPtr)(void))
{
	USART2_CallBackPtr = copy_voidPtr;
}

void MUSART3_voidSetCallBack(void (*copy_voidPtr)(void))
{
	USART3_CallBackPtr = copy_voidPtr;
}
