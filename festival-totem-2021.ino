// Platform
#include "esp_system.h"

// LED Deps
#define FASTLED_INTERNAL
#include "FastLED.h"

// 9DoF Position Sensor Deps
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include "src/states/OverlayState.h"
#include "src/states/PositionState.h"
#include "src/states/HueState.h"
#include "src/states/SerialState.h"

#include "src/ble/BleServer.h"
#include "src/animator/Animator.h"

using namespace animator;
using namespace states;
using namespace overlays;
using namespace ble;
FASTLED_USING_NAMESPACE

#include "src/config.h"

// Sensors
Adafruit_BNO055 bno = Adafruit_BNO055(55); // 9DoF Position Sensor

// States
OverlayState* overlay;
PositionState* position;
HueState* hue;

// BLE
BleServer* bleServer;

CRGB leds[NUM_LEDS];
int brightness = 25;

Animator* anim;

void setup() {
    overlay = new OverlayState();
    position = new PositionState();
    hue = new HueState();
    
    anim = new Animator(leds, overlay, hue);

    Serial.begin(115200);
    delay(3000); // 3 seconds of delay for disaster recovery
    DEBUG_CORE_0 && Serial.println("Booting");
    setupPositionSensor();
    bleServer = new BleServer(hue);

    FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER,DATA_RATE_MHZ(12)>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(brightness);

    anim->start();
}

void loop() {
    DEBUG_CORE_0 && Serial.println("MainLoop");

    updatePosition();

    // bluetooth stack will go into congestion, if too many packets are sent
    // in 6 hours test i was able to go as low as 3ms
    EVERY_N_MILLISECONDS( 10 ) { bleServer->tick(); }

    // slowly cycle the "base color" through the rainbow
    EVERY_N_MILLISECONDS( 20 ) { hue->increment(); }
}

void updatePosition() {
    DEBUG_CORE_0 && Serial.println("updatePosition");
    // imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    // position->update(euler);
}


void setupPositionSensor() {
    DEBUG_CORE_0 && Serial.println("setupPositionSensor");
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
