#include "RainbowEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class ChaseEffect: public RainbowEffect {
        private:
            int duration;
            void frame();
            
        public:
            ChaseEffect(CRGB* l, HueState* h, int d);
    };

}