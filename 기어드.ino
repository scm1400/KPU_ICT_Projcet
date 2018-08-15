


#define speedPin 6
#define backRotation 8
#define normalRotation 7


int motorSpeed = 200;  // default speed and hold variable
int motorSpeed_FAST = 250;
int motorSpeed_SLOW = 150;

void XMotorF()
{
	analogWrite(speedPin, MotorSpeed);
	digitalWrite(normalRotation,HIGH);
	digitalWrite(backRotation, LOW);
}

void XMotorB()
{
	analogWrite(speedPin, MotorSpeed);
	digitalWrite(backRotation,HIGH);
	digitalWrite(normalRotation, LOW);
}

void YMotorF()
{
	analogWrite(speedPin, MotorSpeed);
	digitalWrite(normalRotation,HIGH);
	digitalWrite(backRotation, LOW);
}

void YMotorB()
{
	analogWrite(speedPin, MotorSpeed);
	digitalWrite(normalRotation,HIGH);
	digitalWrite(backRotation, LOW);
}

void setup()
{
	
}

void loop()
{

	while (digitalRead(buttonRight) == LOW && 
    digitalRead(buttonForward)== HIGH  && digitalRead(buttonBackward)== HIGH ) {     
    XMotorF()
               }

	while (digitalRead(buttonLeft) == LOW && 
    digitalRead(buttonForward)== HIGH  && digitalRead(buttonBackward)== HIGH ){     
    XMotorB()
             } 

  
}
