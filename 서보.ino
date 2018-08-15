

#include <Servo.h>



int servoPower = 9; 
Servo myservo;  // create servo object to control a servo 
int val;



void setup()
{
	pinMode(servoPower, OUTPUT);
	digitalWrite(servoPower, LOW);
	 myservo.attach(9);

	 	for(int val=145; val>45; val--)
	{
	myservo.write(val);
	delay(15);
	}
}

void loop()
{
	/*
	for(int val=20; val<=130; val++)
	{
	myservo.write(val);
	delay(15);
	}
	*/
}

