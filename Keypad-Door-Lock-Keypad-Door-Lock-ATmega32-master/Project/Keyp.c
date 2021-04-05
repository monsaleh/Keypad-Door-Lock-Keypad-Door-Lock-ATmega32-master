#include <avr/io.h>
#include <util/delay.h>
#define SetBit(reg,pos) reg|=(1<<pos)
#define ClearBit(reg,pos) reg&=~(1<<pos)
#define ToggelBit(reg,pos) reg^=(1<<pos)

void keypad_init()
{
	DDRC=0xf0;
	PORTC=0xff;
	
}

char keypad_scan()
{
	char row,col;
	for(row=4;row<8;row++)
	{
		PORTC=0xff;
		ClearBit(PORTC,row);
		col=PINC&0x0f;
		if (col!=0x0f)
		{
			while((PINC&0x0f)!=0x0f);
			break;
		}
	}
	if (row==8)
	{
		return 0;
	}
	
	switch (row)
	{
		case 4: switch(col)
		{
			case 0x0e:
			return '1';
			case 0x0d:
			return '2';
			case 0x0b:
			return '3';
			
		}
		case 5: switch(col)
		{
			case 0x0e:
			return '4';
			case 0x0d:
			return'5';
			case 0x0b:
			return '6';
			
		}
		case 6: switch(col)
		{
			case 0x0e:
			return '7';
			case 0x0d:
			return '8';
			case 0x0b:
			return '9';
			
		}
		case 7: switch(col)
		{
			case 0x0e:
			return '*';
			case 0x0d:
			return '0';
			case 0x0b:
			return '#';
			
		}
	}
	
}
