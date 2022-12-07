/*
 * GRADUATION_PROJECT.c
 *
 * Created: 04/12/2022 02:34:22 AM
 * Author : Team          
 */ 

#define F_CPU 16000000UL
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "UART_int.h"
#include "Timer1_int.h"
#include "Timer1_priv.h"
#include "Timer_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "FUNCTIONS.h"
#include "GIE_int.h"

f64 Distance_1 , Distance_2 ;

int main(void)
{
	DIO_voidInit();
	TIMER0_void_Init();
	TIMER1_voidOvInt();  // Enable Timer1 overflow interrupts
	UART_voidInit();
	GIE_voidEnable();   // Enable global interrupt
	
	u8 resieve ;
	resieve = UART_u8ReceiveByte();
	
	
	while(1)
	{
		if (resieve == 'a' )
		{
			DIO_voidSetPinValue(DIO_U8_PIN15,HIGH);
			GO_FORWARD();
			
			Distance_1 = ULTRASONIC_f64Distance();
			_delay_ms(500);
			Distance_2 = ULTRASONIC_f64Distance();
			
			if( (Distance_1 < 25.0000 ) && ( Distance_2 < 25.0000) )
			{
				STOP();
				CHECK();
			}
		}
	}
}


