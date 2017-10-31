#include "HX711.h"

#define DOUT1  4
#define CLK1  2

#define DOUT2 6
#define CLK2 5
HX711 scale1(DOUT1, CLK1);
HX711 scale2(DOUT2, CLK2);

int light = 12;
int successCount = 0;
float combined = 0;
float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  pinMode(light, OUTPUT);
  scale1.set_scale();
  scale2.set_scale();
  scale1.tare(); //Reset the scale to 0
  scale2.tare();
  long zero_factor1 = scale1.read_average(); //Get a baseline reading
  long zero_factor2 = scale2.read_average();
  Serial.print("Zero factor 1: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor1);
  Serial.print("Zero factor 2: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor2);
}

void loop() {

  scale1.set_scale(calibration_factor); //Adjust to this calibration factor
  scale2.set_scale(calibration_factor);

  combined = (scale1.get_units() + scale2.get_units()) / 2;
  Serial.print("Reading: ");
  Serial.print(abs(combined));
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  
  Serial.println();
  delay(500);

  combined = abs(combined);

  if(combined > 4.40 && combined < 6.00)
  {
    successCount++;
    Serial.println(successCount);
  }
  else
  {
    successCount = 0;
  }

  if(successCount > 3)
  {
    digitalWrite(light, HIGH);
    Serial.println("Success");
  }
  else
  {
    digitalWrite(light, LOW);
    
  }

  
  
}
