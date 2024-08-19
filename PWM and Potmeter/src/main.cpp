#include <Arduino.h>

#define RPWM 12 // Pin for right direction
#define LPWM 13 // Pin for left direction
const int potentiometerPin = 14;  // Pin where the potentiometer is connected

void setup() {
    Serial.begin(115200);  // Start the serial communication at 115200 baud rate
    
    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);

    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
}

void loop() {
    int potValue = analogRead(potentiometerPin);  // Read the analog value from the potentiometer
    //Serial.println(potValue);  // Print the value to the serial monitor
    int distance = map(potValue, 0, 4095, 0, 980);  // Map the potentiometer value to the desired distance range
    //Serial.println(distance);  // Print the distance to the serial monitor
    //delay(100);  // Small delay to make it readable

    int speed = map(potValue, 0, 4095, 0, 255);  // Map the potentiometer value to the desired speed range
    analogWrite(RPWM, speed);
    analogWrite(LPWM, 0);
    // Serial.println(speed);  // Print the speed to the serial monitor
    // delay(100);  // Small delay to make it readable

    int currentPosition = analogRead(potentiometerPin);  // Read the current position of the motor
    int targetPosition = map(distance, 0, 980, 0, 4095);  // Map the desired distance to the potentiometer range
    int rpm = map(speed, 0, 255, 0, 3000);  // Map the speed to the desired RPM range
    Serial.println(rpm);  // Print the RPM to the serial monitor
    delay(100);  // Small delay to make it readable

    if (currentPosition < targetPosition) {
        analogWrite(RPWM, rpm);
        analogWrite(LPWM, 0);
    } else if (currentPosition > targetPosition) {
        analogWrite(RPWM, 0);
        analogWrite(LPWM, rpm);
    } else {
        analogWrite(RPWM, 0);
        analogWrite(LPWM, 0);
    }


   
}
