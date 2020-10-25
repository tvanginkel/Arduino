#include <Servo.h>

const int trig = 22;
const int echo = 24;
const int pinH = 26;
const int pinH2 = 28;
const int MotorA_F = 8;
const int MotorA_B = 9;
const int MotorB_B = 11;
const int MotorB_F = 10;
const int leftSpeed = 150;
const int rightSpeed = 150;
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
 Move("Forward");
 delay(1000);
 Move("Right");
 delay(1000);
 Move("Left");
 delay(1000);
 Move("Backward");
 delay(1000);
 Move("Stop");
 delay(5000);
}


void Move(String order)
{
  digitalWrite(pinH, HIGH);
  digitalWrite(pinH2, HIGH);
  Serial.println(order);
  
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
