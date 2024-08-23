#include <util/delay.h>

#include"check_password.h"

void checkPassword(){
    initKey();
    _delay_ms(50);
    init_LCD();
    _delay_ms(50);
    char password[] = "55555";
    char passed[] = "Login successful!";
    char notPassed[] = "Wrong password!";
    char locked[] = "account locked";
    char str[6];
    
    int flag = 0;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<5 ; j++){
            str[j] = readKey();
            _delay_ms(50);
        }
        LCD_DATA_STR(str);
        if(strcmp(str, password) == 0){
            _delay_ms(1000);
            LCD_CLEAR();
            _delay_ms(1000);
            LCD_DATA_STR(passed);
            _delay_ms(20);
            flag = 1;
            break;
            
        }
        else{
            LCD_CLEAR();
            _delay_ms(20);
            LCD_DATA_STR(notPassed);
            _delay_ms(20);
            LCD_CLEAR();
        }
    }
    if(flag==0){
        LCD_DATA_STR(locked);
    }
}
