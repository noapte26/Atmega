#include <avr/io.h>
#include "DIO.h"
#include "kpad.h"
#include <util/delay.h>

void initKey() {
    keypad_PORT_DIR = 0x07;  // Set lower 3 bits (rows) as output, upper 4 bits (columns) as input
    keypad_PORT = 0xF8;      // Enable pull-ups on columns, rows initially low
}

char readKey() {
    while (1) {
        for (int row = 0; row < 3; row++) {
            // Set only the current row low, others high
            keypad_PORT = ~(1 << row);

            // Debouncing delay
            _delay_us(10);

            uint8_t col = readPORTB() & 0xF0;  // Read columns (upper 4 bits)
            if (col != 0xF0) {  // If any column is low (button pressed)
                _delay_ms(20);  // Additional debounce
                col = readPORTB() & 0xF0;  // Re-read columns

                if (col != 0xF0) {  // Confirm button press
                    while ((readPORTB() & 0xF0) != 0xF0);  // Wait for button release

                    // Adjusting key mappings based on observed issue
                    if (row == 0) {
                        if (col == 0xE0) return '1';
                        if (col == 0xD0) return '4';  // Previously '4'
                        if (col == 0xB0) return '7';  // Previously '7'
                        if (col == 0x70) return '*';  // Could be '*'
                    } else if (row == 1) {
                        if (col == 0xE0) return '2';  // Previously '2'
                        if (col == 0xD0) return '5';
                        if (col == 0xB0) return '8';  // Previously '8'
                        if (col == 0x70) return '0';  // Could be '0'
                    } else if (row == 2) {
                        if (col == 0xE0) return '3';  // Previously '3'
                        if (col == 0xD0) return '6';  // Previously '6'
                        if (col == 0xB0) return '9';
                        if (col == 0x70) return '#';  // Could be '#'
                    }
                }
            }
        }
    }
}

/*void initKey() {
    keypad_PORT_DIR = 0X07;
    keypad_PORT = 0X07;
}

char readKey() {

    keypad_PORT |= 0X07;
    while (1) {

        if (readPORTB() & 0xF0) {
            keypad_PORT &= 0xF8;
            keypad_PORT |= (1 << 0);
            _delay_ms(5);
            if (readPORTB() & 0x10) {
                _delay_us(500);
                keypad_PORT = 0X07;
                return '1';
            } else if (readPORTB() & 0x20) {
                _delay_us(500);

                keypad_PORT = 0X07;
                return '4';
            } else if (readPORTB() & 0x40) {
                _delay_us(500);
                ;
                keypad_PORT = 0X07;
                return '7';
            } else if (readPORTB() & 0x80) {
                _delay_us(500);
                keypad_PORT = 0X07;
                return '*';
            } else {

                keypad_PORT &= 0xF8;
                keypad_PORT |= (1 << 1);
                _delay_ms(5);
                if (readPORTB() & 0x10) {
                    _delay_us(500);

                    keypad_PORT = 0X07;
                    return '2';
                } else if (readPORTB() & 0x20) {
                    _delay_us(500);

                    keypad_PORT = 0X07;
                    return '5';
                } else if (readPORTB() & 0x40) {
                    _delay_us(500);
                    keypad_PORT = 0X07;
                    return '8';
                } else if (readPORTB() & 0x80) {
                    _delay_us(500);
                    keypad_PORT = 0X07;
                    return '0';
                } else {

                    keypad_PORT &= 0xF8;
                    keypad_PORT |= (1 << 2);
                    _delay_ms(5);
                    if (readPORTB() & 0x10) {
                        _delay_us(500);

                        keypad_PORT = 0X07;
                        return '3';
                    } else if (readPORTB() & 0x20) {
                        _delay_us(500);

                        keypad_PORT = 0X07;
                        return '6';
                    } else if (readPORTB() & 0x40) {
                        _delay_us(500);
                        keypad_PORT = 0X07;
                        return '9';
                    } else if (readPORTB() & 0x80) {
                        _delay_us(500);
                        keypad_PORT = 0X07;
                        return '#';
                    } else {

                    }
                }
            }




        }
        _delay_ms(50);
        keypad_PORT = 0X07;

    }

}*/