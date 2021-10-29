#ifndef LCD_H
#define	LCD_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "UBMP4.h"
#include "PIC16F1459config.h"
#include "stdbool.h"

#define LCD_RS    H5OUT
#define LCD_RW    H6OUT
#define LCD_E     H7OUT

#define LCD_BUSY  H7IN
#define LCD_BTRIS TRISCbits.TRISC6

#define LCD_DB4   H1OUT
#define LCD_DB5   H2OUT
#define LCD_DB6   H3OUT
#define LCD_DB7   H4OUT

#define LCD_TRIS4 TRISCbits.TRISC0
#define LCD_TRIS5 TRISCbits.TRISC1
#define LCD_TRIS6 TRISCbits.TRISC2
#define LCD_TRIS7 TRISCbits.TRISC3


#define LCD_RW_WRITE 0
#define LCD_RW_READ  1


#define __lcd_delay() __delay_us(500)

char ReadByte();

void SendByte(char instruction);

void AwaitUnbusy();


//void SetDisplay(char* topCharacters, char* bottomCharacters);
//void SetDisplay(char* topCharacters, char topLength, char* bottomCharacters, char bottomLength);



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

