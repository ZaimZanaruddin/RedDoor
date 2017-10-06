
/*
 * Puzzle: Sliding Door Activation
 * Description: When players place an RFID coin into correct position, sliding doors will unlock
 *              Both sides are controled by same arduino
 * Episode: Warriors Way, Plano
 * Date Updated: October 6, 2017 
 *
 */

#include <MFRC522.h>
#include <SPI.h>


/*
 * MFRC522 PIN ASSIGNMENT
 * NSS: nfc0 pin different from each one 
 * SCK: pin 13
 * MOSI = pin 11
 * MISO = pin 12
 * GND = GND
 * RST = pin 9
 * VCC = 3.3V 
 */

//Degress pin assignments
const int exitButton = 2;
const int motionSensor = 3;

//Relay pin assingment for both sliding doors
const int relay0 = 4;
const int relay1 = 5;

//SPI PIN for the teo readers (SS Pin)
const int nfc0 = 6;
const int nfc1 = 7;

//Stores the value of the chip
String temp0;
String temp1; 

//Checking different states
int flag0 = -1;
int flag1 = -1;

//Checking differnt states 
int test0 = 0;
int test1 = 1;

//Initializes RFID reader from library
MFRC522 mfrc522_0(nfc0, 9);
MFRC522 mfrc522_1(nfc1, 9);



void setup() {
  Serial.begin(9600);
  pinMode(nfc0, OUTPUT);
  pinMode(nfc1, OUTPUT);

  pinMode(relay0, OUTPUT);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay0, LOW);
  digitalWrite(relay1, LOW);

  pinMode(exitButton, INPUT_PULLUP);
  pinMode(motionSensor, INPUT_PULLUP);

  //SPI COMMUNICATION for rfid reader
 SPI.begin();
 SPI.setBitOrder(MSBFIRST);

 //Call a method from class library to being read
 mfrc522_0.PCD_Init(); 
 mfrc522_1.PCD_Init(); 

}






 void read32bitValue(int value, int ss)
{
 digitalWrite(ss, LOW);
 uint32_t val;
 val = SPI.transfer(0xff); //0xff is a dummy
 val |= (uint32_t)SPI.transfer(0xff) << 8;
 val |= (uint32_t)SPI.transfer(0xff) << 16;
 val |= (uint32_t)SPI.transfer(0xff) << 24;
 digitalWrite(ss, HIGH);
}

// Get the UID of the card being scanned
String getID(MFRC522 card){
 
 String output = "";
 
 for (byte i = 0; i < card.uid.size; i++) {
 output += card.uid.uidByte[i] < 0x10 ? "0" : "";
 output += String(card.uid.uidByte[i],HEX);
 } 

 return output;
}

String readCard(MFRC522 card,int readerNumber) {

 if ( !card.PICC_IsNewCardPresent()) {
  return ("         ");
 }
 
 if ( !card.PICC_ReadCardSerial()) {
  return("BUS");
 }
 
 Serial.print("Card "+String(readerNumber)+":");
 Serial.println(getID(card));

 return(getID(card));
 
 
}

void(* resetFunc) (void) = 0;



void loop() {
 
 //Reads and checks 1st reader
read32bitValue(0, nfc0);
 temp0 = readCard(mfrc522_0,0);
 if((temp0.equals("65656bc9")))
 {
  flag0 = 1;
  test0 = 0;
  
  
 }
 else if(temp0.equals("         ") && test0 == 0)
 {
  test0++;
 }
 else
 {
  flag0 = -1;
  test0 = 0;
 }
  
 
 //Reads and checks 2nd reader
 read32bitValue(0, nfc1);
 temp1 = readCard(mfrc522_1,1);
 if((temp1.equals("b5ee6ac9")))
 {
  flag1 = 1;
  test1 = 0;
 }
 else if(temp1.equals("         ") && test1 == 0)
 {
  test1++;
 }
 else
 {
  flag1 = -1;
  test1 = 0;
 }



Serial.println("................................");


if((flag0 = 1) && (flag1 == 1))
{
  Serial.println("Both Doors are finished");

  //Activate Maglock
  digitalWrite(relay0, HIGH);
  digitalWrite(relay1, HIGH);
  delay(2000);
  digitalWrite(relay1, LOW);
  digitalWrite(relay1, LOW);
  
}

if(exitButton == LOW || motionSensor == LOW)
{

  //Activate Maglock
  digitalWrite(relay0, HIGH);
  digitalWrite(relay1, HIGH);
  delay(2000);
  digitalWrite(relay1, LOW);
  digitalWrite(relay1, LOW);
  
}
 

}
