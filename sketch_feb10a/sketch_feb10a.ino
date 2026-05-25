#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your network credentials
const char* ssid = "140-1";
const char* password = "EDUARDS06";
const char* serverName = "http://192.168.1.3:3000/api/sensors/02d2b4af7e500f8b";

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected! IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;

        // Initialize HTTP connection
        http.begin(client, serverName);

        // Specify content-type header
        http.addHeader("Content-Type", "application/json");

        // Prepare your JSON data
        String httpRequestData = "{\"type\":\"temperature\",\"values\":null}";

        // Send HTTP POST request
        int httpResponseCode = http.POST(httpRequestData);

        if (httpResponseCode > 0) {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            String payload = http.getString();
            Serial.println("Response from server: " + payload);
        } else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
        }

        // Free resources
        http.end();
    } else {
        Serial.println("WiFi Disconnected");
    }

    delay(10000);  // Wait 10 seconds
}