
// WIRE MASTER

#include <Wire.h>



void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(8, 1);
  
  byte recvd = -1;

  if (Wire.available()) { 
    recvd = Wire.read(); 
  }

  if(recvd == 1) {
    Serial.println("Button is pressed");
  } else if(recvd == 0) {
    Serial.println("Button is not pressed");
  } else {
    Serial.println("Device didn't respond");
  }

  delay(500);

}
