#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class SinelonEffect: public BaseHueEffect {
        private:
            void frame();
            
        public:
            SinelonEffect(CRGB *l, HueState *h);
    };

}