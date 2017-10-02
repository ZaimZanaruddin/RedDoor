/*
   Gratuitous Sets
   Command Console Bootup
   (Incomplete Hardware Test)
   for Red Door Escape Room

   May 30, 2017

*/

const int FrontYellow = 14;
const int BackYellow = 15;
const int Correct_State = 16;
const int RedPin1 = 9;         // This pin (and the next 5) are not used in this version of the test
const int GrnPin1 = 10;        //
const int BluPin1 = 11;        //
const int RedPin2 = 3;         //
const int GrnPin2 = 5;         //
const int BluPin2 = 6;         //
const int ButtonLeds = 2;      // (2) 10mm 3v 20mA LEDs in mounted inside the buttons, ORN+, GRY-, 100ohm
const int ConsoleLeds = 8;     // approx 8' of 12v LEDs controled via TIP41A MOSFET
const int HintLed1 = 12;       // (1) 5mm 3v ??mA LED colored to indicate the correct RGB color, WHT+, GRY-, 330ohm
const int HintLed2 = 13;       // (1) 5mm 3v ??mA LED colored to indicate the correct RGB color, WHT+, GRY-, 330ohm
const int KeyPin = 7;          // signal coming in from the key (or switches on RED) wire is probobly VLT, one to pin and one to GND


boolean OnOffState = false;    // true indicates key is present (or switches are correct) and allows the console to be used
boolean PanelState = false;
boolean CorrectPanelB = false;
boolean CorrectPanelF = false;
int Delay1 = 500;
int Delay2 = 500;
int Delay3 = 25;
int i1 = 0;
int i2 = 0;
int first = 0;

void setup()
{
  Serial.begin(9600);

  pinMode (RedPin1, OUTPUT);
  pinMode (GrnPin1, OUTPUT);
  pinMode (BluPin1, OUTPUT);
  pinMode (RedPin2, OUTPUT);
  pinMode (GrnPin2, OUTPUT);
  pinMode (BluPin2, OUTPUT);
  pinMode (ButtonLeds, OUTPUT);
  pinMode (ConsoleLeds, OUTPUT);
  pinMode (HintLed1, OUTPUT);
  pinMode (HintLed2, OUTPUT);
  pinMode (Correct_State, OUTPUT);
  pinMode (KeyPin, INPUT_PULLUP);
  pinMode (BackYellow, INPUT);
  pinMode (FrontYellow, INPUT);
  digitalWrite(FrontYellow, HIGH);
  digitalWrite(BackYellow, HIGH);
  digitalWrite(Correct_State, LOW);
  
  
}

void loop()
{

 //Checks if Correct Fuel Cells are in 
 if (digitalRead(BackYellow) == LOW && digitalRead(FrontYellow) == LOW)
  {
    panel_startup();
  }  
  


  startup(); // looks for the key to be inserted and executes the bootup sequence
  if(OnOffState == true)
  {
    panelCycle();
  }
  shutdn();  // looks for the key to be removed and shuts down the console
  //Serial.println(OnOffState);
}

//=========Primary Functions=========//

void panel_startup()
{
  if(PanelState == false)
  {
    PanelState = true;
    analogWrite(RedPin1, 255);
    analogWrite(RedPin2, 255);
    analogWrite(GrnPin1, 0);
    analogWrite(GrnPin2, 0);
    analogWrite(BluPin1, 0);
    analogWrite(BluPin2, 0);
  }
}

void startup()
{
  if (OnOffState == false)
  {
    if (digitalRead(KeyPin) == LOW)
    {
      OnOffState = true;
      digitalWrite(ButtonLeds, HIGH);
      delay(Delay1);
      digitalWrite(HintLed1, HIGH);
      digitalWrite(HintLed2, HIGH);
      delay(Delay2);
      for (int i = 0; i <= 6; i++)
      {
        digitalWrite(ConsoleLeds, HIGH);
        delay(Delay3);
        digitalWrite(ConsoleLeds, LOW);
        delay(Delay3);
        digitalWrite(ConsoleLeds, HIGH);
      }
    }
  }
}




void shutdn()
{
  if (OnOffState == true)
  {
    if (digitalRead(KeyPin) == HIGH)
    {
      OnOffState = false;
      digitalWrite(ButtonLeds, LOW);
      digitalWrite(ConsoleLeds, LOW);
      digitalWrite(HintLed1, LOW);
      digitalWrite(HintLed2, LOW);
    }
  }
}



