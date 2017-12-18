#include<avr/io.h>

#define PORT_ON(port, pin) port |= (1<<pin);
#define PORT_OFF(port, pin) port &= ~(1<<pin);

int main()
{
	unsigned int adc_value;

	DDRD = 0xFF;

	PORTD = 0x00;

	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS0);

	ADMUX = 0x05;

	while(1)
	{
		ADCSRA = (1<<ADSC);

		while(ADCRSA & (1<<ADSC));
		
		adc_value = ADCW;

		if (adc_value > 512)
		{
			PORT_OFF(PORTD,7);
			PORT_ON(PORTD,6);
		}
		else
		{
			PORT_ON(PORTD,7);
			PORT_OFF(PORTD,6);
		}

	}
	return 0;
}	