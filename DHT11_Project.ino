#include <DHT.h>

// تنظیمات سنسور
#define DHTPIN 2 // پین متصل به DATA سنسور
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature(); // خواندن دما
  float hum = dht.readHumidity();     // خواندن رطوبت

  if (isnan(temp) || isnan(hum)) {
    Serial.println("خطا در خواندن داده از سنسور!");
    return;
  }

  Serial.print("دمای محیط: ");
  Serial.print(temp);
  Serial.println("°C");

  Serial.print("رطوبت محیط: ");
  Serial.print(hum);
  Serial.println("%");

  delay(2000); // هر 2 ثانیه داده‌ها به‌روز شوند
}
