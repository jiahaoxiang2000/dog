#include "move.h"
#include "tim.h"

#define STEP_DELAY 200    // Delay between steps in ms
const uint8_t leg_pin[] = {
    PA6,  // Right back
    PA7,  // Right front
    PB0,  // Left back
    PB1   // Left front
};

// Define leg pin mappings
#define RH leg_pin[0]  // Right Hind
#define RF leg_pin[1]  // Right Front
#define LH leg_pin[2]  // Left Front
#define LF leg_pin[3]  // Left Hind

void moveLegForward(uint8_t leg) {
    if (leg == leg_pin[0] || leg == leg_pin[1]) {
        // Right legs
        setServoAngle(leg, 150);   // Move leg forward
    } else {
        // Left legs
        setServoAngle(leg, 30);  // Move leg forward
    }
    delay(STEP_DELAY);
}

void moveLegBackward(uint8_t leg) {
    if (leg == leg_pin[0] || leg == leg_pin[1]) {
        // Right legs
        setServoAngle(leg, 30);  // Move leg backward
    } else {
        // Left legs
        setServoAngle(leg, 150);   // Move leg backward
    }
    delay(STEP_DELAY);
}

void landLeg(uint8_t leg) {
    setServoAngle(leg, 90);   // Land leg (center position)
    delay(STEP_DELAY);
}

void moveForward() {

    // Phase 1: LH lifts and moves forward
    moveLegBackward(LH);
    // Phase 2: LH lands, LF lifts and moves forward
    landLeg(LH);
    moveLegBackward(LF);
    // Phase 3: LF lands, RH lifts and moves forward
    landLeg(LF);
    moveLegBackward(RH);
    // Phase 4: RH lands, RF lifts and moves forward
    landLeg(RH);
    moveLegBackward(RF);
    // Reset all legs to center position
    landLeg(LH);
    landLeg(RF);
    landLeg(LF);
    landLeg(RH);
}

void trotGait() {
    // Phase 1: Lift and move forward LF and RH
    moveLegBackward(LF);
    moveLegBackward(RH);
    // Phase 2: Land LF and RH, lift and move forward RF and LH
    landLeg(LF);
    landLeg(RH);
    moveLegBackward(RF);
    moveLegBackward(LH);
    // Phase 3: Land RF and LH
    landLeg(RF);
    landLeg(LH);
    // Reset all legs to center position
    landLeg(LF);
    landLeg(RF);
    landLeg(LH);
    landLeg(RH);
}