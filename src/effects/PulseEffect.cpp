#include "PulseEffect.h"

namespace effects {

    PulseEffect::PulseEffect(CRGB *l, OverlayState *o, HueState *h) : BaseHueEffect(l, o, h) {
        beatsPerMinute = 32;
    }

    // Slowly pulse a single color - TODO: maybe some random flickers?
    void PulseEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# PulseEffect");
        uint8_t beat = beatsin8(beatsPerMinute, 1, 254);
        int h = hue->readHue();
        for(int y = 0; y < NUM_LEDS; y++) {
            leds[y] = CHSV(h, 255, 255-beat);
        }
    }

}