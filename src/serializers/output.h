#ifndef OUTPUT_FORMATER_H
#define OUTPUT_FORMATER_H

#include <Arduino.h>

void valuePrinter (Stream &uart, float value, char* label) {
    char output[64];
    sprintf(output, "%s -> %d \n", label, int(value));
    uart.print(output);
}

#endif