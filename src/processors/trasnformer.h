#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>

template<class T>
T scaler(T inp, float scale) {
    return T(inp * scale);
}

template<class T>
T truncate(T inp, T max, T min) {
    if (inp <= min) {
        return inp;
    } 
    else if (inp >= max) {
        return max;
    }
    return inp;
}

#endif