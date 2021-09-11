#include "JuggleEffect.h"

namespace effects {

    JuggleEffect::JuggleEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
    }

    void JuggleEffect::frame() {
        fadeToBlackBy(leds, NUM_LEDS, 20);

        byte dothue = 0;

        for(int i = 0; i < 8; i++) {
            leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
            dothue += 32;
        }
    }

}