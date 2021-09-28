#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class JuggleEffect: public BaseHueEffect {
        private:        
            void frame();
            
        public:
            JuggleEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}