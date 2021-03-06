#include "HueState.h"

namespace states {
    int HueState::readHue() {
        int h;
        
        if (overrideTime > 0) {
            if ((millis() - overrideTime) <= 1000) {
                lock();
                h = hueOverride;
                releaseLock();
                return h;
            }
        }

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

    void HueState::set(uint8_t h) {
        lock();
        hue = h % 256;
        overrideTime = millis();
        releaseLock();
    };
}