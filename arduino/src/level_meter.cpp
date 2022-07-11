/**
 * @file level_meter.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Capsulation of the interaction with the fill level sensor.
 */

/* ------ Libraries ------ */
#include <ArduinoLog.h>
#include <math.h>

/* ------ Custom Headers ------ */
#include "level_meter.hpp"

/* ------ Constructors ------ */

LevelMeter::LevelMeter(u_int16_t empty_distance, u_int16_t full_distance, pin_size_t pin) 
    : empty_distance(empty_distance), full_distance(full_distance), arduino_pin(pin) {};

/* ------ Methods ------ */

u_int16_t LevelMeter::calculateDistance(u_int16_t pin_value)
{
    return u_int16_t (1000000000 * pow(pin_value, -3.016));
}

u_int8_t LevelMeter::getFillLevel()
{
    u_int16_t distance = calculateDistance(analogRead(arduino_pin));
    
    // depending on definition of full_distance, fill level might be over 100%
    if (distance < full_distance)
        return 100;

    // depending on definition of empty_distance, fill level might be under 0%
    if (distance > empty_distance)
        return 0;
    
    u_int16_t range = empty_distance - full_distance;
    u_int16_t fill_height = empty_distance - distance;
    
    return 100 * fill_height / range;
}