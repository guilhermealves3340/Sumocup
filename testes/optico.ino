#define opticoD1 A0
#define opticoD2 A1
#define opticoTras A7

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.print("OPTICO DIANTEIRO DIREITO: ");
    Serial.println(analogRead(opticoD1));

    Serial.print("OPTICO DIANTEIRO ESQUERDO: ");
    Serial.println(analogRead(opticoD2));

    Serial.print("OPTICO TRASEIRO: ");
    Serial.println(analogRead(opticoTras));

    Serial.println(" ");
    delay(1000);
}