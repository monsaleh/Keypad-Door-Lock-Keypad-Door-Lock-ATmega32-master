#define F_CPU 8000000ul
#include "SPIS.h"
#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>
#define SetBit(reg,pos) reg|= 1<<pos
#define ClrBit(reg,pos) reg&=~(1<<pos)
#define ToggleBit(reg,pos) reg^= 1<<pos
#define DDR_SPI DDRB
#define DD_MISO 6


void SPI_SlaveInit(void)
{
	DDR_SPI = (1<<DD_MISO);
	SPCR = (1<<SPE);

}
unsigned char SPI_SlaveReceive(void)
{
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
	
	
	