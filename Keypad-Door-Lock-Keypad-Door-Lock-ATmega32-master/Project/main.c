#include "EEPROM.h"
#include "I2C.h"

int main(void)

{
 TWI_init();
 DDRA=0xFF;
 char received ;

 while(1)
 {
 EEPROM_Write(0x03,0x400) ;
 _delay_ms(1000);
 received=EEPROM_Read(0x400);
 PORTA=received; 
 }
 }
