/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 16, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/* Will be removed later when we make the driver for SCB core peripheral */
void MNVIC_voidInit(void)
{
	#define SCB_AIRCR *((volatile uint32*)(0xE000ED00 + 0x0C))
	SCB_AIRCR = NVIC_GROUP_SUB_DIST;
}


void MNVIC_voidEnableInterrupt(uint8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;		/* Minus 32 to write 1 in the correct bit in the second register */
		NVIC_ISER1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidDisableInterrupt(uint8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;		/* Minus 32 to write 1 in the correct bit in the second register */
		NVIC_ICER1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidSetPendingFlag(uint8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;		/* Minus 32 to write 1 in the correct bit in the second register */
		NVIC_ISPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidClearPendingFlag(uint8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;		/* Minus 32 to write 1 in the correct bit in the second register */
		NVIC_ICPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}

uint8 MNVIC_u8GetActiveFlag(uint8 copy_u8IntNumber)
{
	uint8 local_u8Result = 0;
	if(copy_u8IntNumber <= 31)
	{
		local_u8Result = CHECK_BIT(NVIC_IABR0, copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;		/* Minus 32 to write 1 in the correct bit in the second register */
		local_u8Result = CHECK_BIT(NVIC_IABR1, copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
	return local_u8Result;
}


void MNVIC_voidSetPriority(sint8 copy_s8IntId, uint8 copy_u8GroupPriority, uint8 copy_u8SubGroupPriority)
{
	/* Generating the 4 bits to be inserted in the NIVC_IPRx */
	uint8 local_u8Priority = (copy_u8SubGroupPriority) | (copy_u8GroupPriority<<((NVIC_GROUP_SUB_DIST - NVIC_GROUP_4_SUB_0) / 256));

	/* Check whether the interrupt is from Core Peripheral or External Peripheral */
	if(copy_s8IntId >= 0)	/* External Peripheral */
	{
		NVIC_IPR[copy_s8IntId] = (local_u8Priority << 4); /* To insert the 4 bits in the Most significant 4 bits of IPx in IPRx register */
	}
}

