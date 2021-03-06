#include "JuggleEffect.h"

namespace effects {

    JuggleEffect::JuggleEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) { }

    // eight colored dots, weaving in and out of sync with each other
    void JuggleEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# JuggleEffect");
        fadeToBlackBy(leds, NUM_LEDS, 20);

        byte dothue = 0;

        for(int i = 0; i < 8; i++) {
            leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
            dothue += 32;
        }
    }

}