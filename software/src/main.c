#include "main.h"
#include "tim.h"
#include "move.h"

#define LED_PIN PC13
#define TEST_DELAY 500    // Delay between servo movements in ms
#define BLINK_DELAY 200   // LED blink delay in ms

void testServo(uint8_t pin) {
    // Test sequence: 0° -> 90° -> 180° -> 90° -> 0°
    setServoAngle(pin, 0);
    delay(TEST_DELAY);
    setServoAngle(pin, 90);
    delay(TEST_DELAY);
    setServoAngle(pin, 180);
    delay(TEST_DELAY);
    setServoAngle(pin, 90);
    delay(TEST_DELAY);
    setServoAngle(pin, 0);
    delay(TEST_DELAY);
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    setupTimer3();
    delay(500);  // Give time for timer to stabilize
    
    // Initialize all servos to starting position
    for (int i = 0; i < 4; i++) {
        setServoAngle(leg_pin[i], 90);  // Center position
    }
    delay(1000);
    
    digitalWrite(LED_PIN, HIGH);
}

void loop() {
    // Call the moveForward function to move the robot forward
//    moveForward();
    // trotGait();
    // Blink LED to indicate movement cycle
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
}
