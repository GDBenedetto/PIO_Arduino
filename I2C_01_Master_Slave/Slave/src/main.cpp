#include <Arduino.h> // diese bibliothek führt zu einem fehler in thinkercad

/*
  I2C Slave Demo
  i2c-slave-demo.ino
  Demonstrate use of I2C bus
  Slave receives character from Master and responds
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define Slave answer size
#define ANSWERSIZE 5

String answer = "Hello";

// 🔧 Funktionsprototypen
void requestEvent();
void receiveEvent(int howMany);

void setup() {

  Wire.begin(SLAVE_ADDR);
  
  Wire.onRequest(requestEvent); 
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}

void receiveEvent(int howMany) {

  while (Wire.available()) {
    byte x = Wire.read();
    Serial.println(x);
  }
  
  Serial.println("Receive event");
}

void requestEvent() {

  byte response[ANSWERSIZE];
  
  for (byte i = 0; i < ANSWERSIZE; i++) {
    response[i] = (byte)answer.charAt(i);
  }
  
  Wire.write(response, sizeof(response));
  
  Serial.println("Request event");
}

void loop() {
  delay(50);
}