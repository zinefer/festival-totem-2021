#include "SinelonEffect.h"

namespace effects {

    SinelonEffect::SinelonEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
    }

    void SinelonEffect::frame() {
        fadeToBlackBy(leds, NUM_LEDS, 20);

        int pos = beatsin16(13, 0, NUM_LEDS-1 );
        leds[pos] += CHSV(hue->readHue(), 255, 192);
    }

}