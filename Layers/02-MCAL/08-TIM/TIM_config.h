/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 25, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef TIM_CONFIG_H_
#define TIM_CONFIG_H_




/* Options:	EDGE_ALLIGNED_MODE
 * 			CENTER_ALIGNED_MODE_1
 * 			CENTER_ALIGNED_MODE_2
 * 			CENTER_ALIGNED_MODE_3 */
#define TIM_MODE		EDGE_ALIGNED_MODE

/* Choose from 128 To 655535 */
#define TIM_PRESCALER	512


/* Options : UP_COUNT
 * 			 DOWN_COUNT */
#define TIM_DIRECTION	UP_COUNT



#endif /* TIM_CONFIG_H_ */
