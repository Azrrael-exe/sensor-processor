#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <Arduino.h>
#include <entities/value.h>

class Temperature : public ValueABC<float> {
    public:
        Temperature():ValueABC(){};
        Temperature(float value, uint8_t source):ValueABC(value, source){};
};

#endif
