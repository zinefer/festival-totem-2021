#include "BleHueCallbacks.h"

namespace ble {

    BleHueCallbacks::BleHueCallbacks(HueState *h) {
        hueState = h;
    };

    void BleHueCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
        //unsigned char value = pCharacteristic->getValue();
        uint8_t* data = pCharacteristic->getData();
        hueState->set(*data);
    };

}