/***********************************************************
File name: 03_btnAndLed02.ino
Description: Using interrupt mode, every time you press the 
             button, LED status is switched(ON->OFF，OFF->ON).
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

int ledpin=11;            //definition digital 11 pins as pin to control the LED
int btnpin=2;             //Set the digital 2 to button interface 
volatile int state = LOW; //Defined output status LED Interface

void setup()
{                
  pinMode(ledpin, OUTPUT);                  //Set digital 11 port mode, the OUTPUT for the output
  attachInterrupt(0, stateChange, FALLING); //Monitoring Interrupt 0 (Digital PIN 2) changes in the input pins FALLING
}
void loop()                     
{
  digitalWrite(ledpin, state);              //Output control status LED, ON or OFF 
}
void stateChange()                          //Interrupt function
{
  if(digitalRead(btnpin)==LOW)              //Detection button interface to low
  { 
   
      delayMicroseconds(10000);             //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btnpin)==LOW)          //Confirm button is pressed
      {
          state = !state;                   //Negate operation, each time you run the program here, state the HGIH becomes LOW, or the state becomes the LOW HGIH.
      }
   }
}
