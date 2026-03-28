#include <Arduino.h>

void setup() {
  
  Serial.begin(9600);
  
  // -----------------------------------
  // Digitale Pins als Ausgangs nutzen
  // -----------------------------------
  pinMode(13, 1);       // 1 = OUTPUT
  
  // -----------------------------------
  // Digitale Pins als Eingang nutzen
  // -----------------------------------
  
  // Variante 1 - Pull-Down circuit r=10 kOhm!!!
  pinMode(9, 0);       // Versuchen Sie zuert mit 0 (INPUT) und R=10 kOhm
                       // danach mit 2 (INPUT_PULLUP). Das verhalten (Beobachtung) bleibt gleich wie bei 'INPUT'
  					           // jetzt mit R=1000 kOhm bleibt immer auf 1 (HIGH)
  
  // Variante 2  - Pull-Up circuit r=10 kOhm oder 4,7!!!
  pinMode(7, 2);       // 2 = INPUT_PULLUP
                       // Bei diesem Schaltkreis ist das beobachtete Leseverhalten von Pin 7 mit INPUT und INPUT_PULLUP praktisch gleich.

}


void loop() {
  
  // Digitale Pins als Ausgangs benutzen
  digitalWrite(13,1);  // (LED_BUILTIN, HIGH oder true)    
  //delay(1000);
  digitalWrite(13,false);  // (LED_BUILTIN, HIGH oder true)    
  //delay(1000);
  
  // -----------------------------------
  // Digitale Pins als Eingang nutzen
  // -----------------------------------

  // Variante 1
  Serial.print("D_Pin 9: ");
  Serial.println(digitalRead(9));
  
  // Variante 2
  Serial.print("D_Pin 7: ");
  Serial.println(digitalRead(7));

  
  delay(1000);
}