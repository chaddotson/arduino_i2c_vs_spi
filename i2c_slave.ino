
// WIRE SLAVE

#include <Wire.h>


int buttonPin = 4;

byte state = 0;
int tx;
int rx;




void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); 

  Wire.begin(8);
  Wire.onRequest(requestEvent);


}

void loop() {
  
}

void requestEvent() {
  state = digitalRead(buttonPin);


  if(state) {
    Serial.println("Button is pressed");
  } else {
    Serial.println("Button is not pressed");
  }

  Serial.println(state, BIN);
  
  Wire.write(state);
}

