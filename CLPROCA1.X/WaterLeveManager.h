/* 
 * File:   WaterLeveManager.h
 * Author: KaoChihChien
 *
 * Created on February 10, 2022, 5:30 PM
 */

#ifndef WATERLEVEMANAGER_H
#define	WATERLEVEMANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/pin_manager.h"   
    
#define WATER_LEVE_SENSORS 2

    // Hardware interface
#define WaterLeveA1_pin WH1_MCU_PORT
#define WaterLeveA2_pin WM1_MCU_PORT
#define WaterLeveB1_pin WH2_MCU_PORT
#define WaterLeveB2_pin WM2_MCU_PORT
#define WaterLeveSignal_pin COM_MCU_LAT

#define WATER_LEVE_SIGNAL_ENABLE 1
#define WATER_LEVE_SIGNAL_DISENABLE 0

#define WATER_LEVE_DISENABLE 0
#define WATER_LEVE_ENABLE 1

#define INJECT_WATER 1
#define DO_NOT_INJECT_WATER 2

#define LOW_WATER_LEVEL 0
#define MID_WATER_LEVEL 1
#define HIGH_WATER_LEVEL 2

    void WaterLeveManager_Initialize(void);
    
    void WaterLeveManager_MainLoop(void);
    
    void WaterLeveManager_Sync_MainLoop(void);

    void WaterLeveManager_Enable(void);

    void WaterLeveManager_Disenable(void);

    unsigned char WaterLeveManager_IsInject_A(void);

    unsigned char WaterLeveManager_GetLeveState_A(void);

    unsigned char WaterLeveManager_IsInject_B(void);

    unsigned char WaterLeveManager_GetLeveState_B(void);

    void WaterLeveManager_WaterProtectTimer(void);
    
    
//#include "mcc_generated_files/pin_manager.h"
//
//#define WATER_LEVE_SENSORS 2
//
//    // Hardware interface
//#define WaterLeveA1_pin WH1_MCU_PORT
//#define WaterLeveA2_pin WM1_MCU_PORT
//#define WaterLeveB1_pin WH2_MCU_PORT
//#define WaterLeveB2_pin WM2_MCU_PORT
//#define WaterLeveSignal_pin COM_MCU_LAT
//
//#define WATER_LEVE_SIGNAL_ENABLE 1
//#define WATER_LEVE_SIGNAL_DISENABLE 0
//
//#define WATER_LEVE_DISENABLE 0
//#define WATER_LEVE_ENABLE 1
//
//#define WATER_LEVE_DISENABLE 0
//#define WATER_LEVE_ENABLE 1
//
//#define INJECT_WATER 1
//#define DO_NOT_INJECT_WATER 2
//
//#define LOW_WATER_LEVEL 0
//#define MID_WATER_LEVEL 1
//#define HIGH_WATER_LEVEL 2
//
//    typedef unsigned char(*scanFunction)(void);
//    
//    enum waterLeve_sensor_names {
//        Sensor_A = 0,
//        Sensor_B = 1,
//    };
//
//    enum waterLeve_manager_names {
//        Manager_A = 0,
//        Manager_B = 1,
//    };
//
//    void WaterLeveManager_InitializeAll(void);
//
//    void WaterLeveManager_MainLoop(void);
//
//    unsigned char WaterLeveManager_IsInject(enum waterLeve_manager_names name);
//
//    unsigned char WaterLeveManager_GetLeveState(enum waterLeve_manager_names name);
//
//    void WaterLeveManager_Enable(void);
//
//    void WaterLeveManager_Disenable(void);
//
//    void WaterLeveManager_RunTimer(void);
//
//    void WaterLeveManager_SetTimerHandler(void (* Handler)(void));

#ifdef	__cplusplus
}
#endif

#endif	/* WATERLEVEMANAGER_H */

