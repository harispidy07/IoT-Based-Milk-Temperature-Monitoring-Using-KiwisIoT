#include <OneWire.h>
#include <DallasTemperature.h>
#include <KiwisIoT.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

// DS18B20 sensor
#define SENSOR_PIN D2

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

// Temperature monitoring range
const float MIN_TEMP = 2.0;
const float MAX_TEMP = 6.0;

// Update interval
unsigned long lastSend = 0;
const unsigned long SEND_INTERVAL = 5000;

float milkTemperature = 0;
String temperatureStatus = "NORMAL";

void setup()
{
  Serial.begin(115200);

  sensors.begin();

  kiwisiot.begin();

  Serial.println("Milk Temperature Monitoring Started");
}

void loop()
{
  kiwisiot.run();

  if (millis() - lastSend >= SEND_INTERVAL)
  {
    lastSend = millis();

    sensors.requestTemperatures();

    milkTemperature =
      sensors.getTempCByIndex(0);

    // Sensor validation
    if (milkTemperature == DEVICE_DISCONNECTED_C)
    {
      Serial.println("DS18B20 Sensor Error");
      return;
    }

    // Temperature status
    if (milkTemperature < MIN_TEMP)
    {
      temperatureStatus = "LOW TEMPERATURE";
    }
    else if (milkTemperature > MAX_TEMP)
    {
      temperatureStatus = "HIGH TEMPERATURE";
    }
    else
    {
      temperatureStatus = "NORMAL";
    }

    // Serial Monitor
    Serial.println("----------------------");

    Serial.print("Milk Temperature: ");
    Serial.print(milkTemperature);
    Serial.println(" C");

    Serial.print("Temperature Status: ");
    Serial.println(temperatureStatus);

    // Send to KiwisIoT
    kiwisiot.send("0", String(milkTemperature, 2));

    kiwisiot.send("1", temperatureStatus);
  }
}