/***********************************************************
File name: 18_DHT11.ino
Description: you can see the temperature and humidity data
             displayed on the LCD1602.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
 
#include <dht11.h>
#include <LiquidCrystal.h>
 
dht11 DHT11;
#define DHT11PIN 2
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);    
void setup()
{ 
     lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
     lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 
     delay(1000); //delay 1000ms
}
 
void loop()
{
    int chk = DHT11.read(DHT11PIN);
    lcd.setCursor(0, 0); // set the cursor to column 0, line 0
    lcd.print("Humidity:");// Print a message of "Humidity: "to the LCD.
    lcd.print((float)DHT11.humidity, 2);// Print a message of "Humidity: "to the LCD.
    lcd.print(" % "); // Print the unit of the centigrade temperature to the LCD.
    
    lcd.setCursor(0, 1); // set the cursor to column 0, line 0
    lcd.print("Temp:    ");// Print a message of "Temp: "to the LCD.
    lcd.print((float)DHT11.temperature, 2);// Print a centigrade temperature to the LCD. 
    lcd.print(" C "); // Print the unit of the centigrade temperature to the LCD.
    delay(1000);     
}
