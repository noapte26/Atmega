/*
 * File:   newavr-main.c
 * Author: hebai
 *
 * Created on August 4, 2024, 11:22 PM
 */


#include <avr/io.h>
#include <avr/interrupt.h>
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
#include "myINT0.h"
#include"myINT1.h"
#include"myINT2.h"
#include "LCD4BIT.h"

#define F_CPU 16000000UL

#define ADC_STEP  5.0/1023.0*1000   //IN MILIVOLT

#define CH0  0
#define CH1  1
#define CH2  2
#define CH3  3
#define CH4  4
#define CH5  5
#define CH6  6
#define CH7  7

#define AREF  0   //00
#define AVCC  1   //01
#define INTERNAL_VOLTAGE 3  //11

#define ADC_FREQ_DIV128  7  //111



void init_ADC(char CH, char REF, char FREQ);
void ADC_SELECT_CH(char ch);
void ADC_SELECT_REF(char ref);
void ADC_SELECT_FREQ(char freq);
void ADC_SC();
void ADC_EN();
void ADC_AUTO_TRIGGERING(char mode);
void ADC_INT_EN();


void readSensors();

int main(void) {
    /* Replace with your application code */

    initKey();
    init_LCD();



    while (1) {
        /*char x = readKey();
        _delay_ms(1000);
        LCD_DATA(x);
        _delay_ms(1000);*/
        readSensors();
        

    }
}

void init_ADC(char CH, char REF, char FREQ) {
    //SELECT CHANNEL
    ADC_SELECT_CH(CH);
    //SELECT REFERENCE
    ADC_SELECT_REF(REF);
    //SELECT FREQUENCY
    ADC_SELECT_FREQ(FREQ);

    //ENABLE INTERUPT IF NEEDED
    //ADC_INT_EN();

    //ENABLE ADC PRIPHERAL 
    ADC_EN();

}

void ADC_SELECT_CH(char CH) {
    //ADMUX
    ADMUX &= ~((1 << MUX2) | (1 << MUX1) | (1 << MUX0));
    ADMUX |= CH;
}

void ADC_SELECT_REF(char REF) {
    //ADMUX
    ADMUX &= ~((1 << REFS1) | (1 << REFS0));
    ADMUX |= (REF << 6);

}

void ADC_SELECT_FREQ(char FREQ) {
    //ADCSRA
    ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
    ADCSRA |= FREQ;
}

void ADC_SC() {
    //ADCSRA
    ADCSRA |= (1 << ADSC);
}

void ADC_EN() {
    //ADCSRA
    ADCSRA |= (1 << ADEN);
}

void ADC_INT_EN() {
    //ADCSRA
    ADCSRA |= (1 << ADIE);
}

void readSensors() {
    init_LCD();
    initKey();
    char x = readKey();
    int temp;
    if (x == '1') {
        init_ADC(CH0, AREF, ADC_FREQ_DIV128);
        ADC_SC();
        _delay_ms(2);
        //waiting for flag
        while ((ADCSRA & (1 << ADSC)) == 1); //POLLING
        LCD_CLEAR();
        temp = (ADCW * ADC_STEP * 0.1);
        LCD_DATA_STR("TEMP : ");
        LCD_DATA_NUM(temp);
        LCD_DATA_STR(" C");
        _delay_ms(3000);
    } else if (x == '2') {
        init_ADC(CH1, AREF, ADC_FREQ_DIV128);
        ADC_SC();
        _delay_ms(2);
        //waiting for flag
        while ((ADCSRA & (1 << ADSC)) == 1); //POLLING
        LCD_CLEAR();
        temp = (ADCW * ADC_STEP * 0.1);
        LCD_DATA_STR("TEMP : ");
        LCD_DATA_NUM(temp);
        LCD_DATA_STR(" C");
        _delay_ms(3000);
    } else if (x == '3') {
        init_ADC(CH2, AREF, ADC_FREQ_DIV128);
        ADC_SC();
        _delay_ms(2);
        //waiting for flag
        while ((ADCSRA & (1 << ADSC)) == 1); //POLLING
        LCD_CLEAR();
        temp = (ADCW * ADC_STEP * 0.1);
        LCD_DATA_STR("TEMP : ");
        LCD_DATA_NUM(temp);
        LCD_DATA_STR(" C");
        _delay_ms(3000);
    }
    _delay_ms(60000);
}