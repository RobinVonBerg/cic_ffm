/**
 * @file ble_peripheral.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Capsulation of the BLE Peripheral interaction to advertise events
 *        to other microcontrollers.
 */

/* ------ Libraries ------ */
#include "ArduinoBLE.h"
#include "ArduinoLog.h"

/* ------ Custom Headers ------ */
#include "types.hpp"
#include "ble_peripheral.hpp"

/* ---- Makros ---- */
/**
 * @brief Advertising name. 
 */
#define BLE_NAME ("PartyTime")

/**
 * @brief Duration until the default value "0" gets written again,
 *        after an event publication.
 */
#define BLE_ADVERTISING_DURATION_MS 3000


/* ------ Methods ------ */

BLEPeripheralWrapper::BLEPeripheralWrapper()
            : service(UUIDS[ARDUINO_ID].service),
              characteristic(UUIDS[ARDUINO_ID].characteristic, BLERead | BLENotify) {}


boolean BLEPeripheralWrapper::init(void)
{
    if (!BLE.begin()) {
        Log.errorln("BLE.begin() for Peripheral was unsuccessful.");
        return false;
    }

    BLE.setAdvertisedService(service);
    BLE.setLocalName(BLE_NAME);

    service.addCharacteristic(characteristic);

    BLE.addService(service);

    characteristic.writeValue(0);
    
    BLE.advertise();

    Log.infoln("BLE peripheral successfully initialised and advertising.");
    return true;
}


void BLEPeripheralWrapper::update()
{
    BLE.poll();
    if (millis() > ts_end) 
    {
        characteristic.writeValue(0);
        ts_end = -1ul;
        Log.infoln("Advertisment timer ended, characteristic reset again.");
    }
}


void BLEPeripheralWrapper::publishEvent(u_int8_t val)
{
    if (ts_end == -1ul)
    {
        ts_end = millis() + BLE_ADVERTISING_DURATION_MS;
        characteristic.writeValue(val);
        Log.infoln("New value written in characteristic, advertisment timer started.");
    }
    else
    {
        Log.warningln("Couldn't write new value, still one value present.");
    }
}