#include <avr/io.h>
#include <util/delay.h>
#define SetBit(reg,pos) reg|=(1<<pos)
#define ClearBit(reg,pos) reg&=~(1<<pos)
#define ToggelBit(reg,pos) reg^=(1<<pos)
#define F_CPU 8000000ul
#include "lcd.h"
#include "Keyp.h"
#include "PWM-.h"
#include "S-M.h"
#define DDR_SPI DDRB
#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK   7

int main(void)
{
	SPI_init();
	LCD_INIT();
	
	keypad_init();
	LCD_GOTO_XY(0,0);
	unsigned char f=0;
	char pass[]=" Enter Password:";
	char correct[]=" Correct Password";
	char wrong[]=" Wrong Password";
	char op[]="*-->Open The Door";
	char ch[]="#-->Change Password";
	char m1[]="Door OPening";
	char m2[]="Door Closing";
	
	
	
	//lcd intro
	 while(op[f]!='\0')
	 {
		 LCD_SENDDATA(op[f]);
		 f++;
		 _delay_ms(500);
	 }
	
	LCD_GOTO_XY(0,1);
	f=0;
	
	////lcd intro
	while(ch[f]!='\0')
	{
		LCD_SENDDATA(ch[f]);
		f++;
		_delay_ms(500);
	}
	
	unsigned char x,count=0,pass_set[]="123",status=0,choose,i=0,flag=1,k=0,w=0,a=0,v=0,m,c=0;
	
    while(1)
    {
		choose=keypad_scan();
	
		//if you choose to open the door
		if (choose=='*')
		{
			_delay_ms(500);
			lCD_CLRSCR();
			status=1;
		}			
	
	   while(status==1)      
	   {
		   while(count<3)
		    {
			 LCD_GOTO_XY(0,0);
			 
			 while(pass[k]!='\0')                         //ask about pass
			 {
				 LCD_SENDDATA(pass[k]);
				 k++;
				 _delay_ms(500);
			 }
			 
			 LCD_GOTO_XY(count,1);
			 x=keypad_scan();
			                            //sending data to lcd and make array of entered pass
			 if(x!=0)
			    {
				LCD_SENDDATA('*');
				_delay_ms(200);
				
				SPI_MasterTransmit(x);
				_delay_ms(500);
				count++;
	         	}
				 	     
		        }	
			count=0;
			status=2;	
				}	
				
	if(status==2)
	{
		_delay_ms(5000);
		m= SPI_MasterTransmit(0xff);
		//LCD_SENDDATA(m);
		_delay_ms(2000);
		if(m==1)
		{
			_delay_ms(1000);
			lCD_CLRSCR();
			
			while(correct[v]!='\0')                              //pass is correct
			{
				LCD_SENDDATA(correct[v]);
				v++;
				_delay_ms(500);
			}
			
			_delay_ms(2000);
			
			LCD_GOTO_XY(1,1);
			
			while(m1[a]!='\0')                                   //opening the door sign
			{
				LCD_SENDDATA(m1[a]);
				a++;
				_delay_ms(500);
			}
			pwm0_init();
			pwm0_duty(50);                                  //motor anti clockwise
			_delay_ms(30000);
			TCCR0=0;
			
			pwm2_init();
			pwm2_duty(50);                                   //motor clockwise
			_delay_ms(5000);
			LCD_GOTO_XY(1,1);
			
			while(m2[w]!='\0')                                //closing the door sign
			{
				LCD_SENDDATA(m2[w]);
				w++;
				_delay_ms(500);
			}
			
			_delay_ms(15000);
			TCCR2=0;
		}
		
		//if the pass is wrong at all
		else
		{
			_delay_ms(1000);
			lCD_CLRSCR();
			k=0;
			while(wrong[k]!='\0')
			{
				LCD_SENDDATA(wrong[k]);                           //wrong pass
				k++;
				_delay_ms(1000);
			}
			
			_delay_ms(10000);
			k=0;
			
			status=1;
		}
		lCD_CLRSCR();
		
	}			
		
    }//while(1)
	
}	//main
