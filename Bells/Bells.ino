#include <Button.h>



//Button rs1 = Button(5,true, true, 20);
//Button rs2 = Button(6,true, true, 20);


Button rs1 = Button(5,true, false, 20);
Button rs2 = Button(6,true, false, 20);
Button rs3 = Button(7,true, false, 30);



int state1 = 0;
int state2 = 0;
int state3 = 0;
int n;
int i = 0;
int j= 0;


const int solenoid1=8;
const int solenoid2=9;
const int solenoid3=10;




const int relay=12;


byte combination[] = {2, 1, 3, 3, 1};  //Change values of array to change combination
byte input[5]; // created array, to be compared to combination



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
 // pinMode(button1, INPUT_PULLUP);
 // pinMode(button2, INPUT_PULLUP);
 // pinMode(button3, INPUT_PULLUP);
  
  pinMode(solenoid1, OUTPUT);
  pinMode(solenoid2, OUTPUT);
  pinMode(solenoid3, OUTPUT);

  digitalWrite(solenoid1, HIGH);
  digitalWrite(solenoid2, HIGH);
  digitalWrite(solenoid3, HIGH);

  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

}

void loop() {

i=0;
j=0;

Serial.println('\r');
Serial.println("start");

while( i < 5){
  
      rs1.read();
      rs2.read();
      rs3.read();
     
      
      
      if(rs1.wasReleased() ){       
    
     digitalWrite(solenoid1, LOW);
    delay(25);
    digitalWrite(solenoid1, HIGH);
 
     Serial.println("1--------------");  
  
        Serial.println('1');
        input[i] = 1;
        i++;
   
      }
      
      if(rs2.wasReleased() ){
       
         digitalWrite(solenoid2, LOW);
    delay(40);
    digitalWrite(solenoid2, HIGH);
        
       
            Serial.println("Code Reset");
            i = 0;
     
        Serial.println('2');
        input[i] = 2;
        i++;
        
      }
      
      if(rs3.wasReleased() ){
       
        
         digitalWrite(solenoid3, LOW);
    delay(50);
    digitalWrite(solenoid3, HIGH);
        
     //   Serial.println("3--------------");  
        Serial.println('3');
        input[i] = 3;
        i++;
        
      }
      
   // Serial.print("j=");
   // Serial.println(j);

    
    }

  Serial.println("Outside of loop");
    
   for(int n = 0; n < 5; n++){
        Serial.print(input[n]);
    }


boolean flag = true; // to compare them we'll start with a flag set true
 
for (byte n = 0; n < 5 ; n++){
   if (input[n] != combination[n]) // loop to check array any number that doesn't match means a miss
   {
       flag = false;
  }

}



  if(flag == true)  {    // if flag is true, output whatever
      
      Serial.println('\r');
      Serial.println("Correct Combination");
      digitalWrite(13,HIGH);
      delay(3000);
      digitalWrite(13,LOW);

 
  }




}
