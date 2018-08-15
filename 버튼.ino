const int buttonForward = 31;
const int buttonBackward = 33;
const int buttonLeft = 35;
const int buttonRight = 37;

int buttonStateForward = HIGH;  
int buttonStateBackward = HIGH;  
int buttonStateLeft = HIGH;  
int buttonStateRight = HIGH;



void setup()
{
   pinMode(buttonForward, INPUT); 
   pinMode(buttonBackward, INPUT); 
   pinMode(buttonLeft, INPUT); 
   pinMode(buttonRight, INPUT); 

   digitalWrite(buttonForward, INPUT_PULLUP);
   digitalWrite(buttonBackward, INPUT_PULLUP);
   digitalWrite(buttonLeft, INPUT_PULLUP);
   digitalWrite(buttonRight, INPUT_PULLUP);
}

void loop()
{
   buttonStateForward =   digitalRead(buttonForward);
   buttonStateBackward =   digitalRead(buttonBackward);
   buttonStateLeft =       digitalRead(buttonLeft);
   buttonStateRight =     digitalRead(buttonRight);
/*
       while (digitalRead(buttonLeft) == LOW && 
    digitalRead(buttonForward)== HIGH  && digitalRead(buttonBackward)== HIGH ){     
  
      if (second() >= timelimit)
          break;                } //  end the game  without this player can hold directon and 
                                //the loop will skip over the timelimit check      

    while (digitalRead(buttonRight) == LOW && 
    digitalRead(buttonForward)== HIGH  && digitalRead(buttonBackward)== HIGH ) {     
      Xstepper.step(-25);
      if (second() >= timelimit)
          break;               }
    
    */
    digitalWrite(38,LOW); //disables hold (no current supplied to stepper when idle)
    digitalWrite(40,LOW);
    digitalWrite(42,LOW);
    digitalWrite(44,LOW);

  
  //-------Y Axis------------------------------------------
    /*
    while (digitalRead(buttonForward) == LOW 
    && digitalRead(buttonRight) == HIGH && digitalRead(buttonLeft) == HIGH) {     
      Ystepper.step(25);  
      if (second() >= timelimit)
          break;      }

    while (digitalRead(buttonBackward) == LOW
    && digitalRead(buttonRight) == HIGH && digitalRead(buttonLeft) == HIGH ) {     
      Ystepper.step(-25);     
      if (second() >= timelimit)
          break;   }
    */
                         
     digitalWrite(22,LOW); //disables hold (no current supplied to stepper when idle)
     digitalWrite(24,LOW);
     digitalWrite(26,LOW);
     digitalWrite(28,LOW);
}

