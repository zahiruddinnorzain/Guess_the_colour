#include <Servo.h>
int butR     = 2;
int butY     = 3;
int butB     = 4;
int LedR1    = 5;
int LedR2    = 6;
int LedY1    = 7;
int LedY2    = 8;
int LedB1    = 9;
int LedB2    = 10;
int servoPin = 11;
int mark     = 0;

int condR       =0;
int condY       =0;
int condB       =0;
int servoAngle  =0;
Servo servo;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(LedR1, OUTPUT);
  pinMode(LedR2, OUTPUT);
  pinMode(LedY1, OUTPUT);
  pinMode(LedY2, OUTPUT);
  pinMode(LedB1, OUTPUT);
  pinMode(LedB2, OUTPUT);
  pinMode(butR,  INPUT);
  pinMode(butY,  INPUT);
  pinMode(butB,  INPUT);
}

void Reward()
{
  for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);              
    delay(50);                  
  }
}

void Answer()
{
  condR = (digitalRead(LedR1) == 1) || (digitalRead(LedR2) == 1) ;
  condY = (digitalRead(LedY1) == 1) || (digitalRead(LedY2) == 1) ;
  condB = (digitalRead(LedB1) == 1) || (digitalRead(LedB2) == 1) ;
  
  while ( condR == 1 )
    {
    if ( butR == 1 )
    {
      mark = mark +1;
      condR = 0;
    }
    
    else if ( butY == 1 )
    {
      mark = mark -1;
      condR = 0;
    }

    else if ( butB == 1 )
    {
      mark = mark -1;
      condR = 0;
    }
  }

   while ( condY == 1 )
  {
    if ( butY == 1 )
    {
      mark = mark -1;
      condY = 0;
    }
    
    else if ( butY == 1 )
    {
      mark = mark +1;
      condY = 0;
    }

    else if ( butB == 1 )
    {
      mark = mark -1;
      condY = 0;
    }
  }

   while ( condB == 1 )
  {
    if ( butR == 1 )
    {
      mark = mark -1;
      condB = 0;
    }
    
    else if ( butY == 1 )
    {
      mark = mark -1;
      condB = 0;
    }

    else if ( butB == 1 )
    {
      mark = mark +1;
      condB = 0;
    }
  }
  
}

void loop() {
  
  digitalWrite(LedR1, HIGH);
  Answer();

  digitalWrite(LedY2, HIGH);
  Answer();

  digitalWrite(LedB1, HIGH);
  Answer();

  digitalWrite(LedY1, HIGH);
  Answer();

  digitalWrite(LedB2, HIGH);
  Answer();

  digitalWrite(LedR2, HIGH);
  Answer();

  delay (5000);

  Reward();


  
}
