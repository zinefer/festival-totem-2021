#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "Effect.h"
#include "Overlay.h"

//#include "KeyFrame.h"
#include "Timeline.h"
#include "EffectFactory.h"
#include "OverlayFactory.h"

#include "../effects/BaseEffect.h"
#include "../overlays/BaseOverlay.h"

using namespace states;
using namespace effects;

namespace animator {
    class Animator {
        private:
            const int taskCore = 1;
            const int taskPriority = 1;
            TaskHandle_t Task1;

            //const int FRAMES_PER_SECOND = 120;
            unsigned long frameStart;

            Timeline* timeline;

            EffectFactory* effectFactory;
            OverlayFactory* overlayFactory;
            
            BaseEffect* effect = NULL;
            BaseOverlay* overlay = NULL;

            int effectStart;
            bool started = false;

            static void loop(void *pvParameters);

        public:
            Animator(CRGB* leds, OverlayState* overlayState, HueState* hueState);
            void start();
            void tick();

    };
}