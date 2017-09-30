/*
 * Episode: The Gift
 * Puzzle: Light-House Puzzle
 * Code and Documented by: Zaim Zanaruddin
 * Description: Lighthouses will have 3 light sensors to detect light. Players will have to shine 3 flashlights to activate puzzle
 * Last Updated: September 30th, 2017
 * All rights reserved to Red Door Escape Room
 * 
 */

// Define Various notes for pitches
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978



/*
 * Initialize Pin Assignments
 * LRD: Light Sensors (digital pin ; input)
 * Light: LED Lights (digital pin ; output)
 * cuckoo: Sound (digital pin ; output)
 * bird: Motor (digital pin ; output) 
 * relay: Maglock (digital pin ; output)
 */
const int cuckoo = 11;
const int bird = 13;
const int light1=2;
const int LDR1 = 3;
const int light2=4;
const int LDR2 = 5;
const int light3= 6;
const int LDR3 = 7;
const int relay =9;


//Initialize melody tone
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


 void setup() 
 {
   //Set up LEDS
   pinMode(light1,OUTPUT);
   pinMode(light2, OUTPUT);
   pinMode(light3, OUTPUT);
  

   //Set up Light Sensors
    pinMode(LDR1, INPUT);
    pinMode(LDR2, INPUT);
    pinMode(LDR3, INPUT);
   
   //Set up Relay
   pinMode(relay, OUTPUT);
   digitalWrite(relay,HIGH);

   //Set up Bird activation and sound
   pinMode(cuckoo, OUTPUT);
   pinMode(bird, OUTPUT);
   
   //Serial Port for debugging
   Serial.begin(9600);           
 }
 


 
 /*
  * Main Function of the program
  * Detects if all three light sensors are activated
  * If light is detected, LED for specific lighthouse will light up
  */
 void loop() {
  
 //Debugging for Sensor 1
 Serial.print("Light1:");
 Serial.println(digitalRead(LDR1));

  if(digitalRead(LDR1) ==LOW)     //Checking Sensor 1
  {
    digitalWrite(light1, HIGH);
  }
  else
  {
    digitalWrite(light1,LOW);
  }
  

 //Debugging for Sensor 2
 Serial.print("Light2:");
 Serial.println(digitalRead(LDR2));
 
  if(digitalRead(LDR2) ==LOW)    //Checking Sensor 2
  {
    digitalWrite(light2, HIGH);
  }
  else
  {
    digitalWrite(light2,LOW);
  }
  
  
 
 //Debugging for Sensor 3
 Serial.print("Light3:");
 Serial.println(digitalRead(LDR3));

 if(digitalRead(LDR3) ==LOW)      // //Checking Sensor 3
  {
    digitalWrite(light3, HIGH);
  }
  else
  {
    digitalWrite(light3,LOW);
  }
  

/*
 * Checks all three sensors
 * If LOW, releases bird, plays audio, and unlocks maglock
 */
if(digitalRead(LDR1) ==LOW && digitalRead(LDR2) ==LOW && digitalRead(LDR3) ==LOW)    
{
 
 //Releases Bird from its Reseting State
 digitalWrite(cuckoo, HIGH);
 // turn the LED on (HIGH is the voltage level)
 delay(2000);  
 digitalWrite(cuckoo, LOW); // wait for a second
 // turn the LED off by making the voltage LOW
 delay(1000);

  //Plays Tone 
  for (int thisNote = 0; thisNote < 5; thisNote++) 
  {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(12, melody[thisNote], noteDuration);
      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(12);
  }
 
  //Unlocks Maglock for 3 seconds
  digitalWrite(relay, LOW);
  delay(3000);
  digitalWrite(relay, HIGH);

 }

}
