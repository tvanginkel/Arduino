//Stores the Bluetooth's input
char input;

//Indicates the state of the robot
bool Automatic = false; 

// Arduino pins
const int trig = 22;
const int echo = 24;
const int leftSensor = A0;
const int rightSensor = A1;
const int pinH = 26;
const int pinH2 = 28;
const int MotorA_F = 8;
const int MotorA_B = 12;
const int MotorB_B = 11;
const int MotorB_F = 10;

//Speed of the DC motors
const int leftSpeed = 150;
const int rightSpeed = 150;

//Indicates if the previous check found and object
bool found = false;

//Setup 
void setup() {
  
  //Sets pins to INPUT or OUTPUT
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(MotorA_F, OUTPUT);
  pinMode(MotorA_B, OUTPUT);
  pinMode(MotorB_F, OUTPUT);
  pinMode(MotorB_B, OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  Serial.begin(9600);

  //Checks Serial works
  Serial.println("-----START-----");

}

//Main loop
void loop() 
  { 
    //If the Bluetooth module recives an input    
    if (Serial.available()>0)  
    {
      //Store the input
      input = Serial.read(); 

      //Set the robot in Automatic mode
      if (input == 'A')
      {
        Automatic = true; 
        Serial.println("Automatic Mode On");
      }
      //Set the robot in Manual mode
      else if (input == 'M')
      {
        Automatic = false;
        Serial.println("Manual Mode On");
      }

        //Move the robot in the directed direction
        Move(input);
    }  

    // Controlls the robot in Automatic mode
    if (Automatic == true)
    {
      //If the sensors detect black go back to the playing area
      if (isOnBlack())
      {
        Move('D');
        delay(700);
        Move('S');
        delay(700);
      }
      //If the robot is in the playing area
      else 
      {
        int dis = distance();

        //When the ultrasonic sensor detects and object go towards it
        if (dis < 60)
        {
          Serial.print("OBJECT FOUND AT: ");
          Serial.print(dis);
          Serial.println();
          Move('F');
          delay(20);
          found = true;
        }
        
        //Search for object
        else
        {
          //If in the previous loop it found and object go backwards to make some distance
          //otherwise if the Ultrasonic is too close it will ignore the object in front of it
          if (found)
          {
            Move('D');
            delay(400);
            Move('S');
            delay(100);
            found = false;
          }
          // Rotate and look for an object
          else
          {
            Serial.println("Looking for Object");
            //Rotate until it finds an object
            Move('R');
            delay(125);
            Move('S');
            delay(700); 
          }

        }
      }
    }
}

//Checks for and object in front of it and return a distance
int distance()
{
  //Checks distance
  delay(100);
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

//Return true if sensors detect black, and false if they don't
bool isOnBlack()
{
  if (analogRead(leftSensor) < 930 && analogRead(rightSensor) < 930)
  {
    return false;
  }
  else
  {
    Serial.println("IS ON BLACK!!");
    return true;
  }
}

//Move the robot in the indicated direction
//'F' is forward, 'L' is left, R' is right, 'D' is backwards and 'S' is stop 
void Move(char order)
{
  digitalWrite(pinH, HIGH);
  digitalWrite(pinH2, HIGH);
  Serial.println(order);

  //Go forward
  if (order == 'F' )
  {
    digitalWrite(MotorA_B, LOW);
    analogWrite(MotorA_F, rightSpeed);
    analogWrite(MotorB_F, leftSpeed);
    digitalWrite(MotorB_B, LOW);
  }
  //Go right
  else if (order == 'R')
  {
    digitalWrite(MotorA_B, LOW);
    analogWrite(MotorA_F, rightSpeed + 100);
    analogWrite(MotorB_B, leftSpeed + 100);
    digitalWrite(MotorB_F, LOW);  
  }
  //Go left
  else if (order == 'L')
  {
    digitalWrite(MotorA_F, LOW);
    analogWrite(MotorA_B, rightSpeed + 100);
    analogWrite(MotorB_F, leftSpeed + 100);
    digitalWrite(MotorB_B, LOW);
  }
  //Stop
  else if (order == 'S')
  {
    digitalWrite(MotorA_B, LOW);
    digitalWrite(MotorA_F, LOW);
    digitalWrite(MotorB_F, LOW);
    digitalWrite(MotorB_B, LOW);
  }
  //Go backwards
  else if (order == 'D')
  {
    digitalWrite(MotorA_F, LOW);
    analogWrite(MotorA_B, rightSpeed);
    analogWrite(MotorB_B, leftSpeed);
    digitalWrite(MotorB_F, LOW);
  }
}
