#include <Servo.h>
#include <string.h> 

using namespace std;
int ledrojo     = 13 ;
int sensorLedL  = 2  ;
int sensorLedR  = 3  ;
int sensorReadL = 0  ; 
int sensorReadR = 0  ;


Servo myservo;
Servo myservo2;
Servo myultraservo;

void setup(){
  Serial.begin(9600);
  pinMode (ledrojo    ,OUTPUT);
  myservo.attach      (8 );
  myservo2.attach     (9 );
}

void loop() {
  
  sensorReadL = digitalRead (sensorLedL);
  sensorReadR = digitalRead (sensorLedR);
    
    if  (sensorReadL == HIGH && sensorReadR == HIGH  )
    {
    digitalWrite (ledrojo, HIGH);
    myservo.write  (180);
    myservo2.write (0);
    delay (10);
    }
    else if (sensorReadL == LOW && sensorReadR == LOW  )
    {
      myservo.write  (0);
      myservo2.write (180);
      delay (10);
    }

    else if (sensorReadL == HIGH )
    {
    digitalWrite (ledrojo , HIGH);
    delay (10);
    digitalWrite (ledrojo , LOW);
    delay (10);
    myservo.write (0);
    myservo2.write (90);
    delay (10);
    }
    else if (sensorReadR == HIGH)
    {
    digitalWrite (ledrojo , HIGH);
    delay (10);
    digitalWrite (ledrojo , LOW);
    delay (10);
    myservo.write  (90);
    myservo2.write (180);
    delay (10);
    }

}



