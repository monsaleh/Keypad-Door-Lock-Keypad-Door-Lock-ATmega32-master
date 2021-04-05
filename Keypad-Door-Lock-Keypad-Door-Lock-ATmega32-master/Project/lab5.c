#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

main(void)
{
	LCD_INIT();
	//LCD_PRINTNUM(12345);
	LCD_MOVE("hello");

    while(1)
    {
       
    }
}