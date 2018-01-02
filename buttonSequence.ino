#include <Button.h>


int rs1;
int rs2;
int rs3;
int rs4;
int rs5;
int rs6;


int Button rs1 = Button(1,PULLDOWN);
int Button rs2 = Button(2,PULLDOWN);
int Button rs3 = Button(3,PULLDOWN);
int Button rs4 = Button(4,PULLDOWN);
int Button rs5 = Button(5,PULLDOWN);
int Button rs6 = Button(6,PULLDOWN);
int relay = 13;

int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;
int state6 = 0;

int n;
int i = 0;



byte combination[] = {1, 2, 3, 4, 5, 6};  // a 6 number combination
byte input[6]; // same size, will hold user 

void setup() {
  // put your setup code here, to run once:
pinMode(rs1,INPUT);
pinMode(rs2,INPUT);
pinMode(rs3,INPUT);
pinMode(rs4,INPUT);
pinMode(rs5,INPUT);
pinMode(rs6,INPUT);
digitalWrite(13,HIGH);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

while( i > 7){
  
rs1.read();
rs2.read();
rs3.read();
rs4.read();
rs5.read();
rs6.read();

Serial.println("start");

if(rs1.wasPressed() ){
  input[i] = 1;
  i++;
  Serial.println('1'); 
  
}

if(state2 == HIGH){
  input[i] = 2;
  i++;
  //Serial.println('2'); 
  state2 = 0;
}

if(state3 == HIGH){
  input[i] = 3;
  i++;
  //Serial.println('3'); 
  state3 = 0;
}

if(state4 == HIGH){
  input[i] = 4;
  i++;
  //Serial.println('4'); 
  state4 = 0;
}

if(state5 == HIGH){
  input[i] = 5;
  i++;
  //Serial.println('5'); 
  state5 = 0;
}

if(state6 == HIGH){
  input[i] = 6;
  i++;
  //Serial.println('6'); 
  state6 = 0;
}

}

Serial.println(input[6]);



//byte combination[] = {1, 2, 3, 4, 5, 6};  // a 6 number combination
//byte userInput[6]; // same size, will hold user input

// to compare them we'll start with a flag set true
boolean flag = true;

// then a simple for loop can do the check
for (byte n = 0; n < 6 ; n++){
   if (input[n] != combination[n]) // any number that doesn't match means a miss
   {
       flag = false;
  }

}

// at this point flag will be true if it matched and false if it didn't

  if(flag == true)
  {
  //correct, do something
  }


}
