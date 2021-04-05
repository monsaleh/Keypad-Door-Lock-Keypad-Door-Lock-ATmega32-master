#ifndef INCFILE1_H_
#define INCFILE1_H_

void lCD_CLRSCR();
void LCD_GOTO_XY(unsigned char X,unsigned char Y);
void LCD_SENDSTR(char *PTR);
void LCD_INIT();
void LCD_SENDCMD(char CMD);
void LCD_SENDDATA(char DATA);
void LCD_PRINTNUM(int num);
void LCD_MOVE(char yt);
 
#endif 