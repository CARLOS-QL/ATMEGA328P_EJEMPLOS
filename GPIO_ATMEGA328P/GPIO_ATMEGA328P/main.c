/*
 * GPIO_ATMEGA328P.c
 *
 * Created: 11/08/2018 14:25:05
 * Author : Carlos QL
 */ 

#define F_CPU 16000000
#include <avr/io.h>


int main(void)
{
	DDRB &= ~(1<<2);		//PB2 in
	PORTB |= (1<<PB2);		//pull up on
	
	DDRC |= (1<<3);			//PC3 out
	PORTC &= ~(1<<PC3);		//LOW

	
    /* Replace with your application code */
    while (1) 
    {
		if((PINB&(1<<2)) == 0)
		{
			PORTC |= (1<<PC3);		//alto
		}
		else
		{
			PORTC &= ~(1<<PC3);		//bajo
		}
    }
}
