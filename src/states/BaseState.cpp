#include "BaseState.h"

namespace states {

    BaseState::BaseState() {
        accessLock = xSemaphoreCreateMutex();
    }

    void BaseState::lock() {
        xSemaphoreTake( accessLock, ( TickType_t ) 100000 );
    }

    void BaseState::releaseLock() {
        xSemaphoreGive( accessLock );
    }

}