#ifndef I2C_H
#define I2C_H

void TWI_init();
void TWI_Start();
void TWI_Stop();
unsigned char TWI_GetStatus();
void TWI_Write(unsigned char u8data);
unsigned char TWI_ReadACK();
unsigned char TWI_ReadNACK();







#endif
