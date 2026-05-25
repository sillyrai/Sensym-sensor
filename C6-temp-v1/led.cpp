#include "led.h"
#include <Adafruit_NeoPixel.h>

// ------------------- LED Params-------------------

#define LED_PIN 8
#define NUM_LEDS 1

// ------------------- LED Configuration -------------------

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// ------------------- LED Utils -------------------

void ledInit() {
    strip.begin();
    strip.show();
}

void ledColor(uint8_t r, uint8_t g, uint8_t b) {
    strip.setPixelColor(0, strip.Color(r, g, b));
    strip.show();
}

void ledOn() {
    strip.setPixelColor(0, strip.Color(255, 255, 255));
    strip.show();
}
void ledOff() {
    strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.show();
}
