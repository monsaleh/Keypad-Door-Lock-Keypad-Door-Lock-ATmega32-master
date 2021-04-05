#define SetBit(reg,pos) reg|=(1<<pos)
#define ClearBit(reg,pos) reg&=~(1<<pos)
#define ToggelBit(reg,pos) reg^=(1<<pos)
#include <avr/interrupt.h>
#define Freq 1000000
#define presc 256
#include "Tim.h"
int count;

void timer1_init()
{
	TIMSK|=0x10;
	TCCR1A=0x00;
	TCCR1B=0b00001100;
	sei();
}

void timer2_init()
{
	TIMSK|=0x80;
	TCCR2=0b00001110;
	sei();
}

ISR(TIMER1_COMPA_vect)
{
	ClearBit(TCCR0,5);
	ClearBit(PORTB,3);
}

ISR (TIMER2_COMP_vect)
{
	ToggelBit(PORTC,0);
}

void timer1_sec(unsigned char TM)
{
	count=(TM*Freq)/(presc);
	OCR1A=ceil(count);
}

void timer2_msec(unsigned char TM)
{
	count=(TM*Freq)/(presc*1000);
	OCR2 = ceil(count);
}
