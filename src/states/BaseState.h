#ifndef BASESTATE
#define BASESTATE
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include <Arduino.h>

namespace states {

    class BaseState {
        private:
            SemaphoreHandle_t accessLock = NULL;
            
        public:
            BaseState();
            void lock();
            void releaseLock();
    };

}
#endif