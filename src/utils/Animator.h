// LED Deps
#define FASTLED_INTERNAL
#include "FastLED.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

#include "../effects/BeatEffect.h"
#include "../effects/ChaseEffect.h"
#include "../effects/ConfettiEffect.h"
#include "../effects/FireEffect.h"
#include "../effects/JuggleEffect.h"
#include "../effects/LevelsEffect.h"
#include "../effects/LightningEffect.h"
#include "../effects/MeteorEffect.h"
#include "../effects/PulseEffect.h"
#include "../effects/RainbowEffect.h"
#include "../effects/SinelonEffect.h"

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

            void reset();
            
        public:
            Animator(CRGB *l, OverlayState *o, HueState *h);
            void tick();
    };

}