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


/* Turn on the LED */
void LED_voidLedOn(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_HIGH);
}

/* Turn off the LED */
void LED_voidLedOff(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_LOW);
}

/* Turn on the LED for 1 second then Turn it off */
void LED_voidLedToggle(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	/* Toggle each 1 second */
	uint16 w = 1000;
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_HIGH);
	/* Delay for 1second */
	for(uint16 i = 0; i < w; i++)
	{
		for(uint16 j = 0; j < w; j++)
		{
			asm("NOP");
		}
	}
	GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_LOW);
	/* Delay for 1second */
	for(uint16 i = 0; i < w; i++)
	{
		for(uint16 j = 0; j < w; j++)
		{
			asm("NOP");
		}
	}
}