void panelCycle()
{
  
  
  if(digitalRead(BackYellow) == 0 && i1 == 0)
  {
    Serial.println("YES1");
    analogWrite(RedPin1,200);
    analogWrite(GrnPin1,255);
    analogWrite(BluPin1,200);
    delay(100);
    i1++;
    CorrectPanelB = false;
    
  }
  
  if(digitalRead(BackYellow) == 0 && i1 == 1)
  {
    Serial.println("YES2");
    analogWrite(RedPin1,255);
    analogWrite(GrnPin1,0);
    analogWrite(BluPin1,0);
    delay(100);
    i1++;
    CorrectPanelB = false;
    
  }

  if(digitalRead(BackYellow) == 0 && i1 == 2)
  {
    Serial.println("YES3");
    analogWrite(RedPin1,0);
    analogWrite(GrnPin1,50);
    analogWrite(BluPin1,255);
    delay(100);
    i1++;
    CorrectPanelB = false;
    
  }

  if(digitalRead(BackYellow) == 0 && i1 == 3)
  {
    Serial.println("YES4");
    analogWrite(RedPin1,255);
    analogWrite(GrnPin1,150);
    analogWrite(BluPin1,0);
    delay(100);
    i1++;
    CorrectPanelB = false;
    
  }
  
  if(digitalRead(BackYellow) == 0 && i1 == 4)
  {
    Serial.println("YES5");
    analogWrite(RedPin1,200);
    analogWrite(GrnPin1,0);
    analogWrite(BluPin1,200);
    delay(100);
    i1++;
    CorrectPanelB = false;
    
  }

  if(digitalRead(BackYellow) == 0 && i1 == 5)
  {
    Serial.println("YES6");
    analogWrite(RedPin1,0);
    analogWrite(GrnPin1,255);
    analogWrite(BluPin1,0);
    delay(100);
    i1 = 0;
    CorrectPanelB = true;
    
  }

  
  if(digitalRead(FrontYellow) == 0 && i2 == 0)
  {
    Serial.println("YES7");
    analogWrite(RedPin2,200);
    analogWrite(GrnPin2,255);
    analogWrite(BluPin2,200);
    delay(100);
    i2++;
    CorrectPanelF = false;
    
  }
  
  if(digitalRead(FrontYellow) == 0 && i2 == 1)
  {
    Serial.println("YES8");
    analogWrite(RedPin2,255);
    analogWrite(GrnPin2,0);
    analogWrite(BluPin2,0);
    delay(100);
    i2++;
    CorrectPanelF = false;
    
  }

  if(digitalRead(FrontYellow) == 0 && i2 == 2)
  {
    Serial.println("YES9");
    analogWrite(RedPin2,0);
    analogWrite(GrnPin2,50);
    analogWrite(BluPin2,255);
    delay(100);
    i2++;
    CorrectPanelF = false;
    
  }

  if(digitalRead(FrontYellow) == 0 && i2 == 3)
  {
    Serial.println("YES10");
    analogWrite(RedPin2,255);
    analogWrite(GrnPin2,150);
    analogWrite(BluPin2,0);
    delay(100);
    i2++;
    CorrectPanelF = true;
    
  }
  
  if(digitalRead(FrontYellow) == 0 && i2 == 4)
  {
    Serial.println("YES11");
    analogWrite(RedPin2,200);
    analogWrite(GrnPin2,0);
    analogWrite(BluPin2,200);
    delay(100);
    i2++;
    CorrectPanelF = false;
    
  }

  if(digitalRead(FrontYellow) == 0 && i2 == 5)
  {
    Serial.println("YES12");
    analogWrite(RedPin2,0);
    analogWrite(GrnPin2,255);
    analogWrite(BluPin2,0);
    delay(100);
    i2 = 0;
    CorrectPanelF = false;
    
  }

  if(CorrectPanelB == true && CorrectPanelF == true)
  {
    digitalWrite(Correct_State, HIGH);
    
  }

  else
  {
    digitalWrite(Correct_State, LOW);
  }
  
}

//========Secondary Functions========//
void keyCheck()
{
  digitalRead(KeyPin);
}

