/*
https://www.tinkercad.com/things/9rSTzxF0auL-21-servomotor
Servomotor mit Fotowiderstand steuern
Ziel ist:
- wie man die Servo-Bibliothek verwendet um einen Servomotor anzusteuern
- wie man ein Objekt erstellt und Methoden aufruft
- anwendung von präprozessor-Makros und Konstanten 
- wie man map() verwendet um Werte zu skalieren
*/

#include <Arduino.h>
#include "Servo.h"

#define SERVOPIN 10   // Digitaler Ausgang für Servosignal
#define SENSORPIN 17  // Analoger Eingang (z. B. A3 = 17)

/*
#define SERVOPIN 10
→ Präprozessor-Makro (reine Textersetzung, kein Datentyp)

const int SERVOPIN = 10;
→ Typisierte Konstante (empfohlen, sicherer)

#define A 10+5
int x = A * 2;   // → 10+5*2 = 20 (!)

const int A = 10+5;
int x = A * 2;   // → 30 (korrekt)
*/

Servo Servomotor;     // Servo-Objekt zur Ansteuerung

int Sensorwert;       // Speichert Analogwert (0–1023)
byte Servowinkel;     // Speichert Winkel (0–180°)

void setup() {
  Serial.begin(9600);        // Startet serielle Ausgabe
  Servomotor.attach(SERVOPIN); // Verbindet Servo mit Pin 10
} 

void loop() {
  Sensorwert = analogRead(SENSORPIN); // Liest Helligkeit vom Fotowiderstand
  
  Servowinkel = map(Sensorwert, 0, 1023, 0, 180); // Skaliert Wert auf Servo-Winkel
  
  Serial.println(Servowinkel); // Gibt berechneten Winkel aus
  
  Servomotor.write(Servowinkel); // Stellt Servo auf berechneten Winkel
  
  delay(50); // Kurze Pause für stabile Bewegung
}












