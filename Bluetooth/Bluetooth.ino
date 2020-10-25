void setup() {
 
   Serial.begin(19200);
   Serial.println("Hello World!! :D");
   pinMode(13, OUTPUT); 
 
}
 
void loop(){
 
  if (Serial.available() > 1) {
         char incomingData = Serial.read();
         Serial.print("I received: ");
         Serial.println(incomingData);
        
         digitalWrite(13, HIGH);
         delay(100);
         digitalWrite(13, LOW);
         delay(100);
   }
}
