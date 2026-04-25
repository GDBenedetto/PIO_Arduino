#include <Arduino.h>  // Grundlegende Arduino-Funktionen
#include <Wire.h>  // Bibliothek für I²C-Kommunikation



void setup() {
  Wire.begin();  
  // Startet den I²C-Bus als MASTER
  // → Kein Parameter = dieses Gerät ist Master!!!

  Serial.begin(9600);
  // Serielle Schnittstelle nur für Debugging / Anzeige
}



void loop() {

  Wire.beginTransmission(8);  
  // Startet eine Übertragung an ein Gerät mit Adresse 8
  // → Der Par. 8 ist die "Slave-Adresse" (muss eindeutig im Bus sein)

  Wire.write("Hallo");  
  // Sendet Daten an den Slave
  // → Hier: ein String (mehrere Bytes)
  // → Alternativ auch einzelne Bytes oder Arrays möglich

  Wire.endTransmission();  
  // Beendet die Übertragung
  // → Daten werden jetzt tatsächlich gesendet

  Serial.println("Nachricht gesendet");
  // Nur zur Kontrolle für Studierende

  delay(1000);  
  // Wartet 1 Sekunde
  // → Wichtig: verhindert, dass der Bus überlastet wird
}