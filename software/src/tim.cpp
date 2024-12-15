#include "tim.h"
#include <Arduino.h>
#include <HardwareTimer.h>

// Define PWM pins using Arduino pin numbers
const uint8_t PWM_PINS[] = {
    PA6,  // TIM3_CH1
    PA7,  // TIM3_CH2 
    PB0,  // TIM3_CH3
    PB1,  // TIM3_CH4
    0     // End marker
}; 

// Define channel mappings for Timer3
const PinMap PinMap_TIM[] = {
    // TIM3 Channels
    {PA_6,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, 0, 1, 0)}, // TIM3_CH1
    {PA_7,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, 0, 2, 0)}, // TIM3_CH2  
    {PB_0,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, 0, 3, 0)}, // TIM3_CH3
    {PB_1,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, 0, 4, 0)}, // TIM3_CH4
    {NC,    NP,    0}
};

// Define hardware timer instance for Timer3
HardwareTimer *Timer3 = new HardwareTimer(TIM3);

void setupTimer3() {
    Timer3->pause();
    Timer3->setMode(1, TIMER_OUTPUT_COMPARE_PWM1, PWM_PINS[0]);
    Timer3->setMode(2, TIMER_OUTPUT_COMPARE_PWM1, PWM_PINS[1]);
    Timer3->setMode(3, TIMER_OUTPUT_COMPARE_PWM1,  PWM_PINS[2]);
    Timer3->setMode(4, TIMER_OUTPUT_COMPARE_PWM1, PWM_PINS[3]);
    
    // Configure for 50Hz operation
    Timer3->setPrescaleFactor(72);      // 72MHz/72 = 1MHz counting frequency
    Timer3->setOverflow(20000);         // 1MHz/20000 = 50Hz
    
    // Initialize all servos to middle position
    for(int i = 1; i <= 4; i++) {
        Timer3->setCaptureCompare(i, 1500); // 1.5ms pulse (90 degrees)
    }
    
    Timer3->refresh();
    Timer3->resume();
}

uint16_t angleToPulse(uint8_t angle) {
    // Ensure angle is within 0-180 range
    angle = constrain(angle, 0, 180);
    
    // Convert angle to pulse width (544-2400 microseconds for SG90)
    return map(angle, 0, 180, MIN_PULSE_US, MAX_PULSE_US);
}

void startPWM(uint8_t pin, uint16_t pulseWidth) {
    // Find channel number based on pin
    int channel = 0;
    for(int i = 0; i < 4; i++) {
        if(PWM_PINS[i] == pin) {
            channel = i + 1;
            break;
        }
    }
    
    if(channel > 0) {
        pulseWidth = constrain(pulseWidth, MIN_PULSE_US, MAX_PULSE_US);
        Timer3->setCaptureCompare(channel, pulseWidth);
    }
}

void setServoAngle(uint8_t pin, uint8_t angle) {
    uint16_t pulseWidth = angleToPulse(angle);
    startPWM(pin, pulseWidth);
}
