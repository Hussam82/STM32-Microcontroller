/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 20, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

void MAFIO_voidSetEXTI(uint8 copy_u8Line, uint8 copy_u8PortMap)
{
	uint8 local_u8RegIndex = 0;	/* Variable to indicate the index of the EXTICRx Register */
	if(copy_u8Line <= 3)
	{
		local_u8RegIndex = 0;	/* AFIO_EXTICR1 */
	}
	else if(copy_u8Line <= 7)
	{
		local_u8RegIndex = 1;	/* AFIO_EXTICR2 */

	}
	else if(copy_u8Line <= 11)
	{
		local_u8RegIndex = 2;	/* AFIO_EXTICR3 */
	}
	else if(copy_u8Line <= 15)
	{
		local_u8RegIndex = 3;	/* AFIO_EXTICR4 */
	}
	/* To write in the right place in EXTICR register ex: Line 14 is in EXTICR4 in the second 4 bits field EXTI14 */
	copy_u8Line %= 4;
	/* Clear the 4 bits of EXTIx in EXTICRx register */
	AFIO->EXTICR[local_u8RegIndex] &= ~((0b1111)<<(copy_u8Line * 4));
	/* Insert the required port map in the 4 bits of EXTIx in EXTICRx register*/
	AFIO->EXTICR[local_u8RegIndex] |= ((copy_u8PortMap)<<(copy_u8Line * 4));
}
