#include <Wire.h>
#include "PCF8574.h"

// Pin definitions
const int SDA_PIN = 21;  // Custom SDA pin for ESP32 
const int SCL_PIN = 22;  // Custom SCL pin for ESP32 
const uint32_t CLOCK_SPEED = 400000;  // 400kHz I2C speed (più veloce del valore predefinito di 100kHz)

// Create a PCF8574Config structure with custom settings
PCF8574Config customConfig;

void setup() {
    Serial.begin(9600);
    while (!Serial);

    // Set custom I2C configuration
    customConfig.sdaPin = SDA_PIN;      // Assign custom SDA pin
    customConfig.sclPin = SCL_PIN;      // Assign custom SCL pin
    customConfig.clockSpeed = CLOCK_SPEED; // Set custom I2C clock speed

    // Create a PCF8574 instance with the custom configuration
    PCF8574 pcf(0x20, customConfig); // I2C address 0x20 and custom configuration

    // Check if PCF8574 is available
    if (pcf.available()) {
        Serial.println("PCF8574 with custom I2C configuration initialized successfully!");
    } else {
        Serial.println("Failed to initialize PCF8574!");
        while (1);
    }

    // Set all pins to OUTPUT
    pcf.SetAllPinMode(OUTPUT);

    // Set initial value to all HIGH (0xFF)
    pcf.WriteAll(0xFF);
}

void loop() {
    // Toggle all pins
    pcf.ToggleAll();
    delay(1000);
}
