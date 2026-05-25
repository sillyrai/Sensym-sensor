#ifndef SENSYM_STORAGE_H
#define SENSYM_STORAGE_H

#include <Preferences.h>
#include <nvs_flash.h>
#include <Arduino.h>

class SensymStorage {
    public:
        SensymStorage();

        void init(bool state);
        void end(); 

        void writeInt(char* key, int value);
        void writeF(char* key, float value);
        void writeStr(char* key, String value);

        int getInt(char* key);
        float getF(char* key);
        String getStr(char* key);

        void rmKey(char* key);
        void clear();
        void purge();
    
    private:
        Preferences preferences;
};

#endif
