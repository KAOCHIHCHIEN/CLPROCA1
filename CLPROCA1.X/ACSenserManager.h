/* 
 * File:   ACSenserManager.h
 * Author: KaoChihChien
 *
 * Created on 2022?2?15?, ?? 12:11
 */

#ifndef ACSENSERMANAGER_H
#define	ACSENSERMANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/pin_manager.h"

#define AC_SENSORS 5

    enum ac_sensor_names {
        AC_HEATING = 0,
        AC_SODA = 1,
        AC_COOL = 2,
        AC_CHILLING = 3,
        AC_HOT = 4,
    };

    unsigned char ac_get_heating(void);

    unsigned char ac_get_soda(void);

    unsigned char ac_get_cool(void);

    unsigned char ac_get_chilling(void);

    unsigned char ac_get_hot(void);

    void ACSenserManager_SetTimerHandler(void (* Handler)(void));
    void ACSenserManager_InitializeAll(void);
    void ACSenserManager_MainLoop(void);
    unsigned char ACSenserManager_GetPortState(enum ac_sensor_names name);
    void ACSenserManager_RunTimer(void);


#ifdef	__cplusplus
}
#endif

#endif	/* ACSENSERMANAGER_H */

