int motorPin = 3;
 
void setup() 
{ 
  /*Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");*/
  analogWrite(motorPin,150);
} 
 
 
void loop() 
{ 
/*  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }*/
} 
