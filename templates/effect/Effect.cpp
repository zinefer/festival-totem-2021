#include "TemplateEffect.h"

namespace effects {

    TemplateEffect::TemplateEffect(CRGB *l, OverlayState *o, HueState *h) : BaseEffect(l, o) {
        hue = h;
    }

    void TemplateEffect::frame() {

    }

}