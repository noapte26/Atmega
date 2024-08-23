#include"myINT2.h"

 void INT2_selectMode(char INT_MODE){
       MCUCSR &= 0XBF;
       switch(INT_MODE){
           case '1':
               MCUCSR |= (0<<ISC2);
               break;
           case '2':
               MCUCSR |= (1<<ISC2);
               break;
       }
   }  
void init_INT2(char MODE){
    //SELECT MODE
    INT2_selectMode( MODE);
    GICR |= (1<<INT2);
    
    
}   
void INT2_DISABLE(){
    GICR &= ~(1<<INT2);
}
void INT2_changeMode(char INT_MODE){
    GICR &= ~(1<<INT2);
    INT2_selectMode(INT_MODE);
    GIFR |= (1<<INTF2);
    GICR |= (1<<INT2);
}
