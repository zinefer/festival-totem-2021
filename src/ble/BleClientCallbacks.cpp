#include "BleClientCallbacks.h"

namespace ble {

    void BleClientCallbacks::onConnect(BLEServer* pServer) {
        connected = true;
        disconnectedAt = NULL;
        BLEDevice::startAdvertising();
    };

    void BleClientCallbacks::onDisconnect(BLEServer* pServer) {
        connected = false;
        disconnectedAt = millis();
        BLEDevice::startAdvertising();
    };

}

