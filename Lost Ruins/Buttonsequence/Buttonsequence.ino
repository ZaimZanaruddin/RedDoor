#include <Button.h>


// Tree, Seed, Star, Moon

Button button1 = Button(9, true, true, 25); // Leaf
Button button2 = Button(2, true, true, 25); // Seed
Button button3 = Button(3, true, true, 25); // Moon
Button button4 = Button(4, true, true, 25); // Sun
Button button5 = Button(5, true, true, 25); // Cloud
Button button6 = Button(6, true, true, 25); // Star
Button button7 = Button(7, true, true, 25); // Flower
Button button8 = Button(8, true, true, 25); // Tree




void setup() {
  pinMode(1, INPUT);
  digitalWrite(1, HIGH);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(12, INPUT);
  digitalWrite(12, HIGH);
  pinMode(11, INPUT);
  digitalWrite(11, HIGH);

  Serial.begin(9600);

}

void loop() {
  int i = 0;
  digitalWrite(13, LOW);
  button1.read();
  button2.read();
  button3.read();
  button4.read();
  button5.read();
  button6.read();
  button7.read();
  button8.read();
  
  while(digitalRead(12) == LOW || digitalRead(11) == LOW)
  {
    digitalWrite(13, HIGH);
  }
  if(button8.wasReleased() == true)
  {
    Serial.println("test");
    while(i == 0)
    {
        digitalWrite(13, LOW);
        button1.read();
        button2.read();
        button3.read();
        button4.read();
        button5.read();
        button6.read();
        button7.read();
        button8.read();
        Serial.print("1:");
        
  

    while(digitalRead(12) == LOW || digitalRead(11) == LOW)
  {
    digitalWrite(13, HIGH);
  }
        
      Serial.println("Enter while loop1");
    
      if(button2.wasReleased() == true)
      {
        Serial.println("test2");
        i = 1;
        while(i == 1)
        {
          button1.read();
          button2.read();
          button3.read();
          button4.read();
          button5.read();
          button6.read();
          button7.read();
          button8.read();
          Serial.println("Enter while loop2");
          while(digitalRead(12) == LOW || digitalRead(11) == LOW)
          {
            digitalWrite(13, HIGH);
          }
          if(button6.wasReleased() == true)
          {
            i = 2;
            while( i == 2)
            {
              button1.read();
              button2.read();
              button3.read();
              button4.read();
              button5.read();
              button6.read();
              button7.read();
              button8.read();
              Serial.println("Enter while loop3");
              while(digitalRead(12) == LOW || digitalRead(11) == LOW)
              {
                digitalWrite(13, HIGH);
              }
              if(button3.wasReleased() == true)
              {
                Serial.println("Complete");
                digitalWrite(13,HIGH);
                delay(3000);
                digitalWrite(13, LOW);
                return;
                
                
                i = -1;
              }
              if(button8.wasReleased() == true)
              {
                i = 0;
                
              }
              if(button1.wasReleased() == true || button2.wasReleased() == true || button4.wasReleased() == true || button5.wasReleased() == true || button6.wasReleased() == true || button7.wasReleased() == true)
              {
                i = -1;
                
              }
            }
            
            
          }
          if(button8.wasReleased() == true)
          {
            i = 0;
          }
          if(button1.wasReleased() == true || button2.wasReleased() == true || button3.wasReleased() == true || button4.wasReleased() == true || button5.wasReleased() == true || button7.wasReleased() == true)
          {
            i = -1;
          }
          
        }
      }
      
      
      if( button1.wasReleased() == true || button3.wasReleased() == true || button4.wasReleased() == true || button5.wasReleased() == true || button6.wasReleased() == true || button7.wasReleased() == true)
      {
        i = -1;
      }
      
  
    }
    
  }

  

}


