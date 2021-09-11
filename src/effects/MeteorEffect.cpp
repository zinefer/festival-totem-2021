#include "MeteorEffect.h"

namespace effects {

    MeteorEffect::MeteorEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
        position = 0;
    }

    // "Drip" a pixel down the strand, leaving behind a variably decaying trail
    void MeteorEffect::frame() {
        EVERY_N_MILLISECONDS( 20 ) {
            position = (position + 1) % NUM_LEDS;

            for(int y = 0; y < NUM_LEDS; y++) {
                leds[y].fadeToBlackBy(decay[y]);
            }

            int pos = NUM_LEDS - position; // :(
            int h = hue->readHue();

            leds[pos] += CHSV(h, 255, 255);
            leds[pos+1] += CHSV(h, 255, 255);
            leds[pos-1] %= random8(100,150);
            decay[pos-1] = random8(15,35);
        }
    }

}