/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 11, 2022		*******
 ******* 	Description		:		main function		*******
 **************************************************************/

#include "STD_TYPES.h"
#include "common_macros.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"

#include "SEVENSEG_interface.h"

#include "BUTTON_interface.h"
#include "BUTTON_config.h"

#include "NVIC_interface.h"

#include "STK_interface.h"
#include "STK_config.h"

#include "EXTI_interface.h"

#include "AFIO_interface.h"

#include "USART_interface.h"

#include "ADC_interface.h"

#include "PWM_interface.h"

#include "TIM_interface.h"



void ToggleLed(void)
{
	if(USART1_u8RxBuffer[0] == '5')
	{
		LED_voidLedToggle(GPIOC_ID, PIN14);
	}
	MUSART_voidSendString(USART2, "USART1 Received Successfully! \n");
}



void LedBrightness(void)
{
	/* Convert each element in the array into integer then form the entire number */
    uint32 local_u32Result = 0;
    for(uint8 i = 0; USART2_u8RxBuffer[i] != '\0'; i++)
    {
    	local_u32Result = local_u32Result * 10 + (USART2_u8RxBuffer[i] - '0');
    }
	MPWM_voidSetDutyCycle(TIMER4, 4, local_u32Result, 1);
	MUSART_voidSendString(USART2, "USART2 Received Successfully! \n");
}

int main(void)
{
	/* Initialize Clock System */
	RCC_voidInitSysClock();

	/* Enable Peripheral 2 on APB2 Bus (GPIOA) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA);

	/* Enable Peripheral 3 on APB2 Bus (GPIOB) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOB);

	/* Enable Peripheral 4 on APB2 Bus (GPIOC) */
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOC);

	/* Enable Peripheral 0 on APB2 Bus (AFIO) */
	RCC_voidEnableClock(RCC_APB2, 0);



	/* Enable Peripheral 2 on APB1 Bus (TIM4) */
	RCC_voidEnableClock(RCC_APB1, 2);

	/* Enable Peripheral 0 on AHB Bus (DMA1) */
	RCC_voidEnableClock(RCC_AHB, 0);

	/* Enable Peripheral 9 on APB2 Bus (ADC1) */
	RCC_voidEnableClock(RCC_APB2, 9);

	/******************* Initialize USART1 ***************************/
	/* Enable Peripheral 14 on APB2 Bus (USART1) */
	RCC_voidEnableClock(RCC_APB2, 14);

	/* Configure A10(RX) as input floating */
	GPIO_voidSetPinDirection(GPIOA_ID, PIN10, INPUT_FLOATING);

	/* Configure A9(TX) as OUTPUT PUSH PULL 50 MHz */
	GPIO_voidSetPinDirection(GPIOA_ID, PIN9, OUTPUT_SPEED_50MHZ_AFPP);

	/* Initialize USART1 */
	MUSART_voidInit(USART1);

	/* Enable USART1 Global Interrupt */
	MNVIC_voidEnableInterrupt(37);

	/* Set the call back function */
	MUSART1_voidSetCallBack(ToggleLed);

	/******************* Initialize USART2 ***************************/
	/* Enable Peripheral 17 on APB1 Bus (USART2) */
	RCC_voidEnableClock(RCC_APB1, 17);

	/* Configure A3(RX) as input floating */
	GPIO_voidSetPinDirection(GPIOA_ID, PIN3, INPUT_FLOATING);

	/* Configure A2(TX) as OUTPUT PUSH PULL 50 MHz */
	GPIO_voidSetPinDirection(GPIOA_ID, PIN2, OUTPUT_SPEED_50MHZ_AFPP);

	/* Initialize USART2 */
	MUSART_voidInit(USART2);

	/* Enable USART2 Global Interrupt */
	MNVIC_voidEnableInterrupt(38);

	/* Set the call back function */
	MUSART2_voidSetCallBack(LedBrightness);

	/******************* Initialize PWM ***************************/
	/* Set B9 ( TIM4 CH4 ) as alternating function push pull */
	GPIO_voidSetPinDirection(GPIOB_ID, PIN9, OUTPUT_SPEED_2MHZ_AFPP);

	/* Initialize PWM channel 4 */
	MPWM_voidInit(TIMER4, 4);

	/******************* Initialize SysTick ***************************/
	MSTK_voidInit();

	/******************* APP ***************************/
	MUSART_voidSendString(USART1, "Welcome USART1");
	MSTK_voidSetBusyWait(100);
	MUSART_voidSendString(USART2, "Welcome USART2");




	while(1)
	{


	}
	return 0;
}





