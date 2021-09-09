// LED Deps
#include "FastLED.h"

// 9DoF Deps
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include "src/state/PositionState.h"
#include "src/state/SerialState.h"
#include "src/effects/BaseEffect.h"

using namespace state;
using namespace effects;

Adafruit_BNO055 bno = Adafruit_BNO055(55);
PositionState* position;

void setup() {
    position = new PositionState();

    Serial.begin(19200);
    delay(3000); // 3 seconds of delay for disaster recovery
    setupPositionSensor();
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

}

void updatePosition() {
    // imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    // position.update(euler);
}
