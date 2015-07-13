/***********************************************************
File name: 19_ultrasonicDistanceSensor.ino
Description: When you move the ultrasonic distance sensor,
             you will find LCD1602 display distance.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

#include <LiquidCrystal.h>
const int pingPin = 5;  // pin connected to Echo Pin in the ultrasonic distance sensor
const int trigPin  = 7; // pin connected to trig Pin in the ultrasonic distance sensor

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);   
void setup() 
{
   pinMode(pingPin, INPUT); //Set the connection pin output mode Echo pin
   pinMode(trigPin, OUTPUT);//Set the connection pin output mode trog pin
   lcd.begin(16, 2);        //set up the LCD's number of columns and rows: 
   lcd.clear();             //Clears the LCD screen and positions the cursor in the upper-left corner 
   delay(1000);             //delay 1000ms
} 

void loop() 
{ 
   int cm = ping(pingPin) ; 
   lcd.setCursor(0, 0);           // set the cursor to column 0, line 0
    lcd.print("     adeept     ");// Print a message of "Temp: "to the LCD.

    lcd.setCursor(0, 1);          // set the cursor to column 0, line 0
    lcd.print("distance: ");      // Print a message of "Temp: "to the LCD.
    lcd.print(cm);                // Print a centigrade temperature to the LCD. 
    lcd.print(" cm    ");         // Print the unit of the centigrade temperature to the LCD.
   delay(500);
}
     
int ping(int pingPin) 
{ 
   // establish variables for duration of the ping, 
   // and the distance result in inches and centimeters: 
   long duration, cm; 
   // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. 
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
   pinMode(trigPin, OUTPUT); 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, LOW); 

   pinMode(pingPin, INPUT); 
   duration = pulseIn(pingPin, HIGH); 

   // convert the time into a distance 
   cm = microsecondsToCentimeters(duration); 
   return cm ; 
} 

long microsecondsToCentimeters(long microseconds) 
{ 
   // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
   // The ping travels out and back, so to find the distance of the 
   // object we take half of the distance travelled. 
   return microseconds / 29 / 2; 
} 

        
        
        
        
      
