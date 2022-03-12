/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 26, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/


/********************************************* Single channel mode only *****************************************************/
/*********************** Multiple channel mode need DMA driver will be made later on ******************************************/

#include "STD_TYPES.h"
#include "common_macros.h"


#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "TIM_interface.h"
/* Will be removed later */
#include "DMA_private.h"


volatile uint16 ADC_u16ReadValue = 0;
volatile uint16 ADC_u16ReadValueArr[ADC_NUM_CHANNELS] = {0};

void MADC_voidInit(void)
{
	/* Enable ADC Interrupt */
	SET_BIT(ADC1->CR1, 5);

	/* Select ADC MODE */
	#if(ADC_MODE == ADC_CONTINUOUS_MODE)
	{
		SET_BIT(ADC1->CR2, 1);
	}
	#elif(ADC_MODE == ADC_DISCONTINUOUS_MODE)
	{
		CLEAR_BIT(ADC1->CR2, 1);
	}
	#endif

}

void MADC_voidReadChannel(uint8 copy_u8Channel)
{
	/* Select the channel */
	ADC1->SQR3 |= copy_u8Channel;

	/* Set the sampling rate */
	if(copy_u8Channel <= 9)
	{
		ADC1->SMPR2 |= ((0b111) << copy_u8Channel * 3);
	}
	else if(copy_u8Channel <= 17)
	{
		ADC1->SMPR1 |= ((0b111) << ((copy_u8Channel * 3) - 30));
	}

	/* Enable ADC Conversion */
	SET_BIT(ADC1->CR2, 0);
	MTIM_voidInit(TIMER4);
	MTIM_voidSetBusyWait(TIMER4, 1); /* Delay 1 ms */
	SET_BIT(ADC1->CR2, 0);

	/* Set calibration and wait for it to finish */
	SET_BIT(ADC1->CR2, 2);
	while(CHECK_BIT(ADC1->CR2, 2));
}

void MADC_voidReadMultipleChannels(uint8 copy_u8Channel[])
{
	if(ADC_NUM_CHANNELS > 1)
	{
		/* Select the number of channels */
		ADC1->SQR1 &= ~((0b1111) << 20);
		ADC1->SQR1 |= ((ADC_NUM_CHANNELS - 1) << 20);

		/* Setup each channel in the array */
		for(uint8 i = 0; i < ADC_NUM_CHANNELS; i++)
		{
			/* Set sampling rate for each channel */
			if(copy_u8Channel[i] <= 9)
			{
				ADC1->SMPR2 |= ((0b111) << copy_u8Channel[i] * 3);
			}
			else if(copy_u8Channel[i] <= 17)
			{
				ADC1->SMPR1 |= ((0b111) << ((copy_u8Channel[i] * 3) - 30));
			}
			/* Set the sequence of channels according to their order in the array */
			if(copy_u8Channel[i] <= 6)
			{
				ADC1->SQR3 &= ~((0b11111) << i * 5);
				ADC1->SQR3 |= ((copy_u8Channel[i]) << i * 5);
			}
			else if(copy_u8Channel[i] <= 12)
			{
				ADC1->SQR2 &= ~((0b11111) << ((i * 5) - 35));
				ADC1->SQR2 |= ((copy_u8Channel[i]) << ((i * 5) - 35));
			}
			else if(copy_u8Channel[i] <= 16)
			{
				ADC1->SQR1 &= ~((0b11111) << ((i * 5) - 65));
				ADC1->SQR1 |= ((copy_u8Channel[i]) << ((i * 5) - 65));
			}
		}

		/* Enable Scan mode in the CR1 register */
		SET_BIT(ADC1->CR1, 8);

		/* Enable DMA in CR2 */
		SET_BIT(ADC1->CR2, 8);

		/* Setting DMA */
		/* This will be removed and replaced by doing DMA driver */
		DMA1->CPAR1 = (uint32)(&(ADC1->DR)); 			/* Assign the peripheral address to DMA */
		DMA1->CMAR1 = (uint32)ADC_u16ReadValueArr;	/* Assign the Memory addres to DMA */
		DMA1->CNDTR1 = ADC_NUM_CHANNELS;	/* Assign the number of data to DMA */
		SET_BIT(DMA1->CCR1, 5); 			/* Enable circular mode */
		SET_BIT(DMA1->CCR1, 7); 			/* Enable memory increment mode */
		/* Choose 16-bit peripheral size which is the ADC data register size */
		CLEAR_BIT(DMA1->CCR1, 9);
		SET_BIT(DMA1->CCR1, 8);
		/* Choose 16-bit memory size */
		CLEAR_BIT(DMA1->CCR1, 11);
		SET_BIT(DMA1->CCR1, 10);
		/* Enable DMA */
		SET_BIT(DMA1->CCR1, 0);

		/* Enable ADC Conversion */
		SET_BIT(ADC1->CR2, 0);
		//MTIM_voidInit();
		MTIM_voidSetBusyWait(TIMER4, 1); /* Delay 1 ms */
		SET_BIT(ADC1->CR2, 0);

		/* Set calibration and wait for it to finish */
		SET_BIT(ADC1->CR2, 2);
		while(CHECK_BIT(ADC1->CR2, 2));
	}
	else
	{
		/* ERROR : USE SINGLE CHANNEL MODE */
	}

}

void MADC_voidDeInit(void)
{
	CLEAR_BIT(ADC1->CR2, 0);
}

void ADC1_2_IRQHandler(void)
{
	ADC_u16ReadValue = (0x0000FFFF & ADC1->DR);
}


