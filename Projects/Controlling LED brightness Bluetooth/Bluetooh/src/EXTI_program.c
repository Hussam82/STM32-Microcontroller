/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 20, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*EXTI_CallBackPtr[16])(void) = {NULL_PTR};


/* Change the mode only one time pre-build
 * Use one function only either this one or MEXTI_voidSetSignalLatch.
 * Don't use both */
void MEXTI_voidInit()
{
	#if(EXTI_MODE == RISING_EDGE)
		SET_BIT(EXTI->RTSR, EXTI_LINE);
	#elif(EXTI_MODE == FALLING_EDGE)
		SET_BIT(EXTI->FTSR, EXTI_LINE);
	#elif(EXTI_MODE == ON_CHANGE)
		SET_BIT(EXTI->RTSR, EXTI_LINE);
		SET_BIT(EXTI->FTSR, EXTI_LINE);
	#else
		#error "Wrong Mode";
	#endif
}

void MEXTI_voidEnableEXTI(uint8 copy_u8Line)
{
	SET_BIT(EXTI->IMR, copy_u8Line);
}

void MEXTI_voidDisableEXTI(uint8 copy_u8Line)
{
	CLEAR_BIT(EXTI->IMR, copy_u8Line);
}

void MEXTI_voidSwTrigger(uint8 copy_u8Line)
{
	SET_BIT(EXTI->SWIER, copy_u8Line);
}

/* Same as MEXTI_voidInit() but to make it possible to change the LINE during runtime */
void MEXTI_voidSetSignalLatch(uint8 copy_u8Line, uint8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
	case RISING_EDGE:
		SET_BIT(EXTI->RTSR, copy_u8Line);
		break;
	case FALLING_EDGE:
		SET_BIT(EXTI->FTSR, copy_u8Line);
		break;
	case ON_CHANGE:
		SET_BIT(EXTI->RTSR, copy_u8Line);
		SET_BIT(EXTI->FTSR, copy_u8Line);
		break;
	default:
		/* ERROR */
		break;
	}
}


void MEXTI_voidEXTI0SetCallBack(void (*copy_voidPtr)(void))
{
	EXTI_CallBackPtr[0] = copy_voidPtr;
}

void MEXTI_voidEXTI1SetCallBack(void (*copy_voidPtr)(void))
{
	EXTI_CallBackPtr[1] = copy_voidPtr;
}

void MEXTI_voidEXTI2SetCallBack(void (*copy_voidPtr)(void))
{
	EXTI_CallBackPtr[2] = copy_voidPtr;
}

void MEXTI_voidEXTI3SetCallBack(void (*copy_voidPtr)(void))
{
	EXTI_CallBackPtr[3] = copy_voidPtr;
}


/* ISR of the EXTI0 */
void EXTI0_IRQHandler(void)
{
	if(EXTI_CallBackPtr[0] != NULL_PTR)
	{
		(*EXTI_CallBackPtr[0])();
	}
	SET_BIT(EXTI->PR, EXTI_LINE0); /* Clear pending bit */
}

/* ISR of the EXTI1 */
void EXTI1_IRQHandler(void)
{
	if(EXTI_CallBackPtr[1] != NULL_PTR)
	{
		(*EXTI_CallBackPtr[1])();
	}
	SET_BIT(EXTI->PR, EXTI_LINE1); /* Clear pending bit */
}

/* ISR of the EXTI2 */
void EXTI2_IRQHandler(void)
{
	if(EXTI_CallBackPtr[2] != NULL_PTR)
	{
		(*EXTI_CallBackPtr[2])();
	}
	SET_BIT(EXTI->PR, EXTI_LINE2); /* Clear pending bit */
}

/* ISR of the EXTI3 */
void EXTI3_IRQHandler(void)
{
	if(EXTI_CallBackPtr[3] != NULL_PTR)
	{
		(*EXTI_CallBackPtr[3])();
		SET_BIT(EXTI->PR, EXTI_LINE3); /* Clear pending bit */
	}
}


