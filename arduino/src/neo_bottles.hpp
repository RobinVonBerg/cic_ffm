/**
 * @file neo_bottles.hpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Header
 *        Capsulation of the interaction with Adafruit Neopixel SK6812RGBW LEDs.
 */

#pragma once

/* ------ Libraries ------ */
#include <Adafruit_NeoPixel.h>

/* ------ Custom Headers ------ */
#include <types.hpp>
#include <animations.hpp>


/**
 * @brief Encapsulates the interaction with a connected chain of
 *        Adafruit Neopixel SK6812RGBW LEDs.
 *        Provides methods to animate the LEDs.
 * 
 */
struct BottleLEDStrip
{
private:
    /**
     * @brief Amount of chained LEDs.
     * 
     */
    const uint16_t num_pixels;

    /**
     * @brief Digital I/O pin to control LEDs.
     * 
     */
    const pin_size_t arduino_pin;

    /**
     * @brief Instance of the "Adafruit NeoPixel" library to control the LEDs.
     * 
     */
    Adafruit_NeoPixel pxl;

public:
    /**
     * @brief Constructs a new group of chained LEDs.
     * 
     * @param num_pixels Amount of chained LEDs.
     * @param arduino_pin Digital I/O pin on the arduino.
     */
    BottleLEDStrip(const uint16_t num_pixels, const pin_size_t arduino_pin);

    void init(void);

    /**
     * @brief All LEDs are updated with a single given color.
     * 
     * @param color Color to show.
     */
    void setColor(const u_int32_t color);

    /**
     * @brief Specified LED is updated with single given color.
     * 
     * @param idx Index the color gets changed.
     * @param color Color to show.
     */
    void setColorAt(const u_int8_t idx, const u_int32_t color);

    /**
     * @brief Must be called in loop.
     * 
     */
    void show(void);
};
