#include "RainbowEffect.h"

namespace effects {

    RainbowEffect::RainbowEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) {
        rDelta = random8(1,16);

        if (random8(1,6) == 4) {
            dynaDelta = true;
            dynaDeltaBeat = random8(6,32);
        }
    }

    // 🌈
    void RainbowEffect::frame() {
        DEBUG_CORE_1 && Serial.print("# fill_rainbow: ");
        DEBUG_CORE_1 && Serial.print(rDelta);
        DEBUG_CORE_1 && Serial.print(" ");
        DEBUG_CORE_1 && Serial.print(dynaDelta);

        if (dynaDelta) {
            rDelta = beatsin16(dynaDeltaBeat, 1, 16);
        }

        fill_rainbow(leds, NUM_LEDS, hue->readHue(), rDelta);
    }

}