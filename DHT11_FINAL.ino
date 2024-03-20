#include <DHT.h>

// Replace with your DHT sensor type (DHT22) and pin (assuming GPIO2)
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  // Set up DHT sensor
  dht.begin();
}

void loop() {
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\tTemperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}
