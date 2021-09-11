#include "ConfettiEffect.h"

namespace effects {

    ConfettiEffect::ConfettiEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
    }

    void ConfettiEffect::frame() {
        fadeToBlackBy(leds, NUM_LEDS, 10);

        int pos = random16(NUM_LEDS);
        leds[pos] += CHSV(hue->readHue() + random8(64), 200, 255);
    }

}