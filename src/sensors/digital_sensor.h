#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include <Arduino.h>
#include <sensors/sensor.h>


class DigitalSensor : public SensorABC<bool> {
    public:
        DigitalSensor(uint8_t id, uint8_t pin):SensorABC<bool>(id) {
            this->pin = pin;
        };
    private:
        uint8_t pin;
        bool read();
};


bool DigitalSensor::read() {
    return digitalRead(this->pin);
}

#endif