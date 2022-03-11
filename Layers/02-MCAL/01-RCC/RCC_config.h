/****************************************************************************************
 *	Author		: Hussam Ali
 * 	Version		: V01
 * 	Date		: 10 Feb 2022
****************************************************************************************/

#ifndef RCC_CONFIG_H
#define	RCC_CONFIG_H

/* Options:		RCC_HSE_CRYSTAL
 * 				RCC_HSE_RC
 * 				RCC_HSI
 * 				RCC_PLL 			*/
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL

#if RCC_CLOCK_TYPE == RCC_PLL
/* Options:		RCC_PLL_IN_HSI_DIV_2
 * 				RCC_PLL_IN_HSE_DIV_2
 * 				RCC_PLL_IN_HSE
 */
/* Note: Select input for PLL only if Clock Type is RCC_PLL */
#define RCC_PLL_INPUT RCC_PLL_IN_HSE_DIV_2
/* Options:		2 to 16 */
#define RCC_PLL_MUL_VALUE	4
#endif






#endif
