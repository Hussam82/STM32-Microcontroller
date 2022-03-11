/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 12, 2022		*******
 ******* 	Description		:		GPIO Source Code	*******
 **************************************************************/



#include "STD_TYPES.h"
#include "common_macros.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_voidSetPinDirection(uint8 copy_u8PortId, uint8 copy_u8PinId, uint8 copy_u8Mode)
{
	switch(copy_u8PortId)
	{
		case GPIOA_ID :
			if(copy_u8PinId <= 7)
			{
				GPIOA_CRL  &= ~((0b1111)<<(copy_u8PinId * 4));
				GPIOA_CRL  |=  ((copy_u8Mode)<<(copy_u8PinId * 4));
			}
			else if(copy_u8PinId <= 15)
			{
				copy_u8PinId = copy_u8PinId - 8;
				GPIOA_CRH  &= ~((0b1111)<<(copy_u8PinId * 4));
				GPIOA_CRH  |=  ((copy_u8Mode)<<(copy_u8PinId * 4));
			}
			break;
		case GPIOB_ID :
			if(copy_u8PinId <= 7)
			{
				GPIOB_CRL  &= ~((0b1111)<<(copy_u8PinId * 4));
				GPIOB_CRL  |=  ((copy_u8Mode)<<(copy_u8PinId * 4));
			}
			else if(copy_u8PinId <= 15)
			{
				copy_u8PinId = copy_u8PinId - 8;
				GPIOB_CRH  &= ~((0b1111)<<(copy_u8PinId * 4));
				GPIOB_CRH  |=  ((copy_u8Mode)<<(copy_u8PinId * 4));
			}
			break;
		case GPIOC_ID :
			if(copy_u8PinId <= 7)
			{
				GPIOC_CRL  &= ~((0b1111)<<(copy_u8PinId * 4));
				GPIOC_CRL  |=  ((copy_u8Mode)<<(copy_u8PinId * 4));
			}
			else if(copy_u8PinId <= 15)
			{
				copy_u8PinId = copy_u8PinId - 8;
				GPIOC_CRH  &= ~((0b1111)<<(copy_u8PinId * 4));
				GPIOC_CRH  |=  ((copy_u8Mode)<<(copy_u8PinId * 4));
			}
			break;
		default:
			break;
	}
}

void GPIO_voidSetPinValue(uint8 copy_u8PortId, uint8 copy_u8PinId, uint8 copy_u8Value)
{
	switch(copy_u8PortId)
	{
		case GPIOA_ID :
			if(copy_u8Value == LOGIC_HIGH)
			{
				SET_BIT(GPIOA_ODR, copy_u8PinId);
			}
			else if(copy_u8Value == LOGIC_LOW)
			{
				CLEAR_BIT(GPIOA_ODR, copy_u8PinId);
			}
			break;
		case GPIOB_ID :
			if(copy_u8Value == LOGIC_HIGH)
			{
				SET_BIT(GPIOB_ODR, copy_u8PinId);
			}
			else if(copy_u8Value == LOGIC_LOW)
			{
				CLEAR_BIT(GPIOB_ODR, copy_u8PinId);
			}
			break;
		case GPIOC_ID :
			if(copy_u8Value == LOGIC_HIGH)
			{
				SET_BIT(GPIOC_ODR, copy_u8PinId);
			}
			else if(copy_u8Value == LOGIC_LOW)
			{
				CLEAR_BIT(GPIOC_ODR, copy_u8PinId);
			}
			break;
		default:
			break;
	}
}

uint8 GPIO_u8GetPinValue(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	uint8 loc_u8Result = 0;
	switch(copy_u8PortId)
	{
		case GPIOA_ID :
			loc_u8Result = CHECK_BIT(GPIOA_IDR, copy_u8PinId);
			break;
		case GPIOB_ID :
			loc_u8Result = CHECK_BIT(GPIOB_IDR, copy_u8PinId);
			break;
		case GPIOC_ID :
			loc_u8Result = CHECK_BIT(GPIOC_IDR, copy_u8PinId);
			break;
		default:
			break;
	}
	return loc_u8Result;
}


/* NEEDS MODIFICATIONS */
void GPIO_voidLockPin(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case GPIOA_ID :
			SET_BIT(GPIOA_LCKR, copy_u8PinId);
			break;
		case GPIOB_ID :
			SET_BIT(GPIOB_LCKR, copy_u8PinId);
			break;
		case GPIOC_ID :
			SET_BIT(GPIOC_LCKR, copy_u8PinId);
			break;
		default:
			break;
	}
}





