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
        hue = (hue + 1) % 256;
        releaseLock();
    };
}