
#include "LCD.h"
#include "DIO.h"
#include <stdlib.h>
#include <util/delay.h>
#include <stdbool.h>
#define F_CPU 16000000UL 

void itoa(int value, char* str, int base) {
    char *ptr = str, *ptr1 = str, tmp_char;
    int tmp_value;

    // Handle 0 explicitly, otherwise empty string is printed for 0
    if (value == 0) {
        *str++ = '0';
        *str = '\0';
        return;
    }

    // Negative number handling for base 10
    bool isNegative = false;
    if (value < 0 && base == 10) {
        isNegative = true;
        value = -value;
    }

    // Process individual digits
    while (value != 0) {
        tmp_value = value % base;
        *str++ = (tmp_value < 10) ? (tmp_value + '0') : (tmp_value - 10 + 'A');
        value /= base;
    }

    // Append minus sign for negative numbers
    if (isNegative) {
        *str++ = '-';
    }

    // Null-terminate string
    *str = '\0';

    // Reverse the string
    while (ptr1 < str - 1) {
        tmp_char = *ptr1;
        *ptr1++ = *--str;
        *str = tmp_char;
    }
}


void LCD_EN(){
    LCD_CONTROL |= (1<<EN);
    _delay_us(50);
    LCD_CONTROL &= ~(1<<EN);
    _delay_ms(20);
}

void LCD_COMMAND(char command){
    //SET RS TO 0
    LCD_CONTROL &= ~(1<<RS);
    LCD_PORT = command;
    LCD_EN();
    _delay_ms(20);
    
    
}
void LCD_DATA(char data){
    LCD_CONTROL |= (1<<RS);
    LCD_PORT = data;
    LCD_EN();
    _delay_ms(20);
}
void init_LCD(){
    // DIO
    setPORTC_DIR_VAL(0XFF, OUT);
    setPIND_DIR(RS, OUT);
    setPIND_DIR(RW, OUT);
    setPIND_DIR(EN, OUT);
    _delay_ms(20);
    //LCD SETUP
    setPIND(RS, LOW);
    //RETURN HOME
    LCD_COMMAND(RETURN_HOME);
    //SET MODE
    LCD_COMMAND(MODE_8BITS);
    //CURSOR SET &DISPLAY MODE
    LCD_COMMAND(CURSOR_OFF_DISPLAY_ON);
    //CLEAR
    LCD_COMMAND(CLEAR);
    LCD_COMMAND(ENTRY_MODE);
}
void LCD_DATA_STR(char* str){
    int i = 0;
    while(str[i]){
        LCD_DATA(str[i]);
        i++;
    }
}
void LCD_DATA_NUM(int num){
    char str[11];
    itoa(num, str, 10);
    LCD_DATA_STR(str);
    
}
void LCD_CLEAR(){
    LCD_CONTROL &= ~(1<<RS);
    LCD_PORT = CLEAR;
    LCD_EN();
    _delay_ms(5);
}