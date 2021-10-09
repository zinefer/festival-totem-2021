#include "SinelonEffect.h"

namespace effects {

    SinelonEffect::SinelonEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) { }

    // a colored dot sweeping back and forth, with fading trails
    void SinelonEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# SinelonEffect");
        fadeToBlackBy(leds, NUM_LEDS, 20);

        int pos = beatsin16(13, 0, NUM_LEDS-1 );
        leds[pos] += CHSV(hue->readHue(), 255, 192);
    }

}