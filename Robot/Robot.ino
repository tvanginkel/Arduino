#include <Servo.h>

long Dizquierda;
long distancia;
long Dderecha;
long tiempo;
long tiempo1;
long tiempo2;
int led = 1;
int ledrojo = 13;
int pos = 0;


Servo myservo;
Servo myservo2;
Servo myultraservo;

void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(5, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(ledrojo, OUTPUT);
  myservo.attach (8);
  myservo2.attach (9);
  myultraservo.attach (11);
}

void loop(){
  myultraservo.write(100);
  delay (100);
  digitalWrite(4,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(4, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(5, HIGH);
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  if (distancia <= 15)
  {

    digitalWrite ( ledrojo, HIGH);
    myservo.write(90);
    myservo2.write (90);
    delay(3000);
    myservo.write (0);
    myservo2.write (0);
    digitalWrite(4,LOW); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(5);
    digitalWrite(4, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);
    tiempo1=pulseIn(5, HIGH);
    Dderecha= int(0.017*tiempo1);
    delay (4000);
    myservo.write (180);
    myservo2.write (180);
    digitalWrite(4,LOW); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(5);
    digitalWrite(4, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);
    tiempo2=pulseIn(5, HIGH);
    Dizquierda= int(0.017*tiempo2);
    delay (4000);
     if (Dizquierda <= 15)
     { 
      myservo.write (0);
      myservo2.write (0);
      delay (2000);
     }
     else if (Dderecha <= 15)
     {
      myservo.write (180);
      myservo2.write (180);
      delay (2000);
     }

      else if (Dderecha && Dizquierda <=15)
      {
      myservo.write (90);
      myservo2.write (90); 
      delay (500);
      }
  }
    else
  {
    digitalWrite ( ledrojo, LOW) ;
    myservo2.write(180);
    myservo.write(0);
    delay (10);   
   }

  delay(20);
}
