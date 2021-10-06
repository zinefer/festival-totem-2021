#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "BleClientCallbacks.h"
#include "BleHueCallbacks.h"
//#include "BleHueCharacteristic.h"

#include "../states/HueState.h"

using namespace states;

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define HUE_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

namespace ble {
    class BleServer {
        
        private:
            BLEServer* pServer;

            BleClientCallbacks* clientCallbacks;
            bool isAdvertising = false;

        public:
            BleServer(HueState *hueState);
            void tick();
    
    };
}