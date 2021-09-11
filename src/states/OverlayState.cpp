#include "OverlayState.h"

namespace states {
    BaseOverlay *OverlayState::get() {
        BaseOverlay *o;
        lock();
        o = overlay;
        releaseLock();
        return o;
    };

    void OverlayState::set(BaseOverlay *o) {
        lock();
        overlay = o;
        releaseLock();
    };
}