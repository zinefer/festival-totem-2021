#ifndef CONFIGINPUTSTATE
#define CONFIGINPUTSTATE
#include <Arduino.h>
#include "BaseState.h"

namespace states {

    class ConfigState: public BaseState {
        private:
            bool lightningEnabled = false;
            
        public:
            bool isLightningEnabled();
            void setLightningEnabled(bool enabled);
    };

}
#endif