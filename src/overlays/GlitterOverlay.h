#define FASTLED_INTERNAL
#include "FastLED.h"
#include "../config.h"

#include "BaseOverlay.h"

namespace overlays {

    class GlitterOverlay: public BaseOverlay {
        public:
            GlitterOverlay(CRGB* l);
            void frame();
    };

}