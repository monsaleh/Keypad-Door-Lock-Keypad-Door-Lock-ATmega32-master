
#define F_CPU 8000000ul
#include "SPIS.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000ul
#define SetBit(reg,pos) reg|= 1<<pos
#define ClrBit(reg,pos) reg&=~(1<<pos)
#define ToggleBit(reg,pos) reg^= 1<<pos
#define DDR_SPI DDRB
#define DD_MOSI 5
#define DD_MISO 6
#define DD_SS   7
volatile unsigned char pass_ent[3];
int main ()
{
	_delay_ms(150);
	SPI_SlaveInit();
    LCD_INIT();
	
	while(1)
	{
		for(int i=0;i<3;i++)
		{
			pass_ent[i]=SPI_SlaveReceive();
			_delay_ms(1000);
		
		}
		
}