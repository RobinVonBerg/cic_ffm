/**
 * @file level_meter.h
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Header
 *        Capsulation of the interaction with the fill level sensor.
 */
#pragma once

/* ------ Libraries ------ */
#include <ArduinoLog.h>


struct LevelMeter
{
    private:

        /**
         * @brief Distance in cm to sensor when fill level is empty.
         * 
         */
        u_int16_t empty_distance;

        /**
         * @brief Distance in cm to sensor which equals a fill level of 100%.
         * 
         */
        u_int16_t full_distance;
        
        /**
         * @brief Analog pin on Arduino.
         * 
         */
        pin_size_t arduino_pin;
        
    public:

        /**
         * @brief Creates interface to interact with the fill level sensor Sensor.
         * 
         * @param min_distance Distance in cm to sensor when fill level is empty.
         * @param max_distance Distance in cm to sensor which equals a fill level of 100%.
         * @param pin Analog pin on Arduino, where the sensor is connected.
         */
        LevelMeter(u_int16_t empty_distance, u_int16_t full_distance, pin_size_t pin);

        /**
         * @brief Calculates the distance in cm,
         *        based on the voltage measured on the connector pin.
         * 
         * @param pin_value measured voltage value.
         * @return u_int16_t calculated distance in cm.
         */
        u_int16_t calculateDistance(u_int16_t pin_value);

        /**
         * @brief Get the fill level in %.
         * 
         * @return u_int16_t fill level in %.
         */
        u_int8_t getFillLevel();
};