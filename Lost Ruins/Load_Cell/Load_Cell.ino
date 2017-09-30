  /*
 * Episode: Lost Ruins
 * Puzzle: Coin Puzzle
 * Code and Documented by: Zaim Zanaruddin
 * Description: Players will have to figure out how many coins need to be placed on each weight sensor to activate 
 *              pinspot lights
 * Last Updated: September 30th, 2017 by Zaim Zanaruddin
 * License: All rights reserved to Red Door Escape Room
 * Library used: HX711.h ; need to download if you do not have it installed on your computer
 * 
 */
 

#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2


/*
 * Created an instance from library for 4 differnt scale with pin assignments
 * HX711 name(DOUT, CLK)
 * DOUT = digital out pin
 * CLK = Clock time
 * 
 */

HX711 scale1(11,10);
HX711 scale2(9, 8);
HX711 scale3(7, 6);
HX711 scale4(3, 2);



/*
 * Initialize Pin Assignments
 * door_relay: cabinet door (digital pin ; output)
 * reset_button: reset all 4 scales (digital pin ; input)
 * pinspot_ligts: 120v relay powering lights (digital pin ; output)
 * light: light sensors (analog pin)
 */
const int door_relay = 5;
const int reset_button = 4;
const int pinspot_light1 = 12;
const int pinspot_light2 = 13;
const int light1 =0;
const int light2 =2;

 

  double temp1;
  double temp2;
  double temp3;
  double temp4;

/*
 * Function name: software_Reset()
 * Used for reset of all 4 scales, resets whole arduino and re-calibrates load cells
 * Called when reset button is pressed
 */
void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
asm volatile ("  jmp 0");  
}  


void setup() {
  
  //Serial Port for  debugging
  Serial.begin(9600);
  Serial.println("HX711 scale demo");

  //Calibrates Scale
  scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare();  
  scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale2.tare();
  scale3.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale3.tare();
  scale4.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale4.tare();  

  //Set up cabinet door relay
  pinMode(door_relay, OUTPUT);
  digitalWrite(door_relay, HIGH);

  //Set up input reset button
  pinMode(reset_button, INPUT);
  digitalWrite(reset_button, HIGH);

  //Set up pinspot lights
  pinMode(pinspot_light1, OUTPUT);
  digitalWrite(pinspot_light1, HIGH);
  pinMode(pinspot_light2, OUTPUT);
  digitalWrite(pinspot_light2,HIGH);

}

void loop() {
  
  //Debugging Purposes
  Serial.print("Reading1: ");
  Serial.print(scale1.get_units(3), 1); 
  Serial.println();

  Serial.print("Reading2: ");
  Serial.print(scale2.get_units(3), 1); 
  Serial.println();

  Serial.print("Reading3: ");
  Serial.print(scale3.get_units(3), 1); 
  Serial.println();

  Serial.print("Reading4: ");
  Serial.print(scale4.get_units(3), 1); 
  Serial.println();


  /*
   * Check to see if number of coins are in desired range
   */
  
  if((((scale1.get_units(3)))>=3.0 && ((scale1.get_units(3)))<=4.3) &&(((scale2.get_units(3)))>=2.0 && ((scale2.get_units(3)))<=2.8) && (((scale3.get_units(3)))>=4.4) && (((scale4.get_units(6)))>=1.00 && ((scale4.get_units(6)))<=1.40))
  {
    //If correct, turn on Pinspot lightd
    Serial.println("Yes Finished\n");   //Debugging Purposes
    digitalWrite(pinspot_light1, LOW);
    digitalWrite(pinspot_light2, LOW);
  }
  else if( ((scale1.get_units(3)))<=2.0 || ((scale2.get_units(3)))<=1.0 || ((scale3.get_units(3)))<=3.0 || ((scale4.get_units(3)))<=.50)
  {
   //If incorrect, turn off Pinspot lights
   digitalWrite(pinspot_light1, HIGH);
   digitalWrite(pinspot_light2, HIGH);
  }

/**********************************************************************************************************/


//Degugging printing to check to see lights sensors
 Serial.print("Light 1:");
 Serial.println(analogRead(light1));
 Serial.print("Light 2:");
 Serial.println(analogRead(light2));





//Opens Cabinet door if light sensors are activated
 if(analogRead(light1)>15 && analogRead(light2)>15)
 {
    Serial.println("light activated\n");
    digitalWrite(door_relay, LOW);
    delay(3000);
    digitalWrite(door_relay, HIGH);
 }
 

/**********************************************************************************************************/

//Checks input button, if high call reset function
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
