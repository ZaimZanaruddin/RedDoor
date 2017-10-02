



int button1 = 3;
int light1  = 6;
int button2 = 2;
int light2  = 5;
int button3 = 4;
int light3  = 7;
int relay = 9;
unsigned long previousMillis = 0;
const long interval = 30000;

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
asm volatile ("  jmp 0");  
} 
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
  pinMode(4, INPUT);
  digitalWrite(4, HIGH);

  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  int pressed = 0;
  int yellow = 0;
  int green = 0;
  int red = 0;
  Serial.print("Reset");
  
  
  while(i < 18)
  {
    unsigned long currentMillis = millis();
    
    if(i >= 1 && currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;
      Serial.print("Reset");
      software_Reset();
      
    }
  

    
    while(digitalRead(button1) == 0)
  {

    
    digitalWrite(light1,HIGH);
    if(pressed == 0)
    {
      i++;
      yellow++;
      pressed = 1;
      Serial.print("YELLOW\n");
      previousMillis = currentMillis;
      
    }
    
    delay(100);
  }
  while(digitalRead(button2) == 0)
  {
    
    digitalWrite(light2,HIGH);
    if(pressed == 0)
    {
      i++;
      green++;
      pressed = 1;
      Serial.print("GREEN\n");
      previousMillis = currentMillis;
     
    }
    
    delay(100);
  }
  while(digitalRead(button3) == 0)
  {
    
    digitalWrite(light3,HIGH);
    if(pressed == 0)
    {
      i++;
      red++;
      pressed = 1;
      Serial.print("RED\n");
      previousMillis = currentMillis;
     
    }
    
    delay(100);
  }

  if(digitalRead(button1) == 1)
  {
    digitalWrite(light1,LOW);
    pressed = 0;
  }
  if(digitalRead(button2) == 1)
  {
    digitalWrite(light2,LOW);
    pressed = 0;
  }
  if(digitalRead(button3) == 1)
  {
    digitalWrite(light3,LOW);
    pressed = 0;
  }

  
  }
  if(i == 18)
  {
    Serial.print("RESET\n");
    
  }
  if(red == 4 && yellow == 9 && green == 5)
  {
    digitalWrite(9, LOW);
    delay(500);
    digitalWrite(9, HIGH);
    digitalWrite(light1,HIGH);
    digitalWrite(light2,HIGH);
    digitalWrite(light3,HIGH);
    delay(300);
    digitalWrite(light1,LOW);
    digitalWrite(light2,LOW);
    digitalWrite(light3,LOW);
    delay(300);
    digitalWrite(light1,HIGH);
    digitalWrite(light2,HIGH);
    digitalWrite(light3,HIGH);
    delay(300);
    digitalWrite(light1,LOW);
    digitalWrite(light2,LOW);
    digitalWrite(light3,LOW);
    delay(300);
    digitalWrite(light1,HIGH);
    digitalWrite(light2,HIGH);
    digitalWrite(light3,HIGH);
    delay(300);
    digitalWrite(light1,LOW);
    digitalWrite(light2,LOW);
    digitalWrite(light3,LOW); 
    software_Reset();
    
    
  }
  else
  {
    digitalWrite(light3,HIGH);
    delay(250);
    digitalWrite(light3,LOW);
    delay(250);
    
    digitalWrite(light3,HIGH);
    delay(250);
    digitalWrite(light3,LOW);
    delay(250);
    digitalWrite(light3,HIGH);
    delay(250);
    digitalWrite(light3,LOW);
    software_Reset();
   
  }
  
  delay(200); 



    

}
