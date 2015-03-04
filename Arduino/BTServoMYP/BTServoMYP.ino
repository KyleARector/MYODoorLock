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
      case '3': // On
        lockServo.write(90);
      break;     
      case '0': // Off
        lockServo.write(0);
      break;
      default:
      break; 
    }
  }                
  delay(15);                         
} 


