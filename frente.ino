int M_DD_1 = 8;
int M_DD_PWM = 5;
int M_DD_2 = 7;

int M_DE_1 = 4;
int M_DE_PWM = 3;
int M_DE_2 = 2;

void setup(){
    pinMode(M_DD_1,OUTPUT);
    pinMode(M_DD_2,OUTPUT);
    pinMode(M_DD_PWM,OUTPUT);

    pinMode(M_DE_2,OUTPUT);
    pinMode(M_DE_PWM,OUTPUT);
    pinMode(M_DE_1,OUTPUT);

    digitalWrite(M_DD_PWM,255);
    digitalWrite(M_DE_PWM,255);
}

void loop(){
  digitalWrite(M_DD_1,0);
  digitalWrite(M_DD_2,0);
  digitalWrite(M_DE_1,0);
  digitalWrite(M_DE_2,0);

  digitalWrite(M_DD_1,1);
  digitalWrite(M_DD_2,0);
  digitalWrite(M_DE_1,1);
  digitalWrite(M_DE_2,0);
  delay(3000);

  digitalWrite(M_DD_1,0);
  digitalWrite(M_DD_2,1);
  digitalWrite(M_DE_1,0);
  digitalWrite(M_DE_2,1);
  delay(3000);
  
}