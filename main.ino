//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

bool start = false;
btn = 6;
int valorArena = 1600;
float diametroArena;
int buzzer = 7;

void setup(){
    pinMode(buzzer,OUTPUT);
    pinMode(btn, INPUT);
}

void frente(){

}

void re(){

}

void girarHorario(){

}

void girarAntiHorario(){

}

void procurar(){
    while(ultrassonico() == false){
        girarHorario();
    }
}

void atacar(){
    while(ultrassonico() == true && olhos(true) < valorArena){
        frente();
    }
}

void recuar(){
    re();
    delay(500);
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

int olhos(bool i){
    int x;
    if(i == true){
        int frenteD = digitalRead(sensorD);
        int frenteE = digitalRead(sensorE);
        x = frenteD + frenteE;
    }
    else{
        int x = digitalRead(sensorTras);
    }

    return x;
}

void loop(){
    if(digitalRead(btn) == 1){
        start = true;
    }

    if(start == true){
        tocarBuzzer();
        while(olhos(true) < valorArena){
            procurar();
            atacar();
        }

        if(olhos(true)>valorArena){
            recuar();
        }
    }
}

void tocarBuzzer(){
    // Aciona o buzzer na frequencia relativa ao Dó em Hz
    tone(buzzer,261);    
    // Espera um tempo para Desativar
    delay(200);
    //Desativa o buzzer
    noTone(buzzer); 
}