#include <Servo.h>
int servoPin = 11;
int servoAngle = 0;   // servo position in degrees
Servo servo;

void setup()  // put your setup code here, to run once:
{
 Serial.begin(9600);  
 servo.attach(servoPin);

}

void Reward()
{
  //for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
                                    
    servo.write(0);              
    delay(3000);
    servo.write(60);                  
  
}

void loop()   // put your main code here, to run repeatedly:
{
  Reward();
}


