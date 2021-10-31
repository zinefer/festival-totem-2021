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
ConfigState* config;
OverlayState* overlay;
PositionState* position;
HueState* hue;

// BLE
BleServer* bleServer;

// Hotfix Input
byte lightningSw = 3; // Set go 3 to make initial state get set

CRGB leds[NUM_LEDS];
int brightness = 50;

Animator* anim;

void setup() {
    // INITIALIZE    
    config = new ConfigState();
    overlay = new OverlayState();
    position = new PositionState();
    hue = new HueState();
       
    anim = new Animator(leds, config, overlay, hue);

    Serial.begin(115200);
    delay(3000); // 3 seconds of delay for disaster recovery
    DEBUG_CORE_0 && Serial.println("Booting");
    
    // SETUP
    //setupConfigInput();
    //setupPositionSensor();
    setupHotfixInput();
    //bleServer = new BleServer(hue);

    FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER,DATA_RATE_MHZ(12)>(leds, NUM_LEDS);
    FastLED.setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(brightness);

    // START OTHER THREAD
    anim->start();
}

void loop() {
    DEBUG_CORE_0 && Serial.println("MainLoop");

    // bluetooth stack will go into congestion, if too many packets are sent
    // in 6 hours test i was able to go as low as 3ms
    //EVERY_N_MILLISECONDS( 10 ) { bleServer->tick(); }

    // slowly cycle the "base color" through the rainbow
    EVERY_N_MILLISECONDS( 20 ) { hue->increment(); }

    //EVERY_N_MILLISECONDS( 20 ) { pollConfigInput(); }
    //EVERY_N_MILLISECONDS( 20 ) { pollPosition(); }
    EVERY_N_MILLISECONDS( 20 ) { pollHotfixInput(); }
}

void setupPositionSensor() {
    DEBUG_CORE_0 && Serial.println("setupPositionSensor");
    /* Initialise the sensor */
    if(!bno.begin())
    {
        /* There was a problem detecting the BNO055 ... check your connections */
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
        while(1);
    }
    delay(1000);
    bno.setExtCrystalUse(true);
}

void pollPosition() {
    DEBUG_CORE_0 && Serial.println("pollPosition");
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    position->update(euler);
}

void setupConfigInput() {
    pinMode(CONFIG_LOAD_PIN, OUTPUT);
    pinMode(CONFIG_CLK_PIN, OUTPUT);
    pinMode(CONFIG_DATA_PIN, INPUT);
}

void setupHotfixInput() {
    pinMode(HOTFIX_INPUT_SW, INPUT_PULLUP);
}

void pollHotfixInput() {
    byte toggleSw = digitalRead(HOTFIX_INPUT_SW);
    DEBUG_CORE_0 && Serial.print("toggleSw - ");
    DEBUG_CORE_0 && Serial.println(toggleSw);

    if (toggleSw != lightningSw) {
        config->setLightningEnabled(toggleSw);
        lightningSw = toggleSw;
    }
}

bool isTouched(uint8_t pin) {
    int val = max(touchRead(pin), touchRead(pin));
    DEBUG_CORE_0 && Serial.print("isTouched - ");
    DEBUG_CORE_0 && Serial.println(val);
    if (val <= HOTFIX_THRESHOLD) {
        return true;
    }
    return false;
}

void pollConfigInput() {
    byte bitVal;
    unsigned int bytesVal = 0;

    digitalWrite(CONFIG_LOAD_PIN, LOW);
    delayMicroseconds(CONFIG_PULSE_WIDTH);
    digitalWrite(CONFIG_LOAD_PIN, HIGH);

    for(int i = 0; i < 8; i++)
    {
        bitVal = digitalRead(CONFIG_DATA_PIN);

        DEBUG_CORE_0 && Serial.print("bitVal - ");
        DEBUG_CORE_0 && Serial.println(bitVal);

        // /* Pulse the Clock (rising edge shifts the next bit).
        digitalWrite(CONFIG_CLK_PIN, HIGH);
        delayMicroseconds(CONFIG_PULSE_WIDTH);
        digitalWrite(CONFIG_CLK_PIN, LOW);
    }
}
