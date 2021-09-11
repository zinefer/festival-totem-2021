#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class SinelonEffect: public BaseEffect {
        private:
            HueState *hue;
        
            void frame();
            
        public:
            SinelonEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}