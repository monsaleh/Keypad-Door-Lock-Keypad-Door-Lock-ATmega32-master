#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	char x;
	keypad_init();
	LCD_INIT();
	
	while(1)
	{
		x=keypad_scan();
		
		if (x!=0)
		{
			LCD_SENDDATA(x);
		}
	}
}