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

HX711 scale(3, 2);


const int relay = 4; 
const int reset_button = 5;

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

  //Calibrate the Sensor 
  scale.set_scale(calibration_factor)l
  scale_tare();
 
  //Set up relay for trigger activation
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
   //Set up input reset button
  pinMode(reset_button, INPUT_PULLUP);





}

void loop() {

    //Debugging Purposes
  Serial.print("Reading1: ");
  Serial.print(scale.get_units(3), 1); 
  Serial.println();


  if((scale.get_units(3) > low_weight) && (scale.get_units(3) < high_weight));
  {
    //Trigger relay 
    digitalWrite(relay, HIGH);
    delay(2000);
    digialWrite(relY, LOW);
  }

/**********************************************************************************************************/

//Checks input button, if high call reset function
if(digitalRead(reset_button) == LOW)
{
  
  Serial.println("Reset");
  software_Reset();
 
}



}
