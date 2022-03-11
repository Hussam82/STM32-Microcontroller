/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 13, 2022		*******
 ******* 	Description		:		7Seg Source Code	*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "GPIO_interface.h"

#include "SEVENSEG_interface.h"
#include "SEVENSEG_private.h"
#include "SEVENSEG_config.h"




void SEVENSEG_voidDisplay(uint8 copy_u8Mode, uint8 copy_u8Digit)
{
	if(copy_u8Mode == COMMON_CATHODE)
	{
		switch(copy_u8Digit)
		{
			case 0:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				break;
			case 1:
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				break;
			case 2:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				break;
			case 3:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				break;
			case 4:
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				break;
			case 5:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				break;
			case 6:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				break;
			case 7:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				break;
			case 8:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				break;
			case 9:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				break;
			default:
				break;


		}
	}
	else if(copy_u8Mode == COMMON_ANODE)
	{
		switch(copy_u8Digit)
		{
			case 0:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				break;
			case 1:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				break;
			case 2:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				break;
			case 3:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				break;
			case 4:
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				break;
			case 5:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				break;
			case 6:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_HIGH);
				break;
			case 7:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_HIGH);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_HIGH);
				break;
			case 8:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				break;
			case 9:
				GPIO_voidSetPinDirection(A_PORT, A_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(A_PORT, A_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(B_PORT, B_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(B_PORT, B_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(C_PORT, C_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(C_PORT, C_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(D_PORT, D_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(D_PORT, D_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(F_PORT, F_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(F_PORT, F_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(G_PORT, G_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(G_PORT, G_PIN, LOGIC_LOW);
				GPIO_voidSetPinDirection(E_PORT, E_PIN, OUTPUT_SPEED_2MHZ_PP);
				GPIO_voidSetPinValue(E_PORT, E_PIN, LOGIC_HIGH);
				break;
			default:
				break;


		}
	}
}
