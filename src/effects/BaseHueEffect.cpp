#include "BaseHueEffect.h"

namespace effects {

    BaseHueEffect::BaseHueEffect(CRGB *l, HueState *h) : BaseEffect(l) {
        hue = h;
    }

    // void BaseHueEffect::stop() {
    //     BaseEffect::stop();
    //     hue->releaseLock();
    // }

}