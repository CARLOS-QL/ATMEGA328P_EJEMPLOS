/*
 * usart_avr.c
 *
 * Created: 11/08/2018 17:24:40
 * Author : CarlosQL
 */ 

#define F_CPU 16000000
#define BAUD 9600
#include <util/setbaud.h>
#include <stdio.h>

#include <string.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "UART.h"

//led1=on*
//led1=off*

char RxBuffer[15];
volatile unsigned char RxContador =0;

ISR(USART_RX_vect){
	
	char dato = UDR0;
	
	if(dato == '*'){
		
		RxBuffer[RxContador] = '\0';
		RxContador = 0;
		
		if(strstr(RxBuffer, "led1=on")){
			
			PORTB |= (1<<5);
			printf("led1 encendido\n\r");
		}else if(strstr(RxBuffer, "led1=off")){
			PORTB &= ~(1<<5);
			printf("led1 apagado\n\r");
		}
		
	}else{
		RxBuffer[RxContador++] = dato;
	}
	
}

int main(void)
{
	cli();
	DDRB |= (1<<5);
	PORTB &= (1<<5);
	
	UART_init();
	
	sei();
	
	float pi = 3.1416;
	printf("este es un mensjae %.4f\n\r", pi);
	
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

