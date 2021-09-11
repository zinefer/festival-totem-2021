#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class JuggleEffect: public BaseEffect {
        private:
            HueState *hue;
        
            void frame();
            
        public:
            JuggleEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}