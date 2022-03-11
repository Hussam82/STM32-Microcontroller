/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Mar 4, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct{
	volatile uint32 ISR;
	volatile uint32 IFCR;
	volatile uint32 CCR1;
	volatile uint32 CNDTR1;
	volatile uint32 CPAR1;
	volatile uint32 CMAR1;
	volatile uint32 RESERVED0;
	volatile uint32 CCR2;
	volatile uint32 CNDTR2;
	volatile uint32 CPAR2;
	volatile uint32 CMAR2;
	volatile uint32 RESERVED1;
	volatile uint32 CCR3;
	volatile uint32 CNDTR3;
	volatile uint32 CPAR3;
	volatile uint32 CMAR3;
	volatile uint32 RESERVED2;
	volatile uint32 CCR4;
	volatile uint32 CNDTR4;
	volatile uint32 CPAR4;
	volatile uint32 CMAR4;
	volatile uint32 RESERVED3;
	volatile uint32 CCR5;
	volatile uint32 CNDTR5;
	volatile uint32 CPAR5;
	volatile uint32 CMAR5;
	volatile uint32 RESERVED4;
	volatile uint32 CCR6;
	volatile uint32 CNDTR6;
	volatile uint32 CPAR6;
	volatile uint32 CMAR6;
	volatile uint32 RESERVED5;
	volatile uint32 CCR7;
	volatile uint32 CNDTR7;
	volatile uint32 CPAR7;
	volatile uint32 CMAR7;
	volatile uint32 RESERVED6;
}DMA_Regs;
#define DMA1 ((volatile DMA_Regs*)0x40020000)

#endif /* DMA_PRIVATE_H_ */
