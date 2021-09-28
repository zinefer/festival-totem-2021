#include "BaseHueEffect.h"

namespace effects {

    BaseHueEffect::BaseHueEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
    }

    void BaseHueEffect::stop() {
        BaseEffect::stop();
        hue->releaseLock();
    }

}