#include <xc.h>

#include "Lcd.h"

char ReadByte() {
    SetTris(1);
    LCD_RW = LCD_RW_READ;
    
    char result = (unsigned char)(ReadNybble() << 4);
    result |= ReadNybble();
    
    return result;
}

char ReadNybble() {
    SetTris(1);
    LCD_E = 1;
    __lcd_delay();
    char result = (unsigned char)((LCD_DB7 << 3) | (LCD_DB6 << 2) | (LCD_DB5 << 1) | LCD_DB6);
    LCD_E = 0;
    __lcd_delay();
    return result;
}

void SendNybble(char nybble) {
    SetTris(0);
    LCD_RW = LCD_RW_WRITE;
    
    
    LCD_DB4 = nybble & 0b0001;
    LCD_DB5 = (nybble & 0b0010) >> 1;
    LCD_DB6 = (nybble & 0b0100) >> 2;
    LCD_DB7 = (nybble & 0b1000) >> 3;
    
    LCD_E = 1;
    
    __lcd_delay();
    
    LCD_E = 0;
    
    __lcd_delay();
}

void SendByte(char byte) {
    SendNybble(byte >> 4);
    SendNybble(byte & 0b1111);
}

void SendInstruction(char instruction) {
    LCD_RS = LCD_RS_INSTRUCTION;
    SendByte(instruction);
}

void WriteCharacter(char character) {
    LCD_RS = LCD_RS_DATA;
    SendByte(character);
}

char ReadCharacter(char address) {
    SendInstruction(LCD_SET_DDRAM_ADDRESS | (address & ~LCD_SET_DDRAM_ADDRESS));
    LCD_RS = LCD_RS_DATA;
    return ReadByte();
}

void SetTris(bool enabled) {
    LCD_TRIS4 = enabled;
    LCD_TRIS5 = enabled;
    LCD_TRIS6 = enabled;
    LCD_TRIS7 = enabled;
}

void AwaitUnbusy() {
    SetTris(1);
    LCD_RW = 1;
    LCD_RS = 0;
    
    while(LCD_BUSY) {
        LCD_E = !LCD_E;
        __lcd_delay();
    }
    
    LCD_E = 0;
}
