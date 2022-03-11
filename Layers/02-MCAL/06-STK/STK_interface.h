/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 22, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

/* Apply Clock Source
 * Disable SysTick
 * Disable SysTick Interrupt
 */
void MSTK_voidInit(void);

/* Polling */
void MSTK_voidSetBusyWait(uint32 copy_u32Ticks);

/* Fire the interrupt only once */
void MSTK_voidSetIntervalSingle(uint32 copy_u32Ticks, void (*copy_voidPtr)(void));

/* Fire the interrupt periodically */
void MSTK_voidSetIntervalPeriodic(uint32 copy_u32Ticks, void (*copy_voidPtr)(void));

/* Stop the timer */
void MSTK_voidStopTimer(void);

/* Get the Elapsed time*/
uint32 MSTK_u32GetElapsedTime(void);

/* Get the Remaining time*/
uint32 MSTK_u32GetRemainingTime(void);

#endif /* STK_INTERFACE_H_ */
