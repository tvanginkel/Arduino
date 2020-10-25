#include <Servo.h>
#include <string.h> 

using namespace std;

long distancia       ;
long tiempo          ;
int ledrojo     = 13 ;
int sensorLedL  = 2  ;
int sensorLedR  = 3  ;
int sensorReadL = 0  ; 
int sensorReadR = 0  ;
int giro = 0         ;


Servo myservo     ;
Servo myservo2    ;
Servo myultraservo;

void Ultrasonido()
{
  digitalWrite(4,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(4, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo= pulseIn(5, HIGH);
  distancia= int(0.017*tiempo);
}

void setup(){
  Serial.begin(9600);
  pinMode (sensorLedL ,INPUT );
  pinMode (4          ,OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode (5          ,INPUT ); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode (ledrojo    ,OUTPUT);
  myservo.attach      (8 );
  myservo2.attach     (9 );
  myultraservo.attach (11);
}

void loop() {
  myultraservo.write (100);
  sensorReadL = digitalRead (sensorLedL);
  sensorReadR = digitalRead (sensorLedR);
  Ultrasonido ();

    if (sensorReadL == LOW && sensorReadR == LOW)
    {          
      if ( distancia <= 60)
      {
        myservo.write (0);
        myservo2.write (180);
        delay (10);
        giro ++;
      }
      else if (distancia > 60)
      {
        if ( giro%2 == 0 )
        {
        myservo.write  (0);
        myservo2.write (90);
        delay (500); 
        myservo.write  (90);
        myservo2.write (90); 
        delay (1000);
        }
        else 
        {
        myservo.write  (90);
        myservo2.write (180);
        delay (500); 
        myservo.write  (90);
        myservo2.write (90); 
        delay (1000);
        }
        
      }
    }
    else if (sensorReadL == HIGH && sensorReadR == HIGH )
    {
      myservo.write (180);
      myservo2.write (0);
      delay (1000);
    }
}



