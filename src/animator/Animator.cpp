#include "Animator.h"

namespace animator {
    
    Animator::Animator(CRGB* leds, OverlayState* overlayState, HueState* hueState) {
        effectFactory = new EffectFactory(leds, overlayState, hueState);
        overlayFactory = new OverlayFactory(leds);

        timeline = new Timeline();
    };

    void Animator::start() {
        started = true;
        xTaskCreatePinnedToCore(
            this->loop,    //Function to implement the task 
            "animator",    //Name of the task
            5000,          //Stack size in words 
            this,          //Task input parameter 
            taskPriority,  //Priority of the task 
            &Task1,        //Task handle.
            taskCore);     //Core where the task should run
    };

    void Animator::loop(void* pvParameters) {
        Animator* _this = (Animator *) pvParameters;   
        _this->effectStart = millis();
        while(_this->started) {
            _this->frameStart = millis();

            _this->tick();
            
            FastLED.show();

            DEBUG_CORE_1 && Serial.println(LEDS.getFPS());

            // Manage framerate
            unsigned long frame_duration = millis() - _this->frameStart;
            FastLED.delay((1000 - frame_duration) / FRAMES_PER_SECOND);

            DEBUG_CORE_1 && Serial.println(uxTaskGetStackHighWaterMark( NULL ));
        }
        vTaskDelete(NULL);
    };

    void Animator::tick() {

        KeyFrame* frame = timeline->current();

        DEBUG_CORE_1 && Serial.print("Frame Effect: ");
        DEBUG_CORE_1 && Serial.print((uint8_t)frame->effect);
        DEBUG_CORE_1 && Serial.print(" ");
        DEBUG_CORE_1 && Serial.println(frame->duration);

        unsigned long elapsed = millis() - effectStart;
        DEBUG_CORE_1 && Serial.print("elapsed: ");
        DEBUG_CORE_1 && Serial.println(elapsed);

        // if we have an effect
        if (effect) {

            if (Overlay::None != frame->overlay && elapsed >= frame->overlayDelay) {
                if (!overlay) {
                    overlay = overlayFactory->build(frame->overlay);
                }
            }

            if (elapsed >= frame->duration) {
                DEBUG_CORE_1 && Serial.println("Advance Timeline");
                effect = NULL;
                overlay = NULL;
                timeline->advance();
            } else {
                // tick effect and overlay
                effect->frame();
                if (overlay) {
                    overlay->frame();
                }
            }

        } else {

            // instantiate current effect
            effect = effectFactory->build(frame->effect, frame->duration);
            effectStart = millis();
        
        }

    };

}