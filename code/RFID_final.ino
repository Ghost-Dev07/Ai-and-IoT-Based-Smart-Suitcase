#include <SPI.h>
#include <MFRC522.h>
#include<Servo.h>
#define SS_PIN 10
#define RST_PIN 9
#define pin 3
#define LED 8
#define LED2 7
byte readCard[4];
String tag_UID2="138085A6";// correct tag
String tagID = "";
Servo myServo;
MFRC522 mfrc522(SS_PIN, RST_PIN); 
void setup()
{
  pinMode(2,INPUT);// ps1=ps2
  pinMode(LED,OUTPUT); // rfid led
  pinMode(LED2,OUTPUT);
  digitalWrite(LED, LOW); //pin 8
  Serial.begin(115200);        
  SPI.begin(); // SPI bus
  mfrc522.PCD_Init(); // Initialise MFRC522
}
int access=0;
int value=0;
void loop()
{
  int copy=digitalRead(2); //ps1=ps2
  while(readID())
  {
    if (tagID == tag_UID2)
    {
       if(copy==HIGH)
       {
          digitalWrite(LED, HIGH); 
          delay(1000);
          digitalWrite(LED, LOW);
          Serial.println("detected");
       }
      
    }
   
  }
   if(copy==LOW)
       {
          digitalWrite(LED, LOW); 
          Serial.println("not detected");
       }
 
}
  boolean readID()
  {
    //Check if a new tag is detected or not. If not return.
    if ( ! mfrc522.PICC_IsNewCardPresent())
    {
      return false;
    }
    //Check if a new tag is readable or not. If not return.
    if ( ! mfrc522.PICC_ReadCardSerial())
    {
      return false;
    }
    tagID = "";
    for ( uint8_t i = 0; i < 4; i++)
    {
      tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Convert the UID to a single String
    }
    tagID.toUpperCase();
    mfrc522.PICC_HaltA(); // Stop reading
    return true;
  }
