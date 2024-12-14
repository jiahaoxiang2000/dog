#include "main.h"
#include "tim.h"

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
    
    // Test first servo with full range motion
    setServoAngle(PA6, 0);    // Move to 0 degrees
    delay(1000);
    setServoAngle(PA6, 90);   // Move to 90 degrees
    delay(1000);
    setServoAngle(PA6, 180);  // Move to 180 degrees
    delay(1000);
    
    digitalWrite(LED_PIN, HIGH);
}

void loop() {
    // Simple sweep test for first servo
    static int angle = 0;
    static int direction = 1;
    
    setServoAngle(PA6, angle);
    
    angle += direction;
    if(angle >= 180) {
        direction = -1;
        digitalWrite(LED_PIN, LOW);
    }
    if(angle <= 0) {
        direction = 1;
        digitalWrite(LED_PIN, HIGH);
    }
    
    delay(20);  // Slow down the sweep
}
