#include <avr/io.h>
#define setbit(reg,pos) reg|=1<<pos
#define clrbit(reg,pos) reg&=~(1<<pos)
#define togglebit(reg,pos) reg^=1<<pos
#include "PWM-.h"

void pwm0_init()
{
	setbit(DDRB,3);
	setbit(DDRD,7);
	clrbit(PORTD,7);
	TCCR0=0b01100100;
}

void pwm2_init()
{
	setbit(DDRD,7);
	setbit(DDRD,3);
	clrbit(PORTD,3);
	TCCR2=0b01100110;
}

void pwm0_duty(unsigned char duty)
{
	OCR0=(duty*255)/100;
}

void pwm2_duty(unsigned char duty)
{
	OCR2=(duty*255)/100;
}
