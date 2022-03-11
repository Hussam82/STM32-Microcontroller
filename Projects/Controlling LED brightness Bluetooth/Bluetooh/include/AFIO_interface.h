/**************************************************************
 *******	Author			: 		Hussam Ali	 		*******
 ******* 	Version			: 		V1.0				*******
 ******* 	Date			:		Feb 20, 2022		*******
 ******* 	Description		:							*******
 **************************************************************/
#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

#define AFIO_PORT_MAP_A			0b0000
#define AFIO_PORT_MAP_B			0b0001
#define AFIO_PORT_MAP_C			0b0010

/* Line ID */
#define AFIO_LINE0	0
#define AFIO_LINE1	1
#define AFIO_LINE2	2
#define AFIO_LINE3	3
#define AFIO_LINE4	4
#define AFIO_LINE5	5
#define AFIO_LINE6	6
#define AFIO_LINE7	7
#define AFIO_LINE8	8
#define AFIO_LINE9	9
#define AFIO_LINE10	10
#define AFIO_LINE11	11
#define AFIO_LINE12	12
#define AFIO_LINE13	13
#define AFIO_LINE14	14
#define AFIO_LINE15	15


void MAFIO_voidSetEXTI(uint8 copy_u8Line, uint8 copy_u8PortMap);

#endif /* AFIO_INTERFACE_H_ */
