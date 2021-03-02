#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include <Arduino.h>
#include <sensors/sensor.h>


class AnalogSensor : public SensorABC<int> {
    public:
        AnalogSensor(uint8_t id, uint8_t pin):SensorABC(id) {
            this->pin = pin;
        };
    private:
        uint8_t pin;
        int read();
};


int AnalogSensor::read() {
    return analogRead(this->pin);
}

#endif