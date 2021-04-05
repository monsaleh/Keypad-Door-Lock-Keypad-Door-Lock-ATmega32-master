/*
 * SPIM.h
 *
 * Created: 3/28/2016 3:57:45 PM
 *  Author: AaDawood
 */ 


#ifndef SPIM_H_
#define SPIM_H_

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

void SPI_MasterInit(void);
void SPI_MasterTransmit(unsigned char cData);



#endif /* SPIM_H_ */