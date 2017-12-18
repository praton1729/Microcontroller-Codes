#include<avr/io.h>

#define  F_CPU 8000000UL

#include<util/delay.h>

int main(){

	DDRC = 0xFF;
	
	PORTC = 0xFF;

	while(1){

		PORTC |= 1;
		_delay_ms(100);
		PORTC &= ~(1<<0);
		_delay_ms(100);
	}

	return 0;
}
