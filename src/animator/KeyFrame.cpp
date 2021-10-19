#include "KeyFrame.h"

namespace animator {

    KeyFrame::KeyFrame(Effect _effect, Overlay _overlay,
        int _duration, int _overlayDelay) 
    {
        effect = _effect;
        overlay = _overlay;
        duration = _duration;
        overlayDelay = _overlayDelay;
    }

    KeyFrame::KeyFrame(Effect _effect, int _duration) {
        effect = _effect;
        duration = _duration;
        overlay = Overlay::None;
    }

}