/**
 * @file ble_peripheral.hpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Header
 *        Capsulation of the BLE Peripheral interaction to advertise events
 *        to other microcontrollers.
 */

#pragma once

/* ------ Libraries ------ */
#include <ArduinoBLE.h>

/* ------ Custom Headers ------ */
#include <types.hpp>

struct BLEPeripheralWrapper
{
    private:
        /**
         * @brief Service the client advertises.
         * 
         */
        BLEService service;

        /**
         * @brief Characteristic the client writes to and advertises.
         * 
         */
        BLEUnsignedCharCharacteristic characteristic;

        /**
         * @brief When to end a advertised value.
         * 
         */
        u_int32_t ts_end = -1ul;

    public:
        /**
         * @brief Construct a new BLEPeripheralWrapper object.
         *        Initializes service and characteristic
         */
        BLEPeripheralWrapper();

        /**
         * @brief Initializes bluetooth capabilities and starts advertising
         * 
         * @return boolean False if something went wrong.  
         */
        boolean init(void);

        /**
         * @brief Calls BLE.poll() to check for events.
         */
        void update(void);

        /**
         * @brief Writes a new value to characteristic,
         * 
         * @param val Value that gets written.

        */
        void publishEvent(u_int8_t val);
};
