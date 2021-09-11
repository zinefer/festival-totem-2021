#include "BaseEffect.h"

#include "../state/HueState.h"

using namespace state;

namespace effects {

    class RainbowEffect: public BaseEffect {
        private:
            HueState *hue;

            void frame();
            
        public:
            RainbowEffect(CRGB *l, HueState *h);
    };

}