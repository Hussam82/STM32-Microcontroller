/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 23, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_





#define USARTX_BAUD_RATE	9600

/* Options: PARITY_DISABLE
 	 	 	EVEN_PARITY
 	 	 	ODD_PARITY */
#define USARTX_PARITY		PARITY_DISABLE

/* Options: DATA_8_BITS
 	 	 	DATA_9_BITS */
#define DATA_LENGTH			DATA_8_BITS

/* Options: ONE_STOP_BIT
 	 	 	HALF_STOP_BIT
 	 	 	TWO_STOP_BIT
 	 	 	ONE_AND_HALF_STOP_BIT */
#define STOP_BITS			ONE_STOP_BIT

#endif /* USART_CONFIG_H_ */
