/* 
 * File:   lLEDs.h
 * Author: hebai
 *
 * Created on August 4, 2024, 11:24 PM
 */

#ifndef LLEDS_H
#define	LLEDS_H



#define LED0     PC2
#define LED1     PC7
#define LED2     PD3


void initLEDs(void);
void LED_ON(int LED_NUM);
void LED_OFF(int LED_NUM);

#endif	/* LEDS_H */


