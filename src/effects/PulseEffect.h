#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class PulseEffect: public BaseHueEffect {
        private:
            uint8_t beatsPerMinute;
        
            void frame();
            
        public:
            PulseEffect(CRGB *l, HueState *h);
    };

}