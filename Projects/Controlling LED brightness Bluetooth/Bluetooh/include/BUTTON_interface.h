/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 13, 2022				*******
 ******* 	Description		:					*******
 **************************************************************/
#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_


#define		PULL_UP				0
#define		PULL_DOWN			1
#if(BUTTON_MODE == PULL_UP)
	#define		BUTTON_PRESSED		0
	#define		BUTTON_RELEASED		1
#elif(BUTTON_MODE == PULL_DOWN)
	#define		BUTTON_PRESSED		1
	#define		BUTTON_RELEASED		0
#endif



uint8 BUTTON_u8ReadStatus(uint8 copy_u8PortId, uint8 copy_u8PinId);




#endif /* BUTTON_INTERFACE_H_ */
