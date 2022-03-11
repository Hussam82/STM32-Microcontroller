/****************************************************************************************
 *	Author		: Hussam Ali
 * 	Version		: V01
 * 	Date		: 10 Feb 2022
 ****************************************************************************************/

#ifndef RCC_INTERFACE_H
#define	RCC_INTERFACE_H

#define RCC_AHB			0
#define RCC_APB1		1
#define RCC_APB2		2

#define RCC_GPIOA		2
#define RCC_GPIOB		3
#define RCC_GPIOC		4

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId);
void RCC_voidDisableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId);

#endif
