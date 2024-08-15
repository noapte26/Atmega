#include"check_password.h"

void checkPassword(){
    char password[] = "55555";
    char passed[] = "Login successful!";
    char notPassed[] = "Wrong password!";
    char locked[] = "account locked";
    char str[6];
    init_LCD();
    int i;
    for(i=0 ; i<3 ; i++){
        for(int j=0 ; j<5 ; j++){
            str[j] = readKey();
        }
        if(strcmp(str, password) == 0){
            LCD_CLEAR();
            LCD_DATA_STR(passed);
            break;
            
        }
        else{
            LCD_CLEAR();
            LCD_DATA_STR(notPassed);
            LCD_CLEAR();
        }
    }
    if(i == 2){
        LCD_DATA_STR(locked);
    }
}
