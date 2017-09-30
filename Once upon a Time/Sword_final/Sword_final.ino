const int switch1=11;
const int switch2=12;
const int solenoid=13;
int i=0;


void setup() {
  pinMode(switch1, INPUT);
  digitalWrite(switch1, HIGH);
  pinMode(switch2, INPUT);
  digitalWrite(switch2, HIGH);
  pinMode(solenoid, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  boolean test1 = false;
  boolean test2 = false;

  Serial.println("REset");
 Serial.println(digitalRead(switch1));
 Serial.println(digitalRead(switch2));

  if(digitalRead(switch1) == 0)
  {
    test1 = true;
  }


  if(digitalRead(switch2) == 0)
  {
    test2 = true; 
  }

  
  if(test1 == true && test2== true)
  {
   digitalWrite(solenoid, HIGH);
   for(i=0; i<120; i++)
    {
     if(digitalRead(switch1)==0 && digitalRead(switch2)==0)
    {
      Serial.println("YO");
      Serial.print(i);
      delay(1500);
    }
    else
    {
      digitalWrite(solenoid,LOW);
      break;
    }
   }
  }
  else{
      digitalWrite(solenoid,LOW);
     }



     

while(digitalRead(switch1) == 0 && digitalRead(switch2) == 0)
{
 delay(1000);
 Serial.println("Off");
 
  digitalWrite(solenoid,LOW);
  Serial.println("In Loop 2");
 Serial.println(digitalRead(switch1));
 Serial.println(digitalRead(switch2));
  
}
 

  

}
