/**
 * @file main_dtof.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Contains the setup and main loop of the Arduino Nano 33 BLE program.
 *        Reads dTOF sensor and sets the DETECT-pin HIGH.
 *        If the other Arduino sends HIGH on ACK-pin,
 *        it starts advertising a BLE event.
 */

/* ------ System Headers ------ */

/* ------ Libraries ------ */
#include <Arduino.h>
#include <ArduinoLog.h>

/* ------ Custom Headers ------ */
#include <tmf8821.hpp>
#include <ble_peripheral.hpp>

/* ------ Constants ------ */
#define DETECT_PIN 10
#define ACK_PIN 11

/* ------ Global Variables ------ */

TMF8821 dtof;
BLEPeripheralWrapper ble;

/* ------ Methods  ------ */

void setup()
{
    delay(1000);

    /* Initialie logging. */
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.infoln("Serial initialized.");

    /* Define Output and Acknowledge pins */
    pinMode(DETECT_PIN, OUTPUT);
    pinMode(ACK_PIN, INPUT);
    
    /* Initialize TMF8821 */
    dtof.init();

    /* Initialize BLE */
    ble.init();
}

void loop()
{
    if (digitalRead(ACK_PIN) == HIGH) {
        Log.infoln("ACK-pin read HIGH, DETECT-pin set LOW.");
        digitalWrite(DETECT_PIN, LOW);

        // Delay advertisement by 50 * 20 miliseconds
        for (uint32_t i = 0; i < 50; i++)
        {
            delay(20);
            ble.update();
        }
        ble.publishEvent(1);
        Log.infoln("BLE-Event publsihed.");
    }

    dtof.start();

    // Detect something even in state INCOMING, because
    // movement-direction-detection isn't fast enough yet
    if (dtof.getState(true) != NONE) {
        Log.infoln("dTOF sensor sensed something, DETECT-pin set HIGH.");
        digitalWrite(DETECT_PIN, HIGH);
    }

    ble.update();
}