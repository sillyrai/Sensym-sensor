#include "display.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ------------------- OLED Params -------------------

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SDA_PIN 6
#define SCL_PIN 7
#define OLED_RESET -1

/* Character size
size    width       height
1	    6 px        8 px
2	    12 px       16 px
3	    18 px	    24 px
4       24 px	    32 px
*/

// ------------------- OLED Configuration -------------------

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ------------------- OLED Utils -------------------

void displayInit() {
    Wire.begin(SDA_PIN, SCL_PIN);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("OLED failed"));
    } else {
        writeDisplay("Starting...", "Sensym");
    }
}

void writeDisplay(String text1, String text2) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(text1);

    display.setTextSize(2);
    display.setCursor(22, 18);
    display.println(text2);

    display.display();
}
