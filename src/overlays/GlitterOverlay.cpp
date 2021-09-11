#include "BaseOverlay.h"
#include "GlitterOverlay.h"

using namespace states;

namespace overlays {

    fract8 chanceOfGlitter = 80;

    GlitterOverlay::GlitterOverlay(CRGB *l) : BaseOverlay(l) { }

    void GlitterOverlay::frame() {
        if(random8() < chanceOfGlitter) {
            leds[ random16(NUM_LEDS) ] += CRGB::White;
        }
    }

}