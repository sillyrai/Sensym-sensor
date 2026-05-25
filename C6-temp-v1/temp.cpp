#include <OneWire.h>
#include <DallasTemperature.h>

#include "temp.h"

// ------------------- Temp Params -------------------

const int oneWireBus = 4;

// ------------------- Temp Configuration -------------------

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// ------------------- Temp Utils -------------------

void tempInit() {
    sensors.begin();
}

float tempGet() {
    sensors.requestTemperatures();
    float temp = sensors.getTempCByIndex(0);

    if (temp != DEVICE_DISCONNECTED_C) {
        return temp;
    } else {
        return NAN;
    }
}
