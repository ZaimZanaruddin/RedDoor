/*
 * Episode: Warriors Way
 * Puzzle: Weight Sword Puzzle
 * Code and Documented by: Zaim Zanaruddin
 * Description: PLayers will have to find all three swords and place them onto the stand. Weight will detect this. 
 * Last Updted: October 7th, 2017 
 * License: All rights reserved to Red Door Escape Room
 * Library Used: HX711.h ; need to download if you do not have in installed on your computer
 * 
 */

#include "HX711.h"
#define calabration_factor -7050.0

/*
 * Created an instance from library for 4 differnt scale with pin assignments
 * HX711 name(DOUT, CLK)
 * DOUT = digital out pin
 * CLK = Clock time
 * 
 */

HX711 Lscale(6, 5);
HX711 Rscale(4, 2);

float temp1;
float temp2;
float final_temp;
float tempf;

const int relay = 12; 
const int reset_button = 8;

float low_weight = 10.0; //Need to change 
float high_weight = 15.0; //Need to change


/*
 * Function name: software_Reset()
 * Used for reset of all  scale, resets whole arduino and re-calibrates load cells
 * Called when reset button is pressed
 */
void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
asm volatile ("  jmp 0");  
}




void setup() {
  //Serial Port for debugging
  Serial.begin(9600);
   Serial.println("HX711 scale demo");
  

  //Calibrate the Sensor 
  Lscale.set_scale(calabration_factor);
  Lscale.tare();

  Rscale.set_scale(calabration_factor);
  Rscale.tare();
 
  //Set up relay for trigger activation
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
   //Set up input reset button
  pinMode(reset_button, INPUT_PULLUP);





}

void loop() {

    //Debugging Purposes
  Serial.print("Reading1: ");
  Serial.print(Lscale.get_units(3), 1); 
  Serial.println();

   Serial.print("Reading1: ");
  Serial.print(Rscale.get_units(3), 1); 
  Serial.println();

  temp1 = (Lscale.get_units(3), 1);
  temp2 = (Rscale.get_units(3), 1);

  
  tempf = abs((temp1+temp2)); 

   Serial.print("temp:");
    Serial.println(tempf);


  final_temp = tempf/2;

  Serial.print("Final Weight: ");
  Serial.print(final_temp);
  Serial.println();

/**********************************************************************************************************/

/*
//Checks input button, if high call reset function
if(digitalRead(reset_button) == LOW)
{
  
  Serial.println("Reset");
  software_Reset();
 
}

*/

}
