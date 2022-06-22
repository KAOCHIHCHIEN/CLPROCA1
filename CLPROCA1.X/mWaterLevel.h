/* 
 * File:   mWaterLevel.h
 * Author: KaoChihChien
 *
 * Created on December 23, 2020, 10:27 PM
 */

#ifndef MWATERLEVEL_H
#define	MWATERLEVEL_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LOW_WATER_LEVEL 0
#define MID_WATER_LEVEL 1
#define HIGH_WATER_LEVEL 2
#define CK_S_WATER_LEVEL_COUNT 20
#define CK_WATER_LEVEL_COUNT 10000
#define CK_LOW_DELAY 5    

    void ck_water_INIT(void);
uint8_t ck_water1_level (void);
uint8_t ck_water2_level (void);

#ifdef	__cplusplus
}
#endif

#endif	/* MWATERLEVEL_H */

