#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "../states/HueState.h"

using namespace states;

namespace ble {
    class BleHueCallbacks: public BLECharacteristicCallbacks {
        private:
            HueState *hueState;
        
        public:
            BleHueCallbacks(HueState *h);
            void onWrite(BLECharacteristic *pCharacteristic);
    };
}