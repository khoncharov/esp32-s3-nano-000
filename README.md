Board - ESP32 S3 Nano
Chip - fh4r2

usb vid:pid=303A:1001 ser=3c:0f:02:e1:ae:00 location=1-1:x.0

Проверка через буфера:
``` cpp
if (Serial.availableForWrite() > 10) {
  // Шлем данные только если в буфере есть место
  Serial.println("Hello");
}
```
