#include "RainbowEffect.h"

namespace effects {

    RainbowEffect::RainbowEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) {
        rDelta = random8(1,16);

        if (random8(1,6) == 3) {
            dynaDelta = true;
        }
    }

    // 🌈
    void RainbowEffect::frame() {
        DEBUG_CORE_1 && Serial.print("# fill_rainbow: ");
        DEBUG_CORE_1 && Serial.println(rDelta);

        if (dynaDelta) {
            rDelta = beatsin16(6, 1, 16);
        }

        fill_rainbow(leds, NUM_LEDS, hue->readHue(), rDelta);
    }

}