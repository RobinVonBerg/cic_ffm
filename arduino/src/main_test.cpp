/**
 * @file main_test.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Contains the setup and main loop of the Arduino Nano 33 BLE program.
 *        Used for tests.
 */

/* ------ System Headers ------ */

/* ------ Libraries ------ */
#include "Arduino.h"
#include "ArduinoLog.h"

/* ------ Custom Headers ------ */
#include "types.hpp"

/* ------ Makros ------ */


/* ------ Global Variables------ */


/* ------ Main Program ------ */

void setup(void)
{
    delay(1000);
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.infoln("Serial initialized.");
}

void loop(void)
{

}
