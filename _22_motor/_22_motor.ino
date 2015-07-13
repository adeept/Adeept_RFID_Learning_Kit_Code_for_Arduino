/***********************************************************
File name: 22_motor.ino
Description: The state of DC motor includes its forward, reverse,
             acceleration, deceleration and stop.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/

const int motorIn1 = 11;  //attach to one of the pin of the motor
const int motorIn2 = 10;  //attach to another pin of the motor

int btn1pin=13;           //Set the digital 13 to button interface 
int led1pin=5;            //definition digital 5 pins as pin to control the LED
int btn2pin=12;           //Set the digital 12 to button interface 
int led2pin=4;            //definition digital 4 pins as pin to control the LED
int btn3pin=7;            //Set the digital 7 to button interface 
int led3pin=3;            //definition digital 3 pins as pin to control the LED
int btn4pin=6;            //Set the digital 6 to button interface 
int led4pin=2;            //definition digital 2 pins as pin to control the LED

int state = 0;            //Record the motor state. 0:STOP  1:forward  2:reverse  
int DCmotorspeed = 128;   //Motor speed  0~255

void setup()
{
  pinMode(motorIn1,OUTPUT);     //initialize the motorIn1 pin as output 
  pinMode(motorIn2,OUTPUT);     //initialize the motorIn2 pin as output 
  pinMode(btn1pin,INPUT_PULLUP);//Set digital 13 port mode, the INPUT for the input
  pinMode(led1pin,OUTPUT);      //Set digital 5 port mode, the OUTPUT for the output
  pinMode(btn2pin,INPUT_PULLUP);//Set digital 12 port mode, the INPUT for the input
  pinMode(led2pin,OUTPUT);      //Set digital 4 port mode, the OUTPUT for the output
  pinMode(btn3pin,INPUT_PULLUP);//Set digital 7 port mode, the INPUT for the input
  pinMode(led3pin,OUTPUT);      //Set digital 3 port mode, the OUTPUT for the output
  pinMode(btn4pin,INPUT_PULLUP);//Set digital 6 port mode, the INPUT for the input
  pinMode(led4pin,OUTPUT);      //Set digital 2 port mode, the OUTPUT for the output
}

void loop()
{
  if(digitalRead(btn1pin)==LOW)          //Detection button interface to low
  {   
      delay(10);                         //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btn1pin)==LOW)      //Confirm button is pressed
      {     
        while(digitalRead(btn1pin)==LOW);//Wait for key interfaces to high
        delay(10);                       //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btn1pin)==LOW);//Confirm button release
        for(int i=0;i<4;i++)     
        {
          digitalWrite(led1pin,HIGH); //Output control status LED, ON
          delay(100);                 //delay 100ms
          digitalWrite(led1pin,LOW);  //Output control status LED, OFF
          delay(100);                 //delay 100ms
        }
        if(state!=0)                  //Detecting the motor is running
        {
           state = 0;                 // Motor stop
           digitalWrite(led1pin,LOW); //Output control status LED, OFF
        }
        else
        {   
           state = 1;                 //Motor Run
           digitalWrite(led1pin,HIGH);//Output control status LED, ON
        }  
      }
   }
   
  if(digitalRead(btn2pin)==LOW)          //Detection button interface to low
  {   
      delay(10);                         //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btn2pin)==LOW)      //Confirm button is pressed
      {     
        while(digitalRead(btn2pin)==LOW);//Wait for key interfaces to high
        delay(10);                       //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btn2pin)==LOW);//Confirm button release
        if(state!=0)                     //Detecting the motor is running
        {
           for(int i=0;i<4;i++)
           {
              digitalWrite(led2pin,HIGH);//Output control status LED, ON
              delay(100);                //delay 100ms
              digitalWrite(led2pin,LOW); //Output control status LED, OFF
              delay(100);                //delay 100ms
            }
            if(state==1)                 //Motor forward
            {state = 2;}                 //Motor reverse
            else if(state==2)            //Motor reverse
            {state = 1;}                 //Motor forward
         }    
      }
   }
   
  if(digitalRead(btn3pin)==LOW)          //Detection button interface to low
  {   
      delay(10);                         //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btn3pin)==LOW)      //Confirm button is pressed
      {     
        while(digitalRead(btn3pin)==LOW);//Wait for key interfaces to high
        delay(10);                       //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btn3pin)==LOW);//Confirm button release
        if(state!=0)
        {
            for(int i=0;i<4;i++)
            {
               digitalWrite(led3pin,HIGH);//Output control status LED, ON
               delay(100);                //delay 100ms
               digitalWrite(led3pin,LOW); //Output control status LED, OFF
               delay(100);                //delay 100ms
             }
             if(DCmotorspeed<230)         
             {DCmotorspeed += 20;}       //Motor speed increases 20
             else
             {DCmotorspeed = 230;}       //Motor speed  230
         }
      }
   }
   
   if(digitalRead(btn4pin)==LOW)         //Detection button interface to low
   {   
      delay(10);                         //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btn4pin)==LOW)      //Confirm button is pressed
      {     
        while(digitalRead(btn4pin)==LOW);//Wait for key interfaces to high
        delay(10);                       //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btn4pin)==LOW);//Confirm button release
        if(state!=0)
        {
           for(int i=0;i<4;i++)
           {
              digitalWrite(led4pin,HIGH);//Output control status LED, ON
              delay(100);                //Delay 100ms
              digitalWrite(led4pin,LOW); //Output control status LED, OFF
              delay(100);                //Delay 100ms
            }
            if(DCmotorspeed>30)
            {DCmotorspeed -= 20;}        //Motor speed reduction 20
            else
            {DCmotorspeed = 20;}         //Motor speed 20
        }  
      }
   }
   
  switch(state)
  {
    case 0:  clockwise(0);                  //rotate clockwise 
             break;
    case 1:  clockwise(DCmotorspeed);       //rotate clockwise 
             break;
    case 2:  counterclockwise(DCmotorspeed);//rotate clockwise 
             break;
    default: clockwise(0);                  //rotate clockwise 
             break;
  }
}

//The function to drive motor rotate clockwise
void clockwise(int Speed)
{
  analogWrite(motorIn1,Speed); //set the speed of motor
  analogWrite(motorIn2,0);     //stop the motorIn2 pin of motor
}

//The function to drive motor rotate counterclockwise
void counterclockwise(int Speed)
{
  analogWrite(motorIn1,0);     //stop the motorIn1 pin of motor
  analogWrite(motorIn2,Speed); //set the speed of motor
}

