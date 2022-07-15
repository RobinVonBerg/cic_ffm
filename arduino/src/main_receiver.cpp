/**
 * @file main_receiver.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Contains the setup and main loop of the Arduino Nano 33 BLE program.
 *        Reacts to BLE value changes from Master arduino
 *        and starts NeoPixel animations.
 */

/* ------ System Headers ------ */

/* ------ Libraries ------ */
#include "Arduino.h"
#include "ArduinoLog.h"
#include "ArduinoBLE.h"

/* ------ Custom Headers ------ */
#include "types.hpp"
#include "neo_animation.hpp"

/* ------ Makros ------ */
/** 
 * @brief Number of LEDs.
 * 
 */
#define NUM_LEDS 12

/** 
 * @brief Digital I/O pin to control LEDs.
 * 
 */
#define LED_PIN 2

/* ------ Global Variables------ */

const static u_int8_t HEIGHT_MAP[NUM_LEDS] =
{
    5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5
}; 

RhombusLEDStrip leds(NUM_LEDS, LED_PIN, HEIGHT_MAP);

static u_int8_t val = 0;
static bool connected = false;

/* ------ Main Program ------ */

void setup(void)
{
    delay(1000);
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.infoln("Serial initialized.");
    pinMode(LED_BUILTIN, OUTPUT);

    leds.init();
    BLE.begin();
    BLE.scanForUuid(UUIDS[PERIPHERAL_ARDUINO_ID].service);
}

void loop(void)
{
    BLEDevice peripheral = BLE.available();

    if (peripheral)
    {
        Log.infoln("Found peripheral.");
        BLE.stopScan();

        if (peripheral.connect() && peripheral.discoverAttributes())
        {
            if (!connected)
            {
                connected = true;
                digitalWrite(LED_BUILTIN, LOW);
                Log.warningln("Connection established.");
            }
            Log.infoln("Connected to peripheral.");

            BLECharacteristic characteristic = 
                peripheral.characteristic(UUIDS[PERIPHERAL_ARDUINO_ID].characteristic);

            if (characteristic 
                        && characteristic.canSubscribe() 
                        && characteristic.subscribe())
            {
                while (peripheral.connected())
                {
                    Log.infoln("Connected to characteristic.");
                    if (characteristic.valueUpdated())
                    {
                        Log.infoln("Characteristic value changed.");
                        characteristic.readValue(val);

                        if (val) leds.startAnimation(ANIMATION_BLUE_UP);
                        Log.infoln("Starting Animation.");

                        while (leds.animationActive()) leds.update();
                    }
                }
            }
        }
        BLE.scanForUuid(UUIDS[PERIPHERAL_ARDUINO_ID].service);
    }
    if (connected)
    {
        connected = false;
        digitalWrite(LED_BUILTIN, HIGH);
        Log.warningln("Connection lost.");
    }
}
