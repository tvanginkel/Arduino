#include <Servo.h>

const int trig = 12;
const int echo = 13;
const int pinH = 7;
const int pinH2 = 4;
const int MotorA_F = 3;
const int MotorA_B = 5;
const int MotorB_B = 6;
const int MotorB_F = 11;
const int leftSpeed = 116;
const int rightSpeed = 95;
const int duration;
const int cm;

Servo myServo;

int distance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);

  int cm = (duration / 2) * 0.0343;
  delay(100);

  return cm;
}

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(MotorA_F, OUTPUT);
  pinMode(MotorA_B, OUTPUT);
  pinMode(MotorB_F, OUTPUT);
  pinMode(MotorB_B, OUTPUT);
  
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
 
  if (distance() < 30)
  {
    Serial.print(Evade());
    Serial.println();
  }
  else
  {
    Move("Forward");
  }
}

String Evade()
{
  int leftCm;
  int rightCm;

  Move("Stop");
  delay(700);
  Move("Backward");
  delay(500);
  Move("Stop");
  delay(700);
    
  myServo.write(20);
  delay(200);
  rightCm = distance();
  Serial.print("Right Distance: ");
  Serial.print(rightCm); 
  delay(500);

  myServo.write(180);
  delay(350);
  leftCm = distance();
  Serial.print("        Left Distance: ");
  Serial.print(leftCm);
  Serial.println();
  delay(500);

  myServo.write(100);

  if (leftCm < rightCm)
  {
    Move("Right");
    delay(800);
    Move("Stop");
    delay(200);
    
    return "Right";
  }
  else if (rightCm < leftCm)
  {
    Move("Left");
    delay(850);
    Move("Stop");
    delay(200);

    return "Left";
  }
}
void Move(String order)
{
  digitalWrite(pinH, HIGH);
  digitalWrite(pinH2, HIGH);
  
  if (order == "Forward")
  {
    digitalWrite(MotorA_B, LOW);
    analogWrite(MotorA_F, rightSpeed);
    analogWrite(MotorB_F, leftSpeed);
    digitalWrite(MotorB_B, LOW);
  }
  else if (order == "Left")
  {
    digitalWrite(MotorA_B, LOW);
    analogWrite(MotorA_F, rightSpeed);
    analogWrite(MotorB_B, leftSpeed);
    digitalWrite(MotorB_F, LOW);  
  }
  else if (order == "Right")
  {
    digitalWrite(MotorA_F, LOW);
    analogWrite(MotorA_B, rightSpeed);
    analogWrite(MotorB_F, leftSpeed);
    digitalWrite(MotorB_B, LOW);
  }
  else if (order == "Stop")
  {
    digitalWrite(MotorA_B, LOW);
    digitalWrite(MotorA_F, LOW);
    digitalWrite(MotorB_F, LOW);
    digitalWrite(MotorB_B, LOW);
  }
  else if (order == "Backward")
  {
    digitalWrite(MotorA_F, LOW);
    analogWrite(MotorA_B, rightSpeed);
    analogWrite(MotorB_B, leftSpeed);
    digitalWrite(MotorB_F, LOW);
  }
}
