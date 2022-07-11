/**
 * @file tmf8821.cpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Capsulation of the interaction with the VCSEL dToF TMF8821 sensor.
 * 
 * TMF8821 Documentation:
 * https://sparkfun.github.io/SparkFun_Qwiic_TMF882X_Arduino_Library/
 */

/* ------ Libraries ------ */
#include <SparkFun_TMF882X_Library.h>
#include <ArduinoLog.h>
#include <Wire.h>

/* ------ Custom Headers ------ */
#include <tmf8821.hpp>

/* ------ Constants ------ */
#define DETECTION_DISTANCE_MM 320
#define DTOF_CONFIDENCE 190

/* ------ Constructors ------ */


/* ------ Methods ------ */

void TMF8821::init ()
{
    // https://sparkfun.github.io/SparkFun_Qwiic_TMF882X_Arduino_Library/api_device/#begin
    // https://docs.arduino.cc/learn/communication/wire
    if (!sensor.begin())
    {
        Log.errorln("The TMF8821 failed to initialize.\n");
    }

    /*  SPAD-map IDs:
        1 = 3x3 Normal mode (33° x 32°)
        6 = 3x3 Wide mode (41° x 52°)
        7 = 4x4 Normal mode (41° x 52°)
        10 = 3x6 Mode (33° x 60°) *doesn't work properly
        13 = 4x4 Narrow mode (33° x 42°)
    

        SPAD-map orientation
        (the sensor has a little dot in one corner,
        thats the corner where section number 7 is located):

                          Sensor                           Spad-Map
        ########################################### | ###################
        #                                         # | #     #     #     #
        #                                         # | #  1  #  2  #  3  #
        #        #####              #####         # | ###################
        #        #   #              #   #         # | #     #     #     #
        #        #   #              #   #         # | #  4  #  5  #  6  #
        #        #####              #####         # | ###################
        #                                         # | #     #     #     #
        # ( )                                     # | #  7  #  8  #  9  #
        ########################################### | ###################
   */

    // spad_map_id 6 seems to work best. 1 works well, too, but it's narrower.
    // CAUTION: Changing spad-map to a not 3x3 variant needs adjustment in
    //          checkMiddleRow() and checkBottomRow() functions.
    u_int8_t spad_map_id = 6;
    if (!sensor.setCurrentSPADMap(spad_map_id)
        || sensor.getCurrentSPADMap() != spad_map_id) 
    {
        Log.errorln("Failed to set the SPAD Map.");
    }
    // setSampleDelay sets minimum time between measurements.
    // Testing showed that setting it below 50 ms leads to less accuracy.
    sensor.setSampleDelay(50);
}

void TMF8821::start(void)
{
    sensor.startMeasuring(results);

    // save momentary state
    IntakeState curr = state;

    switch (curr) 
    {
        case NONE:
            // if nothin was detected before, check if the middle row detects something.
            if (checkMiddleRow())
            {
                state = INCOMING;
                Log.infoln("new state: INCOMING");
            }
            break;
        case INCOMING:
            // if state was INCOMING, check if object moved down
            // and is now only detected by the bottom row.
            if (checkBottomRow() && !checkMiddleRow())
            {
                state = DETECTED;
                Log.infoln("new state: DETECTED");
            }
            else if (!checkBottomRow() && !checkMiddleRow())
            {
                state = NONE;
                Log.infoln("new state: NONE");
            }
            break;
        default:
            // if state is DETECTED don't do anything because state wasn't read yet.
            break;
    }
}

IntakeState TMF8821::getState(bool reset_detected_state)
{
    if (state == DETECTED && reset_detected_state)
    {
        state = NONE;
        Log.infoln("new state: NONE");
        return DETECTED;
    }
    return state;
}

bool TMF8821::checkMiddleRow()
{
    bool result = false;
    for (u_int32_t i = 0; i < results.num_results; ++i)
    {
        tmf882x_meas_result res = results.results[i];
        
        // if confidence isn't high enough or channel isn't in middle row,
        // no need to check
        if (res.confidence > DTOF_CONFIDENCE 
            && ((res.channel % 3) == 2))
        {
            if (res.distance_mm < DETECTION_DISTANCE_MM)
            {
               result = true; 
            }
        }
    }
    return result;
}

bool TMF8821::checkBottomRow()
{
    bool result = false;
    for (u_int32_t i = 0; i < results.num_results; ++i)
    {
        tmf882x_meas_result res = results.results[i];

        // if confidence isn't high enough or channel isn't in bottom row,
        // no need to check
        if (res.confidence > DTOF_CONFIDENCE 
            && ((res.channel % 3) == 0))
        {
            if (res.distance_mm < DETECTION_DISTANCE_MM)
            {
               result = true; 
            }
        }
    }
    return result;
}