/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Mar 13, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_private.h"


/* SPI IDs: SPI1
 * 			SPI2
 */

void MSPI_voidInit(SPI_Regs *SPIx);
void MSPI_voidSendReceiveSynch(SPI_Regs *SPIx, uint8 copy_u8SlavePort, uint8 copy_u8SlavePin, uint8 copy_u8DataToTransmit, uint8 *copy_u8DataToReceive);
void MSPI_voidSendReceiveAsynch(SPI_Regs *SPIx, uint8 copy_u8SlavePort, uint8 copy_u8SlavePin, uint8 copy_u8DataToTransmit, void (*copy_voidPtr)(uint8));



#endif /* SPI_INTERFACE_H_ */
