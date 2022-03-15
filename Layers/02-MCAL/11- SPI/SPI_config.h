/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Mar 13, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_



/*	Options: BR_CLK_2
 * 			 BR_CLK_4
 * 			 BR_CLK_8
 * 			 BR_CLK_16
 * 			 BR_CLK_32
 * 			 BR_CLK_64
 * 			 BR_CLK_128
 * 			 BR_CLK_256
 */
#define SPI_BAUD_RATE		BR_CLK_2

/* Options: LSB_FIRST
 * 			MSB_FIRST
 */
#define SPI_DATA_ORDER		MSB_FIRST

/* Options: MASTER
 * 			SLAVE
 */
#define SPI_MASTER_SLAVE	MASTER

/* Options: IDLE_LOW
 * 			IDLE_HIGH
 */
#define SPI_CLOCK_POLARITY	IDLE_LOW

/* Options: READ_FIRST
 * 			WRITE_FIRST
 */
#define SPI_CLOCK_PHASE		WRITE_FIRST




#endif /* SPI_CONFIG_H_ */
