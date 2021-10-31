#include "BaseEffect.h"

#include "../states/ConfigState.h"

using namespace states;

namespace effects {

    class LightningEffect: public BaseEffect {
        private:
            int pulsePosition;
            ConfigState* config;
        
            void frame();
            
        public:
            LightningEffect(CRGB *l, ConfigState* c);
    };

}