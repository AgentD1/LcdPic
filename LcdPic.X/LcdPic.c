/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    May 16, 2021
 
 This example UBMP4 input and output program demonstrates pushbutton input, LED
 (bit) output, port latch (byte) output, time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

#include    "Lcd.h"
#include    "notes.h"


void lcdInit(void);

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is required, and the program begins executing from here.

const char topText[] = { 0b00010000, ' ', ' ', 'P', 'i', 'c', 'k', ' ', 'a', ' ', 's', 'o', 'n', 'g', ' ', 0b00010001 };

const char songNames[2][16] = {
    "Among us drip",
    "Megalovania"
};



int main(void) {
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    lcdInit();
    
    WriteCharacter('x');
    
    // Code in this while loop runs repeatedly.
    while(1) {
        WriteCharacter('x');
           
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0) {
            RESET();
        }
    }
}

void lcdInit() {
    TRISC = 0b00000000; 
    __delay_ms(20);
    SendNybble(0x03);
    __delay_ms(5);
    SendNybble(0x03);
    __delay_ms(5);
    SendNybble(0x03);
    __delay_ms(5);
    SendNybble(0x02);
    __lcd_delay();
    SendInstruction(LCD_FUNCTION_SET | LCD_DL_4BIT | LCD_N_2LINE | LCD_F_5x8);
    __lcd_delay();
    SendInstruction(LCD_DISPLAY_CONTROL | LCD_DISPLAY_OFF | LCD_CURSOR_OFF | LCD_BLINKING_OFF);
    __lcd_delay();
    SendInstruction(LCD_CLEAR_DISPLAY);
    __lcd_delay();
    SendInstruction(LCD_ENTRY_MODE_SET | LCD_INCREMENT | LCD_EM_CURSOR_MOVE);
    __delay_ms(500);
    SendInstruction(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINKING_OFF);
}
