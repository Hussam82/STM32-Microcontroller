/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 25, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef TIM_PRIVATE_H_
#define TIM_PRIVATE_H_


/* Base Address of TIMERx */
#define TIMER1_BASE_ADDRESS                        0x40012C00
#define TIMER2_BASE_ADDRESS                        0x40000000
#define TIMER3_BASE_ADDRESS                        0x40000400
#define TIMER4_BASE_ADDRESS                        0x40000800
#define TIMER5_BASE_ADDRESS                        0x40000C00
#define TIMER6_BASE_ADDRESS                        0x40001000
#define TIMER7_BASE_ADDRESS                        0x40001400
#define TIMER8_BASE_ADDRESS                        0x40013400
#define TIMER9_BASE_ADDRESS                        0x40014C00
#define TIMER10_BASE_ADDRESS                       0x40015000
#define TIMER11_BASE_ADDRESS                       0x40015400
#define TIMER12_BASE_ADDRESS                       0x40001800
#define TIMER13_BASE_ADDRESS                       0x40001C00
#define TIMER14_BASE_ADDRESS                       0x40002000

/* Registers Structure */
typedef struct{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMCR;
	volatile uint32 DIER;
	volatile uint32 SR;
	volatile uint32 EGR;
	volatile uint32 CCMR1;
	volatile uint32 CCMR2;
	volatile uint32 CCER;
	volatile uint32 CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
	volatile uint32 RESERVED1;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 RESERVED2;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}TIM_Regs;

#define TIMER1                   ((TIM_Regs*)TIMER1_BASE_ADDRESS)	/* Advanced Timer */
#define TIMER2                   ((TIM_Regs*)TIMER2_BASE_ADDRESS)
#define TIMER3                   ((TIM_Regs*)TIMER3_BASE_ADDRESS)
#define TIMER4                   ((TIM_Regs*)TIMER4_BASE_ADDRESS)
#define TIMER5                   ((TIM_Regs*)TIMER5_BASE_ADDRESS)
#define TIMER6                   ((TIM_Regs*)TIMER6_BASE_ADDRESS)	/* Basic Timer */
#define TIMER7                   ((TIM_Regs*)TIMER7_BASE_ADDRESS)	/* Basic Timer */
#define TIMER8                   ((TIM_Regs*)TIMER8_BASE_ADDRESS)	/* Advanced Timer */
#define TIMER9                   ((TIM_Regs*)TIMER9_BASE_ADDRESS)
#define TIMER10                  ((TIM_Regs*)TIMER10_BASE_ADDRESS)
#define TIMER11                  ((TIM_Regs*)TIMER11_BASE_ADDRESS)
#define TIMER12                  ((TIM_Regs*)TIMER12_BASE_ADDRESS)
#define TIMER13                  ((TIM_Regs*)TIMER13_BASE_ADDRESS)
#define TIMER14                  ((TIM_Regs*)TIMER14_BASE_ADDRESS)


/* Timer direction */
#define UP_COUNT 	0
#define DOWN_COUNT	1

/* Timer mode */
#define	EDGE_ALIGNED_MODE		0
#define	CENTER_ALIGNED_MODE_1	1
#define	CENTER_ALIGNED_MODE_2	2
#define	CENTER_ALIGNED_MODE_3	3





#endif /* TIM_PRIVATE_H_ */
