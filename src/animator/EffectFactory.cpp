#include "EffectFactory.h"

namespace animator {

    EffectFactory::EffectFactory(CRGB* l, OverlayState* o, HueState* h) {
        leds = l;
        overlay = o;
        hue = h;
    };
    
    BaseEffect* EffectFactory::build(Effect effect, int duration){
        switch (effect)
        {
            case Effect::Rainbow:
                return new RainbowEffect(leds, hue);
            break;
            case Effect::Confetti:
                return new ConfettiEffect(leds, hue);
            break;
            case Effect::Sinelon:
                return new SinelonEffect(leds, hue);
            break;
            case Effect::Juggle:
                return new JuggleEffect(leds, hue);
            break;
            case Effect::Beat:
                return new BeatEffect(leds, hue);
            break;
            case Effect::Fire:
                return new FireEffect(leds);
            break;
            case Effect::Levels:
                return new LevelsEffect(leds, hue);
            break;
            case Effect::Meteor:
                return new MeteorEffect(leds, hue);
            break;
            case Effect::Pulse:
                return new PulseEffect(leds, hue);
            break;
            case Effect::Lightning:
                return new LightningEffect(leds);
            break;
            case Effect::Chase:
                return new ChaseEffect(leds, hue, duration);
            break;
        }
        
        return new RainbowEffect(leds, hue); // This is a prollem
    };

}