#include "RainbowEffect.h"

namespace effects {

    RainbowEffect::RainbowEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
        rDelta = random8(5,35);
    }

    // 🌈
    void RainbowEffect::frame() {
        DEBUG_CORE_1 && Serial.print("# fill_rainbow: ");
        DEBUG_CORE_1 && Serial.println(rDelta);
        fill_rainbow(leds, NUM_LEDS, hue->readHue(), rDelta);
    }

}