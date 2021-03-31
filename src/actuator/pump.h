#ifndef PUMP_H
#define PUMP_H

#include <Arduino.h>
#include <actuator/actuator.h>
#include <entities/signal.h>

class Pump : public ActuatorABC<float> {
    public:
        Pump(uint8_t id, uint8_t pin):ActuatorABC<float>(id){
            this->pin=pin;
        }
    private:
        uint8_t pin;
        void write(Signal value);
};

void Pump::write(Signal value) {
    uint8_t discrete_value = map(value.getValue(), 0, 1, 0, 255);
    analogWrite(this->pin, discrete_value);
}

#endif