#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd (0x27,20,4);


void setup ()
{
   pinMode (A3, OUTPUT); // define the digital output interface 13 feet
   lcd.begin(          );
}
void loop () {
   lcd.backlight ();
   digitalWrite (A3, HIGH); // open the laser head
   lcd.print ("Led ON");
   delay (1000); // delay one second
   lcd.clear();
}
