int M_Tr_D1 = 7;
int M_Tr_D2 = 8;
int M_Tr_E1 = 10;
int M_Tr_E2 = 11;

void setup(){
    pinMode(M_Tr_D1,OUTPUT);
    pinMode(M_Tr_D2,OUTPUT);
    pinMode(M_Tr_E1,OUTPUT);
    pinMode(M_Tr_E2,OUTPUT);

    pinMode(1,INPUT);

    while(digitalRead(1) == 1){
        int i = 1;
    }

}

void loop(){
    digitalWrite(7,1);
    digitalWrite(8,0);
    delay(3000);

    digitalWrite(7,0);
    digitalWrite(8,1);
    delay(3000);

    digitalWrite(8,0);

    digitalWrite(10,1);
    digitalWrite(11,0);
    delay(3000);

    digitalWrite(10,0);
    digitalWrite(11,1);
    delay(3000);

    digitalWrite(11,0);
    
}


