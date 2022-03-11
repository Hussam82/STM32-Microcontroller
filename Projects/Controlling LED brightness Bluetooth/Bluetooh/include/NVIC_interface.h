/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 16, 2022				*******
 ******* 	Description		:					*******
 **************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_



void MNVIC_voidInit(void);
//void MNVIC_voidSetPriority(uint8 copy_u8IntId, uint8 copy_u8Priority);

void MNVIC_voidEnableInterrupt(uint8 copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(uint8 copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(uint8 copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(uint8 copy_u8IntNumber);
uint8 MNVIC_u8GetActiveFlag(uint8 copy_u8IntNumber);


void MNVIC_voidSetPriority(sint8 copy_s8IntId, uint8 copy_u8GroupPriority, uint8 copy_u8SubGroupPriority);





#endif /* NVIC_INTERFACE_H_ */
