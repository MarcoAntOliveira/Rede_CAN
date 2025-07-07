#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define T_SENSOR 100  // Tempo de amostragem em milissegundos

SoftwareSerial mySerial(10, 11); // RX, TX (ligado ao Arduino de sensoriamento)

unsigned long previousMillis = 0;

void setup() {
  Wire.begin();             // Este Arduino será mestre I2C (para controle)
  Serial.begin(9600);       // Monitor serial
  mySerial.begin(9600);     // Comunicação com Arduino sensor
}

void loop() {
  // Envia comando via I2C para Arduino de controle
  Wire.beginTransmission(8); // Endereço I2C do escravo (navegação/controle)
  Wire.write(90);            // Ângulo do profundor (exemplo)
  Wire.endTransmission();

  // Lê dados do Arduino sensor a cada T_SENSOR milissegundos
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= T_SENSOR) {
    previousMillis = currentMillis;

    if (mySerial.available()) {
      // Lê uma string até o caractere de nova linha
      String data_mano = mySerial.readStringUntil('\n');
      Serial.print("Recebido do sensor: ");
      Serial.println(data_mano);
    }
  }

  delay(10); // Pequeno atraso para estabilidade
}
