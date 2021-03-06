
/*
 * Episode: Warriors Way
 * Puzzle: RFID Teapot  
 * Creater: Zaim Zanaruddin
 * Last Updated: October 2nd,2017
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

//Pin for Maglockrelay
int relay = 8;


//Pin Assingment for SS communication specifc to each reader
int nfc0 = 4; 
int nfc1 = 5;
int nfc2 = 6;
int nfc3 = 7;

//Stores the value of the chip
String temp0;
String temp1;
String temp2;
String temp3;

//Checking different states
int flag0 = -1;
int flag1 = -1;
int flag2 = -1;
int flag3 = -1;

//Checking differnet states
int test0 = 0;
int test1 = 0;
int test2 = 0;
int test3 = 0;

//Initializes RFID reader from library
MFRC522 mfrc522_0(nfc0, 9);
MFRC522 mfrc522_1(nfc1, 9);
MFRC522 mfrc522_2(nfc2, 9);
MFRC522 mfrc522_3(nfc3, 9);


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(nfc0, OUTPUT);
 pinMode(nfc1, OUTPUT);
 pinMode(nfc2, OUTPUT);
 pinMode(nfc3, OUTPUT);
 pinMode(relay, OUTPUT);
 digitalWrite(relay, HIGH);

  //SPI COMMUNICATION for rfid reader
 SPI.begin();
 SPI.setBitOrder(MSBFIRST);

 //Call a method from class library to being read
 mfrc522_0.PCD_Init(); 
 mfrc522_1.PCD_Init(); 
 mfrc522_2.PCD_Init(); 
 mfrc522_3.PCD_Init(); 

}

  
  // put your main code here, to run repeatedly:
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

void loop(){


//Reads and checks 1st reader
read32bitValue(0, nfc0);
 temp0 = readCard(mfrc522_0,0);
 if((temp0.equals("f6ff2412")))
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
 if((temp1.equals("90ed6c4d")))
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
 
 

 
 //Reads and checks 3rd reader
 read32bitValue(0, nfc2);
 temp2 = readCard(mfrc522_2,2);
 if((temp2.equals("c02c2c83")))
 {
  flag2 = 1;
  test2 = 0;
 }
 else if(temp2.equals("         ") && test2 == 0)
 {
  test2++;
 }
 else
 {
  flag2 = -1;
  test2 = 0;
 }



 
 //Reads and checks 4th reader
 read32bitValue(0, nfc3);
 temp3 = readCard(mfrc522_3,3);
 if((temp3.equals("4509fbd1")))
 {
  flag3 = 1;
  test3 = 0;
 }
 else if(temp3.equals("         ") && test3 == 0)
 {
  test3++;
 }
 else
 {
  flag3 = -1;
  test3 = 0;
 }
 

Serial.print("Flags: ");
Serial.println(flag0);
Serial.println(flag1);
Serial.println(flag2);
Serial.println(flag3);


Serial.println("................................");



if((flag0==1) && (flag1==1) && (flag2 == 1) && (flag3 == 1))
{
  Serial.println("FINSIHED");
  
  //Activate Maglock
  digitalWrite(relay,LOW);
  delay(2000);
  digitalWrite(relay,HIGH);
 
}




}
