#ifndef __MOVE_H__
#define __MOVE_H__

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const uint8_t leg_pin[];

void moveForward();
void moveLegForward(uint8_t leg);
void moveLegBackward(uint8_t leg);
void landLeg(uint8_t leg);


void trotGait();
#ifdef __cplusplus
}
#endif

#endif /* __MOVE_H__ */