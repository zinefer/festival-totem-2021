#include "BaseEffect.h"
#include "RainbowEffect.h"

using namespace state;

namespace effects {

    RainbowEffect::RainbowEffect(CRGB *l, HueState *h) : BaseEffect(l) {
        hue = h;
    }

    void RainbowEffect::frame() {
        byte rDelta = random8(5,35);
        fill_rainbow(leds, NUM_LEDS, hue->readHue(), rDelta);
    }

}