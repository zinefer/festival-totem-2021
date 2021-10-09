#ifndef RAINBOWEFFECT
#define RAINBOWEFFECT
#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class RainbowEffect: public BaseHueEffect {
        private:
            byte rDelta;

        protected:
            void frame();
            
        public:
            RainbowEffect(CRGB *l, HueState *h);
    };

}
#endif