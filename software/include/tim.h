#ifndef __TIM_H__
#define __TIM_H__

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

// SG90 Servo constants
#define SERVO_FREQ 50        // 50Hz PWM frequency
#define MIN_PULSE_US 544     // Min pulse width for 0 degrees (SG90 specific)
#define MAX_PULSE_US 2400    // Max pulse width for 180 degrees (SG90 specific)
#define PERIOD_US 20000      // 20ms period (1/50Hz)
#define TIMER_CLOCK 72000000 // 72MHz timer clock for STM32

extern const uint8_t PWM_PINS[];

void setupTimer3();
void startPWM(uint8_t pin, uint16_t pulseWidth);
void setServoAngle(uint8_t pin, uint8_t angle);
uint16_t angleToPulse(uint8_t angle);

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */
