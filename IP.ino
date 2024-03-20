#include <ESP8266WiFi.h>
#include <Arduino.h>

const char *ssid = "POCO X3 Pro";
const char *password = "987654321";
IPAddress ip(192, 168, 1, 10); // La dirección IP estática que deseas asignar
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);



void setup() {
  Serial.begin(115200);

  // Conectar a la red WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  // Configurar la dirección IP estática
  WiFi.config(ip, gateway, subnet);

  Serial.println("Conectado a la red WiFi");
  Serial.print("Dirección IP asignada: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Tu código aquí
}
