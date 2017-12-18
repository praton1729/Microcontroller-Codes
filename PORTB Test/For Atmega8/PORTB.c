#include<avr/io.h>

#define  F_CPU 8000000UL

#include<util/delay.h>

int main(){

	DDRB = 0xFF;
	
	PORTB = 0xFF;

	while(1){

		PORTB |= 1;
		_delay_ms(100);
		PORTB &= ~(1<<0);
		_delay_ms(100);
	}

	return 0;
}
