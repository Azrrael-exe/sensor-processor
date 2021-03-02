#include <Arduino.h>
#include <config.h>
#include <serializers/output.h>
#include <processors/circular_buffer.h>
#include <processors/trasnformer.h>

#include <sensors/analog_sensor.h>

CircularBuffer<int> circular = CircularBuffer<int>(10);
AnalogSensor sensor = AnalogSensor(0x7E, A0);

void setup() {
  Serial.begin(115200);
  pinMode(CONFIG::SENSOR_INPUNT, INPUT);
}

void loop() {
  
  sensor.excecute();
  if(sensor.hasChanged()){
    int raw_read = sensor.getValue().getValue();
    int scaled_read = scaler<int>(raw_read, 1.0);
    int processed_read = truncate<int>(scaled_read, 1023, 0);
    circular.append(raw_read);
    int mean = circular.mean();

    valuePrinter(Serial, mean, "Mean Value");
    valuePrinter(Serial, processed_read, "Proc Value");
  }

  delay(500);
}
