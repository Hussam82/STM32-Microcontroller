/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 26, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef struct{
	volatile uint32 SR;
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMPR1;
	volatile uint32 SMPR2;
	volatile uint32 JOFR1;
	volatile uint32 JOFR2;
	volatile uint32 JOFR3;
	volatile uint32 JOFR4;
	volatile uint32 HTR;
	volatile uint32 LTR;
	volatile uint32 SQR1;
	volatile uint32 SQR2;
	volatile uint32 SQR3;
	volatile uint32 JSQR;
	volatile uint32 JDR1;
	volatile uint32 JDR2;
	volatile uint32 JDR3;
	volatile uint32 JDR4;
	volatile uint32 DR;
}ADC_Regs;

#define ADC1 ((volatile ADC_Regs*)0x40012400)


/* ADC MODE */
#define ADC_CONTINUOUS_MODE			0
#define ADC_DISCONTINUOUS_MODE		1

/* ADC CHANNEL MODE */
#define ADC_SINGLE_CHANNEL				0
#define ADC_MULTIPLE_CHANNEL			1

#endif /* ADC_PRIVATE_H_ */
