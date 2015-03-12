#include <Servo.h> 
Servo lockServo; 
int state=0;

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
    switch(state)
    {      
      case '1': // Unlock
        lockServo.write(90);
      break;
      case '0': // Lock
        lockServo.write(0);
      break;
      default:
      break; 
    }    
    delay(2000); 
  }
} 
