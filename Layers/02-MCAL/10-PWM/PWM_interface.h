/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 27, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#include "TIM_private.h"

void MPWM_voidInit(TIM_Regs *TIMERx, uint8 copy_u8Channel);
void MPWM_voidSetDutyCycle(TIM_Regs *TIMERx, uint8 copy_u8Channel, uint8 copy_u8DutyCycle, uint32 copy_u32PeriodInMs);
void MPWM_voidDeInit(TIM_Regs *TIMERx, uint8 copy_u8Channel);

#endif /* PWM_INTERFACE_H_ */
