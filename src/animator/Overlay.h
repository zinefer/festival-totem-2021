#ifndef OVERLAYENUM
#define OVERLAYENUM
// LED Deps
#define FASTLED_INTERNAL
#include "FastLED.h"

enum class Overlay : uint8_t {
    None, // Must be 0
    Glitter
};
#endif