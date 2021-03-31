#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <actuator/actuator.h>
#include <entities/signal.h>

class Led : public ActuatorABC<float> {
    public:
        Led(uint8_t id, uint8_t pin):ActuatorABC<float>(id){
            this->pin=pin;
        }
    private:
        uint8_t pin;
        void write(Signal value);
};

void Led::write(Signal value) {
    bool bool_value  = (0.5 > value.getValue());
    digitalWrite(this->pin, bool_value);
}

#endif