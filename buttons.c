
#include<avr/io.h>
#include "buttons.h"

void initButtons(){
    // set the pins corresponding to the buttons as inputs
    setPORTD_DIR_VAL((1<<Button1) | (1<<Button2), IN);
    setPINB(Button0, IN);
}

int is_pressed(int buttonNum){
    switch(buttonNum){
        case Button0:
            return readPINB(Button0);
            break;
        case Button1:
            return readPIND(Button1);
            break;
        case Button2:
            return readPIND(Button2);
            break;
    }
}
