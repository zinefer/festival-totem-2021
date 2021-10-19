#include "BaseEffect.h"

#include "../states/OverlayState.h"

using namespace states;

namespace effects {

    class FireEffect: public BaseEffect {
        private:
            unsigned long last_tick;
            
            // Array of temperature readings at each simulation cell
            byte heat[NUM_LEDS];
            
            // COOLING: How much does the air cool as it rises?
            // Less cooling = taller flames.  More cooling = shorter flames.
            // Default 50, suggested range 20-100
            static constexpr int COOLING = 30;
            
            // SPARKING: What chance (out of 255) is there that a new spark will be lit?
            // Higher chance = more roaring fire.  Lower chance = more flickery fire.
            // Default 120, suggested range 50-200.
            static constexpr int SPARKING = 30;

            bool gReverseDirection = false;

            CRGBPalette16 palette;
            String paletteName;

            void frame();
            
        public:
            FireEffect(CRGB *l);
    };

}