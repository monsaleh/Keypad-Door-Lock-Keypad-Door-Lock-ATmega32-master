#define  F_CPU 8000000ul
#include <avr/io.h>
#include "S-M.h"
#include <util/delay.h>
#define SetBit(reg,pos) reg|= 1<<pos
#define ClrBit(reg,pos) reg&=~(1<<pos)
#define ToggleBit(reg,pos) reg^= 1<<pos
#define DDR_SPI DDRB
#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK   7

void SPI_init(void)
{
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);

	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

unsigned char SPI_MasterTransmit(unsigned char cData)
{
	
	SPDR = cData;
	
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;

}
