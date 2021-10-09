#include "Effect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

#include "../effects/Effects.h"

using namespace states;
using namespace effects;

namespace animator {
    class EffectFactory {
        public:
            CRGB* leds;
            OverlayState* overlay;
            HueState* hue;

            EffectFactory(CRGB* l, OverlayState* o, HueState* h);
            BaseEffect* build(Effect effect, int duration);
    };
}