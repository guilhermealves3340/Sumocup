//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 9
#define pino_echo 10
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

bool start = true;
int valorArena = 1600;  // Valor limite para estar dentro da arena
float diametroArena = 75.0; //diametro
int buzzer = 11;
int forca = 255;    // força dos motores trazeiros

// Sentidos dos motores
int HorarioD1 = 0;
int HorarioD2 = 5;
int AntiHorarioE1 = 2;
int AntiHorarioE2 = 6;
int AntiHorarioD1 = 3;
int AntiHorarioD2 = 7;
int HorarioE1 = 4;
int HorarioE2 = 8;

// Definindo os pinos para o sensores de refletancia
# define sensorD A1
# define sensorE A2
# define sensorTras A3
# define btn A4
# define PWMD2 A5
# define PWME2 A6

void setup(){
    pinMode(buzzer,OUTPUT);

    pinMode(HorarioD1,OUTPUT);
    pinMode(AntiHorarioE1,OUTPUT);
    pinMode(HorarioD2,OUTPUT);
    pinMode(AntiHorarioE2,OUTPUT);
    pinMode(HorarioE1,OUTPUT);
    pinMode(AntiHorarioD1,OUTPUT);
    pinMode(HorarioE2,OUTPUT);
    pinMode(AntiHorarioD2,OUTPUT);
    
    while(start){
        if(analogRead(btn) >= 200){
            start = false;
            tocarBuzzer();
        }
    }
}

void GO(){
    analogWrite(PWMD2, forca);
    analogWrite(PWME2, forca);

    // Direita
    digitalWrite(AntiHorarioD2,0);
    digitalWrite(AntiHorarioD1,0);
    digitalWrite(HorarioD1,1);
    digitalWrite(HorarioD2,1);

    // Esquerda
    digitalWrite(HorarioE1,0);
    digitalWrite(HorarioE2,0);
    digitalWrite(AntiHorarioE1,1);
    digitalWrite(AntiHorarioE2,1);
}

void re(){
    analogWrite(PWMD2, forca);
    analogWrite(PWME2, forca);

    // Direita
    digitalWrite(AntiHorarioE1,0);
    digitalWrite(AntiHorarioE2,0);
    digitalWrite(HorarioE1,1);
    digitalWrite(HorarioE2,1);

    // Esquerda
    digitalWrite(AntiHorarioE1,0);
    digitalWrite(AntiHorarioE2,0);
    digitalWrite(AntiHorarioD2,1);
    digitalWrite(AntiHorarioD1,1);
}

void girarHorario(){
    analogWrite(PWMD2, forca);
    analogWrite(PWME2, forca);

    // Direita
    digitalWrite(HorarioD1,0);
    digitalWrite(HorarioD2,0);
    digitalWrite(AntiHorarioD1,1);
    digitalWrite(AntiHorarioD2,1);

    // Esquerda
    digitalWrite(HorarioE1,0);
    digitalWrite(HorarioE2,0);
    digitalWrite(AntiHorarioE1,1);
    digitalWrite(AntiHorarioE2,1);

}

void girarAntiHorario(){
    analogWrite(PWMD2, forca);
    analogWrite(PWME2, forca);

    // Direita
    digitalWrite(AntiHorarioD1,0);
    digitalWrite(AntiHorarioD2,0);
    digitalWrite(HorarioD1,1);
    digitalWrite(HorarioD2,1);


    // Esquerda
    digitalWrite(AntiHorarioE1,0);
    digitalWrite(AntiHorarioE2,0);
    digitalWrite(HorarioE1,1);
    digitalWrite(HorarioE2,1);
}

void procurar(){
    re();
    delay(150);
    while(ultrassonico() == false){
        girarHorario();
    }
}

void atacar(){
    while(ultrassonico() == true && olhos(true) < valorArena){
        GO();
    }
}

void recuar(){
    re();
    delay(500);
}

void recuar2(){
    GO();
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
    if(olhos(true) > valorArena){
        recuar();
    }

    if(olhos(false) > 600){
        recuar2();
    }

    procurar();

    atacar();

}

void tocarBuzzer(){
    // Aciona o buzzer na frequencia relativa ao Dó em Hz
    tone(buzzer,261);    
    // Espera um tempo para Desativar
    delay(200);
    //Desativa o buzzer
    noTone(buzzer); 
}