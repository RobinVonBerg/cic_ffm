/**
 * @file types.hpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Definitions of custom types.
 */

#pragma once

/* ------ Makros ------ */
/**
 * @brief Amount of Arduinos.
 * 
 */
#define NUM_ARDUINOS 3

/**
 * @brief ID for Arduino with peripheral role.
 * 
 */
#define PERIPHERAL_ARDUINO_ID 0

/**
 * @brief Maximale Anzahl an unterschiedlichen Farbwerten pro Animationsframe.
 *        Jeder Farbwert stellt eine 
 * 
 */
#define AMOUNT_LED_LAYERS 19

/* ------ Typedefs ------ */
/**
 * 
 * @brief Represents two 128 bit string UUIDs for BLE communication.
 *        There are two, because one is needed for the service
 *        and one for a characteristic
 * 
 *        Example: "10160001-7a03-401f-b878-dcdf5c0f30e9"
 * 
 */
typedef struct
{
    char service[37];
    char characteristic[37];
} UUIDStruct;


/**
 * @brief Duration in miliseconds.
 * 
 */
typedef uint16_t DurationMS;

typedef enum {
    ANIMATION_ORANGE_UP,
    ANIMATION_GREEN_UP,
    ANIMATION_BLUE_UP,
    META_AMOUNT_ANIMATIONS,
    OFF = META_AMOUNT_ANIMATIONS
} AnimationType;


typedef enum {
    NONE,
    INCOMING,
    DETECTED
} IntakeState;

/**
 * @brief All data needed for animations.
 * 
 */
typedef struct
{
    AnimationType state;
    DurationMS duration;
    u_int32_t ts_start;
} NeoData;

typedef struct
{
    AnimationType state;
    DurationMS duration;
    u_int32_t ts_start;
    u_int32_t *animation_ptr;
} NeoAnimationData;

/* ------ Constants ------ */

/**
 * @brief Used BLE UUIDs.
 * 
 */
static const UUIDStruct UUIDS[NUM_ARDUINOS] =
{
    {"ed40f0b8-4fa3-4544-99f0-0e80bd0ff854", "ed40f0b9-4fa3-4544-99f0-0e80bd0ff854"},
    {"bd77fbb4-cf10-4c1d-8794-805984d9a925", "bd77fbb5-cf10-4c1d-8794-805984d9a925"},
    {"ebe744c4-6e46-4e5a-acc2-ddb6b98c07f0", "ebe744c5-6e46-4e5a-acc2-ddb6b98c07f0"},
};
