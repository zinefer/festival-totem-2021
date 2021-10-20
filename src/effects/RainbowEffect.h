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
            bool dynaDelta = false;
            byte dynaDeltaBeat;
            
        protected:
            void frame();
            
        public:
            RainbowEffect(CRGB *l, HueState *h);
    };

}
#endif