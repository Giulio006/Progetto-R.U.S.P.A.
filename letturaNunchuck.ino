#include <Wire.h>

void setup() {
  Wire.begin();        // Inizializza la libreria I2C
  Serial.begin(9600);  // Inizializza la comunicazione seriale per la visualizzazione dei dati
  nunchuk_init();      // Inizializza il Nunchuk
}

void loop() {
  nunchuk_getdata();
  delay(100); // Leggi i dati ogni 100 millisecondi (10Hz)
}

void nunchuk_init() {
  Wire.beginTransmission(0x52); // Indirizzo del Nunchuk
  Wire.write(0x40);
  Wire.write(0x00);
  Wire.endTransmission();
}

void nunchuk_getdata() {
  Wire.requestFrom(0xA4, 6); // Richiedi 6 byte di dati dal Nunchuk

  while (Wire.available()) {
    byte data = Wire.read();
    Serial.print(data, HEX);
    Serial.print(" ");
  }
  Serial.println();
}
