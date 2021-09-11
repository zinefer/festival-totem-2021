#include "ChaseEffect.h"

namespace effects {

    ChaseEffect::ChaseEffect(CRGB *l, OverlayState *o, HueState *h, int d) : RainbowEffect(l, o, h) {
        duration = d;
    }

    void ChaseEffect::frame() {
        RainbowEffect::frame();
        int offset = (duration / 75) % 3;

        for(int y = 0; y < NUM_LEDS; y++) {
            if (y % 3 == 0) {
                leds[y + offset] = CRGB::Black;
            }
        }
    }

}