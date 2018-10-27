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

float diametroArena = 77.0; //diametro

// Definindo os pinos para o sensores de refletancia
#define sensorD A0
#define sensorE A1
#define sensorTras A2

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
void procurar(){
    while(!ultrassonico()){
      voltar();
      parar();
      delay(200);
      girarHorario();
      if(ultrassonico())
        {break;}
      delay(1000);
      parar();
      delay(300);
      if(ultrassonico())
        {break;}
        voltar();
      girarAntiHorario();
      delay(1000);
}
atacar();
}

void voltar()
{
  if(olhos(1) == false){
   parar();
   re();
   delay(1000);
   girarHorario();
   delay(700);
   /*girarHorario();
   delay(500);
   re();
   delay(700);*/
  }
  else if(olhos(2) == false)
  {
    parar();     
    GO();
    delay(1000);
    girarHorario();
    delay(600);
    girarHorario();
    delay(600);
    GO();
    delay(1000);
    }
    parar();
  }

void atacar(){
     while(ultrassonico())
        {
          GO();
          voltar();    
        }
     procurar();
}


bool ultrassonico(){
    float distancia;
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
    
    if(distancia > diametroArena){
        return false;
    }
    else if(distancia < diametroArena){
            return true;
        }
    return false;
 }


bool olhos(int i){
    int x1 = analogRead(sensorD);
    int x2 = analogRead(sensorE);
    int x3 = analogRead(sensorTras);
    if(i == 1){
      if(x1 < 200){
          re();
          delay(2000);
        return false;
        }   
        if(x2 < 200){
            re();
            delay(2000);
            return false;
        }
        else{
        return true;
        }
    }
    else
       if(x3 < 270){
           return false;
       }
       else{
           return true;
       }
}

void loop(){
 //girarAntiHorario();
 //delay(2000);
  procurar();
 //GO();

}
