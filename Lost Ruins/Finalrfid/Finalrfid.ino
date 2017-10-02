#include <SoftwareSerial.h>
//SoftwareSerial SSerial2(9,8);//rx = digital 1, tx == digital 2

SoftwareSerial SSerial(11,10);

int RFIDResetPin1 = 3; //digital3
int RFIDResetPin2 = 4; //digital4

//Register your RFID tags here
char tag1[13] = "030044CE0F";
char tag2[13] = "040021427A";
char tag3[13] = "01023C013A04";
char tag4[13] = "01023101093A";
char tag5[13] = "01023C0A4376";

void setup(){
  Serial.begin(9600);
  
  //SSerial.begin(9600);
  pinMode(RFIDResetPin1, OUTPUT);
  pinMode(RFIDResetPin2, OUTPUT);
  
  digitalWrite(RFIDResetPin1, HIGH);
  digitalWrite(RFIDResetPin2, HIGH);
}

void loop(){
  
  checkRFIDReader1();// check serial
  
  checkRFIDReader2();// check serial
}


void checkRFIDReader1(){

  //RFID tags are 13+1 characters,
  //so no need to check until we have that many bytes available
  
  if(Serial.available() >= 6){
    
    

//    char tagString[13]; //this will hold the tag string;

    int readByte = Serial.read(); //read next available byte

    //we MUST start proces at a 2 as it marks the tag begining
    //if it is not a 2, get out of here.
//    if(readByte != 2) return; 

    //buffer to hold our tag
    char tagString[13];
    
//    //read the serial until we gat a 3, the end of the tag
    Serial.readBytesUntil(3, tagString, 13);
     Serial.print("From 1 ");

    checkTag(tagString); //Check if it is a match
    clearTag(tagString); //Clear the char of all value
    SSerial.begin(9600);
    resetReader1(); //eset the RFID reader
  }
  
//  delay(1000);

}


void checkRFIDReader2(){

  //RFID tags are 13+1 characters,
  //so no need to check until we have that many bytes available
  
  if(SSerial.available() >= 6){
    

    //char tagString[13]; //this will hold the tag string;

    int readByte = SSerial.read(); //read next available byte

    //we MUST start proces at a 2 as it marks the tag begining
    //if it is not a 2, get out of here.
//    if(readByte != 2) return; 

    //buffer to hold our tag
    char tagString[13];
    
    //read the serial until we gat a 3, the end of the tag
    SSerial.readBytesUntil(3, tagString, 13);
    Serial.print("From 2 ");
    checkTag(tagString); //Check if it is a match
    clearTag(tagString); //Clear the char of all value
    resetReader2(); //eset the RFID reader
  }
//  delay(1000);

}


void checkTag(char tag[]){
  ///////////////////////////////////
  //Check the read tag against known tags
  ///////////////////////////////////

  if(strlen(tag) == 0) return; //empty, no need to contunue

//  if(compareTag(tag, tag1)){ // if matched tag1, do this
//    Serial.println("tag 1");
//  
//  }else if(compareTag(tag, tag2)){ //if matched tag2, do this
//    Serial.println("tag 2");
//
//  }else if(compareTag(tag, tag3)){
//    Serial.println("tag 3");
//
//  }else if(compareTag(tag, tag4)){
//    Serial.println("tag 4");
//
//  }else if(compareTag(tag, tag5)){
//    Serial.println("tag 5");

//  }
    else{
    Serial.print("Tag: ");
    Serial.println(tag); //read out any unknown tag
  }

}

//void lightLED(int pin){
//  ///////////////////////////////////
//  //Turn on LED on pin "pin" for 250ms
//  ///////////////////////////////////
//  Serial.println(pin);
//
//  digitalWrite(pin, HIGH);
//  delay(250);
//  digitalWrite(pin, LOW);
//}

void resetReader1(){
  ///////////////////////////////////
  //Reset the RFID reader to read again.
  ///////////////////////////////////
  digitalWrite(RFIDResetPin1, LOW);
  digitalWrite(RFIDResetPin1, HIGH);
  delay(150);
}

void resetReader2(){
  ///////////////////////////////////
  //Reset the RFID reader to read again.
  ///////////////////////////////////
  digitalWrite(RFIDResetPin2, LOW);
  digitalWrite(RFIDResetPin2, HIGH);
  delay(150);
}

void clearTag(char one[]){
  ///////////////////////////////////
  //clear the char array by filling with null - ASCII 0
  //otherwise, it will think same tag has been read
  ///////////////////////////////////
  for(int i = 0; i < 12; i++){
    one[i] = 0;
  }
}

boolean compareTag(char one[], char two[]){
  ///////////////////////////////////
  //compare two value to see if same,
  //strcmp not working 100% so we do this
  ///////////////////////////////////

  if(strlen(one) == 0) return false; //empty

  for(int i = 0; i < 12; i++){
    if(one[i] != two[i]) return false;
  }

  return true; //no mismatches
}
