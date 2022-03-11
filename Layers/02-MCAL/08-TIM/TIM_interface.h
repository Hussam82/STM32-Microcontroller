/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 25, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_

#include "TIM_private.h"

/* Timer IDs : 	TIMER1
 * 				TIMER2
 * 				TIMER3
 * 				TIMER4
 * 				TIMER5
 * 				TIMER6
 * 				TIMER7
 * 				TIMER8
 * 				TIMER9
 * 				TIMER10
 * 				TIMER11
 * 				TIMER12
 * 				TIMER13
 * 				TIMER14
 */
void MTIM_voidInit(TIM_Regs *TIMERx);
void MTIM_voidSetBusyWait(TIM_Regs *TIMERx, uint32 copy_u32Ticks);
void MTIM_voidSetIntervalPeriodic(TIM_Regs *TIMERx, uint32 copy_u32Ticks);
void MTIM_voidStopTimer(TIM_Regs *TIMERx);
void MTIM_voidTIM2SetCallBack(void (*copy_voidPtr)(void));
void MTIM_voidTIM3SetCallBack(void (*copy_voidPtr)(void));
void MTIM_voidTIM4SetCallBack(void (*copy_voidPtr)(void));


#endif /* TIM_INTERFACE_H_ */
