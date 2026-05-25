#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ------------------- OLED Configuration -------------------

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SDA_PIN 6
#define SCL_PIN 7
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int oneWireBus = 4; // GPIO pin where the DS18B20 DQ wire is connected
OneWire oneWire(oneWireBus); // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature sensor

// ------------------- My Functions -------------------

void writeSerialTemp(float temp) {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("°C");
}

void writeDisplay(String text) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(25, 20);

    display.println(text);

    display.display();
}

void writeDisplayTemp(float temp) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(25, 20);

    // Print the temperature with 1 decimal place
    display.print(temp, 1);
    display.println(" C");  // 'C' instead of '°C' for simpler font handling

    display.display();
}

// ------------------- Real Code -------------------

void setup(void) {
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("OLED failed"));
    } else {
        writeDisplay("Yo!");
    }

    sensors.begin();
    writeDisplay("DS18B20 Initialized");
}

void loop(void) {
    // Request temperatures from the sensor
    sensors.requestTemperatures();

    // Fetch the temperature in Celsius
    float temperatureC = sensors.getTempCByIndex(0);

    // Check if reading was successful
    if (temperatureC != DEVICE_DISCONNECTED_C) {
        writeDisplayTemp(temperatureC);
    } else {
        Serial.println("Error: Could not read temperature data");
    }

    // Wait 0.1 seconds before next reading
    delay(1000);
}