#include "Timeline.h"

namespace animator {
     
    Timeline::Timeline() {
        frames.setStorage(frameArray);

        add(new KeyFrame(
            Effect::Rainbow,
            Overlay::Glitter,
            40000,
            20000
        ));

        add(new KeyFrame(
            Effect::Confetti,
            20000
        ));

        add(new KeyFrame(
            Effect::Sinelon,
            20000
        ));

        add(new KeyFrame(
            Effect::Juggle,
            20000
        ));

        add(new KeyFrame(
            Effect::Beat,
            20000
        ));

        add(new KeyFrame(
            Effect::Fire,
            20000
        ));

        add(new KeyFrame(
            Effect::Levels,
            20000
        ));

        add(new KeyFrame(
            Effect::Meteor,
            20000
        ));

        add(new KeyFrame(
            Effect::Pulse,
            20000
        ));

        add(new KeyFrame(
            Effect::Lightning,
            20000
        ));

        add(new KeyFrame(
            Effect::Chase,
            20000
        ));

    };

    void Timeline::add(KeyFrame* frame) {
        frames.push_back(frame);
    };

    void Timeline::remove(int i) {
        frames.remove(i);
    };

    void Timeline::advance() {
        currentFrame = (currentFrame + 1) % frames.size();
    };

    KeyFrame* Timeline::current() {
        return frames.at(currentFrame);
    };
}