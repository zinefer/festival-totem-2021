#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class LevelsEffect: public BaseEffect {
        private:
            HueState *hue;
            int position;

            void frame();
            
        public:
            LevelsEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}