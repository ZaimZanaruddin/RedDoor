#include <softspi.h>
#include <rfid1.h>


RFID1 rfid;
uchar serNum1[5];
uchar serNum2[5];
uchar serNum3[5];
uchar serNum4[5];
uchar empty[5] = "00000";
int relay = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(relay, OUTPUT);
  digitalWrite(relay,HIGH);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  checkRFID(0);
  checkRFID(1);
  checkRFID(2);
  checkRFID(3);
  uchar* id1 = serNum1;
  uchar* id2 = serNum2;
  uchar* id3 = serNum3;
  uchar* id4 = serNum4;

  
  if( (id1[0]==0x05 && id1[1]==0x65 && id1[2]==0x6B && id1[3]==0xC9) && (id2[0]==0xA5 && id2[1]==0x64 && id2[2]==0x6B && id2[3]==0xC9) && (id3[0]==0x65 && id3[1]==0x65 && id3[2]==0x6B && id3[3]==0xC9) && (id4[0]==0xB5 && id4[1]==0xEE && id4[2]==0x6A && id4[3]==0xC9)  ) 
    {
      digitalWrite(relay,LOW);
      
      
    }
   else
   {
    digitalWrite(relay,HIGH);
   }
    
}


void checkRFID(int i){
  if(i==0){
    rfid.begin(10,13,11,4,12,9);
    Serial.println("1:");
  }
  if(i==1){
    rfid.begin(10,13,11,5,12,9);
    Serial.println("2:");
  }
  if(i==2){
    rfid.begin(10,13,11,6,12,9);
    Serial.println("3:");
  }
  if(i==3){
    rfid.begin(10,13,11,7,12,9);
    Serial.println("4:");
  }
 
  
  delay(100);
  rfid.init();
  uchar status;
  uchar str[MAX_LEN];
  
  // Search card, return card types
  status = rfid.request(PICC_REQIDL, str);
  if (status != MI_OK)
  {
    if(i==0){
    memcpy(serNum1, empty, 5);
  }
  if(i==1){
    memcpy(serNum2, empty, 5);
  }
  if(i==2){
    memcpy(serNum3, empty, 5);
  }
  if(i==3){
    memcpy(serNum4, empty, 5);
  }
    return;
  }
  // Show card type
  rfid.showCardType(str);
  //Prevent conflict, return the 4 bytes Serial number of the card
  status = rfid.anticoll(str);
  if (status == MI_OK)
  {
    if(i == 0)
    {
      memcpy(serNum1, str, 5);
      rfid.showCardID(serNum1);//show the card ID
    }
    if(i == 1)
    {
      memcpy(serNum2, str, 5);
      rfid.showCardID(serNum2);//show the card ID
    }
    if(i == 2)
    {
      memcpy(serNum3, str, 5);
      rfid.showCardID(serNum3);//show the card ID
    }
    if(i == 3)
    {
      memcpy(serNum4, str, 5);
      rfid.showCardID(serNum4);//show the card ID
    }
    Serial.println();
    Serial.println();
  }
  delay(100);
  rfid.halt(); //command the card into sleep mode 
}

