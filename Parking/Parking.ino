#include <dht.h>
dht DHT;
#define DHT22_PIN 4

long tiempo=0;
float hum;
float temp;

int SensorLuz=2;
bool Claridad=0;
int Farolas=3;

void setup() {

millis();
tiempo=millis();

Serial.begin(9600);

pinMode(SensorLuz, INPUT);
pinMode(Farolas, OUTPUT);

}

void loop() {

TyH ();
Print();


}

void TyH () {
if(millis()-tiempo>1000){
  int chk = DHT.read22(DHT22_PIN);
  hum = DHT.humidity;
  temp= DHT.temperature;
  tiempo=millis();
}
}
void Print () {

Claridad=digitalRead(SensorLuz);
if (Claridad==0){
Serial.print("Claro");
digitalWrite(Farolas, LOW);}
else{
Serial.print("Oscuro");
digitalWrite(Farolas, HIGH);}
Serial.print("      ");

Serial.print("Humedad: ");
Serial.print(hum);
Serial.print("%, Temperatura: ");
Serial.print(temp);
Serial.println("ºC");

}


