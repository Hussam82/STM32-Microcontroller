/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Mar 13, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS	0x40013000
#define SPI2_BASE_ADDRESS	0x40003800


/* SPI Baud Rate */
#define BR_CLK_2		0b000
#define BR_CLK_4		0b001
#define BR_CLK_8		0b010
#define BR_CLK_16		0b011
#define BR_CLK_32		0b100
#define BR_CLK_64		0b101
#define BR_CLK_128		0b110
#define BR_CLK_256		0b111

/* SPI Data Order */
#define MSB_FIRST			0
#define LSB_FIRST			1

/* SPI Master or Slave */
#define SLAVE			0
#define MASTER			1

/* SPI Clock Polarity */
#define IDLE_LOW		0
#define IDLE_HIGH		1

/* SPI Clock Phase */
#define READ_FIRST		0
#define WRITE_FIRST		1


typedef struct{
	volatile uint32	CR1;
	volatile uint32	CR2;
	volatile uint32	SR;
	volatile uint32	DR;
	volatile uint32	CRCPR;
	volatile uint32	RXCRCR;
	volatile uint32	TXCRCR;
	volatile uint32	I2SCFGR;
	volatile uint32	I2SPR;
}SPI_Regs;
#define SPI1 ((SPI_Regs*)SPI1_BASE_ADDRESS)
#define SPI2 ((SPI_Regs*)SPI2_BASE_ADDRESS)


#endif /* SPI_PRIVATE_H_ */
