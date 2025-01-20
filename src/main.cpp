#include <Arduino.h>

// Define pin constants for easy modification and reference
static const int ANALOG_PIN_A = 1;  // Corresponds to A0 (GPIO1)
static const int ANALOG_PIN_B = 2;  // Corresponds to A1 (GPIO2)

void setup() {
  // Initialize serial communication with a baud rate of 115200
  Serial.begin(115200);

  // Attach the pins to ADC (ESP32-specific function)
  adcAttachPin(ANALOG_PIN_A);
  adcAttachPin(ANALOG_PIN_B);

  // Set ADC attenuation to 11 dB, allowing measurements from 0 to approximately 3.3V
  analogSetAttenuation(ADC_11db);
}

void loop() {
  // Read raw ADC values (ranging from 0 to 4095)
  int rawValueA = analogRead(ANALOG_PIN_A);
  int rawValueB = analogRead(ANALOG_PIN_B);

  // Convert raw values to actual voltage (in volts)
  float voltageA = (rawValueA / 4095.0) * 3.3;
  float voltageB = (rawValueB / 4095.0) * 3.3;

  // Print the output to the serial monitor
  Serial.print("Pin A Voltage: ");
  Serial.print(voltageA);
  Serial.print(" V | Pin B Voltage: ");
  Serial.print(voltageB);
  Serial.println(" V");

  // Pause for one second before the next measurement
  delay(1000);
}
