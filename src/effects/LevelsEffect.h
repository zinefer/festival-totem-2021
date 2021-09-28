#include "BaseHueEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class LevelsEffect: public BaseHueEffect {
        private:
            int position;

            void frame();
            
        public:
            LevelsEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}