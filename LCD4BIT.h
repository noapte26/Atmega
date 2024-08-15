/* 
 * File:   LCD4BIT.h
 * Author: hebai
 *
 * Created on August 10, 2024, 7:50 PM
 */

#ifndef LCD4BIT_H
#define	LCD4BIT_H

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

void init_LCD4();
void LCD4_COMMAND(char command);
void LCD4_DATA(char data);
void LCD4_EN();
void LCD4_DATA_STR(char*);
void LCD4_DATA_NUM(int num);
void LCD4_CLEAR();


#endif	/* LCD4BIT_H */

