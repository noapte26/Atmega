/* 
 * File:   buttons.h
 * Author: hebai
 *
 * Created on August 4, 2024, 11:25 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

 
#include <avr/io.h>

#define BTN0 PB0
#define BTN1 PD6
#define BTN2 PD2

void initBTNs();

char isPressedA(char pinNUM);
char isPressedB(char pinNUM);
char isPressedC(char pinNUM);
char isPressedD(char pinNUM);

#endif	/* BUTTONS_H */
