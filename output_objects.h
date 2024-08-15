/* 
 * File:   output_objects.h
 * Author: hebai
 *
 * Created on August 15, 2024, 3:07 PM
 */

#ifndef OUTPUT_OBJECTS_H
#define	OUTPUT_OBJECTS_H
#include <avr/io.h>


#include"DIO.h"

#define RELAY PA2
#define BUZZER PA3

void setBuzzerDir();
void setRelayDir();
void setBuzzer_ON();
void setBuzzer_OFF();
void setRelay_ON();
void setRelay_OFF();

#endif	/* OUTPUT_OBJECTS_H */

