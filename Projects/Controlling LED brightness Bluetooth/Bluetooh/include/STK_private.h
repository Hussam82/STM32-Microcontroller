/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 22, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

typedef struct{
	volatile uint32 CTRL;
	volatile uint32 LOAD;
	volatile uint32 VAL;
	volatile uint32 CALIB;
}STK_Regs;
#define	STK	((volatile STK_Regs*)0xE000E010)


#define STK_AHB					0
#define STK_AHB_8				1

#define STK_INTERVAL_SINGLE		0
#define STK_INTERVAL_PERIODIC	1

#endif /* STK_PRIVATE_H_ */
