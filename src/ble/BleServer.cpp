#include "BleServer.h"

namespace ble {

    BleServer::BleServer(HueState *hueState) {
        // Create the BLE Device
        BLEDevice::init("ESP32");

        // Create the BLE Server
        pServer = BLEDevice::createServer();
        clientCallbacks = new BleClientCallbacks();
        pServer->setCallbacks(clientCallbacks);

        // Create the BLE Service
        BLEService *pService = pServer->createService(SERVICE_UUID);

        // Create a BLE Characteristic
        hueCharacteristic = pService->createCharacteristic(
                                HUE_CHARACTERISTIC_UUID, 
                                BLECharacteristic::PROPERTY_READ   |
                                BLECharacteristic::PROPERTY_WRITE
                            );

        // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
        // Create a BLE Descriptor
        //hueCharacteristic->addDescriptor(new BLE2902());
        hueCharacteristic->setCallbacks(new BleHueCallbacks(hueState));

        pService->addCharacteristic(hueCharacteristic);

        // Start the service
        pService->start();

        // Start advertising
        BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
        pAdvertising->addServiceUUID(SERVICE_UUID);
        pAdvertising->setScanResponse(false);
        pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
        BLEDevice::startAdvertising();
    };

    void BleServer::tick() {
        // notify changed value
        // if (clientCallbacks->connected) {
        //     pCharacteristic->setValue((uint8_t*)&value, 4);
        //     pCharacteristic->notify();
        //     value++;
        // }

        // disconnecting
        if (!clientCallbacks->connected && !isAdvertising) {
            // give the bluetooth stack the chance to get things ready
            if (millis() - clientCallbacks->disconnectedAt >= 500) {
                pServer->startAdvertising(); // restart advertising
                isAdvertising = true;
            }
        }

        // connecting
        if (clientCallbacks->connected && isAdvertising) {
            // do stuff here on connecting
            isAdvertising = false;
        }
    };

}