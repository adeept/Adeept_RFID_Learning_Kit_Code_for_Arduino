/***********************************************************
File name: 20_ADXL345.ino
Description: you can see the acceleration data which ADXL345 
             collected displayed on the LCD1602.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

#include <Wire.h>        //arduino IDE contains I2C library
#include <LiquidCrystal.h>   

#define Register_ID 0    //Address defined ADXL345 register
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37
                    
#define Reg_OFSX 0x1E     //ADXL345 correct register address definitions
#define Reg_OFSY 0x1F
#define Reg_OFSZ 0x20
#define Reg_PWR_CTL 0x2D

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);  
int ADXAddress = 0xA7>>1;  //Converted to 7 address
int reading = 0;
int val = 0;
int X0,X1,X_out;
int Y0,Y1,Y_out;
int Z1,Z0,Z_out;
double Xg,Yg,Zg;

void setup()
{
   lcd.begin(16, 2);       // set up the LCD's number of columns and rows: 
   lcd.clear();            //Clears the LCD screen and positions the cursor in the upper-left corner 
   delay(100);
   Wire.begin();           //Initializes I2C
   setAccReg(0x31,0x0B);   //Measuring range, plus or minus 16g, 13 bit pattern
   setAccReg(0x2C,0x08);   //Reference rate is set to 12.5 Page pdf13
   setAccReg(0x2D,0x08);   //Select Power Mode Reference pdf24 page
   setAccReg(0x2E,0x80);   //Interrupt Enable DATA_READY
   setAccReg(0x1E,0x00);   //X Offset pdf29 page written test based on the state of the sensor
   setAccReg(0x1F,0x00);   //Y offset pdf29 page written test based on the state of the sensor
   setAccReg(0x20,0x05);   //Z offset pdf29 page written test based on the state of the sensor
   delay(100);
   Wire.beginTransmission(ADXAddress);
   Wire.write(Register_2D);
   Wire.write(8);
   Wire.endTransmission();
   delay(500);
}

void loop()
{
  Wire.beginTransmission(ADXAddress);//Read X-axis data
  Wire.write(Register_X0);
  Wire.write(Register_X1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2)
  {
    X0 = Wire.read();
    X1 = Wire.read();
    X1 = X1<<8;
    X_out = X0+X1;
  }
  Wire.beginTransmission(ADXAddress);//Read y-axis data
  Wire.write(Register_Y0);
  Wire.write(Register_Y1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2)
  {
    Y0 = Wire.read();
    Y1 = Wire.read();
    Y1 = Y1<<8;
    Y_out = Y0+Y1;
  }
  Wire.beginTransmission(ADXAddress);//Read z-axis data
  Wire.write(Register_Z0);
  Wire.write(Register_Z1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2)
  {
    Z0 = Wire.read();
    Z1 = Wire.read();
    Z1 = Z1<<8;
    Z_out = Z0+Z1;
  }

  Xg = X_out/256.00;   //The output is converted to gravitational acceleration g, 2 decimal places later.
  Yg = Y_out/256.00;
  Zg = Z_out/256.00;
  lcd.clear();         //Clear screen
  lcd.setCursor(0, 0); //set the cursor to column 0, line 0
  lcd.print("Adeept  X="); //So that the display text 'Adeept  X ='
  lcd.print(Xg);
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print("Y=");
  lcd.print(Yg);
  lcd.setCursor(8, 1); // set the cursor to column 8, line 1
  lcd.print("Z=");
  lcd.print(Zg);
  delay(300);          //Delay 0.3 seconds, the refresh rate is adjusted here
}

void setAccReg(int reg,byte value){
    setReg(ADXAddress,reg,value);    //ADXAddress = 0xA7>>1
}

void setReg(int device,int reg,byte value){
    Wire.beginTransmission(device);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}
