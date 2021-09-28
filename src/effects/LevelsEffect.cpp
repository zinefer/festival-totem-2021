#include "LevelsEffect.h"

namespace effects {

    LevelsEffect::LevelsEffect(CRGB *l, OverlayState *o, HueState *h) : BaseHueEffect(l, o, h) { }

    // Randomly generate a percentage, set leds from 0->percentage to bright
    // let the rest fade to black
    void LevelsEffect::frame() {
        DEBUG_CORE_1 && Serial.println("# LevelsEffect");
        EVERY_N_MILLISECONDS( 625 ) {
            position = random16(NUM_LEDS / 2, NUM_LEDS - 5);
        }

        fadeToBlackBy(leds, NUM_LEDS, 25);
        
        int h = hue->readHue();
        for(int y = 0; y < position; y++) {
            leds[y] = CHSV(h, 255, 192);
        }
    }

}