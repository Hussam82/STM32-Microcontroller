/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 20, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

typedef struct{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR[4];
	volatile uint32 MAPR2;
}AFIO_Regs;
#define	AFIO ((volatile AFIO_Regs*)0x40010000)




#endif /* AFIO_PRIVATE_H_ */
