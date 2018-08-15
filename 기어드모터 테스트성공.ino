
#include <Servo.h>
#define XspeedPin 6
#define XnormalRotation 7
#define XbackRotation 8

#define YspeedPin 3
#define YnormalRotation 4
#define YbackRotation 5

const int buttonCoin = 45;
const int buttonStart = 47;


int MotorSpeed = 250;  // default speed and hold variable

int joystick_x = A0;    
int joystick_y = A1;
int joystick_z = 2;    

void setup()
{
 pinMode(XbackRotation, OUTPUT);
 pinMode(XnormalRotation, OUTPUT);
 pinMode(XspeedPin, OUTPUT);
 pinMode(joystick_z,INPUT_PULLUP);    
 Serial.begin(9600);              
}

void loop()
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
                                

 if (buttonStateCoin == HIGH)                 
   {           
       buttonStateStart = digitalRead(buttonStart); 
    } 
while (buttonStateStart == HIGH);               
       runGame();                                      

} 

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
	analogWrite(YspeedPin, MotorSpeed);
	digitalWrite(YnormalRotation,HIGH);
	digitalWrite(YbackRotation, LOW);
}

void YMotorB()
{
	analogWrite(YspeedPin, MotorSpeed);
	digitalWrite(YnormalRotation,HIGH);
	digitalWrite(YbackRotation, LOW);
}

void runGame()
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

