#include <Servo.h>

Servo lockServo; 
int state=0;
int currState=0;

void setup()
{
  lockServo.attach(9);  
  Serial.begin(9600); 
}

void loop() 
{   
  if (Serial.available() > 0)
  {
    state = Serial.read(); 
    
    if ((state == 1) && (currState == 0))
    {
      lockServo.writeMicroseconds(1500);
      delay(1000);
      currState = 1;
    }
    else if ((state == 0) && (currState == 1))
    {
      lockServo.writeMicroseconds(500);
      delay(1000);
      currState = 0;
    }    
  }                    
} 


