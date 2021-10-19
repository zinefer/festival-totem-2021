#include "BlendWaveEffect.h"

namespace effects {

    BlendWaveEffect::BlendWaveEffect(CRGB *l, HueState *h) : BaseHueEffect(l, h) { }

    void BlendWaveEffect::frame() {
        DEBUG_CORE_1 && Serial.print("# BlendWave");

        uint8_t speed = beatsin8(6,0,255);

        CRGB clr1 = blend(CHSV(beatsin8(3,0,255),255,255), CHSV(beatsin8(4,0,255),255,255), speed);
        CRGB clr2 = blend(CHSV(beatsin8(4,0,255),255,255), CHSV(beatsin8(3,0,255),255,255), speed);

        uint8_t loc1 = beatsin8(10,0,NUM_LEDS-1);
        
        fill_gradient_RGB(leds, 0, clr2, loc1, clr1);
        fill_gradient_RGB(leds, loc1, clr2, NUM_LEDS-1, clr1);
    }

}