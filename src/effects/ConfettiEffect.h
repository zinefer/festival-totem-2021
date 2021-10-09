#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class ConfettiEffect: public BaseHueEffect {
        private:        
            void frame();
            
        public:
            ConfettiEffect(CRGB *l, HueState *h);
    };

}