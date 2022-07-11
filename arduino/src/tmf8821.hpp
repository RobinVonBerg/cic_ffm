/**
 * @file tmf8821.hpp
 * @author Sven Hülsen (inf104302), Robin von Berg (inf104426)
 * @brief Header
 *        Capsulation of the interaction with the VCSEL dToF tmf88221 sensor.
 */

#pragma once

/* ------ Libraries ------ */
#include <SparkFun_TMF882X_Library.h>

/* ------ Custom Headers ------ */
#include <types.hpp>


struct TMF8821
{
private:
    /**
     * @brief Sensor instance from the "SparkFun_TMF882X_Library" library.
     * 
     */
    SparkFun_TMF882X sensor;

    /**
     * @brief Measurement results.
     * 
     */
    tmf882x_msg_meas_results results;

    /**
     * @brief State of the intake, defined by the last measurement.
     * 
     */
    IntakeState state;

    /**
     * @brief checks if the middle spad mad row detected something
     * 
     * @return true something was detected
     * @return false nothing was detected
     */
    bool checkMiddleRow();

    /**
     * @brief checks if the middle spad mad row detected something
     * 
     * @return true something was detected
     * @return false nothing was detected
     */
    bool checkBottomRow();

public:

    /**
     * @brief Initializes the TMF8821 Sensor with given params.
     * 
     */
    void init(void);

    /**
     * @brief Starts measuring until stop method is called.
     * 
     */
    void start(void);

    /**
     * @brief Get the state of the intake monitored by this sensor.
     *        Resets state to NONE if read state was DETECTED.
     * 
     * @param reset_detected_state set to true, if DETECTED state should be reset to NONE after reading. 
     * @return State of the intake.
     */
    IntakeState getState(bool reset_detected_state);
};