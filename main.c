#include <avr/io.h>
#include <util/delay.h>
#include <USART_Init.h>

#define F_CPU 1000000
#define FOSC 1000000
#define BAUD 4800
#define MYUBRR FOSC/16/BAUD-1

char chararray[] = "I wonder how long I can make this array? What special characters work?? !@#$%^&*()_-+=~";

int main (void)
{
	USART_Init(MYUBRR);
	//Init_USART(MYUBRR);
	while(1) {
		USART_putstring(chararray);	
		_delay_ms(1000);
		USART_Transmit_char('\n');
		USART_Transmit_char('\r');
	}
}
