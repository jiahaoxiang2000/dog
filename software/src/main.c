#include "main.h"

void setup() {
    // Initialize LED pin as output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Toggle LED
    digitalWrite(LED_PIN, HIGH);
    delay(1000);  // Wait for 1 second
    digitalWrite(LED_PIN, LOW);
    delay(1000);  // Wait for 1 second
}
