#ifndef LED_H
#define LED_H

#include <Arduino.h>

void ledInit();
void ledColor(uint8_t r, uint8_t g, uint8_t b);
void ledOn();
void ledOff();

#endif
