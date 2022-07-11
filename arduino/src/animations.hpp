/**
 * @file animations.hpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief animation data in flash memory.
 */

#pragma once

/* ------ Custom Headers ------ */
#include <types.hpp>

/* ------ Makros ------ */
/**
 * @brief Highest amount of frames an animation is using.
 */
#define MAX_ANIMATION_LENGTH_DS 44

/* ------ Global Variables ------ */

/**
 * @brief Animation durations in miliseconds.
 * 
 */
static const u_int32_t ANIMATION_DURATIONS_MS[META_AMOUNT_ANIMATIONS] = {
    4400, 4400, 4400
};

/**
 * @brief Colorvalues (RGB) of given animation
 *        Are stored in flash memory with a resolution of 10 fps.
 *        
 *        Each row describes an animation frame
 *        and holds a color value for each possible height.
 */
static PROGMEM uint32_t ANIMATIONS[META_AMOUNT_ANIMATIONS][AMOUNT_LED_LAYERS * MAX_ANIMATION_LENGTH_DS] = 
{
    {
        512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 
        512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 
        1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 
        10752, 10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 
        10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 
        10752, 10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 
        10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 
        10752, 10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 
        10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 
        10752, 10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 
        10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 
        10752, 10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 
        10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 
        10752, 10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 
        10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 
        10752, 18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 
        18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 
        18688, 18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 
        18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 
        18688, 18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 
        18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 
        18688, 18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 
        18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        18688, 18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        18688, 29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        29952, 44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        44544, 62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        62720, 44544, 29952, 18688, 18688, 18688, 18688, 18688, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 10752, 
        1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 
        1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 
        512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512
    },
    {
        131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 
        131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 
        458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 
        2752512, 2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 
        2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 
        2752512, 2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 
        2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 
        2752512, 2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 
        2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 
        2752512, 4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 
        4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        4784128, 7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        7667712, 11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        11403264, 16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        16056320, 11403264, 7667712, 4784128, 4784128, 4784128, 4784128, 4784128, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 2752512, 
        458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 458752, 
        262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 262144, 
        131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072, 131072
    },
    {
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 
        42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 
        42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 
        42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 
        42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 
        42, 42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 
        42, 42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 
        42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 
        42, 42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 
        42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 
        42, 42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 
        42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 
        42, 42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 
        42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 
        42, 42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 
        42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 
        42, 42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 
        42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 
        42, 42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 
        42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 
        42, 42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 
        42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 
        42, 73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 
        73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 
        73, 73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 
        73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 
        73, 73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 
        73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 
        73, 73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 
        73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 
        73, 73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 
        73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 
        73, 117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 
        117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 42, 
        117, 174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 42, 
        174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 
        174, 245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 
        245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 
        245, 174, 117, 73, 73, 73, 73, 73, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
    }
};

/* ---- Methods ---- */

/**
 * @brief Returns the duration in miliseconds for the given animation.
 */
DurationMS getAnimationDuration(AnimationType animation);

/**
* @brief Returns the (flash memory) pointer for the given animation.
*/
uint32_t* getAnimationPointer(AnimationType animation);
