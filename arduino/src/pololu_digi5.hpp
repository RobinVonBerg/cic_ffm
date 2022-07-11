/**
 * @file pololu_digi5.h
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Header
 *        Capsulation of the interaction with the Pololu Digital
 *        Distance Sensor.
 */

#pragma once

/* ------ Libraries ------ */
#include <ArduinoLog.h>

/* ------ Custom Headers ------ */
#include <types.hpp>

struct Pololu5CM
{
    /**
     * @brief Digital I/O pin on which the sensor is connected to the Arduino.
     * 
     */
    pin_size_t arduino_pin;

    /**
     * @brief Creates interface to interact with a Pololu Digital Distance Sensor.
     * 
     * @param arduino_pin Digital I/O Arduino pin. 
     */
    Pololu5CM(pin_size_t arduino_pin);

    /**
     * @brief Reads current state of the sensor.
     * 
     * @return true Something sensed.
     * @return false Nothing sensed.
     */
    bool read(void);
};