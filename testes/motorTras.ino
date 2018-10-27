#define PWMA 3
#define PWMB 5 

#define AIN1 4
#define AIN2 2
#define BIN1 8
#define BIN2 7
#define AH 10
#define AA 11
#define BA 7
#define BH 8

void setup(){ 
    pinMode(PWMA,OUTPUT);
    pinMode(PWMB,OUTPUT);

    digitalWrite(PWMA,1);
    digitalWrite(PWMB,1);

    pinMode(1,INPUT);

    pinMode(AIN1,OUTPUT);
    pinMode(AIN2,OUTPUT);
    pinMode(AH,OUTPUT);
    pinMode(AA,OUTPUT);

    pinMode(BH,OUTPUT);
    pinMode(BA,OUTPUT);
    pinMode(BIN1,OUTPUT);
    pinMode(BIN2,OUTPUT);


    delay(3000); // OBRIGATORIO PELAS REGRAS
}

void loop(){
    digitalWrite(AIN1,0);
    digitalWrite(AIN2,1);
    digitalWrite(BIN1,1);
    digitalWrite(BIN2,0);

    digitalWrite(AH,0);
    digitalWrite(AA,1);
    digitalWrite(BH,1);
    digitalWrite(BA,0);
}