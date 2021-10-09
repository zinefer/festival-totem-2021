#include "Overlay.h"

#include "../overlays/GlitterOverlay.h"

using namespace overlays;

namespace animator {
    class OverlayFactory {
        public:
            CRGB* leds;

            OverlayFactory(CRGB* l);
            BaseOverlay* build(Overlay overlay);
    };
}