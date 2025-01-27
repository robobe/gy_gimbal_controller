#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>

// Create an MPU6050 object
MPU6050 mpu;

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    
    // Initialize the I2C communication
    Wire.begin();
    mpu.initialize();
    if (mpu.testConnection()) {
        Serial.println("MPU6050 connection successful!");
    } else {
        Serial.println("MPU6050 connection failed. Check wiring!");
        while (1);
    }
}

void loop() {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    // Read raw accelerometer and gyroscope data
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    // Delay for readability
    delay(500);
}
