#include "SensymStorage.h"

SensymStorage::SensymStorage() { }

void SensymStorage::init(bool state) { preferences.begin("sensym", state); }
void SensymStorage::end() { preferences.end(); }

void SensymStorage::writeInt(char* key, int value) { preferences.putInt(key, value); }
void SensymStorage::writeF(char* key, float value) { preferences.putFloat(key, value); }
void SensymStorage::writeStr(char* key, String value) { preferences.putString(key, value); }

int SensymStorage::getInt(char* key) { return preferences.getInt(key, 0); }
float SensymStorage::getF(char* key) { return preferences.getFloat(key, 0.0f); }
String SensymStorage::getStr(char* key) { return preferences.getString(key, ""); }


void SensymStorage::rmKey(char* key) { preferences.remove(key); }
void SensymStorage::clear() { preferences.clear(); }
void SensymStorage::purge() {
    preferences.end();
    nvs_flash_erase(); // erase the NVS partition and...
    nvs_flash_init(); // initialize the NVS partition.
    ESP.restart();
}
