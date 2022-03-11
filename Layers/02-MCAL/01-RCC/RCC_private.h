/****************************************************************************************
 *	Author		: Hussam Ali
 * 	Version		: V01
 * 	Date		: 10 Feb 2022
 ****************************************************************************************/

#ifndef RCC_PRIVATE_H
#define	RCC_PRIVATE_H


/* Registers Definitions */
/* Base Address 0x40021000 */
#define RCC_CR			*((uint32*)0x40021000) /*CLOCK*/
#define RCC_CFGR		*((uint32*)0x40021004) /*CLOCK*/
#define RCC_CIR			*((uint32*)0x40021008)
#define RCC_APB2RSTR	*((uint32*)0x4002100C)
#define RCC_APB1RSTS	*((uint32*)0x40021010)
#define RCC_AHBENR		*((uint32*)0x40021014) /*CLOCK*/
#define RCC_APB2ENR		*((uint32*)0x40021018) /*CLOCK*/
#define RCC_APB1ENR		*((uint32*)0x4002101C) /*CLOCK*/
#define RCC_BDCR		*((uint32*)0x40021020)
#define RCC_CSR			*((uint32*)0x40021024)


/* Clock Types */
#define RCC_HSE_CRYSTAL			0
#define RCC_HSE_RC				1
#define RCC_HSI					2
#define RCC_PLL					3

/* PLL Input Options */
#define RCC_PLL_IN_HSI_DIV_2	4
#define RCC_PLL_IN_HSE_DIV_2	5
#define RCC_PLL_IN_HSE			6

#endif
