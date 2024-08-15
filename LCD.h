/* 
 * File:   LCD.h
 * Author: hebai
 *
 * Created on August 10, 2024, 5:29 PM
 */
#include<avr/io.h>
#ifndef LCD_H
#define	LCD_H

#define LCD_PORT_DIR DDRC
#define LCD_PORT PORTC
#define RS PD0 
#define RW PD1
#define EN PD2
#define LCD_CONTROL PORTD
#define LCD_CONTROL_DIR DDRD


 // LCD COMMAND CODES
#define CLEAR   0X01
#define MODE_8BITS 0X38
#define MODE_4BITS  0X28
#define RETURN_HOME 0X02
#define CURSOR_OFF_DISPLAY_ON  0X0C
#define ENTRY_MODE 0X06

#define F_CPU 16000000UL
void itoa(int, char*, int);
void init_LCD();
void LCD_COMMAND(char command);
void LCD_COMMAND_4BIT(char);
void LCD_DATA(char data);
void LCD_EN();
void LCD_DATA_STR(char*);
void LCD_DATA_NUM(int num);
void LCD_CLEAR();


#endif	/* LCD_H */

