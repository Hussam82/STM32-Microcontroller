/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 26, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


extern volatile uint16 ADC_u16ReadValue;
extern volatile uint16 ADC_u16ReadValueArr[];

void MADC_voidInit(void);
void MADC_voidReadChannel(uint8 copy_u8Channel);
void MADC_voidReadMultipleChannels(uint8 copy_u8channel[]);
void MADC_voidDeInit(void);
#endif /* ADC_INTERFACE_H_ */
