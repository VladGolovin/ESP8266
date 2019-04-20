#include <ESP8266WiFi.h>

void setup() {
  // Старт последовательного порта
  // для передачи текста в монитор
  Serial.begin(115200);
  // Настраиваем GPIO5 (D1) как ввод
  pinMode(5, INPUT);  
}

void loop() {
  // Читаем уровень на GPIO5 и выводим в монитор:
  Serial.print("State of GPIO 5: ");
  Serial.println(digitalRead(5));

  delay(1000);
}
