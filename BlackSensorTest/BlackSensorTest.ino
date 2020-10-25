const int leftSensor = A0;
const int rightSensor = A1;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
 
  Serial.begin(9600);
  Serial.println("-----START-----");

}

void loop() {
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  Serial.print("Left Value: ");
  Serial.print(leftValue);
  Serial.print("                        ");  
  Serial.print("Right Value: ");
  Serial.print(rightValue);
  Serial.println();

}
