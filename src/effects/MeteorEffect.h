#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class MeteorEffect: public BaseEffect {
        private:
            HueState *hue;

            int position;
            uint8_t decay[NUM_LEDS];

            void frame();
            
        public:
            MeteorEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}