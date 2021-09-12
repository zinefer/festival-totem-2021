#include "PulseEffect.h"

namespace effects {

    PulseEffect::PulseEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
        beatsPerMinute = 32;
    }

    // Slowly pulse a single color - TODO: maybe some random flickers?
    void PulseEffect::frame() {
        for(int y = 0; y < NUM_LEDS; y++) {
            uint8_t beat = beatsin8(beatsPerMinute, 1, 254);
            leds[y] = CHSV(constrain(hue->readHue(), 1, 255), 255, 255-beat);
        }
    }

}