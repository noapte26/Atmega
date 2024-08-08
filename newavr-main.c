/*
 * File:   newavr-main.c
 * Author: hebai
 *
 * Created on August 4, 2024, 11:22 PM
 */


#include <avr/io.h>


#include <avr/io.h>
#include <xc.h>
#include <avr/iom32a.h>
#include "DIO.h"
#include "leds.h"
#include "buttons.h"






int main(void) {
    /* Replace with your application code */


    initLEDs();
    initButtons();
    LED_ON(LED2);
    
    /*while (1) {
        if(is_pressed(Button0)){
        LED_ON(LED0);
    }
        else{
        LED_OFF(LED0);
    }

    }*/
}

