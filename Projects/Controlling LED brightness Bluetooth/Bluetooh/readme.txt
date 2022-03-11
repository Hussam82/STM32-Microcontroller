This project uses 2 USARTs both are operated at 9600 baud rate:

==> USART1 is connected to the PC by using USB TO TTL converter
	By sending '5' it toggles the Green LED conneected at PC14
	Sending from the PC is done by using PuTTy terminal
	
	
==> USART2 is connected to the mobile by using Bluetooth module HC-05
	The value sent from the mobile thorugh the bluetooth controls the LED brightness
	by converting the number received to an integer to be the dutycycle to the PWM
	channel which is connected to the RED LED at B9(PWM CH4) by using TIMER4