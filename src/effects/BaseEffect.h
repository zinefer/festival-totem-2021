#ifndef BASEEFFECT
#define BASEEFFECT
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define FASTLED_INTERNAL
#include "FastLED.h"
#include "../config.h"

#include "../overlays/BaseOverlay.h"
#include "../states/OverlayState.h"

using namespace states;
using namespace overlays;

namespace effects {

    class BaseEffect {
        private:
            const int taskCore = 1;
            const int taskPriority = 1;

            //const int FRAMES_PER_SECOND = 120;
            unsigned long frame_start;
            TaskHandle_t Task1;

            OverlayState *overlay;

            static void loop(void *pvParameters);
            virtual void frame();

        protected:
            CRGB *leds;
            
        public:
            bool started;
            
            BaseEffect(CRGB *l, OverlayState *o);
            ~BaseEffect();
            void start();
            virtual void stop();
    };

}
#endif