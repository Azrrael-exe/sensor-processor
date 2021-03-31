#ifndef SIGNAL_H
#define SIGNAL_H

#include <Arduino.h>
#include <entities/value.h>


class Signal : public ValueABC<float> {
    public:
        Signal():ValueABC(){};
        Signal(float value, uint8_t source):ValueABC(value, source){};
};

#endif