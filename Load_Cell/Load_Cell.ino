/*
 Example using the SparkFun HX711 breakout board with a scale
 By: Nathan Seidle
 SparkFun Electronics
 Date: November 19th, 2014
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 This example demonstrates basic scale output. See the calibration sketch to get the calibration_factor for your
 specific load cell setup.
 
 This example code uses bogde's excellent library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE
 
 The HX711 does one thing well: read load cells. The breakout board is compatible with any wheat-stone bridge
 based load cell which should allow a user to measure everything from a few grams to tens of tons.
 Arduino pin 2 -> HX711 CLK
 3 -> DAT
 5V -> VCC
 GND -> GND
 
 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.
 
*/

#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2

HX711 scale1(11,10);
HX711 scale2(9, 8);
HX711 scale3(7, 6);
HX711 scale4(3, 2);

const int door_relay = 5;
const int reset_button = 4;
const int pinspot_light1 = 12;
const int pinspot_light2 = 13;
const int light1 = 0;
const int light2 = 2;
 

  double temp1;
  double temp2;
  double temp3;
  double temp4;


void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
asm volatile ("  jmp 0");  
}  

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 scale demo");

  scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0
  scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale2.tare();
  scale3.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale3.tare();
  scale4.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale4.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  pinMode(door_relay, OUTPUT);
  digitalWrite(door_relay, HIGH);


  pinMode(reset_button, INPUT);
  digitalWrite(reset_button, HIGH);

  pinMode(pinspot_light1, OUTPUT);
   digitalWrite(pinspot_light1, HIGH);

 pinMode(pinspot_light2, OUTPUT);
   digitalWrite(pinspot_light2,HIGH);


  Serial.println("Readings:");

 


}

void loop() {
  
  /*
  
  Serial.print("Reading1: ");
  Serial.print(scale1.get_units(3), 1); //scale.get_units() returns a float
//  temp1 = ((scale1.get_units(3)));
 // Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();

  Serial.print("Reading2: ");
  Serial.print(scale2.get_units(3), 1); //scale.get_units() returns a float
//  temp2 = ((scale2.get_units(3)));
 // Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();

  Serial.print("Reading3: ");
  Serial.print(scale3.get_units(3), 1); //scale.get_units() returns a float
 // temp3  = ((scale3.get_units(3)));
 // Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();

  Serial.print("Reading4: ");
  Serial.print(scale4.get_units(3), 1); //scale.get_units() returns a float
//  temp4= ((scale4.get_units(6)));
  Serial.println();

 /*
  Serial.print("Reading 1:");
  Serial.println(temp1);
  Serial.print("Reading 2:");
  Serial.println(temp2);
  Serial.print("Reading 3:");
  Serial.println(temp3);
  Serial.print("Reading 4:");
  Serial.println(temp4);
*/

  if((((scale1.get_units(3)))>=3.0 && ((scale1.get_units(3)))<=4.3) &&(((scale2.get_units(3)))>=2.0 && ((scale2.get_units(3)))<=2.8) && (((scale3.get_units(3)))>=4.4) && (((scale4.get_units(6)))>=1.00 && ((scale4.get_units(6)))<=1.40))
  {
    Serial.println("Yes Finished\n");
    digitalWrite(pinspot_light1, LOW);
    digitalWrite(pinspot_light2, LOW);
  }
  else if( ((scale1.get_units(3)))<=2.0 || ((scale2.get_units(3)))<=1.0 || ((scale3.get_units(3)))<=3.0 || ((scale4.get_units(3)))<=.50)
  {
    
     digitalWrite(pinspot_light1, HIGH);
   digitalWrite(pinspot_light2, HIGH);
  }


/*
  if((temp1>=.78 && temp1<=.95) &&(temp2>=0.50 && temp2<=.65) && (temp3>=1.00 && temp3<=1.25) && (temp4>=0.20 && temp4<=.35))
  {
    Serial.println("Yes Finished\n");
    digitalWrite(pinspot_light1, LOW);
    digitalWrite(pinspot_light2, LOW);
  }
  else if( temp1<=.45 || temp2<=.30 || temp3<=.65 || temp4<=.10){
    
     digitalWrite(pinspot_light1, HIGH);
   digitalWrite(pinspot_light2, HIGH);
  }

 
 */
 
 
 
 
 
 Serial.print("Light 1:");
 Serial.println(analogRead(light1));

   Serial.print("Light 2:");
  Serial.println(analogRead(light2));






 if(analogRead(light1)>15 && analogRead(light2)>15)
 {
    Serial.println("light activated\n");
    digitalWrite(door_relay, LOW);
    delay(3000);
    digitalWrite(door_relay, HIGH);
 }
 

if(digitalRead(reset_button) == LOW)
{
  
   Serial.println("Reset");
  digitalWrite(pinspot_light1, LOW);
  digitalWrite(pinspot_light2, LOW);
  delay(1000);
  digitalWrite(pinspot_light1, HIGH);
  digitalWrite(pinspot_light2, HIGH);
  software_Reset();
 
}


  
  
 

  
}
