#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class ConfettiEffect: public BaseEffect {
        private:
            HueState *hue;
        
            void frame();
            
        public:
            ConfettiEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}