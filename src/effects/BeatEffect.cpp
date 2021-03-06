#include "BeatEffect.h"

namespace effects {

    BeatEffect::BeatEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) {
        beatsPerMinute = 62;
        palette = PartyColors_p;
    }

    void BeatEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# BeatEffect");
        uint8_t beat = beatsin8(beatsPerMinute, 64, 255);
        int gHue = hue->readHue();

        for(int i = 0; i < NUM_LEDS; i++) {
            leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
        }
    }

}