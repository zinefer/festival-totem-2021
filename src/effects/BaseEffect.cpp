#include "BaseEffect.h"

namespace effects {

    BaseEffect::BaseEffect(state::PositionState p){
        position = p;
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
    }

    void BaseEffect::loop(void *pvParameters) {
        BaseEffect *_this = (BaseEffect *) pvParameters;   
        for (;;){
            _this->frame_start = millis();

            _this->frame();
            
            FastLED.show();

            // Manage framerate
            unsigned long frame_duration = millis() - _this->frame_start;
            FastLED.delay((1000 - frame_duration) / _this->FRAMES_PER_SECOND);
        }
    }

    void BaseEffect::frame() {
        
    }

    void BaseEffect::stop() {
        vTaskDelete(Task1);
    }

}