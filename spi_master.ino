// SPI MASTER


#include <SPI.h>

byte rx;

void setup() {
  Serial.begin(9600);
  SPI.begin();
}

void loop() {
  digitalWrite(SS, LOW);
  delay(20);
  rx = SPI.transfer(255);
  delay(20);

  if(rx) {
    Serial.println("Button is pressed");
  } else {
    Serial.println("Button is not pressed");
  }

  digitalWrite(SS, HIGH);
  delay(500);
}
