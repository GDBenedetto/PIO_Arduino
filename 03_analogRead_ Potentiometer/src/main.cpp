/*
Ziel dieser Übung ist es: 
- Anwendung eines analogen Pins
- Verwendung der Funktion analogRead()
- Nutzung eines Potentiometers zur Steuerung der Helligkeit einer LED
*/

#include <Arduino.h>

void setup() {
	pinMode(13, OUTPUT);     // Setzt Pin 13 als Ausgang (LED)
  pinMode(A0, INPUT);      // optional, aber dokumentiert die Absicht, dass A0 als Eingang verwendet wird
	Serial.begin(9600);      // Startet serielle Kommunikation zur Ausgabe von Messwerten
}

void loop() {
  
   int Wartezeit = analogRead(A0); // Liest den Analogwert vom Potentiometer (0–1023)
                                   // Parameter: uint8_t (Pin), Rückgabewert: int (0–1023)
  
   Serial.println(Wartezeit);      // Gibt den gelesenen Wert im Serial Monitor aus
  
   digitalWrite(13, 1);            // Schaltet die LED ein
  
   delay(Wartezeit);               // Wartet abhängig vom Potentiometerwert
  
   digitalWrite(13, 0);            // Schaltet die LED aus
  
   delay(Wartezeit);               // Wartet erneut (bestimmt Blinkfrequenz)
}