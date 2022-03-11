/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 13, 2022		*******
 ******* 	Description		:		7Seg Interface File	*******
 **************************************************************/
#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_




#define		COMMON_CATHODE		0
#define		COMMON_ANODE		1

#define		A_PORT				GPIOA_ID
#define		A_PIN				PIN4

#define		B_PORT				GPIOA_ID
#define		B_PIN				PIN5

#define		C_PORT				GPIOA_ID
#define		C_PIN				PIN2

#define		D_PORT				GPIOA_ID
#define		D_PIN				PIN1

#define		E_PORT				GPIOA_ID
#define		E_PIN				PIN0

#define		F_PORT				GPIOA_ID
#define		F_PIN				PIN6

#define		G_PORT				GPIOA_ID
#define		G_PIN				PIN7


void SEVENSEG_voidDisplay(uint8 copy_u8Mode, uint8 copy_u8Digit);

#endif /* SEVENSEG_INTERFACE_H_ */
