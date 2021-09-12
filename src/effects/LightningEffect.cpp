#include "LightningEffect.h"

namespace effects {

    LightningEffect::LightningEffect(CRGB *l, OverlayState *o) : BaseEffect(l, o) {
        pulsePosition = 0;
    }

    // A fast bright, white blink with a flicker triggered pretty randomly
    void LightningEffect::frame() {
        EVERY_N_MILLISECONDS( 20 ) {
            int segment = NUM_LEDS / 5;
            fadeToBlackBy(leds, NUM_LEDS, 50);

            if (pulsePosition > 0) {
                switch(pulsePosition++) {
                    case 2:
                        for(int y = 4 * segment; y > segment; y--) {
                            leds[y] += CRGB::White;
                        }
                        break;
                    case 3:
                        for(int y = segment; y > 0; y--) {
                            leds[y] += CRGB::White;
                        }
                        pulsePosition = 0;
                    break;
                }
            } else {
                if (random8(0, 10) == 2) {
                    for(int y = 5 * segment; y > 4 * segment; y--) {
                        leds[y] += CRGB::White;
                    }
                    pulsePosition = 1;
                }
            }
        }
    }

}