#include "ChaseEffect.h"

namespace effects {

    ChaseEffect::ChaseEffect(CRGB *l, HueState *h, int d) : RainbowEffect(l, h) {
        duration = d;
    }

    // 1 dot every other LED is turned off and move it along the strip
    void ChaseEffect::frame() {
        RainbowEffect::frame();
        DEBUG_CORE_1 && Serial.println("# ChaseEffect");
        int offset = beatsin16(20, 1, 3);

        for(int y = 0; y < NUM_LEDS; y++) {
            if (y % 3 == 0) {
                int p = min(y + offset, NUM_LEDS-1);
                leds[p] = CRGB::Black;
            }
        }
    }

}