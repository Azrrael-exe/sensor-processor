#include <Arduino.h>
#include <config.h>
#include <serializers/output.h>
#include <processors/circular_buffer.h>
#include <processors/trasnformer.h>


CircularBuffer<int> circular = CircularBuffer<int>(10);

void setup() {
  Serial.begin(115200);
  pinMode(CONFIG::SENSOR_INPUNT, INPUT);
}

void loop() {
  int raw_read = analogRead(CONFIG::SENSOR_INPUNT);
  int scaled_read = scaler<int>(raw_read, 1.0);
  int processed_read = truncate<int>(scaled_read, 1023, 0);
  circular.append(raw_read);
  int mean = circular.mean();
  
  valuePrinter(Serial, mean, "Mean Value");
  valuePrinter(Serial, processed_read, "Proc Value");
  delay(500);
}
