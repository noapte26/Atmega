#include <avr/io.h>
#include "DIO.h"
#include "kpad.h"
#include"LEDs.h"
#include <util/delay.h>
#include"LCD.h"

void initKey() {
    keypad_PORT_DIR = 0X07;
    keypad_PORT = 0X07;
}

char readKey() {
    
    keypad_PORT |= 0x07;
    while (1) {
        if (readPORTB() & 0xF0) {
            keypad_PORT &= 0xF8;
            keypad_PORT |= (1 << 0);
            _delay_ms(5);
            if (readPORTB() & 0x10) {
                _delay_us(500);
                LCD_DATA_NUM(1);
                return '1';
            } else if (readPORTB() & 0x20) {
                _delay_us(500);
                LCD_DATA_NUM(4);
                return '4';
            } else if (readPORTB() & 0x40) {
                _delay_us(500);
                LCD_DATA_NUM(7);
                return '7';
            } else if (readPORTB() & 0x80) {
                _delay_us(500);
                LCD_DATA('*');
                return '*';
            } else {
                
                keypad_PORT &= 0xF8;
                keypad_PORT |= (1 << 1);
                _delay_ms(5);
                if (readPORTB() & 0x10) {
                    _delay_us(500);
                    LCD_DATA_NUM(2);
                    return '2';
                } else if (readPORTB() & 0x20) {
                    _delay_us(500);
                    LCD_DATA_NUM(5);
                    return '5';
                } else if (readPORTB() & 0x40) {
                    _delay_us(500);
                    LCD_DATA_NUM(8);
                    return '8';
                } else if (readPORTB() & 0x80) {
                    _delay_us(500);
                    LCD_DATA_NUM(0);
                    return '0';
                } else {
                   
                    keypad_PORT &= 0xF8;
                    keypad_PORT |= (1 << 2);
                    _delay_ms(5);
                    if (readPORTB() & 0x10) {
                        _delay_us(500);
                        LCD_DATA_NUM(3);
                        return '3';
                    } else if (readPORTB() & 0x20) {
                        _delay_us(500);
                        LCD_DATA_NUM(6);
                        return '6';
                    } else if (readPORTB() & 0x40) {
                        _delay_us(500);
                        LCD_DATA_NUM(9);
                        return '9';
                    } else if (readPORTB() & 0x80) {
                        _delay_us(500);
                        LCD_DATA('#');
                        return '#';
                    } else {

                    }
                }
            }




        }
        _delay_ms(20);
        keypad_PORT |= 0x07;
    }
    LCD_DATA('.');
    return '.';
}