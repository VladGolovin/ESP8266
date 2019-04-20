#include <ESP8266WiFi.h>

const char* ssid="100110100";
const char* password="6543265432";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
