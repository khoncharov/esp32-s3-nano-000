#include <Arduino.h>

#define LED_PIN 48

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);  // Дать USB‑CDC время подняться

  Serial.println("ESP32-S3 Nano: LED + millis() test");
}

void loop() {
  static bool state = false;

  // Переключаем LED
  state = !state;
  digitalWrite(LED_PIN, state);

  // Печатаем время в миллисекундах
  Serial.printf("Time: %lu ms\n", millis());

  delay(1000);
}