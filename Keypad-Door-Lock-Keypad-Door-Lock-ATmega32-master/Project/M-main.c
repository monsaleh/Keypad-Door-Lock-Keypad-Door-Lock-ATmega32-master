/*
 * main.c
 *
 * Created: 3/28/2016 3:57:35 PM
 *  Author: AaDawood
 */ 

#define  F_CPU 8000000ul
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#define SetBit(reg,pos) reg|= 1<<pos
#define ClrBit(reg,pos) reg&=~(1<<pos)
#define ToggleBit(reg,pos) reg^= 1<<pos
#define DDR_SPI DDRB
#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK   7

int main ()
{
	SPI_MasterInit();
	//char x=0;
	while(1)
	{
	//	for(x=0;x<10;x++)
		//{
			
			SPI_MasterTransmit(9);
			_delay_ms(1000);
			
			/*if(x==10)
			{
				x=0;
			}
		}*/
	}
}