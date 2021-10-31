/**
 * A BLE client example that is rich in capabilities.
 * There is a lot new capabilities implemented.
 * author unknown
 * updated by chegewara
 */

#include "BLEDevice.h"
//#include "BLEScan.h"

#define SERVICE_UUID "421dd58e-8985-4547-a67a-20aa5a44f4ad"
#define HUE_CHARACTERISTIC_UUID "37affa35-4fff-4b04-bd4e-a7d7feebed6c"

// The remote service we wish to connect to.
static BLEUUID serviceUUID(SERVICE_UUID);
// The characteristic of the remote service we are interested in.
static BLEUUID charUUID(HUE_CHARACTERISTIC_UUID);

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;

byte sw1;
byte sw2;
byte sw3;
byte sw4;
byte sw5;
byte sw6;
byte sw7;
byte sw8;
byte sw9;
byte sw10;
byte sw11;
byte sw12;
byte sw13;
byte sw14;
byte sw15;
byte sw16;
byte sw17;
byte sw18;
byte sw19;

static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {
    Serial.print("Notify callback for characteristic ");
    Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
    Serial.print(" of data length ");
    Serial.println(length);
    Serial.print("data: ");
    Serial.println((char*)pData);
}

class MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient* pclient) {
    Serial.println("help");
  }

  void onDisconnect(BLEClient* pclient) {
    connected = false;
    Serial.println("onDisconnect");
  }
};

bool connectToServer() {
    Serial.print("Forming a connection to ");
    Serial.println(myDevice->getAddress().toString().c_str());
    
    BLEClient*  pClient  = BLEDevice::createClient();
    Serial.println(" - Created client");

    pClient->setClientCallbacks(new MyClientCallback());

    // Connect to the remove BLE Server.
    pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
    Serial.println(" - Connected to server fuck");
    //pClient->setMTU(517); //set client to request maximum MTU from server (default is 23 otherwise)


  
    // Obtain a reference to the service we are after in the remote BLE server.
    BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
    if (pRemoteService == nullptr) {
      Serial.print("Failed to find our service UUID: ");
      Serial.println(serviceUUID.toString().c_str());
      pClient->disconnect();
      return false;
    }
    Serial.println(" - Found our service");

    Serial.println("sup2");

    // Obtain a reference to the characteristic in the service of the remote BLE server.
    pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
    if (pRemoteCharacteristic == nullptr) {
      Serial.print("Failed to find our characteristic UUID: ");
      Serial.println(charUUID.toString().c_str());
      pClient->disconnect();
      return false;
    }
    Serial.println(" - Found our characteristic");

    // Read the value of the characteristic.
    // if(pRemoteCharacteristic->canRead()) {
    //   std::string value = pRemoteCharacteristic->readValue();
    //   Serial.print("The characteristic value was: ");
    //   Serial.println(value.c_str());
    // }

    if(pRemoteCharacteristic->canNotify())
      pRemoteCharacteristic->registerForNotify(notifyCallback);

    connected = true;
    return true;
}
/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
 /**
   * Called for each advertising BLE server.
   */
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    Serial.print("BLE Advertised Device found: ");
    Serial.println(advertisedDevice.toString().c_str());

    // We have found a device, let us now see if it contains the service we are looking for.
    if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {

      BLEDevice::getScan()->stop();
      myDevice = new BLEAdvertisedDevice(advertisedDevice);
      doConnect = true;
      doScan = true;

    } // Found our server
  } // onResult
}; // MyAdvertisedDeviceCallbacks


void setup() {
  Serial.begin(115200);
  Serial.println("Starting Arduino BLE Client application...");
  BLEDevice::init("");

  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 5 seconds.
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);




    // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
} // End of setup.


// This is the Arduino main loop function.
void loop() {

  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are 
  // connected we set the connected flag to be true.
  if (doConnect == true) {
    if (connectToServer()) {
      Serial.println("We are now connected to the BLE Server.");
    } else {
      Serial.println("We have failed to connect to the server; there is nothin more we will do.");
    }
    doConnect = false;
  }

  // If we are connected to a peer BLE Server, update the characteristic each time we are reached
  // with the current time since boot.
  if (connected) {
    handleInput();
  } else if(doScan) {
    BLEDevice::getScan()->start(0);  // this is just example to start scan after disconnect, most likely there is better way to do it in arduino
  }

  
  delay(1000); // Delay a second between loops.
} // End of loop

void handleInput() {
  uint8_t hueOverride = 0;

  byte sw1i = digitalRead(2);
  Serial.print("sw1 - ");
  Serial.println(sw1i);

  byte sw2i = digitalRead(4);
  Serial.print("sw2 - ");
  Serial.println(sw2i);

  byte sw3i = digitalRead(5);
  Serial.print("sw3 - ");
  Serial.println(sw3i);

  byte sw4i = digitalRead(18);
  if (sw4i != sw4) { // red
    hueOverride += 5;
  }
  Serial.print("sw4 - ");
  Serial.println(sw4i);

  byte sw5i = digitalRead(19);
  if (sw5i != sw5) { // Green
    hueOverride += 45;
  }
  Serial.print("sw5 - ");
  Serial.println(sw5i);

  byte sw6i = digitalRead(21); 
  if (sw6i != sw6) { // Blue
    hueOverride += 65;
  }
  Serial.print("sw6 - ");
  Serial.println(sw6i);

  byte sw7i = digitalRead(22);
  Serial.print("sw7 - ");
  Serial.println(sw7i);

  byte sw8i = digitalRead(23);
  Serial.print("sw8 - ");
  Serial.println(sw8i);

  byte sw9i = digitalRead(13); // black
  Serial.print("sw9 - ");
  Serial.println(sw9i);

  byte sw10i = digitalRead(12); // white
  Serial.print("sw10 - ");
  Serial.println(sw10i);

  byte sw11i = digitalRead(14); // yellow
  if (sw11i != sw11) {
    hueOverride += 25;
  }
  Serial.print("sw11 - ");
  Serial.println(sw11i);

  byte sw12i = digitalRead(27);
  Serial.print("sw12 - ");
  Serial.println(sw12i);

  byte sw13i = digitalRead(26);
  Serial.print("sw13 - ");
  Serial.println(sw13i);

  byte sw14i = digitalRead(25);
  Serial.print("sw14 - ");
  Serial.println(sw14i);

  byte sw15i = digitalRead(33);
  Serial.print("sw15 - ");
  Serial.println(sw15);

  byte sw16i = digitalRead(32);
  Serial.print("sw16 - ");
  Serial.println(sw16i);

  byte sw17i = digitalRead(35);
  Serial.print("sw17 - ");
  Serial.println(sw17i);

  byte sw18i = digitalRead(34);
  Serial.print("sw18 - ");
  Serial.println(sw18i);

  byte sw19i = digitalRead(15);
  Serial.print("sw19 - ");
  Serial.println(sw19i);

  if (hueOverride > 0) {
    Serial.println("hueOverride");
    pRemoteCharacteristic->writeValue(hueOverride);
  }
}