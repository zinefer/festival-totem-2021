#include "Animator.h"

namespace utils {

    Animator::Animator(CRGB *l, OverlayState *o, HueState *h) {
        leds = l;
        overlay = o;
        hue = h;

        reset();
    }

    void Animator::tick() {
        
        switch (state) {
            case 0: // Rainbow for 40 seconds, glitter during the final 20
                if (effect == NULL) {
                    stateDuration = 40000; // 40 seconds
                    effect = new RainbowEffect(leds, overlay, hue);
                    overlayDelay = 20000;  // 20 seconds
                    stateOverlay = new GlitterOverlay(leds);
                }
            break;
            case 1: // Confetti for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new ConfettiEffect(leds, overlay, hue);
                }
            break;
            case 2: // Sinelon for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new SinelonEffect(leds, overlay, hue);
                }
            break;
            case 3: // Juggle for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new JuggleEffect(leds, overlay, hue);
                }
            break;
            case 4: // Beat for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new BeatEffect(leds, overlay, hue);
                }
            break;
            case 5: // Fire for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new FireEffect(leds, overlay);
                }
            break;
            case 6: // Levels for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new LevelsEffect(leds, overlay, hue);
                }
            break;
            case 7: // Meteor for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new MeteorEffect(leds, overlay, hue);
                }
            break;
            case 8: // Pulse for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new PulseEffect(leds, overlay, hue);
                }
            break;
            case 9: // Lightning for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 20 seconds
                    effect = new LightningEffect(leds, overlay);
                }
            break;
            case 10: // Chase for 20 seconds
                if (effect == NULL) {
                    stateDuration = 20000; // 40 seconds
                    effect = new ChaseEffect(leds, overlay, hue, stateDuration);
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
                reset();
                state++;
            }
        }
    }

    void Animator::reset() {
        state = 0;
        stateStarted = 0;
        overlayDelay = INT_MAX;
        effect = NULL;
        stateOverlay = NULL;
        overlay->set(NULL);
    }

}