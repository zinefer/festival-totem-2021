#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "BleClientCallbacks.h"
#include "BleHueCallbacks.h"

#include "../states/HueState.h"

using namespace states;

#define SERVICE_UUID "421dd58e-8985-4547-a67a-20aa5a44f4ad"
#define HUE_CHARACTERISTIC_UUID "37affa35-4fff-4b04-bd4e-a7d7feebed6c"

namespace ble {
    class BleServer {
        
        private:
            BLEServer* pServer;

            BleClientCallbacks* clientCallbacks;
            bool isAdvertising = false;

            BLECharacteristic* hueCharacteristic;

        public:
            BleServer(HueState *hueState);
            void tick();
    
    };
}