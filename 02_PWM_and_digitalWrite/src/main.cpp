#include <Arduino.h>

// setup() läuft genau einmal beim Start.
void setup() {
  pinMode(11, OUTPUT); // Pin 11 steuert die LED.
  pinMode(3, OUTPUT);  // Pin 3 steuert den Piezo.
}

// loop() läuft danach immer wieder.
void loop() {
  // int ist ein ganzzahliger Datentyp.
  // value zählt von 0 bis 255.
  // 0 = aus, 255 = volle Leistung.
  for (int value = 0; value <= 255; value++) {
    analogWrite(11, value); // LED wird heller.
    analogWrite(3, value);  // Piezo bekommt mehr Signal.
    delay(40);              // Kurze Pause pro Schritt.
  }

  // value zählt wieder zurück.
  for (int value = 255; value >= 0; value--) {
    analogWrite(11, value); // LED wird dunkler.
    analogWrite(3, value);  // Piezo bekommt weniger Signal.
    delay(40);              // Kurze Pause pro Schritt.
  }
}
