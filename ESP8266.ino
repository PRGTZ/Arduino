#include <ESP8266WiFi.h>
#include <DHT.h>

const char* ssid = "POCO X3 Pro";
const char* password = "987654321";
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  server.begin();
  dht.begin();
  Serial.println("DHT11 server started!");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            float humidity = dht.readHumidity();
            if (isnan(humidity)) {
              client.println("HTTP/1.1 500 Internal Server Error");
              client.println("Content-Type: text/plain");
              client.println("Connection: close");
              client.println();
              client.println("Failed to read from DHT sensor");
            } else {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type: text/plain");
              client.println("Connection: close");
              client.println();
              client.println(humidity);
            }
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    delay(1);
    client.stop();
  }
}
