/**
 * @file main_transmitter.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Contains the setup and main loop of the Arduino Nano 33 BLE program.
 *        Reacts to input from the dTOF arduino, reads bottle sensors
 *        and handles NeoLED interaction.
 */

/* ------ System Headers ------ */

/* ------ Libraries ------ */
#include "Arduino.h"
#include "ArduinoLog.h"
#include "Adafruit_NeoPixel.h"

/* ------ Custom Headers ------ */
#include "types.hpp"
#include "pololu_digi5.hpp"
#include "neo_animation.hpp"
#include "neo_bottles.hpp"

/* ------ Makros ------ */

#define AMNT_BOTTLE_LEDS 2
#define AMNT_BOTTLE_SENSORS 3
#define AMNT_RHOMBUS_LEDS 3

#define LED_BOTTLES_PIN_1 2
#define LED_BOTTLES_PIN_2 3
#define LED_RHOMBUS_PIN_1 4 
#define LED_RHOMBUS_PIN_2 5
#define LED_RHOMBUS_PIN_3 6

#define BOTTLE_SENSOR_PIN_1 7
#define BOTTLE_SENSOR_PIN_2 8
#define BOTTLE_SENSOR_PIN_3 9

#define DETECT_PIN 10
#define ACK_PIN 11

/* Duration until the ACK-PIN gets reset to LOW again. */
#define TIME_ACK_MS 500

/* ------ Global Variables------ */

/* LEDS in different connected NeoPixel stripes.*/
static const u_int8_t AMOUNT_LEDs[5] =
{
    16, 14, 36, 24, 35
};

/* Color shown if bottle sensor senses a bottle. */
static const u_int32_t BOTTLE_LED_COLOR_ON
            = Adafruit_NeoPixel::Color(255, 255, 255, 255);

/* Color shown if bottle sensor does not senses a bottle. */
static const u_int32_t BOTTLE_LED_COLOR_OFF
            = Adafruit_NeoPixel::Color(0, 0, 0, 0);

/* Heightmaps for the LED Stripes that form a rhombus of little rhombuses. */
static const u_int8_t LED_MAPPING_1[36] =
{
    18,17,16,16,17,18,15,14,13,13,14,15,15,14,13,13,14,15,
    12,11,10,10,11,12,12,11,10,10,11,12,12,11,10,10,11,12
};
static const u_int8_t LED_MAPPING_2[24] =
{
    9,8,7,7,8,9,9,8,7,7,8,9,
    9,8,7,7,8,9,9,8,7,7,8,9
};
static const u_int8_t LED_MAPPING_3[35] =
{
    6,5,4,4,5,6,6,5,4,4,5,6,6,5,4,4,5,6,
    3,2,1,1,2,3,3,2,1,1,2,3,0,0,0,0,0
};

BottleLEDStrip bottleLEDs[AMNT_BOTTLE_LEDS] =
{
    BottleLEDStrip(AMOUNT_LEDs[0], LED_BOTTLES_PIN_1),
    BottleLEDStrip(AMOUNT_LEDs[1], LED_BOTTLES_PIN_2)
};

RhombusLEDStrip rhombusLEDs[AMNT_RHOMBUS_LEDS] =
{
    RhombusLEDStrip(AMOUNT_LEDs[2], LED_RHOMBUS_PIN_1, LED_MAPPING_1),
    RhombusLEDStrip(AMOUNT_LEDs[3], LED_RHOMBUS_PIN_2, LED_MAPPING_2),
    RhombusLEDStrip(AMOUNT_LEDs[4], LED_RHOMBUS_PIN_3, LED_MAPPING_3)
};

Pololu5CM bottleSensors[AMNT_BOTTLE_SENSORS] =
{
    Pololu5CM(BOTTLE_SENSOR_PIN_1),
    Pololu5CM(BOTTLE_SENSOR_PIN_2),
    Pololu5CM(BOTTLE_SENSOR_PIN_3)
};

bool animation_active = false;
bool bottles_full = false;

/* TImestamp when to reset the ACK-PIN. */
uint32_t ts_ack = -1ul;

/* ------ Main Program ------ */

void setup(void)
{
    delay(1000);
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.infoln("Serial initialized.");

    /* Define Output and Acknowledge pins */
    pinMode(DETECT_PIN, INPUT);
    pinMode(ACK_PIN, OUTPUT);

    for (u_int8_t i = 0; i < AMNT_BOTTLE_LEDS; i++) bottleLEDs[i].init();
    for (u_int8_t i = 0; i < AMNT_RHOMBUS_LEDS; i++) rhombusLEDs[i].init();
    Log.infoln("LEDs initialized.");
}

void loop(void)
{
    if (millis() > ts_ack)
    {
        ts_ack = -1ul;
        digitalWrite(ACK_PIN, LOW);
        Log.infoln("ACK-PIN reset.");
    }

    // Bottle sensors and bottle LEDs.
    for (u_int8_t i = 0; i < AMNT_BOTTLE_LEDS; i++) bottleLEDs[i].setColor(BOTTLE_LED_COLOR_ON);

    uint8_t cnt = 0;
    for (u_int8_t i = 0; i < AMNT_BOTTLE_SENSORS; i++)
    {
        if (!bottleSensors[i].read())
        {
            cnt++;
            bottleLEDs[0].setColorAt((i * 2), BOTTLE_LED_COLOR_OFF);
            bottleLEDs[0].setColorAt((i * 2) + 1, BOTTLE_LED_COLOR_OFF);
            Log.infoln("Bottle sensor %i is sensing something!", i);
        }
    }
    for (u_int8_t i = 0; i < AMNT_BOTTLE_LEDS; i++) bottleLEDs[i].show();

    // Check if all bottle sensors are active
    // and if it is the first loop, that it is like that.
    // Then show an animation.
    if (cnt == AMNT_BOTTLE_SENSORS)
    {
        Log.infoln("All bottle sensors are active.");
        if (!animation_active)
        {
            if (!bottles_full)
            {
                animation_active = true;
                if (ts_ack == -1ul) digitalWrite(ACK_PIN, HIGH);
                for (u_int8_t i = 0; i < AMNT_RHOMBUS_LEDS; i++) rhombusLEDs[i].startAnimation(ANIMATION_BLUE_UP);
                Log.infoln("Started animation.");
            }
            bottles_full = true;
        }
    }
    else
    {
        bottles_full = false;
    }

    // Show an animation if DETECT-pin is HIGH.
    if (!animation_active && digitalRead(DETECT_PIN))
    {
        Log.infoln("HIGH auf DETECT-PIN gelesen.");
        animation_active = true;
        if (ts_ack == -1ul) digitalWrite(ACK_PIN, HIGH);
        for (u_int8_t i = 0; i < AMNT_RHOMBUS_LEDS; i++) rhombusLEDs[i].startAnimation(ANIMATION_BLUE_UP);
        Log.infoln("Started animation.");
    }

    // Update animation on rhombus NeoPixels.
    for (u_int8_t i = 0; i < AMNT_RHOMBUS_LEDS; i++) 
    {
        if (rhombusLEDs[i].animationActive() && rhombusLEDs[i].update()) animation_active = false;
    }
}
