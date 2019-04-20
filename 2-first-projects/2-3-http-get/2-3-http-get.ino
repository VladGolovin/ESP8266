#include <ESP8266WiFi.h>
const char* ssid = "100110100";
const char* password = "6543265432";

const char* host = "example.com";
IPAddress server(64, 233, 162, 138);  // Google

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");  
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  Serial.print("Connecting to ");
  Serial.println(host);

  // Используем класс WiFiClient для создания подключения TCP
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failded");
    return;
  }
  else 
  {
    // Отправляем HTTP-запрос на сервер
    client.print(String("GET /") + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    // delay(10);

    delay(1000);
    // Читаем все строки ответа сервера и выводим их в монитор
    Serial.print("Connecting");
    
    while(!client.available()) {
      delay(500);
      Serial.print(".");
    }

    while(client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  
    Serial.println();
    Serial.println("closing connection");
    delay(5000);
  }
}
