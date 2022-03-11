/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 20, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* Line ID */
#define EXTI_LINE0	0
#define EXTI_LINE1	1
#define EXTI_LINE2	2
#define EXTI_LINE3	3
#define EXTI_LINE4	4
#define EXTI_LINE5	5
#define EXTI_LINE6	6
#define EXTI_LINE7	7
#define EXTI_LINE8	8
#define EXTI_LINE9	9
#define EXTI_LINE10	10
#define EXTI_LINE11	11
#define EXTI_LINE12	12
#define EXTI_LINE13	13
#define EXTI_LINE14	14
#define EXTI_LINE15	15

/* Modes */
#define RISING_EDGE		0
#define	FALLING_EDGE	1
#define ON_CHANGE		2

/* Two Parameters : Line and Mode */
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(uint8 copy_u8Line);
void MEXTI_voidDisableEXTI(uint8 copy_u8Line);
void MEXTI_voidSwTrigger(uint8 copy_u8Line);
void MEXTI_voidSetSignalLatch(uint8 copy_u8Line, uint8 copy_u8Mode);
void MEXTI_voidEXTI0SetCallBack(void (*copy_voidPtr)(void));
void MEXTI_voidEXTI1SetCallBack(void (*copy_voidPtr)(void));
void MEXTI_voidEXTI2SetCallBack(void (*copy_voidPtr)(void));
void MEXTI_voidEXTI3SetCallBack(void (*copy_voidPtr)(void));
#endif /* EXTI_INTERFACE_H_ */
