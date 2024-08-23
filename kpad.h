/* 
 * File:   kpad.h
 * Author: hebai
 *
 * Created on August 9, 2024, 8:26 PM
 */
#include <avr/io.h>
#include "DIO.h"
#ifndef KPAD_H
#define	KPAD_H

#define F_CPU 16000000UL
#define keypad_PORT_DIR DDRB
#define keypad_PORT PORTB

void initKey();
char readKey();

#endif	/* KPAD_H */

