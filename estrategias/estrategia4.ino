
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define trigger 12
#define echo 13
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(trigger, echo);

//bool start = true;
//int valorArena = 1600;  // Valor limite para estar dentro da arena
float diametroArena = 77.0; //diametro

// Definindo os pinos para o sensores de refletancia
#define sensorD A0
#define sensorE A1
#define sensorTras A2
//#define btn 1

#define PWMA 3
#define PWMB 5 

#define FrenteHorarioEsquerdo 4 
#define FrenteAntiHorarioEsquerdo 2
#define TraseiroEsquerdoHorario 8 
#define TraseiroEsquerdoAntiHorario 7
#define TraseiroDireitoHorario 10
#define TraseiroDireitoAntiHorario 11
#define FrenteDireitoHorario 6
#define FrenteDireitoAntiHorario 9

void setup(){ 
    
    pinMode(PWMA,OUTPUT);
    pinMode(PWMB,OUTPUT);

    digitalWrite(PWMA,1);
    digitalWrite(PWMB,1);

    //pinMode(1,INPUT);

    pinMode(FrenteHorarioEsquerdo,OUTPUT);
    pinMode(FrenteAntiHorarioEsquerdo,OUTPUT);
    pinMode(TraseiroEsquerdoAntiHorario,OUTPUT);
    pinMode(TraseiroEsquerdoHorario,OUTPUT);

    pinMode(TraseiroDireitoHorario,OUTPUT);
    pinMode(TraseiroDireitoAntiHorario,OUTPUT);
    pinMode(FrenteDireitoAntiHorario,OUTPUT);
    pinMode(FrenteDireitoHorario,OUTPUT);

    delay(5000);
   /* while(start){
        if(digitalRead(btn) == 1){
            start = false;
        }
    }*/
    //delay(4800); // OBRIGATORIO PELAS REGRAS
}

void GO(){
    digitalWrite(FrenteHorarioEsquerdo,0);
    digitalWrite(FrenteAntiHorarioEsquerdo,1);
    digitalWrite(TraseiroEsquerdoAntiHorario,1);
    digitalWrite(TraseiroEsquerdoHorario,0);

    digitalWrite(TraseiroDireitoHorario,1);
    digitalWrite(TraseiroDireitoAntiHorario,0);
    digitalWrite(FrenteDireitoHorario,0);
    digitalWrite(FrenteDireitoAntiHorario,1);
}

void re(){
    digitalWrite(FrenteHorarioEsquerdo,0);
    digitalWrite(FrenteAntiHorarioEsquerdo,1);
    digitalWrite(TraseiroDireitoHorario,1);
    digitalWrite(TraseiroDireitoAntiHorario,0);

    digitalWrite(TraseiroEsquerdoHorario,0);
    digitalWrite(TraseiroEsquerdoAntiHorario, 1);
    digitalWrite(FrenteDireitoHorario,1);
    digitalWrite(FrenteDireitoAntiHorario,0);
}

void girarHorario(){

    digitalWrite(FrenteHorarioEsquerdo,0);
    digitalWrite(FrenteAntiHorarioEsquerdo,1);
    digitalWrite(TraseiroEsquerdoAntiHorario,1);
    digitalWrite(TraseiroEsquerdoHorario,0);

    digitalWrite(TraseiroDireitoHorario,0);
    digitalWrite(TraseiroDireitoAntiHorario,1);
    digitalWrite(FrenteDireitoHorario,0);
    digitalWrite(FrenteDireitoAntiHorario,1);

}
void girarAntiHorario(){
    digitalWrite(FrenteHorarioEsquerdo,1);
    digitalWrite(FrenteAntiHorarioEsquerdo,0);
    digitalWrite(TraseiroEsquerdoAntiHorario,0);
    digitalWrite(TraseiroEsquerdoHorario,1);

    digitalWrite(TraseiroDireitoHorario,1);
    digitalWrite(TraseiroDireitoAntiHorario,0);
    digitalWrite(FrenteDireitoHorario,1);
    digitalWrite(FrenteDireitoAntiHorario,0);
}

void parar(){
    digitalWrite(FrenteHorarioEsquerdo,0);
    digitalWrite(FrenteAntiHorarioEsquerdo,0);
    digitalWrite(TraseiroEsquerdoAntiHorario,0);
    digitalWrite(TraseiroEsquerdoHorario,0);

    digitalWrite(TraseiroDireitoHorario,0);
    digitalWrite(TraseiroDireitoAntiHorario,0);
    digitalWrite(FrenteDireitoHorario,0);
    digitalWrite(FrenteDireitoAntiHorario,0);
}

bool radar(){
    float distancia;
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
    
    if(distancia > diametroArena){
        return false;
    }
    if(distancia < diametroArena){
        return true;
    }
}

bool olhos(){

    int x1 = analogRead(sensorD);
    int x2 = analogRead(sensorE);
    int x3 = analogRead(sensorTras);

    if(x1 < 200 || x2 < 200 || x3 < 270){
        return false;
    }

    else{
        return true;
    }
}

int aux;
void procurar(){
    if(analogRead(sensorTras < 200)){
        re();
    }
    while(olhos() == true && radar() == false){
        delay(400);
        girarHorario();
        delay(400);
    }
    parar();
}

void atacar(){
    while(olhos() == true && radar() == true){
        GO();
        /*if(analogRead(sensorD < 200 || sensorE < 200)){
            break;
        }*/
    }
    parar();
}

void recuar(){
    /*if(olhos() == false){
        if(analogRead(sensorD < 200 && sensorE > 200)){
            girarHorario();
            delay(500);
            parar();
        }
        if(analogRead(sensorE < 200 && sensorD > 200)){
            girarAntiHorario();
            delay(500);
            parar();
        }

        if(analogRead(sensorD < 200 && sensorE < 200)){
            re();
            delay(500);
            parar();
        }

        if(analogRead(sensorTras < 270 && (sensorD<200 || sensorE<200) )){
            GO();
            delay(700);
            parar();
        }

    }*/

    if(olhos() == false){
        if(analogRead(sensorD < 200 || sensorE < 200 )){
            re();
            delay(1000);
        }
    }
}

void loop(){

    procurar();

    atacar();
    
    recuar();
}