#include <Button.h>
/*
int rs1;
int rs2;
int rs3;
int rs4;
int rs5;
int rs6;
*/

int relay = 13;

Button rs1 = Button(2,false, false, 20);
Button rs2 = Button(3,false, false, 20);
Button rs3 = Button(4,false, false, 20);
Button rs4 = Button(5,false, false, 20);
Button rs5 = Button(6,false, false, 20);
Button rs6 = Button(7,false, false, 20);


int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;
int state6 = 0;

int n;
int i = 0;



byte combination[] = {1, 2, 3, 4, 5, 6};  //Change values of array to change combination
byte input[6]; // created array, to be compared to combination

void setup() {
  
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);

Serial.begin(9600);


}

void loop() {
  
int i = 0;


Serial.println('\r');
Serial.println("start");

while( i < 6){
  
      rs1.read();
      rs2.read();
      rs3.read();
      rs4.read();
      rs5.read();
      rs6.read();
      
      
      
      if(rs1.wasReleased() ){       
        
        Serial.println("Code Reset");
        i = 0;
        Serial.println('1');
        input[i] = 1;
        i++;
   
      }
      
      if(rs2.wasReleased() ){
        Serial.println('2');
        input[i] = 2;
        i++;
        
      }
      
      if(rs3.wasReleased() ){
        Serial.println('3');
        input[i] = 3;
        i++;
        
      }
      
      if(rs4.wasReleased() ){     
        Serial.println('4');
        input[i] = 4;
        i++;
        
      }
      
      if(rs5.wasReleased() ){      
        Serial.println('5');
        input[i] = 5;
        i++;
        
      }
      
      if(rs6.wasReleased() ){      
        Serial.println('6');
        input[i] = 6;
        i++;
        
      }
    
    }
    
   for(int n = 0; n < 6; n++){
        Serial.print(input[n]);
    }


boolean flag = true; // to compare them we'll start with a flag set true
 
for (byte n = 0; n < 6 ; n++){
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
