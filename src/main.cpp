#include <Arduino.h>
#include <config.h>
#include <serializers/output.h>
#include <processors/circular_buffer.h>
#include <processors/trasnformer.h>

#include <sensors/analog_sensor.h>
#include <sensors/digital_sensor.h>
#include <sensors/temperature/lm35.h>
#include <actuator/pump.h>
#include <actuator/led.h>

CircularBuffer<int> circular = CircularBuffer<int>(10);
AnalogSensor level_sensor = AnalogSensor(0x7A, A3);
Pump pump = Pump(0xAB, 7);
Led led = Led(0xAC, 13);


void setup() {
  Serial.begin(115200);
  pinMode(CONFIG::SENSOR_INPUNT, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  level_sensor.excecute();
  if(level_sensor.hasChanged()){
    ValueABC<float> value = level_sensor.getValue();

    // PID: Va aquí;

    pump.setValue(value);
    led.setValue(value);
  }
  pump.excecute();
  led.excecute();
}
