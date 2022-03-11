/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 11, 2022		*******
 ******* 	Description		:		main function		*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"

#include "SEVENSEG_interface.h"

#include "BUTTON_interface.h"
#include "BUTTON_config.h"

#include "NVIC_interface.h"

#include "STK_interface.h"
#include "STK_config.h"

#include "EXTI_interface.h"

#include "AFIO_interface.h"

#include "USART_interface.h"

#include "TIM_interface.h"

static uint8 num = 0;
static uint8 count = 0;
//static uint8 flag = 0;
void Delay(uint32 time_in_ms)
{
	for(uint16 i = 0; i < time_in_ms; i++)
	{
		for(uint16 j = 0; j < time_in_ms; j++)
		{
			asm("NOP");
		}
	}
}

void countSevenSegment(void)
{
	count++;
	if(count <= 5 * 9)
	{
		if(num <= 9)
		{
			SEVENSEG_voidDisplay(COMMON_ANODE, num);
			num++;
		}
		else
		{
			num = 0;
		}
	}
	else if(count <= (5 * 9) + 16)
	{
		MSTK_voidSetIntervalPeriodic(1000,countSevenSegment);
		LED_voidLedToggle(GPIOC_ID, PIN14);
	}
	else
	{
		count = 0;
	}
}

void ToggleLed(void)
{
	LED_voidLedToggle(GPIOC_ID, PIN14);
	//MSTK_voidSetBusyWait(1000);

}


void main(void)
{
	/* Initialize Clock System */
	RCC_voidInitSysClock();

//	/* Enable Peripheral 2 on APB2 Bus (GPIOA) */
//	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA);
//
//	/* Enable Peripheral 3 on APB2 Bus (GPIOB) */
//	RCC_voidEnableClock(RCC_APB2, RCC_GPIOB);
//
//	/* Enable Peripheral 4 on APB2 Bus (GPIOC) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOC);
//
//	/* Enable Peripheral 0 on APB2 Bus (AFIO) */
//	RCC_voidEnableClock(RCC_APB2, 0);



	/* Enable Peripheral 2 on APB1 Bus (TIM4) */
	RCC_voidEnableClock(RCC_APB1, 2);

	/* Initialize TIM4 */
	MTIM_voidInit();

	/* Enable TIM4 interrupt */
	MNVIC_voidEnableInterrupt(30);

	MTIM_voidTIM4SetCallBack(ToggleLed);

	MTIM_voidSetIntervalPeriodic(200);




	while(1)
	{




	}
}




