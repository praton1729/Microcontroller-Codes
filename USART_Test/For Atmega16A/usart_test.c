
/*

Hardware:
   ATmega8 @ 16MHz

   Suitable level converter on RX/TX line
   Connected to PC via RS232
   PC Software :  Hyper terminal @ 19200 baud
               No Parity,1 Stop Bit,
               Flow Control = NONE

*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <inttypes.h>
#include<util/delay.h>
    
void USARTInit(uint16_t ubrr_value)
{

   //Set Baud rate

   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit

   >> char size 8

   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter

   UCSRB=(1<<RXEN)|(1<<TXEN);


}


//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
char USARTReadChar()
{
   //Wait untill a data is available

   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}


//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteChar(char data)
{
   //Wait untill the transmitter is ready

   while(!(UCSRA & (1<<UDRE)))
   {
      //Do nothing
   }

   //Now write the data to USART buffer

   UDR=data;
}

void main()
{
   //This DEMO program will demonstrate the use of simple

   //function for using the USART for data communication

   //Variable Declaration
   char data;
   char i = 30;
   /*First Initialize the USART with baud rate = 19200bps
   
   for Baud rate = 19200bps

   UBRR value = 51

   */
   DDRD |= 0x02;
   
   USARTInit(51);    //UBRR = 51

   //Loop forever
    DDRB = 0xFF;
    
   while(1)
   {
    
        PORTB |= (1<<0);
        _delay_ms(100);
        PORTB &= ~(1<<0);
        _delay_ms(100);
        
      //Read data
      //data=USARTReadChar();
        data = i;
        
      /* Now send the same data but but surround it in
      square bracket. For example if user sent 'a' our
      system will echo back '[a]'.

      */

      //USARTWriteChar('[');
      USARTWriteChar(data);
      //USARTWriteChar(']');
      i++;
      i = i% 100;
   }
}
