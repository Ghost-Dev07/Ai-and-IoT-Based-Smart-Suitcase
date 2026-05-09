#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  pinMode(D5,INPUT);//ir
  pinMode(D4,OUTPUT);//output for ps
  pinMode(D6,OUTPUT);//FMS
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
 
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  if(ps1==ps2)
  {
    digitalWrite(D4,HIGH);
  }
  else
  {
    digitalWrite(D4,LOW);
  }
  if(digitalRead(D5)==LOW)
  {
    status=HIGH;
  }
  else
  {
    status=LOW;
  }
  if(update==HIGH)
  {
    ps1=ps2;
  }
 
  gps=Location(12.9410, 77.5655);
 // locate=Location(12.941, 77.565); //BMS coordinates
  ArduinoCloud.update();
  // Your code here 
  
  
}
