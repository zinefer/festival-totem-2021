#define FASTLED_INTERNAL
#include "FastLED.h"

#include "Effect.h"
#include "Overlay.h"

namespace animator {
    class KeyFrame {

        public:
            //uint8_t id;
            Effect effect;     //uint8_t
            Overlay overlay;   //uint8_t
            int duration;
            int overlayDelay;
        
            KeyFrame(
                Effect _effect, Overlay _overlay,
                int _duration, int _overlayDelay
            );

            KeyFrame(Effect _effect, int _duration);

    };
}

/*
    ID 8?
    Effect 8
    Overlay 8
    Duration 32      // could probably figure a good way to do this with a magnitude
    OverlayDelay 32  // flag that swaps between seconds/ms
*/