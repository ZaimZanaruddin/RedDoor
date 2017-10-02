/*
 * Red Door Escape Room
 * 
 * Communication arduino
 * 
 * August 1, 2017
 */

#include <Button.h>

Button RedBtnL = Button ( 10, true, true, 25);
Button RedBtnR = Button ( 11, true, true, 25);
Button BluBtnL = Button ( 8, true, true, 25);
Button BluBtnR = Button ( 9, true, true, 25);
Button YlwBtnL = Button ( 13, true, true, 25);
Button YlwBtnR = Button ( 12, true, true, 25);

const int PowerReactor1 = 15;
const int PowerReactor2 = 16;

const int BackRed = 2;
const int FrontRed = 3;
const int RedCheck = 4;
const int FrontBlue = 28;
const int BackBlue = 30;
const int BlueCheck = 32;

const int FrontYellow = 19;
const int BackYellow = 18;
const int YellowCheck = 20;

const int DoorMag = 14;

int PowerReactorOn = 1;



int i = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(PowerReactor1, INPUT);
  pinMode(PowerReactor2, INPUT);
  pinMode(BackRed, OUTPUT);
  pinMode(FrontRed, OUTPUT);
  pinMode(BackBlue, OUTPUT);
  pinMode(FrontBlue, OUTPUT);
  pinMode(BackYellow, OUTPUT);
  pinMode(FrontYellow, OUTPUT);
  pinMode(RedCheck, INPUT);
  pinMode(BlueCheck, INPUT);
  pinMode(YellowCheck, INPUT);
  pinMode(DoorMag, OUTPUT);
  digitalWrite(DoorMag, LOW);
  
  digitalWrite(BackBlue, INPUT_PULLUP);
  digitalWrite(FrontBlue, INPUT_PULLUP);
  digitalWrite(BackRed, INPUT_PULLUP);
  digitalWrite(FrontRed, INPUT_PULLUP);
  
  digitalWrite(BackYellow, INPUT_PULLUP);
  digitalWrite(FrontYellow, INPUT_PULLUP);
 

}

void loop() 
{
  
  if(digitalRead(PowerReactor1) == 1 && digitalRead(PowerReactor2) == 1)
  {
    PowerReactorOn++;
    if(PowerReactorOn == 50)
    {
      delay(1000);
      
    digitalWrite(FrontRed, LOW);
    delay(1000);
    digitalWrite(FrontRed, HIGH);
    delay(500);
    digitalWrite(BackRed, LOW);
    delay(500);
    digitalWrite(BackRed, HIGH);
    delay(500);
    digitalWrite(FrontBlue, LOW);
    delay(500);
    digitalWrite(FrontBlue, HIGH);
    delay(500);
    digitalWrite(BackBlue, LOW);
    delay(500);
    digitalWrite(BackBlue, HIGH);
    delay(500);
    digitalWrite(FrontYellow, LOW);
    delay(500);
    digitalWrite(FrontYellow, HIGH);
    delay(500);
    digitalWrite(BackYellow, LOW);
    delay(500);
    digitalWrite(BackYellow, HIGH);
    delay(500);
    }
    
    RedBtnL.read();
    RedBtnR.read();
    BluBtnL.read();
    BluBtnR.read();
    YlwBtnL.read();
    YlwBtnR.read();
  
    
    
    if(RedBtnL.wasReleased() == true)
    {
      digitalWrite(FrontRed, LOW);
      digitalWrite(FrontBlue, LOW);
      digitalWrite(FrontYellow, LOW);
      delay(25);
      digitalWrite(FrontRed, HIGH);
      digitalWrite(FrontBlue, HIGH);
      digitalWrite(FrontYellow, HIGH);
      delay(100);
      digitalWrite(BackRed, LOW);
      digitalWrite(BackBlue, LOW);
      digitalWrite(BackYellow, LOW);
      delay(25);
      digitalWrite(BackRed, HIGH);
      digitalWrite(BackBlue, HIGH);
      digitalWrite(BackYellow, HIGH);
      delay(100);
      
      
      
      
    }
    
    if(BluBtnL.wasReleased() == true)
    {
      digitalWrite(FrontBlue, LOW);
      digitalWrite(FrontYellow, LOW);
      delay(25);
      digitalWrite(FrontBlue, HIGH);
      digitalWrite(FrontYellow, HIGH);
      delay(100);
      digitalWrite(BackRed, LOW);
      digitalWrite(BackBlue, LOW);
      digitalWrite(BackYellow, LOW);
      delay(25);
      digitalWrite(BackRed, HIGH);
      digitalWrite(BackBlue, HIGH);
      digitalWrite(BackYellow, HIGH);
      delay(100);
    }
  
    
    if(YlwBtnR.wasReleased() == true)
    {
      digitalWrite(FrontYellow, LOW);
      delay(25);
      digitalWrite(FrontYellow, HIGH);
      delay(100);
      digitalWrite(BackRed, LOW);
      digitalWrite(BackBlue, LOW);
      digitalWrite(BackYellow, LOW);
      delay(25);
      digitalWrite(BackRed, HIGH);
      digitalWrite(BackBlue, HIGH);
      digitalWrite(BackYellow, HIGH);
      delay(100);
    }
  
    
    if(RedBtnR.wasReleased() == true)
    {
      digitalWrite(FrontYellow, LOW);
      delay(25);
      digitalWrite(FrontYellow, HIGH);
      delay(100);
      digitalWrite(BackRed, LOW);
      digitalWrite(BackBlue, LOW);
      delay(25);
      digitalWrite(BackRed, HIGH);
      digitalWrite(BackBlue, HIGH);
      delay(100);
    }
  
    
    if(YlwBtnL.wasReleased() == true)
    {
      digitalWrite(FrontYellow, LOW);
      delay(25);
      digitalWrite(FrontYellow, HIGH);
      delay(100);
      digitalWrite(BackBlue, LOW);
      delay(25);
      digitalWrite(BackBlue, HIGH);
      delay(100);
    }
  
    
    if(BluBtnR.wasReleased() == true)
    {
      
      digitalWrite(BackBlue, LOW);
      delay(25);
      digitalWrite(BackBlue, HIGH);
      delay(100);
    }
   
    if(digitalRead(BlueCheck) == HIGH && digitalRead(RedCheck) == HIGH && digitalRead(YellowCheck) == HIGH)
    {
      digitalWrite(DoorMag, HIGH);
    }
    
    else
    {
      digitalWrite(DoorMag, LOW);
    }

  }

}


void button1()
{
  digitalWrite(BackBlue, LOW);
  delay(100);
  
  digitalWrite(BackBlue, HIGH);

  
}

void button2()
{
  digitalWrite(FrontYellow, LOW);
  delay(100);
  digitalWrite(FrontYellow, HIGH);
  

}



void button3()
{
  digitalWrite(BackRed, LOW);
  delay(100);
  
  digitalWrite(BackRed, HIGH);
}

void button4()
{
  digitalWrite(BackYellow, LOW);
  delay(100);
  
  digitalWrite(BackYellow, HIGH);
}

void button5()
{
  digitalWrite(FrontBlue, LOW);
  delay(100);
  
  digitalWrite(FrontBlue, HIGH);
}

void button6()
{
  digitalWrite(BackRed, LOW);
  delay(100);
  
  digitalWrite(BackRed, HIGH);
}


