#ifndef HUESTATE
#define HUESTATE
#include <utility/imumaths.h>
#include <Arduino.h>
#include "BaseState.h"

namespace states {

    class HueState: public BaseState {
        private:
            int hue = 0;
            int hueOverride = 0;
            unsigned long overrideTime = 0;

        public:
            int readHue();
            void increment();
            void set(uint8_t h);
    };

}
#endif