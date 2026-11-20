# IoT-Based Milk Temperature Monitoring Using KiwisIoT

## Project Overview

This project monitors milk temperature using IoT technology to help maintain suitable milk storage conditions. The NodeMCU ESP8266 collects temperature readings from a sensor and sends the data to the KiwisIoT dashboard, allowing users to monitor milk storage temperature remotely.

## Hardware Components

- NodeMCU ESP8266
- DS18B20 Temperature Sensor
- Jumper wires
- Power supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- OneWire Library
- DallasTemperature Library
- KiwisIoT Arduino Library
- KiwisIoT Dashboard

## Circuit Connections

| DS18B20 Sensor | NodeMCU ESP8266 |
| -------------- | --------------- |
| VCC            | 3.3V            |
| GND            | GND             |
| DATA           | D4              |

<text color="secondary" size="sm">A 4.7kΩ pull-up resistor is typically connected between DATA and VCC when using a bare DS18B20 sensor.</text>

## Working Principle

The DS18B20 sensor measures the milk storage temperature. The NodeMCU ESP8266 reads the sensor data and transmits the temperature to the KiwisIoT platform over Wi-Fi.

The dashboard enables users to monitor temperature readings remotely and identify temperature changes that may affect milk storage conditions.

## KiwisIoT Dashboard

- View real-time milk temperature.
- Monitor storage temperature remotely.
- Track temperature changes.
- Support milk storage condition monitoring.

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the project configuration.

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

## Applications

- Milk storage monitoring
- Dairy farms
- Milk collection centers
- Dairy processing facilities
- Refrigerated milk storage

## Project Reference

**Hackster.io Project:**  
[IoT-Based Milk Temperature Monitoring Using KiwisIoT](https://www.hackster.io/harispidy07/iot-based-milk-temperature-monitoring-using-kiwisiot-4e4b42)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Smart dairy monitoring through real-time IoT connectivity._
