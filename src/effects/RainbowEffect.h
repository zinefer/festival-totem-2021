#include "BaseEffect.h"

#include "../states/HueState.h"

#include "../overlays/BaseOverlay.h"

using namespace states;

namespace effects {

    class RainbowEffect: public BaseEffect {
        private:
            HueState *hue;
            byte rDelta;

            void frame();
            
        public:
            RainbowEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}