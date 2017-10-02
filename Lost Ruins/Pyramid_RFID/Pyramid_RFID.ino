#include <MFRC522.h>
#include <SPI.h>


int spotlight = 22; //Red
int mask = 24;      //White
int door = 26;      //Green
int nfcreader = 1;
int nfc0 = 12; // SPI PIN for first reader
int nfc1 = 3;
int nfc2 = 4;
int nfc3 = 5;
int nfc4 = 6;
int nfc5 = 7;
int nfc6 = 8;
int nfc7 = 10;

int flag0 = -1;
int flag1 = -1;
int flag2 = -1;
int flag3 = -1;
int flag4 = -1;
int flag5 = -1;
int flag6 = -1;
int flag7 = -1;

int test0 = 0;
int test1 = 0;
int test2 = 0;
int test3 = 0;
int test4 = 0;
int test5 = 0;
int test6 = 0;
int test7 = 0;

int spotlightcheck = 0;


MFRC522 mfrc522_0(nfc0, 9);
MFRC522 mfrc522_1(nfc1, 9);
MFRC522 mfrc522_2(nfc2, 9);
MFRC522 mfrc522_3(nfc3, 9);
MFRC522 mfrc522_4(nfc4, 9);
MFRC522 mfrc522_5(nfc5, 9);
MFRC522 mfrc522_6(nfc6, 9);
MFRC522 mfrc522_7(nfc7, 9);

int FacingSwitch  = 11;
int IdolMagRelay = 13;


/*
String SnakeTotem =    "ba324046";
String GreenCrystal =  "5a0cabdd";
String MonkeyTotem =   "daef3546";
String RedCrystal =    "9ae23546";
String JaguarTotem =   "ca37cadd";
String VioletCrystal = "eae2b5dd";
String EagleTotem =    "1af6cddd";
String BlueCrystal =   "ca8daddd";

String SnakeTotem2 =    "caaac1dd";
String GreenCrystal2 =  "ca1baddd";
String MonkeyTotem2 =   "4ae2c7dd";
String RedCrystal2 =    "7a00cedd";
String JaguarTotem2 =   "fa9ab6dd";
String VioletCrystal2 = "ea6d2846";
String EagleTotem2 =    "ba81cddd";
String BlueCrystal2 =   "5a00cadd";
*/

String temp0;
String temp1;
String temp2;
String temp3;
String temp4;
String temp5;
String temp6;
String temp7;


