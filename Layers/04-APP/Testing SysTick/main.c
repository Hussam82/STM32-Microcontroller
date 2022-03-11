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




void main(void)
{
	/* Initialize Clock System */
	RCC_voidInitSysClock();

	/* Enable Periphral 2 on APB2 Bus (GPIOA) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA);

	/* Enable Periphral 3 on APB2 Bus (GPIOB) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOB);

	/* Enable Periphral 4 on APB2 Bus (GPIOC) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOC);

	/* Initialize SysTick */
	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(200,countSevenSegment);




//	for(uint8 i = 0; i <= 15; i++)
//	{
//		LED_voidLedOff(GPIOA, i);
//		LED_voidLedOff(GPIOB, i);
//	}
//
//	LED_voidLedOn(GPIOC, PIN14);

//	MNVIC_voidInit();				/* Configure SCB_AIRCR */
//	MNVIC_voidSetPriority(6, 1, 0);	/* EXTI0 GROUP 1 SUB 0 */
//	MNVIC_voidSetPriority(7, 0, 3);	/* EXTI1 GROUP 0 SUB 3 */
//	MNVIC_voidEnableInterrupt(6);	/* Enable EXTI0 */
//	MNVIC_voidEnableInterrupt(7);	/* Enable EXTI1 */
//	MNVIC_voidSetPendingFlag(6);	/* Set pending flag of EXTI0 */
	while(1)
	{

//		if(BUTTON_u8ReadStatus(BUTTON_PORT, BUTTON_PIN) == BUTTON_PRESSED)
//		{
//			LED_voidLedOn(LED_PORT, LED_PIN);
//		}
//		else
//		{
//			LED_voidLedOff(LED_PORT, LED_PIN);
//		}


//		SEVENSEG_voidDisplay(COMMON_ANODE, num);
//		Delay(1000);
//		num++;
//		if(num == 10)
//		{
//			num = 0;
//		}

//		if(BUTTON_u8ReadStatus(BUTTON_PORT, BUTTON_PIN) == BUTTON_PRESSED)
//		{
//			for(uint16 i = 0; i < n; i++)
//			{
//				for(uint16 j = 0; j < n; j++)
//				{
//					asm("NOP");
//				}
//			}
//			if(BUTTON_u8ReadStatus(BUTTON_PORT, BUTTON_PIN) == BUTTON_PRESSED)
//			{
//				LED_voidLedToggle(LED_PORT, LED_PIN);
//				if(num <= 9)
//				{
//					SEVENSEG_voidDisplay(COMMON_ANODE, num);
//					num++;
//				}
//				else
//				{
//					num = 0;
//				}
//			}
//		}while(BUTTON_u8ReadStatus(BUTTON_PORT, BUTTON_PIN) == BUTTON_PRESSED) {}
	}
}

void EXTI0_IRQHandler(void)
{
	LED_voidLedOn(GPIOC_ID, PIN14);
	MNVIC_voidSetPendingFlag(7);	/* Set pending flag of EXTI1 */
	SEVENSEG_voidDisplay(COMMON_ANODE, 1);
}

void EXTI1_IRQHandler(void)
{
	SEVENSEG_voidDisplay(COMMON_ANODE, 2);
}

//void SysTick_Handler(void)
//{
//	g_ticks++;
//	if(g_ticks <= 43)
//	{
//		if(num <= 9)
//		{
//			SEVENSEG_voidDisplay(COMMON_ANODE, num);
//			num++;
//		}
//		else
//		{
//			num = 0;
//		}
//	}
//	else
//	{
//		if(g_ticks == 44)
//		{
//			SysTick_voidStart(1000);
//			LED_voidLedToggle(GPIOC_ID, PIN14);
//		}
//		LED_voidLedToggle(GPIOC_ID, PIN14);
//	}
//}

