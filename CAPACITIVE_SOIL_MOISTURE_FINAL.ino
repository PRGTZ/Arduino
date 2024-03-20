/*
 Soil Moisture Sensor 
  Conectar tierra a negativo de la fuente
  Concectar VCC a 5V
  Conectar AUOT a la entrada analógica GPIO0
 */

#include <ESP8266WiFi.h>
#include <CapacitiveSensor.h>

const char *ssid = "NombreDeTuRed";
const char *password = "TuClaveDeRed";
const char *serverIp = "DirecciónIPDelServidor"; // Cambiar por la IP de tu ESP32
const int serverPort = 4000; //Cambiar por cada nuevo ESP01S a programar 4000-12000

// Definición de pines
#define AOUT_PIN 0 // ESP8266 pin GPIO0 (ADC) that connects to AOUT pin of moisture sensor

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");
}

void loop() {
  WiFiClient client;
  if (client.connect(serverIp, serverPort)) {
    // Medir la humedad del suelo
    int value = analogRead(AOUT_PIN); // read the analog value from sensor

    Serial.print("Moisture value: ");
    int soilMoisture = map(value, 0, 1023, 0, 100); // ESP8266 ADC range is 0-1023

    // Enviar datos al servidor
    client.print("Humedad del suelo: ");
    client.println(soilMoisture);


    // Cerrar la conexión
    client.stop();
    delay(5000); // Ajustar el retardo según sea necesario
  } else {
    Serial.println("Error al conectar al servidor");
    delay(5000);
  }
}
