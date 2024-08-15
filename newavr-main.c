/*
 * File:   newavr-main.c
 * Author: hebai
 *
 * Created on August 4, 2024, 11:22 PM
 */


#include <avr/io.h>
#include<util/delay.h>

#include <avr/io.h>
#include <xc.h>
#include <avr/iom32a.h>
#include "DIO.h"
#include "leds.h"
#include "buttons.h"
#include "kpad.h"
#include"LCD.h"
#include"output_objects.h"

#define F_CPU 16000000UL




int main(void) {
    /* Replace with your application code */


    initLEDs();
    initBTNs();
    setBuzzerDir();
  
 
    /*init_LCD();
    _delay_ms(50);
    LCD_DATA('A');
    _delay_ms(1000);*/
    //LED_ON(LED1);
    void initKey();
    while (1) {
       //readKey();
        void checkPassword();

    }
}
    
        /*LED_ON(LED0);
        LED_OFF(LED1);
_      _delay_ms(1000);
        LED_OFF(LED0);
        LED_ON(LED0);
_       _delay_ms(1000);*/