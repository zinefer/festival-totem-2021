#include "SerialState.h"

namespace states {
    void SerialState::write(char msg[]) {
        lock();
        Serial.println(msg);
        releaseLock();
    };
}