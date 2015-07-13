/***********************************************************
File name: 23_joyStick.ino
Description: you can see the joy stick information on the 1602.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);  
int JoyStick_X = 0; //PS2 joystick X-axis is defined, ANALOG IN of Pin0
int JoyStick_Y = 1; //PS2 joystick Y axis is defined, ANALOG IN of Pin1
int JoyStick_Z = 2; //Defined PS2 joystick Z axis,


  void setup(void)
  {
     lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
     lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 
     pinMode(JoyStick_Z, INPUT_PULLUP); //Z axis is defined as an input PS2
  }
   
  void loop(void)
  {
    int x,y,z;
    x=analogRead(JoyStick_X);
    y=analogRead(JoyStick_Y);
    z=digitalRead(JoyStick_Z);
    
    
    lcd.setCursor(0, 0); // set the cursor to column 0, line 0
    lcd.print("adeept joy stick");// Print a message of "Temp: "to the LCD.

    lcd.setCursor(0, 1); // set the cursor to column 0, line 0
    lcd.print("X:");// Print a message of "Temp: "to the LCD.
    lcd.print(x);// Print a centigrade temperature to the LCD.
    lcd.print("   ");// Print a message of "Temp: "to the LCD
    lcd.setCursor(6, 1); // set the cursor to column 0, line 0 
    lcd.print("Y:"); // Print the unit of the centigrade temperature to the LCD.
    lcd.print(y);// Print a centigrade temperature to the LCD
    lcd.print("   ");// Print a message of "Temp: "to the LCD
    lcd.setCursor(13, 1); // set the cursor to column 0, line 0 
    lcd.print("Z:"); // Print the unit of the centigrade temperature to the LCD.
    lcd.print(z);// Print a centigrade temperature to the LCD
    delay(500);
  }
