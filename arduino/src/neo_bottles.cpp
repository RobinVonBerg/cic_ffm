/**
 * @file neo_bottles.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Capsulation of the interaction with Adafruit Neopixel SK6812RGBW LEDs.
 */

/* ------ Libraries ------ */
#include <Adafruit_NeoPixel.h>
#include <ArduinoLog.h>

/* ------ Custom Headers ------ */
#include <neo_bottles.hpp>
#include <types.hpp>

/* ------ Macros ------ */
#define BRIGHTNESS 255

/* ------ Constructors ------ */

BottleLEDStrip::BottleLEDStrip(const uint16_t num_pixels, const pin_size_t arduino_pin)
            : num_pixels(num_pixels), arduino_pin(arduino_pin) {}

void BottleLEDStrip::init(void)
{
    pxl = Adafruit_NeoPixel(num_pixels, arduino_pin, NEO_GRBW + NEO_KHZ800);
    pxl.begin();
    pxl.setBrightness(BRIGHTNESS);
    pxl.clear();
}

/* ------ Methods ------ */

void BottleLEDStrip::setColor(const u_int32_t color)    
{
    pxl.fill(color);
}

void BottleLEDStrip::setColorAt(const u_int8_t idx, const u_int32_t color)    
{
    pxl.setPixelColor(idx, color);
}

void BottleLEDStrip::show(void)
{
    pxl.show();
} 