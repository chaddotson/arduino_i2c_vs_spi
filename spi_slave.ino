// SPI SLAVE

#include <SPI.h>

int buttonPin = 2;

byte state = 0;
int tx;
int rx;


void SlaveInit(void) {
  // Initialize SPI pins.
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, INPUT);
  pinMode(SS, INPUT);
  // Enable SPI as slave.
  SPCR = (1 << SPE);
}


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); 

  SlaveInit(); 
  
}

void loop() {

  if (!digitalRead(SS)) {


    pinMode(MISO, OUTPUT);
  
    tx = digitalRead(buttonPin);


    rx = SPI.transfer(state);
      
    if(state) {
      Serial.println("Button is pressed");
    } else {
      Serial.println("Button is not pressed");
    }


    pinMode(MISO, INPUT);
  }
  //delay(500);
  
}
