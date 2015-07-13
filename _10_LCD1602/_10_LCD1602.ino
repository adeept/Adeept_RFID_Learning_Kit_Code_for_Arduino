/***********************************************************
File name: 10_LCD1602.ino
Description: LCD1602 display a string "Hello Geeks!" scrolling，
             then display “Adeept” and “www.adeept.com” static.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

#include <LiquidCrystal.h>

char array1[]="     Adeept     ";                //the string to print on the LCD
char array2[]="  hello geeks!                ";  //the string to print on the LCD
char array3[]=" www.adeept.com ";                //the string to print on the LCD

int tim = 250;  //the value of delay time

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup()
{
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 
}

void loop() 
{
    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner
    lcd.setCursor(15,0);                   // set the cursor to column 15, line 1
    for (int positionCounter2 = 0; positionCounter2 < 30; positionCounter2++)
    {
      lcd.scrollDisplayLeft();             //Scrolls the contents of the display one space to the left.
      lcd.print(array2[positionCounter2]); // Print a message to the LCD.
      delay(tim);                          //wait for 250 microseconds
    }

    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.   
    
    lcd.setCursor(0,0);                    // set the cursor to column 15, line 0
    for (int positionCounter1 = 0; positionCounter1 < 16; positionCounter1++)
    {
      lcd.print(array1[positionCounter1]); // Print a message to the LCD.
      delay(tim);                          //wait for 250 microseconds
    }
    
    lcd.setCursor(0,1);                    // set the cursor to column 15, line 1
    for (int positionCounter3 = 0; positionCounter3 < 16; positionCounter3++)
    {
      lcd.print(array3[positionCounter3]); // Print a message to the LCD.
      delay(tim);                          //wait for 250 microseconds
    }
}
