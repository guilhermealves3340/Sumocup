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
int valorArena = 1600;  // Valor limite para estar dentro da arena
float diametroArena = 77.0; //diametro

// Definindo os pinos para o sensores de refletancia
#define sensorD A0
#define sensorE A1
#define sensorTras A2
#define btn 1

#define PWMA 3
#define PWMB 5 

#define FrenteHorarioEsquerdo 4 
#define FrenteAntiHorarioEsquerdo 2
#define TraseiroEsquerdoAntiHorario 8 
#define TraseiroEsquerdoHorario 7
#define TraseiroDireitoHorario 10
#define TraseiroDireitoAntiHorario 11
#define BA 6
#define BH 9

void setup(){ 
    pinMode(PWMA,OUTPUT);
    pinMode(PWMB,OUTPUT);

    digitalWrite(PWMA,1);
    digitalWrite(PWMB,1);

    pinMode(1,INPUT);

    pinMode(FrenteHorarioEsquerdo,OUTPUT);
    pinMode(FrenteAntiHorarioEsquerdo,OUTPUT);
    pinMode(TraseiroEsquerdoAntiHorario,OUTPUT);
    pinMode(TraseiroEsquerdoHorario,OUTPUT);

    pinMode(TraseiroDireitoHorario,OUTPUT);
    pinMode(TraseiroDireitoAntiHorario,OUTPUT);
    pinMode(TraseiroEsquerdoAntiHorario,OUTPUT);
    pinMode(TraseiroDireitoAntiHorario,OUTPUT);


    delay(4800); // OBRIGATORIO PELAS REGRAS
}

void GO(){
    digitalWrite(FrenteHorarioEsquerdo,1);
    digitalWrite(FrenteAntiHorarioEsquerdo,0);
    digitalWrite(TraseiroEsquerdoAntiHorario,0);
    digitalWrite(TraseiroEsquerdoHorario,1);

    digitalWrite(TraseiroDireitoHorario,1);
    digitalWrite(TraseiroDireitoAntiHorario,0);
    digitalWrite(BH,1);
    digitalWrite(BA,0);
}

void re(){
    digitalWrite(FrenteHorarioEsquerdo,0);
    digitalWrite(FrenteAntiHorarioEsquerdo,1);
    digitalWrite(TraseiroDireitoHorario,1);
    digitalWrite(TraseiroDireitoAntiHorario,0);

    digitalWrite(TraseiroDireitoHorario,0);
    digitalWrite(TraseiroDireitoAntiHorario,1);
    digitalWrite(BH,1);
    digitalWrite(BA,0);
}

void girarHorario(){
    digitalWrite(FrenteHorarioEsquerdo,0);
    digitalWrite(FrenteAntiHorarioEsquerdo,1);
    digitalWrite(TraseiroEsquerdoAntiHorario,0);
    digitalWrite(TraseiroEsquerdoHorario,1);

    digitalWrite(TraseiroDireitoHorario,0);
    digitalWrite(TraseiroDireitoAntiHorario,1);
    digitalWrite(BH,0);
    digitalWrite(BA,1);
}

void girarAntiHorario(){
    digitalWrite(FrenteHorarioEsquerdo,1);
    digitalWrite(FrenteAntiHorarioEsquerdo,0);
    digitalWrite(TraseiroEsquerdoAntiHorario,1);
    digitalWrite(TraseiroEsquerdoHorario,0);

    digitalWrite(TraseiroDireitoHorario,1);
    digitalWrite(TraseiroDireitoAntiHorario,0);
    digitalWrite(BH,1);
    digitalWrite(BA,0);
}

void procurar(){
        if(olhos(1) == true){
          re();
        delay(1000);
        girarHorario();
        delay(1000);  
      
    }
    if(olhos(2) == true){
     girarHorario();
     delay(1000);
     GO();
     delay(500);
    }
    while(ultrassonico() == false){
        girarHorario();
        delay(1000);
        girarAntiHorario();
        delay(1000);
    }
}

void atacar(){
    while(ultrassonico() == true && ((olhos(1) == false) || olhos(2) == false)){
        GO();
        delay(1000);
    }
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

bool olhos(int i){
    int x1 = analogRead(sensorD);
    int x2 = analogRead(sensorE);
    int x3 = analogRead(sensorTras);
    if(i == 1){
      if(sensorD < 200 || sensorE < 200)
            return false;       
    else
        return true;
    }
    else
       if(sensorTras < 200)
        return false;
    return true;
    
}

void loop(){

    procurar();

    atacar();

}
