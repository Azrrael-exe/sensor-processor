#ifndef LM35_H
#define LM35_H

#include <Arduino.h>
#include <sensors/sensor.h>


class Lm35: public SensorABC<float> {
    public:
        Lm35(uint8_t id, uint8_t pin):SensorABC<float>(id) {
            this->pin = pin;
        };
    private:
        uint8_t pin;
        float read();
};


float Lm35::read() {
    float raw_voltage = 5000 * (analogRead(this->pin) / 1023);
    return raw_voltage / 10;
}

#endif