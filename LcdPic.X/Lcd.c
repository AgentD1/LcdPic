#include <xc.h>

#include "Lcd.h"


void ClearDisplay() {
    SendByte(0b00000001);
}

void ReturnHome() {
    SendByte(0b00000010);
}

void EntryModeSet(bool increment, bool accompaniesDisplayShift) {
    SendByte(0b00000101 | increment << 1 | accompaniesDisplayShift);
}

void DisplayOnToggle


char ReadByte() {
    LCD_RW = LCD_RW_WRITE;
    
    char result = ReadNybble() << 4;
    result |= ReadNybble();
    
    return result;
}

char ReadNybble() {
    LCD_E = 1;
    __lcd_delay();
    char result = (LCD_DB7 << 3) | (LCD_DB6 << 2) | (LCD_DB5 << 1) | LCD_DB6;
    LCD_E = 0;
    __lcd_delay();
    return result;
}

void SendByte(char instruction) {
    SendNybble(instruction >> 4);
    SendNybble(instruction & 0b1111);
}

void SendNybble(char nybble) {
    LCD_RS = 0;
    LCD_RW = LCD_RW_READ;
    
    LCD_E = 1;
    
    LCD_DB4 = nybble & 0b0001;
    LCD_DB5 = nybble & 0b0010;
    LCD_DB6 = nybble & 0b0100;
    LCD_DB7 = nybble & 0b1000;
    
    __lcd_delay();
    
    LCD_E = 0;
    
    __lcd_delay();
}

void AwaitUnbusy() {
    LCD_RS = 0;
    LCD_RW = 1;
    
    LCD_TRIS4 = 1;
    LCD_TRIS5 = 1;
    LCD_TRIS6 = 1;
    LCD_TRIS7 = 1;
    
    while(LCD_BUSY);
}

