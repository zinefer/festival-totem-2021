#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class MeteorEffect: public BaseHueEffect {
        private:
            int position;
            uint8_t decay[NUM_LEDS];

            void frame();
            
        public:
            MeteorEffect(CRGB *l, HueState *h);
    };

}