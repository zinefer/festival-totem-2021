#include "PositionState.h"

namespace state {
    imu::Vector<3> PositionState::readPosition() {
        imu::Vector<3> e;
        lock();
        e = euler;
        releaseLock();
        return e;
    };

    void PositionState::update(imu::Vector<3> e) {
        lock();
        euler = e;
        releaseLock();

        /* Display the floating point data */
        Serial.print("X: ");
        Serial.print(euler.x());
        Serial.print(" Y: ");
        Serial.print(euler.y());
        Serial.print(" Z: ");
        Serial.print(euler.z());
        Serial.println("");
    };
}