/**
 * @file neo_animation.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Capsulation of the interaction with Adafruit Neopixel RGB LEDs.
 */

/* ------ Libraries ------ */
#include <Adafruit_NeoPixel.h>
#include <ArduinoLog.h>

/* ------ Custom Headers ------ */
#include <neo_animation.hpp>
#include <types.hpp>

/* ------ Macros ------ */
#define BRIGHTNESS 255

/* ------ Constructors ------ */

RhombusLEDStrip::RhombusLEDStrip(const uint16_t num_pixels, const pin_size_t arduino_pin, const u_int8_t *height_map)
            : num_pixels(num_pixels), arduino_pin(arduino_pin), height_map(height_map) {}

/* ------ Methods ------ */

void RhombusLEDStrip::init()
{
    pxl = Adafruit_NeoPixel(num_pixels, arduino_pin, NEO_GRB + NEO_KHZ800);
    pxl.begin();
    pxl.setBrightness(BRIGHTNESS);
    pxl.clear();
}

void RhombusLEDStrip::startAnimation(AnimationType animation_type)
{
    animation_data.state = animation_type;
    animation_data.ts_start = millis();
    animation_data.duration = getAnimationDuration(animation_type);
    animation_data.animation_ptr = getAnimationPointer(animation_type);
}

bool RhombusLEDStrip::update(void)
{
    if (animation_data.state == OFF) return false; 

    if (millis() > (animation_data.ts_start + animation_data.duration)) 
    {
        animation_data.state = OFF;
        pxl.clear();
        pxl.show();
        return true;
    } else 
    {
        /* Get index to right row, based on current timestamp
           and the timestamp on animation start. */
        u_int8_t idx = (millis() - animation_data.ts_start) / 100;
        u_int32_t* ptr = animation_data.animation_ptr + (AMOUNT_LED_LAYERS * idx);
        for (uint16_t i = 0; i < num_pixels; i++)
        {
            pxl.setPixelColor(i, pgm_read_dword(ptr + height_map[i]));
        }
        pxl.show();
        return false;
    }
}

boolean RhombusLEDStrip::animationActive()
{
    return animation_data.state != OFF;
}
