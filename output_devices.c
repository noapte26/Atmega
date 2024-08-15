#include"output_objects.h"

void setBuzzerDir(){
    setPINA_DIR(BUZZER, OUT);
}
void setRelayDir(){
    setPINA_DIR(RELAY, OUT);
}
void setBuzzer_ON(){
    setPINA(BUZZER, HIGH);
}
void setBuzzer_OFF(){
    setPINA(BUZZER, LOW);
}
void setRelay_ON(){
    setPINA(RELAY, HIGH);
}
void setRelay_OFF(){
    setPINA(RELAY, LOW);
}