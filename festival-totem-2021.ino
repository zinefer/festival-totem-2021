// LED Deps
#define FASTLED_INTERNAL
#include "FastLED.h"

// 9DoF Deps
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include "src/state/PositionState.h"
#include "src/state/HueState.h"
#include "src/state/SerialState.h"

#include "src/effects/BaseEffect.h"

using namespace state;
using namespace effects;

FASTLED_USING_NAMESPACE

#include "src/config.h"

Adafruit_BNO055 bno = Adafruit_BNO055(55);
PositionState *position;
HueState *hue;

CRGB leds[NUM_LEDS];

void setup() {
    position = new PositionState();
    hue = new HueState();

    Serial.begin(19200);
    delay(3000); // 3 seconds of delay for disaster recovery
    setupPositionSensor();

    FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER,DATA_RATE_MHZ(12)>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void setupPositionSensor() {
    /* Initialise the sensor */
    // if(!bno.begin())
    // {
    //     /* There was a problem detecting the BNO055 ... check your connections */
    //     Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    //     while(1);
    // }
    // delay(1000);
    // bno.setExtCrystalUse(true);
}

void loop() {



    // slowly cycle the "base color" through the rainbow
    EVERY_N_MILLISECONDS( 20 ) { hue->increment(); }
}

void updatePosition() {
    // imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    // position.update(euler);
}
