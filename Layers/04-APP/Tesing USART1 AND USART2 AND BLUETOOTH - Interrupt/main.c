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

static uint8 num = 0;
static uint8 count = 0;
//static uint8 flag = 0;


void countSevenSegment(void)
{
	count++;
	if(count <= 5 * 9)
	{
		if(num <= 9)
		{
			SEVENSEG_voidDisplay(COMMON_ANODE, num);
			num++;
		}
		else
		{
			num = 0;
		}
	}
	else if(count <= (5 * 9) + 16)
	{
		MSTK_voidSetIntervalPeriodic(1000,countSevenSegment);
		LED_voidLedToggle(GPIOC_ID, PIN14);
	}
	else
	{
		count = 0;
	}
}

void ToggleLed(void)
{
	if(USART1_u8RxBuffer[0] == '5')
	{
		LED_voidLedToggle(GPIOC_ID, PIN14);
	}
	MUSART_voidSendString(USART1, "USART1 Received Successfully! \n");
}



void LedBrightness(void)
{
//	if(USART2_u8RxBuffer[0] == '1')
//	{
//		LED_voidLedToggle(GPIOC_ID, PIN14);
//	}
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
	MSTK_voidSetBusyWait(1000);
	MUSART_voidSendString(USART2, "Welcome USART2");

//	uint8 x1;
//	uint8 x2;
//	/******************* Initialize ADC ***************************/
//	/* Set A0 as input analog CH0 */
//	GPIO_voidSetPinDirection(GPIOA_ID, PIN0, INPUT_ANALOG);
//
//	/* Set A1 as input analog CH1 */
//	GPIO_voidSetPinDirection(GPIOA_ID, PIN1, INPUT_ANALOG);
//
//	/* Enable ADC1 NVIC */
//	MNVIC_voidEnableInterrupt(18);
//
//	/* Initialize ADC */
//	MADC_voidInit();
//


//	/* Initialize TIM3 */
//	RCC_voidEnableClock(RCC_APB1, 1);
//	MNVIC_voidEnableInterrupt(29);
//	MTIM_voidInit(TIMER3);
//	MTIM_voidTIM3SetCallBack(ToggleLed);
//	MTIM_voidSetIntervalPeriodic(TIMER3, 1000);
//
//	/******************* APP ***************************/
//	/* Read channel 0 and 1 */
//	uint8 channels[2] = {0, 1};
//	MADC_voidReadMultipleChannels(channels);
//
//	uint8 dutycycle1;
//	uint8 dutycycle2;
//	uint8 x[20];

	while(1)
	{

//
//		dutycycle1 = MUSART1_u32ReceiveInteger(x);
//
//		MPWM_voidSetDutyCycle(TIMER4, 4, dutycycle1, 1);

//		if(x[0] == '5')
//		{
//			LED_voidLedToggle(GPIOC_ID, PIN14);
//		}
//		else if(x[1] == 'R')
//		{
//			LED_voidLedOff(GPIOC_ID, PIN14);
//		}

//		dutycycle1 = ((ADC_u16ReadValueArr[0] * 100.0) / 4095.0);
//		dutycycle2 = ((ADC_u16ReadValueArr[1] * 100.0) / 4095.0);
//		MPWM_voidSetDutyCycle(TIMER4, 4, dutycycle2, 1);
//		if(dutycycle1 > 50)
//		{
//			LED_voidLedOn(GPIOC_ID, PIN14);
//		}
//		else
//		{
//			LED_voidLedOff(GPIOC_ID, PIN14);
//		}
	}
	return 0;
}





