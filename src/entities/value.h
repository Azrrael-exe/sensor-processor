#ifndef VALUE_H
#define VALUE_H

#include <Arduino.h>

template<class T>
class ValueABC {
    public:
        ValueABC();
        ValueABC(T value, uint8_t source);
        uint8_t getSource();
        T getValue();
    private:
        T value;
        uint8_t source;
};

template<class T>
ValueABC<T>::ValueABC(T value, uint8_t source) {
    this->value = value;
    this->source = source;
}

template<class T>
ValueABC<T>::ValueABC() {}

template<class T>
T ValueABC<T>::getValue() {
    return this->value;
}

template<class T>
uint8_t ValueABC<T>::getSource() {
    return this->source;
}

#endif