#include <Servo.h>
#include "pitches.h"

int cuckoo = 2;
int bird = 4;
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
// the setup function runs once when you press reset or power the board
void setup() {
  

  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(cuckoo, OUTPUT);
  pinMode(bird, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(cuckoo, HIGH);
     // turn the LED on (HIGH is the voltage level)
  delay(2000);  
  digitalWrite(cuckoo, LOW);// wait for a second
      // turn the LED off by making the voltage LOW
  delay(1000); 
  for (int thisNote = 0; thisNote < 5; thisNote++) 
  {


      int noteDuration = 1000 / noteDurations[thisNote];
      tone(3, melody[thisNote], noteDuration);
      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(3);
  }
  digitalWrite(bird, HIGH);
  delay(250);
  digitalWrite(bird, LOW);
  delay(250);
  digitalWrite(bird, HIGH);
  delay(250);
  digitalWrite(bird, LOW);
  delay(250);
  digitalWrite(bird, HIGH);
  delay(250);
  digitalWrite(bird, LOW);
  delay(250);
  digitalWrite(bird, HIGH);
  delay(250);
  digitalWrite(bird, LOW);
  delay(250);
  digitalWrite(bird, HIGH);
  delay(250);
  digitalWrite(bird, LOW);
  delay(250);
  digitalWrite(bird, HIGH);
  delay(250);
  digitalWrite(bird, LOW);
  noTone(3);

}
  // wait for a second
