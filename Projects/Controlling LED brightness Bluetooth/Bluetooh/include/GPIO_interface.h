/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 12, 2022		*******
 ******* 	Description		:		GPIO Interface file	*******
 **************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/*			PORTx ID			*/
#define 	GPIOA_ID		0
#define 	GPIOB_ID		1
#define 	GPIOC_ID		2

/*			PINx ID			*/
#define		PIN0		0
#define		PIN1		1
#define		PIN2		2
#define		PIN3		3
#define		PIN4		4
#define		PIN5		5
#define		PIN6		6
#define		PIN7		7
#define		PIN8		8
#define		PIN9		9
#define		PIN10		10
#define		PIN11		11
#define		PIN12		12
#define		PIN13		13
#define		PIN14		14
#define		PIN15		15

/*			Modes ID			*/
/*			INPUT MODE			*/
#define		INPUT_ANALOG				0b0000
#define		INPUT_FLOATING				0b0100
#define		INPUT_PULL_UP_DOWN			0b1000

/*			OUTPUT 10MHZ MODE			*/
#define		OUTPUT_SPEED_10MHZ_PP		0b0001
#define		OUTPUT_SPEED_10MHZ_OD		0b0101
#define		OUTPUT_SPEED_10MHZ_AFPP		0b1001
#define		OUTPUT_SPEED_10MHZ_AFOD		0b1101

/*			OUTPUT 2MHZ MODE			*/
#define		OUTPUT_SPEED_2MHZ_PP		0b0010
#define		OUTPUT_SPEED_2MHZ_OD		0b0110
#define		OUTPUT_SPEED_2MHZ_AFPP		0b1010
#define		OUTPUT_SPEED_2MHZ_AFOD		0b1110

/*			OUTPUT 50MHZ MODE			*/
#define		OUTPUT_SPEED_50MHZ_PP		0b0011
#define		OUTPUT_SPEED_50MHZ_OD		0b0111
#define		OUTPUT_SPEED_50MHZ_AFPP		0b1011
#define		OUTPUT_SPEED_50MHZ_AFOD		0b1111


void GPIO_voidSetPinDirection(uint8 copy_u8PortId, uint8 copy_u8PinId, uint8 copy_u8Mode);
void GPIO_voidSetPinValue(uint8 copy_u8PortId, uint8 copy_u8PinId, uint8 copy_u8Value);
uint8 GPIO_u8GetPinValue(uint8 copy_u8PortId, uint8 copy_u8PinId);
void GPIO_voidLockPin(uint8 copy_u8PortId, uint8 copy_u8PinId);





#endif /* DIO_INTERFACE_H_ */
