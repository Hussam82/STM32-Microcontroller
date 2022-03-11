/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 16, 2022				*******
 ******* 	Description		:					*******
 **************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define		NVIC_BASE_ADDRESS		0xE000E100
//#define		SCB_BASE_ADDRESS		0xE000ED00


#define		NVIC_ISER0				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x000))	 	/* Enable external interrupts from 0 to 31 */
#define		NVIC_ISER1				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x004))	 	/* Enable external interrupts from 32 to 63 */

#define		NVIC_ICER0				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x080))	 	/* Disable external interrupts from 0 to 31 */
#define		NVIC_ICER1				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x084))	 	/* Disable external interrupts from 32 to 63 */

#define		NVIC_ISPR0				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x100))	 	/* Set the pending flag of external interrupts from 0 to 31 */
#define		NVIC_ISPR1				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x104))	 	/* Set the pending flag of external interrupts from 32 to 63 */

#define		NVIC_ICPR0				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x180))	 	/* Clear the pending flag of external interrupts from 0 to 31 */
#define		NVIC_ICPR1				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x184))	 	/* Clear the pending flag of external interrupts from 32 to 63 */

#define		NVIC_IABR0				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x200))	 	/* Clear the pending flag of external interrupts from 0 to 31 */
#define		NVIC_IABR1				*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x204))	 	/* Clear the pending flag of external interrupts from 0 to 31 */

#define		NVIC_IPR				 ((volatile uint8*)(NVIC_BASE_ADDRESS + 0x300))	 		/* Interrupt Priority Register, used as an array
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   to access IPRx */
//#define 	SCB_AIRCR				*((volatile uint32*)(SCB_BASE_ADDRESS + 0x0C))

#define		NVIC_GROUP_4_SUB_0		0x05FA0300		/* 4 bits for Group and 0 bits for sub group */
#define		NVIC_GROUP_3_SUB_1		0x05FA0400		/* 3 bits for Group and 1 bits for sub group */
#define		NVIC_GROUP_2_SUB_2		0x05FA0500		/* 2 bits for Group and 2 bits for sub group */
#define		NVIC_GROUP_1_SUB_3		0x05FA0600		/* 1 bits for Group and 3 bits for sub group */
#define		NVIC_GROUP_0_SUB_4		0x05FA0700		/* 0 bits for Group and 4 bits for sub group */

#endif /* NVIC_PRIVATE_H_ */
