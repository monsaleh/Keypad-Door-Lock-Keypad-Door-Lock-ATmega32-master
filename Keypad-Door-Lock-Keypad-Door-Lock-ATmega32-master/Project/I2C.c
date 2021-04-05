#include "I2C.h"
#include <avr/io.h>

void TWI_init()
{
	TWSR=0x00;
	TWBR=0x07;
	TWCR=(1<<TWEN);
}

void TWI_Start()
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR & (1<<TWINT))==0);
}

void TWI_Stop()
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

unsigned char TWI_GetStatus()
{
	unsigned char status;
	status = TWSR & 0xF8;
	return status;
}

void TWI_Write(unsigned char u8data)
{
	TWDR=u8data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT))==0);
}

unsigned char TWI_ReadACK()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while((TWCR & (1<<TWINT))==0);
	return TWDR;
}

unsigned char TWI_ReadNACK()
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT))==0);
	return TWDR;
}
