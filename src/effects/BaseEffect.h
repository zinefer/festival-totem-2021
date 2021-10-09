#ifndef BASEEFFECT
#define BASEEFFECT

#define FASTLED_INTERNAL
#include "FastLED.h"
#include "../config.h"

#include "../overlays/BaseOverlay.h"
#include "../states/OverlayState.h"

using namespace states;
using namespace overlays;

namespace effects {

    class BaseEffect {
        protected:
            CRGB *leds;
            
        public:            
            BaseEffect(CRGB *l);
            virtual void frame();
    };

}
#endif