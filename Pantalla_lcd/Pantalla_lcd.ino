#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>
//#include <String.h>

LiquidCrystal_I2C lcd (0x27, 20, 4);

long distancia       ;
long tiempo          ;
int led = 13         ;
const String St1 = "   ";
String St2           ;
String ST            ;
long distancia2      ;
long tiempo2         ;
const String St3 = "   ";
String St4           ;
String ST2           ;
int x = A1;
int y = A3;
int angulo1 = 0;
int angulo2 = 0;
Servo myultraservo;

void setup()
{
  pinMode (led        , OUTPUT);
  lcd.init(                  );
  pinMode (4          , OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode (5          , INPUT ); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  myultraservo.attach (11);

}


void loop()
{
  Serial.begin (9600);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("====================");
  lcd.setCursor (0, 3);
  lcd.print("====================");
  lcd.setCursor (5, 1);
  lcd.print ("Valor");
  // myultraservo.write (100);

  // digitalWrite(4,LOW); /* Por cuestión de estabilización del sensor*/
  // delayMicroseconds(5);
  // digitalWrite(4, HIGH); /* envío del pulso ultrasónico*/
  // delayMicroseconds(10);
  // tiempo= pulseIn(5, HIGH);
  // distancia= int(0.017*tiempo);

  //  St2 = String (distancia );
  //  ST = St1 + St2 + "      ";
  angulo1 = map( analogRead(A1), 0, 1024, 0, 180);
  angulo2 = map( analogRead(A3), 0, 1024, 0, 180);

  lcd.setCursor (2, 2);
  lcd.print (angulo1);
  lcd.setCursor (10, 2);
  lcd.print (angulo2);

  delay (500);
  //
  // myultraservo.write (50);
  // digitalWrite(4,LOW); /* Por cuestión de estabilización del sensor*/
  // delayMicroseconds(5);
  // digitalWrite(4, HIGH); /* envío del pulso ultrasónico*/
  // delayMicroseconds(10);
  // tiempo2= pulseIn(5, HIGH);
  // distancia2= int(0.017*tiempo2);
  //
  //  St4 = String (distancia2 );
  //  ST2 = St3 + St4 + "   ";
  //
  //  lcd.setCursor (12,2);
  //  lcd.print (ST2);

  delay (500);
}

