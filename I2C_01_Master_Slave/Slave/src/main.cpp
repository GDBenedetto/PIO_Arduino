#include <Arduino.h>  // Grundlegende Arduino-Funktionen

#include <Wire.h>  // I²C-Bibliothek

void setup() {
  Wire.begin(8);  
  // Startet den I²C-Bus als SLAVE mit Adresse 8
  // → Diese Adresse wird vom Master angesprochen

  Wire.onReceive(receiveEvent);  
  // Registriert eine Funktion (Callback),
  // die AUTOMATISCH aufgerufen wird,
  // wenn Daten empfangen werden

  Serial.begin(9600);
  // Für Ausgabe im Serial Monitor
}



void loop() {
  // Bleibt leer!
  // → Wichtig: Empfang passiert über Interrupt/Callback
}



void receiveEvent(int numberOfBytes) {
  // Diese Funktion wird aufgerufen,
  // sobald Daten vom Master ankommen

  Serial.print("Empfangen: ");

  while (Wire.available()) {
    // Prüft, ob noch Daten im Puffer sind

    char c = Wire.read();
    // Liest ein Byte aus dem I²C-Puffer

    Serial.print(c);
    // Gibt das empfangene Zeichen aus
  }

  Serial.println();
}

/*

Was passiert intern?
Master sendet Daten an Adresse (z. B. 8)
Die I²C-Hardware im Slave erkennt:
→ „Das ist meine Adresse!“
Die Hardware speichert die Daten in einem Puffer
Dann wird automatisch deine Funktion aufgerufen:

void receiveEvent(int numberOfBytes)

Wichtig:
Das passiert nicht im loop()
Sondern asynchron (im Hintergrund)

*/












