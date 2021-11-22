#ifndef LCD_H
#define	LCD_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "UBMP4.h"
#include "PIC16F1459config.h"
#include "stdbool.h"

// Good

#define LCD_RS    H5OUT
#define LCD_RW    H6OUT
#define LCD_E     H7OUT

#define LCD_BUSY  H7IN
#define LCD_BTRIS TRISCbits.TRISC6

#define LCD_DB4   H1OUT
#define LCD_DB5   H2OUT
#define LCD_DB6   H3OUT
#define LCD_DB7   H4OUT

// Probably not good but its ok
#define LCD_TRIS4 TRISCbits.TRISC0
#define LCD_TRIS5 TRISCbits.TRISC1
#define LCD_TRIS6 TRISCbits.TRISC2
#define LCD_TRIS7 TRISCbits.TRISC3

// Good
#define LCD_RW_WRITE 0
#define LCD_RW_READ  1

#define LCD_RS_INSTRUCTION  0
#define LCD_RS_DATA         1

// Good
#define LCD_CLEAR_DISPLAY       0b00000001

#define LCD_RETURN_HOME         0b00000010

#define LCD_FUNCTION_SET        0b00100000
#define LCD_DL_8BIT             0b00010000
#define LCD_DL_4BIT             0b00000000
#define LCD_N_2LINE             0b00001000
#define LCD_N_1LINE             0b00000000
#define LCD_F_5x10              0b00000100
#define LCD_F_5x8               0b00000000

#define LCD_DISPLAY_CONTROL     0b00001000
#define LCD_DISPLAY_OFF         0b00000000
#define LCD_DISPLAY_ON          0b00000100
#define LCD_CURSOR_OFF          0b00000000
#define LCD_CURSOR_ON           0b00000010
#define LCD_BLINKING_OFF        0b00000000
#define LCD_BLINKING_ON         0b00000001

#define LCD_ENTRY_MODE_SET      0b00000100
#define LCD_INCREMENT           0b00000010
#define LCD_DECREMENT           0b00000000
#define LCD_EM_DISPLAY_SHIFT    0b00000001
#define LCD_EM_CURSOR_MOVE      0b00000000

#define LCD_SHIFT               0b00010000
#define LCD_S_DISPLAY_SHIFT     0b00001000
#define LCD_S_CURSOR_MOVE       0b00000000
#define LCD_SHIFT_RIGHT         0b00000100
#define LCD_SHIFT_LEFT          0b00000000

#define LCD_SET_CGRAM_ADDRESS   0b01000000

#define LCD_SET_DDRAM_ADDRESS   0b10000000


#define __lcd_delay() __delay_us(500)



void WriteCharacter(char character);
void SendInstruction(char instruction);

void AwaitUnbusy(void);

// Advanced interface functionality

char ReadByte(void);
char ReadNybble(void);

void SendNybble(char nybble);
void SendByte(char nybble);

void SetTris(bool enabled);



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

