#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>
#define SetBit(reg,pos) reg|=(1<<pos)
#define ClearBit(reg,pos) reg&=~(1<<pos)
#define ToggelBit(reg,pos) reg^=(1<<pos)

#define LCD_DATA_DIR  DDRA
#define LCD_DATA_PORT  PORTA
#define LCD_CTRL_DIR    DDRB
#define LCD_CTLR_PORT   PORTB
#define  Rs 0
#define  E  1

void lCD_CLRSCR()
{
	LCD_SENDCMD(0x01);
}

void LCD_GOTO_XY(unsigned char X,unsigned char Y)
{
	if (Y==0)
	{
		LCD_SENDCMD(0X80+X);
		
	}
	else
	{
		LCD_SENDCMD(0XC0+X);
	}
}

void LCD_MOVE(char phr)
{
	LCD_SENDSTR(phr);
	LCD_SENDCMD(0x1C);
	_delay_ms(500);
}

void LCD_SENDSTR(char *PTR)
{
	int i=0;
	while(PTR[i]!=0)
	{
		LCD_SENDDATA(PTR[i]);
		i++;
	}
}

void LCD_INIT()
{
	LCD_DATA_DIR=0xff;
	SetBit(LCD_CTRL_DIR,Rs);
	SetBit(LCD_CTRL_DIR,E);
	ClearBit(LCD_CTLR_PORT,1);
	LCD_SENDCMD(0X38);
	LCD_SENDCMD(0X0C);
}

void LCD_SENDCMD(char CMD)
{
	LCD_DATA_PORT=CMD;
	ClearBit(LCD_CTLR_PORT,Rs);
	SetBit(LCD_CTLR_PORT,E);
	_delay_ms(10);
	ClearBit(LCD_CTLR_PORT,E);
}

void LCD_SENDDATA(char DATA)
{
	LCD_DATA_PORT=DATA;
	SetBit(LCD_CTLR_PORT,Rs);
	SetBit(LCD_CTLR_PORT,E);
	_delay_ms(10);
	ClearBit(LCD_CTLR_PORT,E);
}

void LCD_PRINTNUM(int num)
{
	int i,count=0,temp;
	temp=num;
	
	while(temp!=0)
	{
		temp/=10;
		count++;
	}
	
	while(count!=0)
	{
		LCD_GOTO_XY(count+10,0);
		i=num%10;
		LCD_SENDDATA(i+'0');
		_delay_ms(100);
		num/=10;
		count--;
	}
}