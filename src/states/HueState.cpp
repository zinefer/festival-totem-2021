#include "HueState.h"

namespace states {
    int HueState::readHue() {
        int h;
        lock();
        h = hue;
        releaseLock();
        return h;
    };

    void HueState::increment() {
        lock();
        hue++;
        releaseLock();
    };
}