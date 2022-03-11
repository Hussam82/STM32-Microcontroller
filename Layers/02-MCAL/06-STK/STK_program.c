/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 22, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

/* Global Pointer to function to hold the address of the call back function */
static void (*STK_CallBackPtr)(void) = NULL_PTR;

/* Global Variable to Hold the Interval Mode */
static uint8 MSTK_u8IntervalMode;

/* ISR of the SysTick which Calls the callback function through the pointer */
void SysTick_Handler(void)
{
	uint8 local_u8Temp;
	if(MSTK_u8IntervalMode == STK_INTERVAL_SINGLE)
	{
		CLEAR_BIT(STK->CTRL, 0); 						/* Disable SysTick */
		CLEAR_BIT(STK->CTRL, 1);						/* Disable SysTick Interrupt */
		STK->LOAD = 0;
		STK->VAL = 0;
	}
	if(STK_CallBackPtr != NULL_PTR)
	{
		(*STK_CallBackPtr)();
	}
	local_u8Temp = CHECK_BIT(STK->CTRL, 16);	/* Clear the flag */
}


void MSTK_voidInit(void)
{
	#if(STK_CLOCK == STK_AHB)
	{
		SET_BIT(STK->CTRL, 2);						/* Clock Source : AHB */
	}
	#elif(STK_CLOCK == STK_AHB_8)
	{
		CLEAR_BIT(STK->CTRL, 2);					/* Clock Source : AHB/8 */
	}
	#endif
	CLEAR_BIT(STK->CTRL, 0); 						/* Disable SysTick */
	CLEAR_BIT(STK->CTRL, 1);						/* Disable SysTick Interrupt */
}


/* This function takes the time in ms Assuming that AHB frequency is 8MHz */
void MSTK_voidSetBusyWait(uint32 copy_u32Ticks)
{
	uint8 local_u8Temp;
	SET_BIT(STK->CTRL, 0); 							/* Enable SysTick */
	#if(STK_CLOCK == STK_AHB)
	{
		STK->LOAD = copy_u32Ticks * 8000; 			/* Each Tick is 125 ns */
	}
	#elif(STK_CLOCK == STK_AHB_8)
	{
		STK->LOAD = copy_u32Ticks * 1000; 			/* Each tick is 1us */
	}
	#endif
	while(!CHECK_BIT(STK->CTRL, 16)); 				/* Wait until flag is 1 */
	local_u8Temp = CHECK_BIT(STK->CTRL, 16);		/* Clear the flag */
	CLEAR_BIT(STK->CTRL, 0); 						/* Disable SysTick */
	/* Stop the timer */
	STK->LOAD = 0;
	STK->VAL = 0;
}


void MSTK_voidSetIntervalSingle(uint32 copy_u32Ticks, void (*copy_voidPtr)(void))
{
	MSTK_u8IntervalMode = STK_INTERVAL_SINGLE;
	STK_CallBackPtr = copy_voidPtr;
	SET_BIT(STK->CTRL, 0); 							/* Enable SysTick */
	SET_BIT(STK->CTRL, 1); 							/* Enable SysTick Interrupt */
	#if(STK_CLOCK == STK_AHB)
	{
		STK->LOAD = copy_u32Ticks * 8000; 			/* Each Tick is 125 ns */
	}
	#elif(STK_CLOCK == STK_AHB_8)
	{
		STK->LOAD = copy_u32Ticks * 1000; 			/* Each tick is 1us */
	}
	#endif
}

void MSTK_voidSetIntervalPeriodic(uint32 copy_u32Ticks, void (*copy_voidPtr)(void))
{
	MSTK_u8IntervalMode = STK_INTERVAL_PERIODIC;
	STK_CallBackPtr = copy_voidPtr;
	SET_BIT(STK->CTRL, 0); 							/* Enable SysTick */
	SET_BIT(STK->CTRL, 1); 							/* Enable SysTick Interrupt */
	#if(STK_CLOCK == STK_AHB)
	{
		STK->LOAD = copy_u32Ticks * 8000; 			/* Each Tick is 125 ns */
	}
	#elif(STK_CLOCK == STK_AHB_8)
	{
		STK->LOAD = copy_u32Ticks * 1000; 			/* Each tick is 1us */
	}
	#endif
}

void MSTK_voidStopTimer(void)
{
	CLEAR_BIT(STK->CTRL, 0); 						/* Disable SysTick */
	CLEAR_BIT(STK->CTRL, 1);						/* Disable SysTick Interrupt */
	STK->LOAD = 0;
	STK->VAL = 0;
}

uint32 MSTK_u32GetElapsedTime(void)
{
	uint32 local_u32ElapsedTime = 0;
	local_u32ElapsedTime = (STK->LOAD - STK->VAL);
	return local_u32ElapsedTime;
}

uint32 MSTK_u32GetRemainingTime(void)
{
	return STK->VAL;
}
