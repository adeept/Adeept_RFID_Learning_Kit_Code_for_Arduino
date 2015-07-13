/***********************************************************
File name: 16_thermistor.ino
Description: The information which a thermistor collects 
             temperature is displayed on the LCD1602.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

#include <LiquidCrystal.h>

int tim = 50;                       //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
int thermistorPin = 0;           // thermistor connected to analog pin 3

void setup()
{
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
  lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 
}

void loop() 
{
   float a = analogRead(thermistorPin);
  //the calculating formula of temperature
  float resistor = (1023.0*10000)/a-10000;
  float tempC = (3435.0/(log(resistor/10000)+(3435.0/(273.15+25)))) - 273.15;
  
  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print("     adeept     ");// Print a message of "Temp: "to the LCD.
 
  lcd.setCursor(0, 1); // set the cursor to column 0, line 0
  lcd.print("  Temp: ");// Print a message of "Temp: "to the LCD.
  lcd.print(tempC);// Print a centigrade temperature to the LCD. 
  lcd.print(" C  "); // Print the unit of the centigrade temperature to the LCD.
  delay(500);
}
