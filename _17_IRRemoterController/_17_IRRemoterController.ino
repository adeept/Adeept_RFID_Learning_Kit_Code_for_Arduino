/***********************************************************
File name: 17_IRRemoterController.ino
Description: When you click the button on the remote control,
             you can see the serial montiol data.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
#include <IRremote.h>

int RECV_PIN = 11;//The definition of the infrared receiver pin 11
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600); //Open serial 
  irrecv.enableIRIn(); // Initialization infrared receiver
} 

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);//Wrap output in hex receive code
    Serial.println();//For ease of viewing the output to add a blank line
    irrecv.resume(); //Receiving the next value
  }
}


