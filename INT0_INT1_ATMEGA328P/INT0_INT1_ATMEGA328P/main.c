/*
 * INTERRUPCIONES_EXTERNAS.c
 *
 * Created: 25/04/2019 14:19:16
 * Author : CarlosQL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
	
	PORTC ^= (1<<0);		//cAMBIA DE ESTADO
}

ISR(INT1_vect, ISR_ALIASOF(INT0_vect));

int main(void)
{
	
	DDRC |= (1<<0);			//PC0 como salida
	PORTC &= ~(1<<0);		//PC0 inicia en 0
	
	DDRC |= (1<<1);			//PC0 como salida
	PORTC &= ~(1<<1);		//PC0 inicia en 0
	
	DDRD &= ~(1<<2);		//PD2 como entrada
	PORTD |= (1<< 2);		//PD2 con pull up
	
	DDRD &= ~(1<<3);		//PD2 como entrada
	PORTD |= (1<< 3);		//PD2 con pull up
	
	
	EICRA = 0b00001010;		//Interrupción externa por flanco de bajada en INT0
	EIMSK = 0b00000011;		//Habilita interrupción externa INT0
	EIFR = 0b00000000;		//SU BIT 0 A 0 PARA DETECTAR LAS INTERUPCIONES
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

