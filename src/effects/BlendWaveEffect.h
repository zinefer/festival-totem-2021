#ifndef BLENDWAVEEFFECT
#define BLENDWAVEEFFECT
#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class BlendWaveEffect: public BaseHueEffect {
        protected:
            void frame();
            
        public:
            BlendWaveEffect(CRGB *l, HueState *h);
    };

}
#endif