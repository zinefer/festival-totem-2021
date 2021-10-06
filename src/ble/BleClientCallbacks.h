#define FASTLED_INTERNAL
#include "FastLED.h"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

namespace ble {

    class BleClientCallbacks: public BLEServerCallbacks {
        public:
            bool connected = false;
            unsigned long disconnectedAt;
        
        void onConnect(BLEServer* pServer);
        void onDisconnect(BLEServer* pServer);
    };

}