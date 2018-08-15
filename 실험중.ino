
#include <Servo.h>
#define XspeedPin 6
#define XnormalRotation 7
#define XbackRotation 8

#define YspeedPin 3
#define YnormalRotation 4
#define YbackRotation 5

#define ZspeedPin 10
#define ZnormalRotation 11
#define ZbackRotation 12

const int buttonCoin = 45;
const int buttonStart = 47;


int motorSpeed = 250;  // default speed and hold variable

int joystick_x = A0;    
int joystick_y = A1;
int joystick_z = 2;    
int buttonStateCoin = HIGH;
int buttonStateStart = HIGH;
int servoPower = 9; 
Servo myservo; 

void XMotorF()
{
	analogWrite(XspeedPin, motorSpeed);
	digitalWrite(XnormalRotation,HIGH);
	digitalWrite(XbackRotation, LOW);
	Serial.println("  X Forward");
}

void XMotorB()
{
	analogWrite(XspeedPin, motorSpeed);
	digitalWrite(XbackRotation,HIGH);
	digitalWrite(XnormalRotation, LOW);
	Serial.println("  X Backward");
}


void XMotorOff()
{
	analogWrite(XspeedPin, 0);
	digitalWrite(XbackRotation,LOW);
	digitalWrite(XnormalRotation, LOW);
	Serial.println("  X Stop");
}

void YMotorF()
{
	analogWrite(YspeedPin, motorSpeed);
	digitalWrite(YnormalRotation,HIGH);
	digitalWrite(YbackRotation, LOW);
}

void YMotorB()
{
	analogWrite(YspeedPin, motorSpeed);
	digitalWrite(YnormalRotation,LOW);
	digitalWrite(YbackRotation, HIGH);
}
void YMotorOff()
{
	analogWrite(YspeedPin, 0);
	digitalWrite(YbackRotation,LOW);
	digitalWrite(YnormalRotation, LOW);
	Serial.println("  Y Stop");
}

void ZmotorDown()
{	
	analogWrite(ZspeedPin, motorSpeed);
	digitalWrite(ZnormalRotation,HIGH);
	digitalWrite(ZbackRotation, LOW);

	delay(4000);

	analogWrite(ZspeedPin, 0);
	digitalWrite(ZnormalRotation,LOW);
	digitalWrite(ZbackRotation, LOW);
}

void grab()
{
	for(int val=145; val>45; val--)
	{
	myservo.write(val);
	delay(15);
	}
}

void backHome()
{
	analogWrite(ZspeedPin, motorSpeed);
	digitalWrite(ZnormalRotation,LOW);
	digitalWrite(ZbackRotation, HIGH);

	delay(4000);

	analogWrite(ZspeedPin, 0);
	digitalWrite(ZnormalRotation,LOW);
	digitalWrite(ZbackRotation, LOW);

	delay(100);

	analogWrite(YspeedPin, motorSpeed);
	digitalWrite(YnormalRotation,LOW);
	digitalWrite(YbackRotation, HIGH);

	delay(4000);

	analogWrite(YspeedPin, 0);
	digitalWrite(YnormalRotation,LOW);
	digitalWrite(YbackRotation, LOW);

	delay(100);

	analogWrite(XspeedPin, motorSpeed);
	digitalWrite(XbackRotation,LOW);
	digitalWrite(XnormalRotation, HIGH);

	delay(4000);

	analogWrite(XspeedPin, 0);
	digitalWrite(XbackRotation,LOW);
	digitalWrite(XnormalRotation, LOW);

	delay(100);

	for(int val=45; val<145; val++)
	{
	myservo.write(val);
	delay(15);
	}

	
}

void runGame()
{
	int x = analogRead(joystick_x);      
	int y = analogRead(joystick_y);      
	int z = digitalRead(joystick_z);    
 	Serial.print("X: ");                   
 	Serial.print(x);                          
 	Serial.print("  Y: ");
 	Serial.print(y);                          
 	Serial.print("  Z: ");
 	Serial.print(z); 

 	digitalWrite(servoPower, HIGH);     
while(z==1)
{
	if(x>600)
	{
		XMotorF();
 	}
 	else if(x<450)
	{
		XMotorB();
 	}
	 else
 	{
 		XMotorOff();
	}

	delay(100);

	 if(y>600)
 	{
		YMotorF();
 	}
 	else if(y<450)
 	{
		YMotorB();
 	}
 	else
 	{
 		YMotorOff();
 	}

 }
 	
 	delay(300);
 	ZmotorDown();
 	delay(300);
 	grab();
 	delay(300);
 	
}


void setup()
{
 pinMode(XbackRotation, OUTPUT);
 pinMode(XnormalRotation, OUTPUT);
 pinMode(XspeedPin, OUTPUT);
 pinMode(joystick_z,INPUT_PULLUP); 
 pinMode(buttonCoin, INPUT);
 pinMode(buttonStart, INPUT);

 digitalWrite(buttonCoin, INPUT_PULLUP);
 digitalWrite(buttonStart, INPUT_PULLUP);   
 digitalWrite(servoPower, LOW);

 myservo.attach(9);
 Serial.begin(9600);              
}

void loop()
{
	/*
	buttonStateCoin =  digitalRead(buttonCoin);                                                 

 if (buttonStateCoin == LOW)                 
   {           
       buttonStateStart = digitalRead(buttonStart); 
    } 
while (buttonStateStart == LOW);
	*/               
       runGame(); 

       	int x = analogRead(joystick_x);      
	int y = analogRead(joystick_y);      
	int z = digitalRead(joystick_z); 

  Serial.print("X: ");                   
  Serial.print(x);                          
  Serial.print("  Y: ");
  Serial.print(y);                          
  Serial.print("  Z: ");
  Serial.print(z);                                          

} 





