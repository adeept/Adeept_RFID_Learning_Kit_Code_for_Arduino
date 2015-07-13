/***********************************************************
File name: 05_flowingLed.ino
Description: LED turn lighting control
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

void setup()
{ 
  unsigned char ledPin;           //ledPin will be set to 1,2,3,4,5,6, 7 and 8.
  for(ledPin=1;ledPin<=8;ledPin++)//In turn set 1 ~ 8 digital pins to output mode 
  pinMode(ledPin,OUTPUT);         //Set the  ledPin pin to output mode 
}

void loop()
{   
  unsigned char ledPin;           //ledPin will be set to 1,2,3,4,5,6, 7 and 8.
  for(ledPin=1;ledPin<=8;ledPin++)//Every 200ms on in order LED1 ~ 8 
  {
    digitalWrite(ledPin,HIGH);    //led on
    delay(200);                   //Delay 200 ms
  }
  for(ledPin=1;ledPin<=8;ledPin++)//Every 200ms off in order LED1 ~ 8 
  {
    digitalWrite(ledPin,LOW);     //led off
    delay(200);                   //Delay 200 ms
  } 
}
