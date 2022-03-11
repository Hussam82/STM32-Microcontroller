/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 20, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}EXTI_Regs;
/* Pointer to EXTI struct to access the EXTI registers */
#define EXTI ((volatile EXTI_Regs*)0x40010400)












#endif /* EXTI_PRIVATE_H_ */
