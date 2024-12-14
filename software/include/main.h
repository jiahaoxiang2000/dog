#ifndef __MAIN_H
#define __MAIN_H

#include <Arduino.h>

// Pin Definitions
#define LED_PIN         PC13      // Built-in LED on Blue Pill board
#define OLED_SCL_PIN    PB8       // OLED I2C Clock
#define OLED_SDA_PIN    PB9       // OLED I2C Data

// Function Prototypes
void setup(void);
void loop(void);

#endif /* __MAIN_H */
