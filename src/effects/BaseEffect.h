#ifndef BASEEFFECT
#define BASEEFFECT
#define FASTLED_INTERNAL
#include "FastLED.h"

#include "freertos/task.h"

#include "../config.h"

#include "../state/PositionState.h"

namespace effects {

    class BaseEffect {
        private:
            const int taskCore = 1;
            const int taskPriority = 1;

            //const int FRAMES_PER_SECOND = 120;
            unsigned long frame_start;
            TaskHandle_t Task1;

            static void loop(void *pvParameters);
            void frame();

        protected:
            CRGB *leds;
            
        public:
            BaseEffect(CRGB *l);
            void start();
            void stop();
    };

}
#endif