void setup() {

 Serial.begin(9600);

 
 pinMode(nfc0, OUTPUT);
 pinMode(nfc1, OUTPUT);
 pinMode(nfc2, OUTPUT);
 pinMode(nfc3, OUTPUT);
 pinMode(nfc4, OUTPUT);
 pinMode(nfc5, OUTPUT);
 pinMode(nfc6, OUTPUT);
 pinMode(nfc7, OUTPUT);
 pinMode(FacingSwitch, INPUT_PULLUP);
 pinMode(IdolMagRelay, OUTPUT);
 pinMode(spotlight, OUTPUT);
 pinMode(mask, OUTPUT);
 pinMode(door, OUTPUT);
 digitalWrite(IdolMagRelay, LOW);
 digitalWrite(spotlight, LOW);
 digitalWrite(mask, LOW);
 digitalWrite(door, LOW);
  
 SPI.begin();
 SPI.setBitOrder(MSBFIRST);

 // Init MFRC522 cards
 mfrc522_0.PCD_Init(); 
 mfrc522_1.PCD_Init();
 mfrc522_2.PCD_Init();
 mfrc522_3.PCD_Init();
 mfrc522_4.PCD_Init();
 mfrc522_5.PCD_Init();
 mfrc522_6.PCD_Init();
 mfrc522_7.PCD_Init();
 

 
 Serial.println("Ready to scan");
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


  

 read32bitValue(0, nfc0);
 nfcreader++; 
 temp0 = readCard(mfrc522_0,0);
 if((temp0.equals("ba324046")) || (temp0.equals("caaac1dd")))
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
  
 read32bitValue(0, nfc1);
 nfcreader++;
 temp1 = readCard(mfrc522_1,1);
 if((temp1.equals("5a0cabdd")) || (temp1.equals("ca1baddd")))
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
 
 
 read32bitValue(0, nfc2);
 nfcreader++;
 temp2 = readCard(mfrc522_2,2);
 if((temp2.equals("daef3546")) || (temp2.equals("4ae2c7dd")))
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

 
 
 read32bitValue(0, nfc3);
 nfcreader++;
 temp3 = readCard(mfrc522_3,3);
 if((temp3.equals("9ae23546")) || (temp3.equals("7a00cedd")))
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
 


 read32bitValue(0, nfc4);
 nfcreader++;
 temp4 =readCard(mfrc522_4,4);
 if((temp4.equals("ca37cadd")) || (temp4.equals("fa9ab6dd")))
 {
  flag4 = 1;
  test4 = 0;
 }
 else if(temp4.equals("         ") && test4 == 0)
 {
  test4++;
 }
 else
 {
  flag4 = -1;
  test4 = 0;
 }
 
 
 read32bitValue(0, nfc5);
 nfcreader++;
 temp5 =readCard(mfrc522_5,5);
 if((temp5.equals("eae2b5dd")) || (temp5.equals("ea6d2846")))
 {
  flag5 = 1;
  test5 = 0;
 }
 else if(temp5.equals("         ") && test5 == 0)
 {
  test5++;
 }
 else
 {
  flag5 = -1;
  test5 = 0;
 }

 read32bitValue(0, nfc6);
 nfcreader++;
 temp6 =readCard(mfrc522_6,6);
 if((temp6.equals("1af6cddd")) || (temp6.equals("ba81cddd")))
 {
  flag6 = 1;
  test6 = 0;
  Serial.println("Eagle");
 }
 else if(temp6.equals("         ") && test6 == 0)
 {
  test6++;
 }
 else
 {
  flag6 = -1;
  test6 = 0;
 }


 read32bitValue(0, nfc7);
 nfcreader++;
 temp7=readCard(mfrc522_7,7);
 if((temp7.equals("ca8daddd")) || (temp7.equals("5a00cadd")))
 {
  flag7 = 1;
  test7 = 0;
 }
 else if(temp7.equals("         ") && test7 == 0)
 {
  test7++;
 }
 else
 {
  flag7 = -1;
  test7 = 0;
 }


 Serial.println("Check");
 

 if(digitalRead(FacingSwitch) == LOW)
 {
  digitalWrite(spotlight, HIGH);
  Serial.println("Spotlight ON");
  spotlightcheck = 1;
 }

 if(digitalRead(FacingSwitch) == HIGH)
 {
  digitalWrite(spotlight, LOW);
  Serial.println("Spotlight OFF");
  spotlightcheck = 0;
 }
 
 
 if((flag0 == 1 && flag2 == 1 && flag4 == 1 && flag6 == 1) || (flag1 == 1 && flag3 == 1 && flag5 == 1 && flag7 == 1))
 {
   digitalWrite(mask, HIGH);
   Serial.println("Masks On");
 }
 else
 {
  digitalWrite(mask, LOW);
  Serial.println("Masks OFF");
  
 }
 Serial.print("0");
 Serial.println(flag0);
 Serial.print("2");
 Serial.println(flag2);
 Serial.print("4");
 Serial.println(flag4);
 Serial.print("6");
 Serial.println(flag6);

 if(flag1 == 1 && flag3 == 1 && flag5 == 1 && flag7 == 1 && flag0 == 1 &&  flag2 == 1 && flag4 == 1 && flag6 == 1 && spotlightcheck == 1)
 {
  digitalWrite(door, HIGH);
  
  for(int i = 0; i <= 6; i++)
  {
    digitalWrite(IdolMagRelay, HIGH);
    delay(45);
    digitalWrite(IdolMagRelay, LOW);
    delay(180);
   
    
  }
  
  digitalWrite(IdolMagRelay, HIGH);
  Serial.println("Yes");
  
  delay(30000);
  digitalWrite(IdolMagRelay, LOW);
  Serial.println("Door ON");
 
  resetFunc();
 }
  else
 {
  digitalWrite(door, LOW);
  digitalWrite(IdolMagRelay, LOW);
  
  
 }

 Serial.print("1");
 Serial.println(flag1);
 Serial.print("3");
 Serial.println(flag3);
 Serial.print("5");
 Serial.println(flag5);
 Serial.print("7");
 Serial.println(flag7);


 
 Serial.println(digitalRead(FacingSwitch));
 Serial.println("Space");
 

}
