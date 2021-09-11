#include "BaseEffect.h"

#include "../states/OverlayState.h"
#include "../states/HueState.h"

using namespace states;

namespace effects {

    class TemplateEffect: public BaseEffect {
        private:
            HueState *hue;
        
            void frame();
            
        public:
            TemplateEffect(CRGB *l, OverlayState *o, HueState *h);
    };

}