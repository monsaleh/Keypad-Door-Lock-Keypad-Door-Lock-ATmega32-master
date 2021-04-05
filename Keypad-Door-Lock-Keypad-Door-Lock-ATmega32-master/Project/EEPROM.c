#include "EEPROM.h"
#include <avr/io.h>

unsigned char EEPROM_Write(unsigned char data ,unsigned short address)
{
	TWI_Start();
	if(TWI_GetStatus()!=0x08)
	{
		return 0;
	}
	TWI_Write(((address&0x0700)>>7)|(0xA0));
	if((TWI_GetStatus()!=0x18))
	{
		return 0;
	}
	TWI_Write((unsigned char)address);
	if((TWI_GetStatus()!=0x28))
	{
		return 0;
	}
	TWI_Write(data);
	if((TWI_GetStatus()!=0x28))
	{
		return 0;
	}
	TWI_Stop();
}

unsigned char EEPROM_Read(unsigned short address)
{
	char x;
	TWI_Start();
	if(TWI_GetStatus()!=0x08)
	{
		return 0;
	}
	TWI_Write(((address&0x0700)>>7)|(0xA0));
	if((TWI_GetStatus()!=0x18))
	{
		return 0;
	}
	TWI_Write((unsigned char)address);
	if((TWI_GetStatus()!=0x28))
	{
		return 0;
	}
	TWI_Start();
	if((TWI_GetStatus()!=0x10))
	{
		return 0;
	}
	TWI_Write(((address&0x0700)>>7)|(0xA0)|0x01);
	if((TWI_GetStatus()!=0x40))
	{
		return 0;
	}

	x=TWI_ReadNACK();
	if((TWI_GetStatus()!=0x58))
	{
		return 0;
	} 

	TWI_Stop();

	return x;

}


