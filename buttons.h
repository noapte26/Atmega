/* 
 * File:   buttons.h
 * Author: hebai
 *
 * Created on August 4, 2024, 11:25 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

 
#include <avr/io.h>


#define OUT      1
#define IN       0

#define HIGH     1
#define LOW      0

#define ON       1
#define OFF      0

#define Button0 PB0
#define Button1 PD6
#define Button2 PD2

void initButtons();
int is_pressed(int buttonNum);

#endif	/* BUTTONS_H */
