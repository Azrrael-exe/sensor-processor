#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include <Arduino.h>
#include <sensors/sensor.h>


class AnalogSensor : public SensorABC<float> {
    public:
        AnalogSensor(uint8_t id, uint8_t pin):SensorABC<float>(id) {
            this->pin = pin;
        };
    private:
        uint8_t pin;
        float read();
};


float AnalogSensor::read() {
    return (analogRead(this->pin) / 1023) * 1.0;
}

#endif