/***********************************************************
File name: 06_LEDBarGraph.ino
Description: When you turn the potentiometer you will see
             LED bar graph display changing.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
int pin1 = 1;
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
int pin9 = 9;
int pin10 = 10;           //definition digital 10 pins as pin to control the LED

int potentiometerPin = 0; // potentiometer connected to analog pin 3

void setup()
{
  pinMode(pin1,OUTPUT);    //Set the digital 1 port mode, OUTPUT: Output mode
  pinMode(pin2,OUTPUT);    //Set the digital 2 port mode, OUTPUT: Output mode
  pinMode(pin3,OUTPUT);    //Set the digital 3 port mode, OUTPUT: Output mode
  pinMode(pin4,OUTPUT);    //Set the digital 4 port mode, OUTPUT: Output mode
  pinMode(pin5,OUTPUT);    //Set the digital 5 port mode, OUTPUT: Output mode
  pinMode(pin6,OUTPUT);    //Set the digital 6 port mode, OUTPUT: Output mode
  pinMode(pin7,OUTPUT);    //Set the digital 7 port mode, OUTPUT: Output mode
  pinMode(pin8,OUTPUT);    //Set the digital 8 port mode, OUTPUT: Output mode
  pinMode(pin9,OUTPUT);    //Set the digital 9 port mode, OUTPUT: Output mode
  pinMode(pin10,OUTPUT);    //Set the digital 10 port mode, OUTPUT: Output mode
}

void loop() 
{
   float a = analogRead(potentiometerPin);//Read the voltage photoresistance
   a = map(a,0,1023,0,11);    //Photoresistor voltage value converted from 0-1023 to 0-11
   for(int i=1;i<=a;i++){
      digitalWrite(i,LOW);    //HIGH is set to about 5V PIN8
   }
   for(int j=10;j>a;j--){
      digitalWrite(j,HIGH);   //HIGH is set to about 5V PIN8
   }   
   delay(50);                 //delay 50ms
}
