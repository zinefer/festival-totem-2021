#include "BaseState.h"

namespace states {

    BaseState::BaseState() {
        accessLock = xSemaphoreCreateMutex();
    }

    void BaseState::lock() {
        if (xSemaphoreTake( accessLock, ( TickType_t ) 100000 ) == false) {
            Serial.println("# xSemaphoreTake ERROR");
        }
    }

    void BaseState::releaseLock() {
        xSemaphoreGive( accessLock );
    }

}