#include "BaseEffect.h"

#include "../states/OverlayState.h"

using namespace states;

namespace effects {

    class LightningEffect: public BaseEffect {
        private:
            int pulsePosition;
        
            void frame();
            
        public:
            LightningEffect(CRGB *l);
    };

}