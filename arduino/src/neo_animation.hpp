/**
 * @file neo_animation.hpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Header
 *        Capsulation of the interaction with Adafruit Neopixel RGB LEDs.
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
struct RhombusLEDStrip
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

    /**
     * @brief Maps index to height.
     */
    const u_int8_t *height_map;

    /**
     * @brief State-Data of the LED-Strip
     * 
     */
    NeoAnimationData animation_data = {
        (AnimationType) OFF,
        (DurationMS) 0,
        -1ul,
        NULL
    };

public:

    /**
     * @brief Constructs a new group of chained LEDs.
     * 
     * @param type Type of LED
     * @param num_pixels Amount of chained LEDs.
     * @param arduino_pin Digital I/O pin on the arduino.
     * @param height_map Maps Index to height. 
     */
    RhombusLEDStrip(const uint16_t num_pixels, const pin_size_t arduino_pin, const u_int8_t *height_map);

    void init(void);

    /**
     * @brief All LEDs are showing a Animation.
     * 
     * @param animation_type Animation to play.
     */
    void startAnimation(AnimationType animation_type);

    /**
     * @brief Gets the right frame for animation and shows it.
     * 
     */
    bool update(void);

    /**
     * @brief Check if an animation is active,
     * 
     * @return boolean True if animation active.
     */
    boolean animationActive(void);
};