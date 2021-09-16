#ifndef BASEOVERLAY
#define BASEOVERLAY

#define FASTLED_INTERNAL
#include "FastLED.h"
#include "../../config.h"

namespace overlays {

    class BaseOverlay {
        protected:
            CRGB *leds;
            
        public:
            BaseOverlay(CRGB *l);
            virtual void frame();
    };

}
#endif