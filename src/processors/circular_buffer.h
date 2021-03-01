#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <Arduino.h>

template<class T>
class CircularBuffer {
private:
    T *buffer;
    uint8_t size;
public:
    CircularBuffer(int);
    void append(T value);
    uint8_t get_size(){
        return this->size;
    };
    float mean();
};

template<class T>
CircularBuffer<T>::CircularBuffer(int s) {
    this->size = s;
    buffer = new T[size];
}

template<class T>
void CircularBuffer<T>::append(T value) {
    for(int i = this->size - 1; i > 0; i--){
        this->buffer[i] = this->buffer[i - 1];
    }
    this->buffer[0] = value;
}

template<class T>
float CircularBuffer<T>::mean(){
    T sum = 0;
    for(int i = 0; i < this->size; i++) {
        sum += this->buffer[i];
    }
    return float(sum) / size;
}

#endif
