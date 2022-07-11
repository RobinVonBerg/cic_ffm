/**
 * @file pololu_digi5.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Capsulation of the interaction with the Pololu Digital
 *        Distance Sensor.
 */

/* ------ Libraries ------ */
#include <ArduinoLog.h>

/* ------ Custom Headers ------ */
#include <pololu_digi5.hpp>
#include <types.hpp>

/* ------ Constructors ------ */

Pololu5CM::Pololu5CM(pin_size_t a_p) : arduino_pin{a_p}
{
    pinMode(arduino_pin, INPUT_PULLUP);
};

/* ------ Methods ------ */

bool Pololu5CM::read(void)
{
    return !digitalRead(arduino_pin);
}
