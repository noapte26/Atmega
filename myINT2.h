/* 
 * File:   myINT2.h
 * Author: hebai
 *
 * Created on August 17, 2024, 3:19 PM
 */

#ifndef MYINT2_H
#define	MYINT2_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#define INT2_FALLING_EDGE 1
#define INT2_RISING_EDGE   2

void INT2_selectMode(char INT_MODE);
void init_INT2(char MODE);
void INT2_DISABLE();
void INT2_changeMode(char INT_MODE);

#endif	/* MYINT2_H */

