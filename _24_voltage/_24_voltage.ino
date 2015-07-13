/***********************************************************
File name: 24_voltage.ino
Description: Now, when you turning the shaft of the potentiometer,
             you will see the voltage displayed on the LCD1602 
             will be changed.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

#include <LiquidCrystal.h>

char array1[]="Adeept Voltmeter                  ";  //the string to print on the LCD
char array2[]=" Voltage: 0.00V                   ";  //the string to print on the LCD

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
int photoresistorPin = 0;  // potentiometer wiper (middle terminal) connected to analog pin 3
int val=0;
int tim = 50;              //the value of delay time

void setup()
{
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
  lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 
  lcd.setCursor(0,0);  // set the cursor to column 15, line 0
  for (int positionCounter1 = 0; positionCounter1 < 16; positionCounter1++)
  {
      lcd.print(array1[positionCounter1]);  // Print a message to the LCD.
      delay(tim);      //wait for 250 microseconds
  }
}

void loop() 
{
   val = analogRead(photoresistorPin)*(5.0 / 1023.0)*100;//Data collection
   array2[10]  = val/100%10+0x30;//Take one hundred - bit data
   array2[12] = val/10%10+0x30;  //Take ten-bit data
   array2[13] = val%10+0x30;     //Take a bit of data
   lcd.setCursor(0,1);           //Set the cursor to column 15, line 1
   for (int positionCounter3 = 0; positionCounter3 < 26; positionCounter3++)
   {
     lcd.print(array2[positionCounter3]);  // Print a message to the LCD.
     delay(tim);                 //Wait for 250 microseconds
   }
}
