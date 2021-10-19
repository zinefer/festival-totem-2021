#include "ConfigState.h"

namespace states {

    bool ConfigState::isLightningEnabled() {
        bool e;
        lock();
        e = lightningEnabled;
        releaseLock();
        return e;
    };

    void ConfigState::setLightningEnabled(bool enabled) {
        lock();
        lightningEnabled = enabled;
        releaseLock();
    }
}