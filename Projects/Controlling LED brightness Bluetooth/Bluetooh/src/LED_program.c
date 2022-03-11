/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 13, 2022		*******
 ******* 	Description		:		LED Source Code		*******
 **************************************************************/


#include "STD_TYPES.h"
#include "common_macros.h"


#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidLedOn(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_HIGH);
}

void LED_voidLedOff(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_LOW);
}

void LED_voidLedToggle(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, OUTPUT_SPEED_2MHZ_PP);

	if(GPIO_u8GetPinValue(copy_u8PortId, copy_u8PinId) == 1)
	{
		GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_LOW);
	}
	else
	{
		GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_HIGH);
	}

}

