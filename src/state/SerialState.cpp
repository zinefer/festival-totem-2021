#include "SerialState.h"

namespace state {
    void SerialState::write(char msg[]) {
        lock();
        Serial.println(msg);
        releaseLock();
    };
}