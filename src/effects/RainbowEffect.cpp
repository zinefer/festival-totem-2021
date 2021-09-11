#include "BaseEffect.h"
#include "RainbowEffect.h"

using namespace states;
using namespace overlays;

namespace effects {

    RainbowEffect::RainbowEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
        rDelta = random8(5,35);
    }

    // 🌈
    void RainbowEffect::frame() {
        fill_rainbow(leds, NUM_LEDS, hue->readHue(), rDelta);
    }

}