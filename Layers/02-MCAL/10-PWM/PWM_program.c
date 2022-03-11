/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 27, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/



#include "STD_TYPES.h"
#include "common_macros.h"

#include "PWM_interface.h"
#include "PWM_config.h"
#include "PWM_private.h"

#include "TIM_interface.h"
#include "TIM_config.h"
#include "TIM_private.h"




void MPWM_voidInit(TIM_Regs *TIMERx, uint8 copy_u8Channel)
{
	/* Pre-scaler and frequency settings */
	TIMERx->PSC = TIM_PRESCALER; /* Pre-scaler 512 Assuming 8MHz clock */

	/* Check for the Timer mode */
	#if(TIM_MODE == EDGE_ALIGNED_MODE)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b00)<<5;
		/* Check for the Timer direction */
		#if(TIM_DIRECTION == UP_COUNTER)
		{
			CLEAR_BIT(TIMERx->CR1, 4); /* Clear DIR bit */
		}
		#elif(TIM_DIRECTION == DOWN_COUNTER)
		{
			SET_BIT(TIMERx->CR1, 4);	/* Set DIR bit */
		}
		#endif
	}
	#elif(TIM_MODE == CENTER_ALIGNED_MODE_1)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b01)<<5;
	}
	#elif(TIM_MODE == CENTER_ALIGNED_MODE_2)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b10)<<5;
	}
	#elif(TIM_MODE == CENTER_ALIGNED_MODE_3)
	{
		/* Select Edge aligned mode */
		TIMERx->CR1 &= ~((0b11)<<5);
		TIMERx->CR1 |= (0b11)<<5;
	}
	#endif

	/* Select the PWM mode */
	#if(TIM_PWM_MODE == PWM_MODE_1)
	{
		switch(copy_u8Channel)
		{
		case 1:
			/* Set OC1M bits */
			TIMERx->CCMR1 &= ~((0b111) << 4);
			TIMERx->CCMR1 |=  (0b110) << 4;
			/* Set OC1PE bit */
			SET_BIT(TIMERx->CCMR1, 3);
			/* Set CC1E bit */
			SET_BIT(TIMERx->CCER, 0);
			break;
		case 2:
			/* Set OC2M bits */
			TIMERx->CCMR1 &= ~((0b111) << 12);
			TIMERx->CCMR1 |=  (0b110) << 12;
			/* Set OC2PE bit */
			SET_BIT(TIMERx->CCMR1, 11);
			/* Set CC2E bit */
			SET_BIT(TIMERx->CCER, 4);
			break;
		case 3:
			/* Set OC3M bits */
			TIMERx->CCMR2 &= ~((0b111) << 4);
			TIMERx->CCMR2 |=  (0b110) << 4;
			/* Set OC3PE bit */
			SET_BIT(TIMERx->CCMR2, 3);
			/* Set CC3E bit */
			SET_BIT(TIMERx->CCER, 8);
			break;
		case 4:
			/* Set OC4M bits */
			TIMERx->CCMR2 &= ~((0b111) << 12);
			TIMERx->CCMR2 |=  (0b110) << 12;
			/* Set OC4PE bit */
			SET_BIT(TIMERx->CCMR2, 11);
			/* Set CC4E bit */
			SET_BIT(TIMERx->CCER, 12);
			break;
		default:
			break;
		}
	}
	#elif(TIM_PWM_MODE == PWM_MODE_2)
	{
		switch(copy_u8Channel)
		{
		case 1:
			/* Set OC1M bits */
			TIMERx->CCMR1 |=  (0b111) << 4;
			/* Set OC1PE bit */
			SET_BIT(TIMERx->CCMR1, 3);
			/* Set CC1E bit */
			SET_BIT(TIMERx->CCER, 0);
			break;
		case 2:
			/* Set OC2M bits */
			TIMERx->CCMR1 |=  (0b111) << 12;
			/* Set OC2PE bit */
			SET_BIT(TIMERx->CCMR1, 11);
			/* Set CC2E bit */
			SET_BIT(TIMERx->CCER, 4);
			break;
		case 3:
			/* Set OC3M bits */
			TIMERx->CCMR2 |=  (0b111) << 4;
			/* Set OC3PE bit */
			SET_BIT(TIMERx->CCMR2, 3);
			/* Set CC3E bit */
			SET_BIT(TIMERx->CCER, 8);
			break;
		case 4:
			/* Set OC4M bits */
			TIMERx->CCMR2 |=  (0b111) << 12;
			/* Set OC4PE bit */
			SET_BIT(TIMERx->CCMR2, 11);
			/* Set CC4E bit */
			SET_BIT(TIMERx->CCER, 12);
			break;
		default:
			break;
		}
	}
	#endif

	/* Set ARPE bit */
	SET_BIT(TIMERx->CR1, 7);

	/* Set UG bit */
	SET_BIT(TIMERx->EGR, 0);


}

void MPWM_voidSetDutyCycle(TIM_Regs *TIMERx, uint8 copy_u8Channel, uint8 copy_u8DutyCycle, uint32 copy_u32PeriodInMs)
{
	TIMERx->ARR = (F_CPU / TIM_PRESCALER) * (copy_u32PeriodInMs / 1000.0);
	switch(copy_u8Channel)
	{
	case 1:
		TIMERx->CCR1 = ((copy_u8DutyCycle / 100.0) * TIMERx->ARR);
		break;
	case 2:
		TIMERx->CCR2 = ((copy_u8DutyCycle / 100.0) * TIMERx->ARR);
		break;
	case 3:
		TIMERx->CCR3 = ((copy_u8DutyCycle / 100.0) * TIMERx->ARR);
		break;
	case 4:
		TIMERx->CCR4 = ((copy_u8DutyCycle / 100.0) * TIMERx->ARR);
		break;
	default:
		break;
	}
	/* Enable Counter */
	SET_BIT(TIMERx->CR1, 0);
}

void MPWM_voidDeInit(TIM_Regs *TIMERx, uint8 copy_u8Channel)
{
	switch(copy_u8Channel)
	{
	case 1:
		/* Clear OC1M bits */
		TIMERx->CCMR1 &= ~((0b111) << 4);
		/* Clear OC1PE bit */
		CLEAR_BIT(TIMERx->CCMR1, 3);
		/* Clear CC1E bit */
		CLEAR_BIT(TIMERx->CCER, 0);
		break;
	case 2:
		/* Clear OC2M bits */
		TIMERx->CCMR1 &= ~((0b111) << 12);
		/* Clear OC2PE bit */
		CLEAR_BIT(TIMERx->CCMR1, 11);
		/* Clear CC2E bit */
		CLEAR_BIT(TIMERx->CCER, 4);
		break;
	case 3:
		/* Clear OC3M bits */
		TIMERx->CCMR2 &= ~((0b111) << 4);
		/* Clear OC3PE bit */
		CLEAR_BIT(TIMERx->CCMR2, 3);
		/* Clear CC3E bit */
		CLEAR_BIT(TIMERx->CCER, 8);
		break;
	case 4:
		/* Clear OC4M bits */
		TIMERx->CCMR2 &= ~((0b111) << 12);
		/* Clear OC4PE bit */
		CLEAR_BIT(TIMERx->CCMR2, 11);
		/* Clear CC4E bit */
		CLEAR_BIT(TIMERx->CCER, 12);
		break;
	default:
		break;
	}
}

