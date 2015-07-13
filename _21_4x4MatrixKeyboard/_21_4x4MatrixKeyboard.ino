/***********************************************************
File name: 21_4x4MatrixKeyboard.ino
Description: when you click the button on the 4x4 matrix 
             keyboard, you can see the serial monitor data.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
#include <Keypad.h>
 
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
 
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
 
void setup(){
  Serial.begin(9600);//Open serial
}
   
void loop(){
  char customKey = customKeypad.getKey();//Read Key data   
  if (customKey){
    Serial.println(customKey);          //send the key data by serial port (UART)
  }
}
