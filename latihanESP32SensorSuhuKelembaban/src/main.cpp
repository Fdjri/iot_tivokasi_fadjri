#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 27      // Pin yang terhubung ke sensor DHT22
#define DHTTYPE DHT22  // Tipe sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  delay(500);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  
  Serial.print(F("%  Temperature: "));
  Serial.print(t);

  Serial.print(F("°C "));
  Serial.print(f);

  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);

  Serial.print(F("°C "));
  Serial.print(hif);

  Serial.println(F("°F"));
}
