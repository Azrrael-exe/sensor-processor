#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

template<class T>
class Read {
    public:
        Read();
        Read(T value, uint8_t source);
        uint8_t getSource();
        T getValue();
    private:
        T value;
        uint8_t source;
};

template<class T>
Read<T>::Read(T value, uint8_t source) {
    this->value = value;
    this->source = source;
}

template<class T>
Read<T>::Read() {}

template<class T>
T Read<T>::getValue() {
    return this->value;
}

template<class T>
uint8_t Read<T>::getSource() {
    return this->source;
}

template<class T>
class SensorABC {
    public:
        SensorABC(uint8_t id);
        bool hasChanged();
        Read<T> getValue();
        uint8_t getId();
        void excecute();
    private:
        bool changed;
        T raw_value;
        Read<T> value;
        uint8_t id;
        virtual T read();
};

template<class T>
SensorABC<T>::SensorABC(uint8_t id){
    this->id = id;
}

template<class T>
Read<T> SensorABC<T>::getValue(){
    this->changed = false;
    return this->value;
}

template<class T>
uint8_t SensorABC<T>::getId(){
    return this->value;
}

template<class T>
bool SensorABC<T>::hasChanged(){
    return this->changed;
}

template<class T>
void SensorABC<T>::excecute(){
    T new_value = this->read();
    if(new_value != this->raw_value){
        this->changed = true;
        this->value = Read<T>(new_value, this->id);
    }
}

#endif