#include <dht.h>
dht DHT;
#define DHT22_PIN 4

long tiempo=0;
float hum;
float temp;

#include <Servo.h> 
Servo myServo;
Servo myServo2;

int Plazas=0;

int servo=9;
int grados=0;
int servo2=10;
int grados2=0;

bool empezar0=0;

int coches=0;

int SensorLuz=2;
bool Claridad=0;
int Farolas=3;

int Entrada1=5;
bool boolEntrada1=0;

int Entrada2=6;
bool boolEntrada2=0;

int Salida1=7;
bool boolSalida1=0;

int Salida2=8;
bool boolSalida2=0;

bool boolPasoEntrada=0;
bool mantenerEntrada=0;
bool boolPasoSalida=0;
bool mantenerSalida=0;

void setup() {

millis();
tiempo=millis();

Serial.begin(9600);

pinMode(SensorLuz, INPUT);
pinMode(Farolas, OUTPUT);

pinMode(Entrada1,INPUT);
pinMode(Entrada2,INPUT);
pinMode(Salida1,INPUT);
pinMode(Salida2,INPUT);

myServo.attach(servo);
myServo2.attach(servo2);

}

void loop() {

if(empezar0==0){
  empezar0=1;
  myServo.write(90);
  grados2=90;
  myServo2.write(90);
  delay(2000);

}

PasoEntrada();
PasoSalida();

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

boolEntrada1=digitalRead(Entrada1);
boolEntrada2=digitalRead(Entrada2);
boolSalida1=digitalRead(Salida1);
boolSalida2=digitalRead(Salida2);


Serial.println(boolEntrada1);
Serial.print("    ");
Serial.print(boolEntrada2);
Serial.print("    ");
Serial.print(boolSalida1);
Serial.print("    ");
Serial.print(boolSalida2);
Serial.print("    ");
Serial.print(coches);
Serial.print("    ");


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

void PasoEntrada() {

  if(boolEntrada1==1&&mantenerEntrada==0&&coches<8){
    mantenerEntrada=1;
    servoEntradaArriba();
  }

  if(boolEntrada2==1&&mantenerEntrada==1){
    boolPasoEntrada=1;
    //servo se queda arriba
  }

  if(boolEntrada2==0&&boolPasoEntrada==1&&mantenerEntrada==1){
    servoEntradaAbajo();
    boolPasoEntrada=0;
    mantenerEntrada=0;
    coches=coches+1;
  }
}

void servoEntradaArriba() {
for(grados=90;grados>0;grados=grados-1){

    delay(30);
    myServo.write(grados);

  }
}

void servoEntradaAbajo(){
    for(grados=0;grados<90;grados=grados+1){

    delay(30);
    myServo.write(grados);

  }
}

void PasoSalida() {

  if(boolSalida1==1&&mantenerSalida==0&&coches>0&&coches<=8){
    mantenerSalida=1;
    servoSalidaArriba();
  }

  if(boolSalida2==1&&mantenerSalida==1){
    boolPasoSalida=1;
    //servo se queda arriba
  }

  if(boolSalida2==0&&boolPasoSalida==1&&mantenerSalida==1){
    servoSalidaAbajo();
    boolPasoSalida=0;
    mantenerSalida=0;
    coches=coches-1;
  }
}

void servoSalidaAbajo() {
    for(grados2=0;grados2<90;grados2=grados2+1){

    delay(30);
    myServo2.write(grados2);

  }
}

void servoSalidaArriba(){
  for(grados2=90;grados2>0;grados2=grados2-1){

    delay(30);
    myServo2.write(grados2);

  }
}


