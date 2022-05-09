/*
 * EJEMPLO_LIB.c
 *
 * Created: 8/05/2022 17:49:11
 * Author : carlo
 */ 

#include <avr/io.h>
#include "PWM0/PWM0.h"
#include "ADC/ADC.h"


int main(void)
{
  
   DDRD = 0XFF;
   PWM0_init();
   ADC_init();
   
  
   PWM0_dcb(10, INVERTING);
    while (1) 
    {
		float adc = ADC_read(1);
		adc = (adc * 100)/1023;
		PWM0_dca((uint8_t)adc, NO_INVERTING);
    }
}

