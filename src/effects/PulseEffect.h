#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class PulseEffect: public BaseEffect {
        private:
            HueState *hue;
            uint8_t beatsPerMinute;
        
            void frame();
            
        public:
            PulseEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}