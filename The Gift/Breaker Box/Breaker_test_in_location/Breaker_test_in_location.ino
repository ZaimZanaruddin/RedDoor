int cir1 = 17;
int cir2 = 2;
int cir3 = 3;
int cir4 = 4;
int cir6 = 6;
int cir7 = 7;
int cir8 = 8;
int cir9 = 9;
int cir10 = 10; 
int cir11 = 11;
int cir13 = 13;
int cir14 = 14;
int cir16 = 16;


int greenLED=22;
int blackLight = 31;


void setup() {
  pinMode(cir1, INPUT_PULLUP);
  pinMode(cir2, INPUT_PULLUP);
  pinMode(cir3, INPUT_PULLUP);
  pinMode(cir4, INPUT_PULLUP);
  pinMode(cir6, INPUT_PULLUP);
  pinMode(cir7, INPUT_PULLUP);
  pinMode(cir8, INPUT_PULLUP);
  pinMode(cir9, INPUT_PULLUP);
  pinMode(cir10, INPUT_PULLUP); 
  pinMode(cir11, INPUT_PULLUP);
  pinMode(cir13, INPUT_PULLUP);
  pinMode(cir14, INPUT_PULLUP);
  pinMode(cir16, INPUT_PULLUP);     
  pinMode(greenLED,OUTPUT);
  pinMode(blackLight, OUTPUT);
  
  Serial.begin(9600);


}


void loop() {
 
  
  boolean test1 = false;
  boolean test2 = false;
  boolean test3 = false;
  boolean test4 = false;
  boolean test5 = false;
  boolean test6 = false;
  boolean test7 = false;
  boolean test8 = false;
  boolean test9 = false;
  boolean test10 = false;
  boolean test11 = false;
  boolean test12 = false;
  boolean test13 = false;
  
  if(digitalRead(cir1) == 1)
  {
    
   
    test1 = true;
    
  }


  if(digitalRead(cir2) == 0)
  {


   
    test2 = true;
    
  }


  if(digitalRead(cir3) == 0)
  {


    test3 = true;
    
  }


  if(digitalRead(cir4) == 1)
  {


    
    test4 = true;
    
  }


  if(digitalRead(cir6) == 1)
  {


    test5 = true;
    
  }


  if(digitalRead(cir7) == 0)
  {


    test6 = true;
    
  }


  if(digitalRead(cir8) == 0)
  {
 
    test7 = true;
    
  }


  if(digitalRead(cir9) == 1)
  {
 
    test8 = true;
    
  }


  if(digitalRead(cir10) == 1)
  {


    test9 = true;
    
  }


  if(digitalRead(cir11) == 0)
  {


    test10 = true;
    
  }


  if(digitalRead(cir13) == 1)
  {


    test11 = true;
    
  }


  if(digitalRead(cir14) == 0)
  {
 
    test12 = true;
    
  }


  if(digitalRead(cir16) == 1)
  {
 
    test13 = true;
    
  }


  if(test1 == true && test2 == true && test3 == true && test4 == true && test5 == true && test6 == true && test7 == true && test8 == true && test9 == true && test10 == true && test11 == true && test12 == true && test13 == true)
 {
  Serial.println("Yes");
  digitalWrite(greenLED, HIGH);
  digitalWrite(blackLight, LOW);
 }


 else
 {
  digitalWrite(greenLED, LOW);
  digitalWrite(blackLight, HIGH);
 }




   
}

