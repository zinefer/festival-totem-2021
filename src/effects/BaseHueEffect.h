#ifndef BASEHUEEFFECT
#define BASEHUEEFFECT
#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class BaseHueEffect: public BaseEffect {
        protected:
            HueState *hue;

        public:
            void stop();
            
        public:
            BaseHueEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}
#endif