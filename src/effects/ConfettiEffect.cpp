#include "ConfettiEffect.h"

namespace effects {

    ConfettiEffect::ConfettiEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) { }

    // random colored speckles that blink in and fade smoothly
    void ConfettiEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# ConfettiEffect");
        fadeToBlackBy(leds, NUM_LEDS, 10);

        int pos = random16(NUM_LEDS);
        leds[pos] += CHSV(hue->readHue() + random8(64), 200, 255);
    }

}