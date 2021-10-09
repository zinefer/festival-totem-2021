#ifndef EFFECTENUM
#define EFFECTENUM
// LED Deps
#define FASTLED_INTERNAL
#include "FastLED.h"

enum class Effect : uint8_t  {
    Rainbow,
    Confetti,
    Sinelon,
    Juggle,
    Beat,
    Fire,
    Levels,
    Meteor,
    Pulse,
    Lightning,
    Chase
};
#endif