#include <Servo.h>
#include <string.h> 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>  

using namespace std;

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
LiquidCrystal_I2C lcd (0x27,20,4);
int x = 0 ;
int y = 0 ;
Servo servo1; 
Servo servo2;

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
    lcd.begin () ;
  servo1.attach (8) ;  // Conectar servo1 al pin 6
  servo2.attach (9) ;
//  pinMode (ledrojo    ,OUTPUT);
}
void loop() {
  lcd.backlight();
  lcd.clear();

  x = map( analogRead(A1), 0, 1024, 0, 180);
  y = map( analogRead(A3), 0, 1024, 0, 180);

  // read the sensor on analog A0:
  int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

   if (range == 2)
  {
    lcd.setCursor (2,2);
    lcd.print ("No fire");
    servo1.write(90 );
    servo2.write(90 );
    delay (100);
  }
  else if (range == 0 || range == 1)
  {
    lcd.setCursor (2,2);
    lcd.print ("Firee");
    servo1.write(0  );
    servo2.write(180);
    delay (100);
  }

  delay(1);  // delay between reads
}



