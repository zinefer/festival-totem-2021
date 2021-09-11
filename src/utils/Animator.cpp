#include "Animator.h"

namespace utils {

    Animator::Animator(CRGB *l, OverlayState *o, HueState *h) {
        leds = l;
        overlay = o;
        hue = h;

        state = 0;
        stateStarted = 0;
        overlayDelay = INT_MAX;
    }

    void Animator::tick() {
        
        switch (state) {
            case 0: // Rainbow for 40 seconds, glitter during the final 20
                if (effect == NULL) {
                    effect = new RainbowEffect(leds, overlay, hue);
                    stateDuration = 40000; // 40 seconds
                    stateOverlay = new GlitterOverlay(leds);
                    overlayDelay = 20000; // 20 seconds
                }
            break;
            default:
                state = 0;
            break;
        }

        if (effect->started == false) {
            effect->start();
            stateStarted = millis();
        }
        
        unsigned long currentDuration = millis() - stateStarted;

        if (effect != NULL) {
            if (currentDuration >= overlayDelay) {
                overlay->set(stateOverlay);
            }

            if (currentDuration >= stateDuration) {
                effect->stop();
                effect = NULL;
                stateOverlay = NULL;
                overlay->set(NULL);
                state++;
            }
        }
    }

}