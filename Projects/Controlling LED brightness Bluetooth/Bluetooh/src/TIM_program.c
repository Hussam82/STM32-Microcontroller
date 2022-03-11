/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 25, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "TIM_interface.h"
#include "TIM_config.h"
#include "TIM_private.h"

static void (*TIM2_CallBackPtr)(void) = NULL_PTR;
static void (*TIM3_CallBackPtr)(void) = NULL_PTR;
static void (*TIM4_CallBackPtr)(void) = NULL_PTR;

void MTIM_voidInit(TIM_Regs *TIMERx)
{

	/* Pre-scaler and frequency settings */
	TIMERx->PSC = TIM_PRESCALER; /* Pre-scaler 512 Assuming 8MHz clock */

	/* Check for the Timer mode */
	#if(TIM_MODE == EDGE_ALIGNED_MODE)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b00)<<5;
		/* Check for the Timer direction */
		#if(TIM_DIRECTION == UP_COUNTER)
		{
			CLEAR_BIT(TIMERx->CR1, 4); /* Clear DIR bit */
		}
		#elif(TIM_DIRECTION == DOWN_COUNTER)
		{
			SET_BIT(TIMERx->CR1, 4);	/* Set DIR bit */
		}
		#endif
	}
	#elif(TIM_MODE == CENTER_ALIGNED_MODE_1)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b01)<<5;
	}
	#elif(TIM_MODE == CENTER_ALIGNED_MODE_2)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b10)<<5;
	}
	#elif(TIM_MODE == CENTER_ALIGNED_MODE_3)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b11)<<5;
	}
	#endif
}

void MTIM_voidSetBusyWait(TIM_Regs *TIMERx, uint32 copy_u32Ticks)
{
	TIMERx->ARR = (F_CPU / TIM_PRESCALER) * (copy_u32Ticks / 1000.0);
	/* Enable Counter */
	SET_BIT(TIMERx->CR1, 0);
	while(!CHECK_BIT(TIMERx->SR, 0));	/* Wait till counting is done */
	CLEAR_BIT(TIMERx->SR, 0); /* Clear the flag */
	/* Disable Counter */
	CLEAR_BIT(TIMERx->CR1, 0);
}



void MTIM_voidSetIntervalPeriodic(TIM_Regs *TIMERx, uint32 copy_u32Ticks)
{

	TIMERx->ARR = (F_CPU / TIM_PRESCALER) * (copy_u32Ticks / 1000.0);

	/* Counter overflow/underflow generates an interrupt */
	SET_BIT(TIMERx->CR1, 2);	/* Set URS bit */

	/* Update Interrupt Enabled */
	SET_BIT(TIMERx->DIER, 0);	/* Set UIE bit */

	/* Update Generation Enabled */
	SET_BIT(TIMERx->DIER, 0);	/* Set UG bit */

	/* Enable Counter */
	SET_BIT(TIMERx->CR1, 0);
}

void MTIM_voidStopTimer(TIM_Regs *TIMERx)
{
	/* Disable Counter */
	CLEAR_BIT(TIMERx->CR1, 0);
	/* CLear counter register */
	TIMERx->CNT = 0;
}

void MTIM_voidTIM2SetCallBack(void (*copy_voidPtr)(void))
{
	TIM2_CallBackPtr = copy_voidPtr;
}

void TIM2_IRQHandler(void)
{
	if(TIM2_CallBackPtr != NULL_PTR)
	{
		(*TIM2_CallBackPtr)();
	}
	CLEAR_BIT(TIMER2->SR, 0); /* Clear the flag */
}

void MTIM_voidTIM3SetCallBack(void (*copy_voidPtr)(void))
{
	TIM3_CallBackPtr = copy_voidPtr;
}

void TIM3_IRQHandler(void)
{
	if(TIM3_CallBackPtr != NULL_PTR)
	{
		(*TIM3_CallBackPtr)();
	}
	CLEAR_BIT(TIMER3->SR, 0); /* Clear the flag */
}

void MTIM_voidTIM4SetCallBack(void (*copy_voidPtr)(void))
{
	TIM4_CallBackPtr = copy_voidPtr;
}

void TIM4_IRQHandler(void)
{
	if(TIM4_CallBackPtr != NULL_PTR)
	{
		(*TIM4_CallBackPtr)();
	}
	CLEAR_BIT(TIMER4->SR, 0); /* Clear the flag */
}




