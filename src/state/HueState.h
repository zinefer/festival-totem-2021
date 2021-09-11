#include <utility/imumaths.h>
#include <Arduino.h>
#include "BaseState.h"

namespace state {

    class HueState: public BaseState {
        private:
            int hue = 0;
            
        public:
            int readHue();
            void increment();
    };

}