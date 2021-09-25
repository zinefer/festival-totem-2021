#include "PulseEffect.h"

namespace effects {

    PulseEffect::PulseEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
        beatsPerMinute = 32;
    }

    // Slowly pulse a single color - TODO: maybe some random flickers?
    void PulseEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# PulseEffect");
        uint8_t beat = beatsin8(beatsPerMinute, 1, 254);
        for(int y = 0; y < NUM_LEDS; y++) {
            leds[y] = CHSV(hue->readHue(), 255, 255-beat);
        }
    }

}