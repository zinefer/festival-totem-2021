#include "FastLED.h"
#include "freertos/task.h"
#include "../state/PositionState.h"

namespace effects {

    class BaseEffect {
        private:
            state::PositionState position;
            const int taskCore = 1;
            const int taskPriority = 1;

            const int FRAMES_PER_SECOND = 120;
            unsigned long frame_start;
            TaskHandle_t Task1;

            static void loop(void *pvParameters);
            void frame();
            
        public:
            BaseEffect(state::PositionState p);
            void start();
            void stop();
    };

}