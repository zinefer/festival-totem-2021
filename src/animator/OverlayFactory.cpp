#include "OverlayFactory.h"

namespace animator {

    OverlayFactory::OverlayFactory(CRGB* l) {
        leds = l;
    };
    
    BaseOverlay* OverlayFactory::build(Overlay overlay){
        switch (overlay)
        {
            case Overlay::Glitter:
                return new GlitterOverlay(leds);
            break;
        }

        return new GlitterOverlay(leds); // This is a prollem
    };

}