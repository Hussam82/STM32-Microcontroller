/****************************************************************************************
 *	Author		: Hussam Ali
 * 	Version		: V01
 * 	Date		: 10 Feb 2022
 ****************************************************************************************/

/* Libraries */
#include "STD_TYPES.h"
#include "common_macros.h"

/* Driver files */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


/* Functions Definitions */

void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; 																		/* Enable HSE without bypass */
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR 	 = 0x00050000;																		/* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081;																		/* Enable HSI + no trimming */
		RCC_CFGR = 0x00000000;
	#elif RCC_CLOCK_TYPE == RCC_PLL
		RCC_CFGR = 0x00000000;
		#if ((RCC_PLL_MUL_VALUE >= 2) && ((RCC_PLL_MUL_VALUE <= 16)))								/* Check the PLL multiply value */
			RCC_CFGR = (RCC_CFGR & 0xFFC3FFFF) | (((RCC_PLL_MUL_VALUE - 2)<<18) & 0x003C0000);		/* Insert the PLL multiply value */
		#else
			#error("Wrong PLL Multiply Value")
		#endif
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CR   = 0x01000081;
			SET_BIT(RCC_CFGR, 2);																	/* Select PLL as system clock */
			/*RCC_CFGR = 0x00000002;*/
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CR   = 0x01010000;
			SET_BIT(RCC_CFGR, 2);																	/* Select PLL as system clock */
			SET_BIT(RCC_CFGR, 16);																	/* Select Input to PLL to be HSE */
			SET_BIT(RCC_CFGR, 17);																	/* Select Input to PLL to be HSE/2 */
			/*RCC_CFGR = 0x00030002;*/
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CR   = 0x01010000;
			SET_BIT(RCC_CFGR, 2);																	/* Select PLL as system clock */
			SET_BIT(RCC_CFGR, 16);																	/* Select Input to PLL to be HSE */
			/*RCC_CFGR = 0x00010002;*/
		#else
			#error("Wrong PLL Input")
		#endif
	#else
		#error("Wrong Clock Type")
	#endif


}




void RCC_voidEnableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, Copy_u8PerId);
			break;
		case RCC_APB1 :
			SET_BIT(RCC_APB1ENR, Copy_u8PerId);
			break;
		case RCC_APB2 :
			SET_BIT(RCC_APB2ENR, Copy_u8PerId);
			break;
		default:
			break;
		}
	}
	else
	{
		/* Return Error */
	}
}


void RCC_voidDisableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB:
			CLEAR_BIT(RCC_AHBENR, Copy_u8PerId);
			break;
		case RCC_APB1 :
			CLEAR_BIT(RCC_APB1ENR, Copy_u8PerId);
			break;
		case RCC_APB2 :
			CLEAR_BIT(RCC_APB2ENR, Copy_u8PerId);
			break;
		}
	}
	else
	{
		/* Return Error */
	}
}

