#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>


float t = 0;
float dt = 0.1; // intervalo de amostragem

void setup() {
  Serial.begin(9600);
}

void loop() {
  float gyro = 30.0 * sin(2 * PI * 0.5 * t);         // Giroscópio simulado
  float pressure = 1013.25 + 10 * sin(2 * PI * 0.1 * t); // Manômetro simulado

  Serial.print("Giro (deg/s): ");
  Serial.print(gyro);
  Serial.println('\n');
  Serial.print("\tPressão (hPa): ");
  Serial.println(pressure);
  Serial.println('\n')
  delay(dt * 1000);
  t += dt;
}



// Simula dados de giroscópio com oscilação senoidal
float simulateGyro(float t) {
  return 30.0 * sin(2 * PI * 0.5 * t); // 30°/s de amplitude, 0.5 Hz
}

// Simula pressão com uma base de 1013.25 hPa (pressão atmosférica) e variação
float simulatePressure(float t) {
  return 1013.25 + 10 * sin(2 * PI * 0.1 * t); // variação de 10 hPa a 0.1 Hz
}
