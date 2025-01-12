#include <DHT.h>

// Define the pin where DHT11 data pin is connected
#define DHT_PIN 2
#define DHT_TYPE DHT11

// Create DHT object
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Air Quality Monitor");
  
  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Reading temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}
