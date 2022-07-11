/**
 * @file animations.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Helper functions for animation data in flash memory.  
 */

/* ------ Libraries ------ */
#include <ArduinoLog.h>

/* ------ Custom Headers ------ */
#include <types.hpp>
#include <animations.hpp>

DurationMS getAnimationDuration(AnimationType animation)
{
    return ANIMATION_DURATIONS_MS[animation];
};

uint32_t* getAnimationPointer(AnimationType animation)
{
    return ANIMATIONS[animation];
};
