/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 13, 2022				*******
 ******* 	Description		:					*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "GPIO_interface.h"

#include "BUTTON_interface.h"
#include "BUTTON_private.h"
#include "BUTTON_config.h"



uint8 BUTTON_u8ReadStatus(uint8 copy_u8PortId, uint8 copy_u8PinId)
{
	uint8 loc_u8ButtonState = 0;
	GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, INPUT_PULL_UP_DOWN);
	#if(BUTTON_MODE == PULL_UP)
		GPIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, LOGIC_HIGH);
	#endif
	if(GPIO_u8GetPinValue(copy_u8PortId, copy_u8PinId) == BUTTON_PRESSED)
	{
		loc_u8ButtonState = BUTTON_PRESSED;
	}
	else
	{
		loc_u8ButtonState = BUTTON_RELEASED;
	}
	return loc_u8ButtonState;
}
