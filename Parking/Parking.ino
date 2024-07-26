#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

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

lcd.init(); 
lcd.clear();
lcd.backlight();
}

void loop() {

if(empezar0==0){
  empezar0=1;
  myServo.write(90);
  grados2=90;
  myServo2.write(90);
  delay(2000);
  Pantalla1();

}
luces();
PasoEntrada();
PasoSalida();
Pantalla();
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
Serial.print("Claro");}
else{
Serial.print("Oscuro");}
Serial.print("      ");

Serial.print("Humedad: ");
Serial.print(hum);
Serial.print("%, Temperatura: ");
Serial.print(temp);
Serial.println("ºC");

}

void luces(){
  if (digitalRead(SensorLuz)==0){
digitalWrite(Farolas, LOW);}
else{
digitalWrite(Farolas, HIGH);}
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
    luces();
    myServo.write(grados);

  }
}

void servoEntradaAbajo(){
    for(grados=0;grados<90;grados=grados+1){

    delay(30);
    luces();
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
    luces();
    myServo2.write(grados2);

  }
}

void servoSalidaArriba(){
  for(grados2=90;grados2>0;grados2=grados2-1){

    delay(30);
    luces();
    myServo2.write(grados2);

  }
}

void Pantalla () {
  
  lcd.setCursor(2,1);
  lcd.print("Plazas libres:");
  Plazas=8-coches;
  lcd.print(Plazas);

  if (coches==8) {
    lcd.setCursor(3,0);
  lcd.print("PARKING OCUPADO");
  }
  else {
    lcd.setCursor(4,0);
  lcd.print("PARKING LIBRE ");
  }

  lcd.setCursor(2,2);
  lcd.print("Temperatura:");
  lcd.setCursor(14,2);
  lcd.print(temp);
  lcd.print("C");

  lcd.setCursor(2,3);
  lcd.print("Humedad:");
  lcd.setCursor(14,3);
  lcd.print(hum);
  lcd.print("%");



}

void Pantalla1() {
  lcd.setCursor(0,0);
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.print("*");
  delay(50);
  lcd.setCursor(19,1);
  lcd.print("*");
  delay(50);
  lcd.setCursor(19,2);
  lcd.print("*");
  delay(50);
  lcd.setCursor(19,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(18,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(17,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(16,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(15,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(14,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(13,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(12,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(11,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(10,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(9,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(8,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(7,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(6,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(5,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(4,3);
  lcd.print("*");
  delay(50);lcd.setCursor(3,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(2,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(1,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(0,3);
  lcd.print("*");
  delay(50);
  lcd.setCursor(0,2);
  lcd.print("*");
  delay(50);
  lcd.setCursor(0,1);
  lcd.print("*");

  delay(200);
  lcd.setCursor(6,1);
  lcd.print("PARKING");
  lcd.setCursor(5,2);
  lcd.print("TONTOROLO");
  delay(5000);
  lcd.clear();
}


