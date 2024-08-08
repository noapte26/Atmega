
#include <avr/io.h>
#include "DIO.h"


void setPORTA_DIR_VAL(int val, int state){
    switch(state){
        case IN:
            DDRA &= ~val;
            break;
        case OUT:
            DDRA |= val;
            break;
        default:
            break;
    }
}
void setPORTB_DIR_VAL(int val, int state){
    switch(state){
        case IN:
            DDRB &= ~val;
            break;
        case OUT:
            DDRB |= val;
            break;
        default:
            break;
    }
}
void setPORTC_DIR_VAL(int val, int state){
    switch(state){
        case IN:
            DDRC &= ~val;
            break;
        case OUT:
            DDRC |= val;
            break;
        default:
            break;
    }
}
void setPORTD_DIR_VAL(int val, int state){
    switch(state){
        case IN:
            DDRD &= ~val;
            break;
        case OUT:
            DDRD |= val;
            break;
        default:
            break;
    }
}

void setPINA_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRA &= ~(1<<pinNum);
            break;
        case OUT:
            DDRA |= (1<<pinNum);
            break;
        default:
            break;
    }
}
void setPINB_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRB &= ~(1<<pinNum);
            break;
        case OUT:
            DDRB |= (1<<pinNum);
            break;
        default:
            break;
    }
}
void setPINC_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRC &= ~(1<<pinNum);
            break;
        case OUT:
            DDRC |= (1<<pinNum);
            break;
        default:
            break;
    }
}
void setPIND_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRD &= ~(1<<pinNum);
            break;
        case OUT:
            DDRD |= (1<<pinNum);
            break;
        default:
            break;
    }
}

void setPORTA_DIR(int state){
    switch(state){
        case IN:
            PORTA = 0X00;
            break;
        case OUT:
            PORTA = 0XFF;
            break;
    }
}
void setPORTB_DIR(int state){
    switch(state){
        case IN:
            PORTB = 0X00;
            break;
        case OUT:
            PORTB = 0XFF;
            break;
    }
}
void setPORTC_DIR(int state){
    switch(state){
        case IN:
            PORTC = 0X00;
            break;
        case OUT:
            PORTC = 0XFF;
            break;
    }
}
void setPORTD_DIR(int state){
    switch(state){
        case IN:
            PORTD = 0X00;
            break;
        case OUT:
            PORTD = 0XFF;
            break;
    }
}

void setPORTA_VAL(int val){
    PORTA = val;
}
void setPORTB_VAL(int val){
    PORTB = val;
}
void setPORTC_VAL(int val){
    PORTC = val;
}
void setPORTD_VAL(int val){
    PORTD = val;
}


void setPINA(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTA |= (1<<pinNUM);
            break;
        case LOW:
            PORTA &= ~(1<<pinNUM);
            break;
    }
}
void setPINB(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTB |= (1<<pinNUM);
            break;
        case LOW:
            PORTB &= ~(1<<pinNUM);
            break;
    }
}
void setPINC(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTC |= (1<<pinNUM);
            break;
        case LOW:
            PORTC &= ~(1<<pinNUM);
            break;
    }
}
void setPIND(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTD |= (1<<pinNUM);
            break;
        case LOW:
            PORTD &= ~(1<<pinNUM);
            break;
    }
}
int readPORTA(){
    return PINA;
}
int readPORTB(){
    return PINB;
}
int readPORTC(){
    return PINC;
}
int readPORTD(){
    return PIND;
}
int readPINA(int pinNum){
    return (PORTA & (1<<pinNum));
}
int readPINB(int pinNum){
    return (PORTB & (1<<pinNum));
}
int readPINC(int pinNum){
    return (PORTC & (1<<pinNum));
}
int readPIND(int pinNum){
    return (PORTD & (1<<pinNum));
}

