#include <Arduino.h>

#define PORT_SPEED 115200

#define LED_PIN 48

#define INIT_DELAY 2000
#define POLLING_INTERVAL 100

#define MODULE_1_ADDRESS 0x48
#define CHANNEL_1 0
#define CHANNEL_2 1
#define CHANNEL_3 2
#define CHANNEL_4 3

const uint8_t FRAME_LEN = 22;
uint8_t frame[FRAME_LEN];

uint16_t sensValue1;
uint16_t sensValue2;
uint16_t sensValue3;
uint16_t sensValue4;

uint32_t time_t0;
uint32_t time_t1;

bool led_state = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(PORT_SPEED);
  delay(INIT_DELAY);

  time_t0 = millis();
}

void loop() {
  time_t1 = millis();

  if (time_t1 - time_t0 >= POLLING_INTERVAL) {
    time_t0 = time_t1;

    sensValue1 = 123;
    sensValue2 = 12321;
    sensValue3 = 65535;
    sensValue4 = 32484;

    frame[0] = 0;
    frame[1] = 0;
    frame[2] = 0;
    frame[4] = 1;
    frame[7] = 2;
    frame[10] = 3;
    frame[13] = 4;
    frame[16] = 5;
    frame[19] = 6;

    frame[3] = MODULE_1_ADDRESS;

    frame[9] = lowByte(time_t1);
    time_t1 >>= 8;
    frame[8] = lowByte(time_t1);
    time_t1 >>= 8;
    frame[6] = lowByte(time_t1);
    time_t1 >>= 8;
    frame[5] = lowByte(time_t1);
    time_t1 >>= 8;

    frame[11] = highByte(sensValue1);
    frame[12] = lowByte(sensValue1);
    frame[14] = highByte(sensValue2);
    frame[15] = lowByte(sensValue2);
    frame[17] = highByte(sensValue3);
    frame[18] = lowByte(sensValue3);
    frame[20] = highByte(sensValue4);
    frame[21] = lowByte(sensValue4);

    led_state = true;
    digitalWrite(LED_PIN, led_state);

    Serial.write(frame, FRAME_LEN);

    led_state = false;
    digitalWrite(LED_PIN, led_state);
  }
}
