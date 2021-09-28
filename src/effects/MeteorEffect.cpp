#include "MeteorEffect.h"

namespace effects {

    MeteorEffect::MeteorEffect(CRGB *l, OverlayState *o, HueState *h) : BaseHueEffect(l, o, h) {
        position = 0;
    }

    // "Drip" a pixel down the strand, leaving behind a variably decaying trail
    void MeteorEffect::frame() {
        EVERY_N_MILLISECONDS( 20 ) {
            DEBUG_CORE_1 && Serial.println("# MeteorEffect");
            
            position = (position + 1) % NUM_LEDS;

            for(int y = 0; y < NUM_LEDS; y++) {
                leds[y].fadeToBlackBy(decay[y]);
            }

            int pos = NUM_LEDS - position; // :(
            int h = hue->readHue();

            leds[min(pos, NUM_LEDS-1)] += CHSV(h, 255, 255);
            leds[min(pos+1, NUM_LEDS-1)] += CHSV(h, 255, 255);
            leds[min(pos-1, NUM_LEDS-1)] %= random8(100,150);
            decay[min(pos-1, NUM_LEDS-1)] = random8(15,35);
        }
    }

}