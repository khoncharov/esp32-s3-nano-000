#include <Arduino.h>

#define LED_PIN 48

#define DELAY 1000 // ms

bool led_state = false;

uint32_t time_t0;
uint32_t time_t1;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);
}

void loop() {
  time_t1 = millis();

  if (time_t1 - time_t0 >= DELAY) {
    time_t0 = time_t1;

    led_state = !led_state;
    digitalWrite(LED_PIN, led_state);

    Serial.printf("Time: %u s\n", millis()/1000);
  }
}
