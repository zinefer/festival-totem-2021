// LED Deps
#define FASTLED_INTERNAL
#include "FastLED.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

#include "../effects/RainbowEffect.h"

#include "../overlays/GlitterOverlay.h"

using namespace effects;
using namespace states;
using namespace overlays;
FASTLED_USING_NAMESPACE

namespace utils {

    class Animator {
        private:
            OverlayState *overlay;
            HueState *hue;

            int state;
            int stateDuration;
            int overlayDelay;            
            unsigned long stateStarted;
            CRGB *leds;
            BaseEffect *effect;
            BaseOverlay *stateOverlay;
            
        public:
            Animator(CRGB *l, OverlayState *o, HueState *h);
            void tick();
    };

}