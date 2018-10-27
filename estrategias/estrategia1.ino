/*

        DIFERENCIAL: NO ATO DA PROCURA O ROBO DA UMA PEQUENA RÉ E DEPOIS FICA GIRANDO PRA DIREITA E PARA A ESQUEDA
        ATÉ ENCONTRAR O OPONENTE

        ANALOGICOS:

        A0 - OPTICO D1
        A1 - OPTICO D2
        A2 - OPTICO TRASEIRO


*/

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define trigger 12
#define echo 13
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(trigger, echo);

bool start = true;
//int valorArena = 1600;  // Valor limite para estar dentro da arena
float diametroArena = 77.0; //diametro

// Definindo os pinos para o sensores de refletancia
#define sensorD A0
#define sensorE A1
#define sensorTras A2
#define btn 1

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

   /* while(start){
        if(digitalRead(btn) == 1){
            start = false;
        }
    }*/
    delay(4500); // OBRIGATORIO PELAS REGRAS
}

void re(){
    digitalWrite(AIN1,0);
    digitalWrite(AIN2,1);
    digitalWrite(BIN1,1);
    digitalWrite(BIN2,0);

    digitalWrite(AH,0);
    digitalWrite(AA,1);
    digitalWrite(BH,1);
    digitalWrite(BA,0);
}

void GO(){
    digitalWrite(AIN1,1);
    digitalWrite(AIN2,0);
    digitalWrite(BIN1,0);
    digitalWrite(BIN2,1);

    digitalWrite(AH,1);
    digitalWrite(AA,0);
    digitalWrite(BH,0);
    digitalWrite(BA,1);
}

void girarHorario(){
    digitalWrite(AIN1,0);
    digitalWrite(AIN2,1);
    digitalWrite(BIN1,0);
    digitalWrite(BIN2,1);

    digitalWrite(AH,0);
    digitalWrite(AA,1);
    digitalWrite(BH,0);
    digitalWrite(BA,1);
}

void girarAntiHorario(){
    digitalWrite(AIN1,1);
    digitalWrite(AIN2,0);
    digitalWrite(BIN1,1);
    digitalWrite(BIN2,0);

    digitalWrite(AH,1);
    digitalWrite(AA,0);
    digitalWrite(BH,1);
    digitalWrite(BA,0);
}

void procurar(){
    re();
    delay(250);
    while(ultrassonico() == false){
        girarHorario();
        delay(500);
        girarAntiHorario();
        delay(500);
    }
}

void atacar(){
    while(ultrassonico() == true && olhos(true) == false){
        GO();
    }
}

void recuar(){
    re();
    delay(800);
}

void recuar2(){
    GO();
    delay(800);
}

bool ultrassonico(){
    float distancia;
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

    if(distancia > diametroArena){
        return false;
    }
    else{
        if( distancia > 0 || distancia < diametroArena){
            return true;
        }
    }
}

bool olhos(bool i){
    int x1 = analogRead(sensorD);
    int x2 = analogRead(sensorE);
    int x3 = analogRead(sensorTras);
    if(i == true){
        if(sensorD < 200 || sensorE < 200 || sensorTras < 200){
            return false;
        }
    }
    else{
        return true;
}}

void loop(){
    if(olhos(true) == false){
        recuar();
    }

    if(olhos(false) == false){
        recuar2();
    }

    procurar();

    atacar();

}
