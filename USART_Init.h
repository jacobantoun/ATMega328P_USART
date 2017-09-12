//#ifndef USART_Init
//#define USART_Init
#include <avr/io.h>

void USART_Init(unsigned int ubrr) {
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)(ubrr);
	UCSR0B = (1 << RXEN0)|(1 << TXEN0);
	UCSR0C = (1 << UCSZ00)|(1 << UCSZ01);
}

void USART_Transmit_char (unsigned char data) {
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void USART_putstring(char* StringPtr) {
	while(*StringPtr != 0x00){    //Here we check if there is still more chars to send, this is done checking the actual char and see if it is different from the null char
		USART_Transmit_char(*StringPtr);    //Using the simple send function we send one char at a time
	StringPtr++;}        //We increment the pointer so we can read the next char
}

void USART_Receive(void) {
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}


//#endif
