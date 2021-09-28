#include "BaseEffect.h"

namespace effects {

    BaseEffect::BaseEffect(CRGB *l, OverlayState *o){
        leds = l;
        overlay = o;
        started = false;
    }

    void BaseEffect::start() {
        xTaskCreatePinnedToCore(
            this->loop,    //Function to implement the task 
            "effect",      //Name of the task
            5000,          //Stack size in words 
            this,          //Task input parameter 
            taskPriority,  //Priority of the task 
            &Task1,        //Task handle.
            taskCore);     //Core where the task should run

        started = true;
    }

    void BaseEffect::loop(void *pvParameters) {
        BaseEffect *_this = (BaseEffect *) pvParameters;   
        while(_this->started) {
            _this->frame_start = millis();

            _this->frame();

            BaseOverlay *o = _this->overlay->get();
            if (o != NULL) {
                o->frame();
            }
            
            FastLED.show();

            DEBUG_CORE_1 && Serial.println(LEDS.getFPS());

            // Manage framerate
            unsigned long frame_duration = millis() - _this->frame_start;
            FastLED.delay((1000 - frame_duration) / FRAMES_PER_SECOND);
        }
        vTaskDelete(NULL);
    }

    void BaseEffect::frame() {
        
    }

    void BaseEffect::stop() {
        vTaskDelete(Task1);
        started = false;
        overlay->releaseLock();
    }

    BaseEffect::~BaseEffect(){
        stop();
    }

}