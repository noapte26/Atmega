/* 
 * File:   myINT1.h
 * Author: hebai
 *
 * Created on August 17, 2024, 3:16 PM
 */

#ifndef MYINT1_H
#define	MYINT1_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#define INT_LOW_LEVEL 1
#define INT_CHANGE   2
#define INT_FALLING_EDGE 3
#define INT_RISING_EDGE 4

void INT1_selectMode(char INT_MODE);
void init_INT1(char MODE);
void INT1_DISABLE();
void INT1_changeMode(char INT_MODE);

#endif	/* MYINT1_H */

