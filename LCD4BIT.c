#define F_CPU 16000000UL 
#include "LCD4BIT.h"
#include "DIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <util/delay.h>

void LCD4_EN(){
    LCD_CONTROL |= (1<<EN);
    _delay_us(50);
    LCD_CONTROL &= ~(1<<EN);
    _delay_ms(20);
}

void LCD4_COMMAND(char command){
    //SET RS TO 0
    LCD_CONTROL &= ~(1<<RS);
    LCD_PORT = (LCD_PORT & 0X0F) | (command & 0XF0);
    _delay_ms(20);
    LCD_PORT = (LCD_PORT & 0X0F) | (command <<4);
    LCD_EN();
    
}
void LCD4_DATA(char data){
    LCD_CONTROL |= (1<<RS);
    LCD_PORT = (LCD_PORT & 0X0F) | (data & 0XF0);
    _delay_ms(20);
    LCD_PORT = (LCD_PORT & 0X0F) | (data <<4);
    LCD_EN();
}
void init_LCD4(){
    // DIO
    setPORTC_DIR_VAL(0XF0, OUT);
    setPIND_DIR(RS, OUT);
    setPIND_DIR(RW, OUT);
    setPIND_DIR(EN, OUT);
    //LCD SETUP
    setPIND(RS, LOW);
    //RETURN HOME
    LCD_COMMAND(RETURN_HOME);
    //SET MODE
    LCD_COMMAND(MODE_4BITS);
    //CURSOR SET &DISPLAY MODE
    LCD_COMMAND(CURSOR_OFF_DISPLAY_ON);
    //CLEAR
    LCD_COMMAND(CLEAR);
}
void LCD4_DATA_STR(char* str){
    int i = 0;
    while(str[i]){
        LCD_DATA(str[i]);
        i++;
    }
}
void LCD4_DATA_NUMi(int num){
    char str[11];
    itoa(num, str, 10);
    LCD_DATA_STR(str);
    
}
void LCD4_CLEAR4(){
    LCD_CONTROL &= ~(1<<RS);
    LCD_PORT = (LCD_PORT & 0X0F) | (CLEAR & 0XF0);
    _delay_ms(20);
    LCD_PORT = (LCD_PORT & 0X0F) | (CLEAR <<4);
    LCD_EN();
}
