#include <Servo.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Wire.h>


Servo profundor;

int pos = 0;

void setup() {
  Wire.begin(); // Inicia como mestre
  profundor.attach(9); // Servo no pino 9
  Serial.begin(9600);  // Para depuração se quiser
}

void loop() {
  // Suponha que o mestre recebe algum valor, por exemplo, da I2C:
  Wire.requestFrom(8, 1); // Pede 1 byte ao escravo com endereço 8

  if (Wire.available()) {
    pos = Wire.read(); // Lê o ângulo vindo do escravo (sensor, por exemplo)
    pos = constrain(pos, 0, 180); // Garante que está no intervalo permitido
    profundor.write(pos); // Move o servo
    Serial.println(pos); // Debug
  }

  delay(100); // Espera um pouco
}
