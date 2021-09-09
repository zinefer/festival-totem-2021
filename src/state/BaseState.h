#ifndef BASESTATE
#define BASESTATE
#include <utility/imumaths.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

namespace state {

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