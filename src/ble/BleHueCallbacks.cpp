#include "BleHueCallbacks.h"

namespace ble {

    BleHueCallbacks::BleHueCallbacks(HueState *h) {
        hueState = h;
    };

    void BleHueCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
        uint8_t* data = pCharacteristic->getData();
        hueState->set(*data);
    };

    void BleHueCallbacks::onRead(BLECharacteristic *pCharacteristic) {
        uint8_t data[1];
        data[0] = hueState->readHue();
        pCharacteristic->setValue(data, 1);
    };

}