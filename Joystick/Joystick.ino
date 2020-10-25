#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>          // Incluir la librería Servo

LiquidCrystal_I2C lcd (0x27,20,4);
Servo servo1; 
Servo servo2;// Crear un objeto tipo Servo llamado servo1

int x = 0 ;
int y = 0 ;
int Eje_X = A1  ;
int Eje_Y = A3  ;


void setup()
{
  servo1.attach (8) ;  // Conectar servo1 al pin 6
  servo2.attach (9) ;
  lcd.begin      ( ) ;
}

void loop()
{
  lcd.backlight();
  lcd.clear();
  
  x = map( analogRead(A1), 0, 1024, 0, 180);
  y = map( analogRead(A3), 0, 1024, 0, 180);

  lcd.setCursor (2,2);
  lcd.print (x);
  lcd.setCursor (10,2);
  lcd.print (y);
 

  if (x < 80)
  {
    servo1.write (0  );
    servo2.write (180);
  }

  else if (x > 95)
  {
    servo1.write (180);
    servo2.write (0  );
  }
   
   else if (y > 90)
  {
    servo2.write (180);
  }
  
  else 
  {
    servo1.write (90);
    servo2.write (90);
  }

  delay(250) ;
}
           
