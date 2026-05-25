#include <Arduino.h>
#include <math.h>

#include "temp.h"
#include "display.h"
#include "SensymWiFi.h"
#include "led.h"

#define WIFI_ssid "140-1"
#define WIFI_password "EDUARDS06"

#define WIFI_serverDataEndpoint "http://192.168.1.3:3000/api/sensors/02d2b4af7e500f8b"
#define WIFI_serverHeartbeatEndpoint ""

#define smallWait = 500
#define bigWait = 2000

SensymWiFi wifi(
    WIFI_ssid,
    WIFI_password,
    WIFI_serverDataEndpoint
);

float oldTemp = 0;
int waitT = bigWait;

void setup() {
    Serial.begin(115200);

    ledInit();       // LED Init
    displayInit();   // OLED Init
    tempInit();      // Temperature sensor Init
    wifi.init();     // WiFi Init
    wifi.setSerialLog(true);
}

void loop() {
    float temp = tempGet();

    if (!isnan(temp)) {
        if (fabs(temp - oldTemp) >= 0.1f) {
            Serial.print(oldTemp);
            Serial.print(" -> ");
            Serial.println(temp);

            writeDisplay("Sending...",  String(temp) + " C");
            int res = wifi.sendTemp(temp);
            writeDisplay("Response: " + String(res), String(temp) + " C");
            oldTemp = temp;
            if (waitT != smallWait) { waitT = smallWait; }
        } else {
            writeDisplay("", String(temp) + " C");
            if (waitT != bigWait) { waitT = bigWait; }
        }
    } else {
        writeDisplay("error", "Null"); // Error display
    }

    delay(waitT);
}
