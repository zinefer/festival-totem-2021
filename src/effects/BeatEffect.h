#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class BeatEffect: public BaseHueEffect {
        private:
            CRGBPalette16 palette;
            uint8_t beatsPerMinute;
        
            void frame();
            
        public:
            BeatEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}