
#include "WaterLeveManager.h"

#define ON_WATER 1
#define HAVE_WATER 0

#define CHECK_COUNT 500
#define CHECK_B_COUNT 3000

typedef struct {
    unsigned char isWaterLevel1;
    unsigned char isWaterLevel2;
    unsigned int setCountWaterLevel;
    unsigned int countWaterLevel1;
    unsigned int countWaterLevel2;
    unsigned char waterLeveState;
    unsigned char isInject;
    unsigned int LowWaterLeveProtectTimer;
    unsigned int MiddleWaterLeveProtectTimer;
    unsigned char LowWaterLeveProtectTimerOUT_Flag;
    unsigned char MiddleWaterLeveProtectTimerOUT_Flag;
} waterLeve_sensor_t;

static waterLeve_sensor_t WaterLevelSensorA;
static waterLeve_sensor_t WaterLevelSensorB;

static unsigned char isWaterLeveEnable;

static void MonitorWaterLevel_A(void) {

    if (WaterLeveA1_pin == ON_WATER) {
        if (WaterLevelSensorA.countWaterLevel1 != 0) {
            WaterLevelSensorA.countWaterLevel1--;
        } else {
            WaterLevelSensorA.isWaterLevel1 = ON_WATER;
        }
    } else {
        WaterLevelSensorA.countWaterLevel1 = WaterLevelSensorA.setCountWaterLevel;
        WaterLevelSensorA.isWaterLevel1 = HAVE_WATER;
    }

    if (WaterLeveA2_pin == ON_WATER) {
        if (WaterLevelSensorA.countWaterLevel2 != 0) {
            WaterLevelSensorA.countWaterLevel2--;
        } else {
            WaterLevelSensorA.isWaterLevel2 = ON_WATER;
        }
    } else {
        WaterLevelSensorA.countWaterLevel2 = WaterLevelSensorA.setCountWaterLevel;
        WaterLevelSensorA.isWaterLevel2 = HAVE_WATER;
    }

    if ((WaterLevelSensorA.isWaterLevel1 == ON_WATER) && (WaterLevelSensorA.isWaterLevel2 == ON_WATER)) {
        WaterLevelSensorA.waterLeveState = LOW_WATER_LEVEL;
    } else if (((WaterLevelSensorA.isWaterLevel1 == ON_WATER) && (WaterLevelSensorA.isWaterLevel2 == HAVE_WATER)) ||
            ((WaterLevelSensorA.isWaterLevel1 == HAVE_WATER) && (WaterLevelSensorA.isWaterLevel2 == ON_WATER))) {
        WaterLevelSensorA.waterLeveState = MID_WATER_LEVEL;
    } else if ((WaterLevelSensorA.isWaterLevel1 == HAVE_WATER) && (WaterLevelSensorA.isWaterLevel2 == HAVE_WATER)) {
        WaterLevelSensorA.waterLeveState = HIGH_WATER_LEVEL;
    }
}

static void MonitorWaterLevel_B(void) {

    if (WaterLeveB1_pin == ON_WATER) {
        if (WaterLevelSensorB.countWaterLevel1 != 0) {
            WaterLevelSensorB.countWaterLevel1--;
            if (WaterLevelSensorB.countWaterLevel1 < 100) {
                WaterLevelSensorB.isWaterLevel1 = ON_WATER;
            }
        }
    } else {
        if (WaterLevelSensorB.countWaterLevel1 < WaterLevelSensorB.setCountWaterLevel) {
            WaterLevelSensorB.countWaterLevel1++;
            if (WaterLevelSensorB.countWaterLevel1 > 2800) {
                WaterLevelSensorB.isWaterLevel1 = HAVE_WATER;
            }
        }
    }

    if (WaterLeveB2_pin == ON_WATER) {
        if (WaterLevelSensorB.countWaterLevel2 != 0) {
            WaterLevelSensorB.countWaterLevel2--;
            if (WaterLevelSensorB.countWaterLevel2 < 100) {
                WaterLevelSensorB.isWaterLevel2 = ON_WATER;
            }
        }
    } else {
        if (WaterLevelSensorB.countWaterLevel2 < WaterLevelSensorB.setCountWaterLevel) {
            WaterLevelSensorB.countWaterLevel2++;
            if (WaterLevelSensorB.countWaterLevel2 > 2800) {
                WaterLevelSensorB.isWaterLevel2 = HAVE_WATER;
            }
        } 
    }

    if ((WaterLevelSensorB.isWaterLevel1 == ON_WATER) && (WaterLevelSensorB.isWaterLevel2 == ON_WATER)) {
        WaterLevelSensorB.waterLeveState = LOW_WATER_LEVEL;
    } else if (((WaterLevelSensorB.isWaterLevel1 == ON_WATER) && (WaterLevelSensorB.isWaterLevel2 == HAVE_WATER)) ||
            ((WaterLevelSensorB.isWaterLevel1 == HAVE_WATER) && (WaterLevelSensorB.isWaterLevel2 == ON_WATER))) {
        WaterLevelSensorB.waterLeveState = MID_WATER_LEVEL;
    } else if ((WaterLevelSensorB.isWaterLevel1 == HAVE_WATER) && (WaterLevelSensorB.isWaterLevel2 == HAVE_WATER)) {
        WaterLevelSensorB.waterLeveState = HIGH_WATER_LEVEL;
    }
}

void WaterLeveManager_Initialize(void) {
    WaterLevelSensorA.countWaterLevel1 = CHECK_COUNT;
    WaterLevelSensorA.countWaterLevel2 = CHECK_COUNT;
    WaterLevelSensorA.setCountWaterLevel = CHECK_COUNT;
    WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
    WaterLevelSensorA.isWaterLevel1 = HAVE_WATER;
    WaterLevelSensorA.isWaterLevel2 = HAVE_WATER;
    WaterLevelSensorA.waterLeveState = HIGH_WATER_LEVEL;
    WaterLevelSensorA.LowWaterLeveProtectTimer = 0;
    WaterLevelSensorA.MiddleWaterLeveProtectTimer = 0;
    WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag = 0;
    WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 0;
    
    WaterLevelSensorB.countWaterLevel1 = CHECK_B_COUNT;
    WaterLevelSensorB.countWaterLevel2 = CHECK_B_COUNT;
    WaterLevelSensorB.setCountWaterLevel = CHECK_B_COUNT;
    WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
    WaterLevelSensorB.isWaterLevel1 = HAVE_WATER;
    WaterLevelSensorB.isWaterLevel2 = HAVE_WATER;
    WaterLevelSensorB.waterLeveState = HIGH_WATER_LEVEL;
    WaterLevelSensorB.LowWaterLeveProtectTimer = 0;
    WaterLevelSensorB.MiddleWaterLeveProtectTimer = 0;
    WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag = 0;
    WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 0;

    isWaterLeveEnable = WATER_LEVE_ENABLE;
}

void WaterLeveManager_WaterProtectTimer(void) {
    
    if (WaterLevelSensorA.LowWaterLeveProtectTimer !=0 ) {
        WaterLevelSensorA.LowWaterLeveProtectTimer--;
    }
    if (WaterLevelSensorA.MiddleWaterLeveProtectTimer !=0 ) {
        WaterLevelSensorA.MiddleWaterLeveProtectTimer--;
    }
    if (WaterLevelSensorB.LowWaterLeveProtectTimer !=0 ) {
        WaterLevelSensorB.LowWaterLeveProtectTimer--;
    }
    if (WaterLevelSensorB.MiddleWaterLeveProtectTimer !=0 ) {
        WaterLevelSensorB.MiddleWaterLeveProtectTimer--;
    }
}

void WaterLeveManager_Sync_MainLoop(void) {

    if (isWaterLeveEnable == WATER_LEVE_ENABLE) {

        COM_MCU_SetHigh();

//        MonitorWaterLevel_A();
//        if (WaterLevelSensorA.waterLeveState == LOW_WATER_LEVEL) {
//            if (WaterLevelSensorA.isInject != INJECT_WATER) {
//                WaterLevelSensorA.LowWaterLeveProtectTimer = 90;
//                WaterLevelSensorA.isInject = INJECT_WATER;
//            }
//            if (WaterLevelSensorA.LowWaterLeveProtectTimer == 0) {
//                WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag = 1;
//            }
//            WaterLevelSensorA.MiddleWaterLeveProtectTimer = 3;
//            WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 0;
//
//        } else if (WaterLevelSensorA.waterLeveState == MID_WATER_LEVEL) {
//            if (WaterLevelSensorA.MiddleWaterLeveProtectTimer == 0) {
//                WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
//                WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 1;
//            }
//            
//        } else if (WaterLevelSensorA.waterLeveState == HIGH_WATER_LEVEL) {
//            WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
//            WaterLevelSensorA.LowWaterLeveProtectTimer = 0;
//            WaterLevelSensorA.MiddleWaterLeveProtectTimer = 0;
//        }
//
//        if (WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag == 1) {
//            WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
//        }


        MonitorWaterLevel_B();

        if (WaterLevelSensorB.waterLeveState == LOW_WATER_LEVEL) {
            if (WaterLevelSensorB.isInject != INJECT_WATER) {
                WaterLevelSensorB.LowWaterLeveProtectTimer = 300;
                WaterLevelSensorB.isInject = INJECT_WATER;
            }
            if (WaterLevelSensorB.LowWaterLeveProtectTimer == 0) {
                WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag = 1;
            }
            WaterLevelSensorB.MiddleWaterLeveProtectTimer = 3;
            WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 0;

        } else if (WaterLevelSensorB.waterLeveState == MID_WATER_LEVEL) {
            if (WaterLevelSensorB.MiddleWaterLeveProtectTimer == 0) {
                WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
                WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 1;
            }
            
        } else if (WaterLevelSensorB.waterLeveState == HIGH_WATER_LEVEL) {
            WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
            WaterLevelSensorB.LowWaterLeveProtectTimer = 0;
            WaterLevelSensorB.MiddleWaterLeveProtectTimer = 0;
        }

        if (WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag == 1) {
            WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
        }
    } else {

        COM_MCU_SetLow();
        WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
        WaterLevelSensorA.countWaterLevel1 = WaterLevelSensorA.setCountWaterLevel;
        WaterLevelSensorA.countWaterLevel2 = WaterLevelSensorA.setCountWaterLevel;
        WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag = 0;
        WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 0;

        WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
        WaterLevelSensorB.countWaterLevel1 = WaterLevelSensorB.setCountWaterLevel;
        WaterLevelSensorB.countWaterLevel2 = WaterLevelSensorB.setCountWaterLevel;
        WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag = 0;
        WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 0;
    }

}

void WaterLeveManager_MainLoop(void) {

    if (isWaterLeveEnable == WATER_LEVE_ENABLE) {

        COM_MCU_SetHigh();

        MonitorWaterLevel_A();
        if (WaterLevelSensorA.waterLeveState == LOW_WATER_LEVEL) {
            if (WaterLevelSensorA.isInject != INJECT_WATER) {
                WaterLevelSensorA.LowWaterLeveProtectTimer = 90;
                WaterLevelSensorA.isInject = INJECT_WATER;
            }
            if (WaterLevelSensorA.LowWaterLeveProtectTimer == 0) {
                WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag = 1;
            }
            WaterLevelSensorA.MiddleWaterLeveProtectTimer = 3;
            WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 0;

        } else if (WaterLevelSensorA.waterLeveState == MID_WATER_LEVEL) {
            if (WaterLevelSensorA.MiddleWaterLeveProtectTimer == 0) {
                WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
                WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 1;
            }
        } else if (WaterLevelSensorA.waterLeveState == HIGH_WATER_LEVEL) {
            WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
            WaterLevelSensorA.LowWaterLeveProtectTimer = 0;
            WaterLevelSensorA.MiddleWaterLeveProtectTimer = 0;
        }

        if (WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag == 1) {
            WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
        }


        MonitorWaterLevel_B();

        if (WaterLevelSensorB.waterLeveState == LOW_WATER_LEVEL) {
            if (WaterLevelSensorB.isInject != INJECT_WATER) {
                WaterLevelSensorB.LowWaterLeveProtectTimer = 300;
                WaterLevelSensorB.isInject = INJECT_WATER;
            }
            if (WaterLevelSensorB.LowWaterLeveProtectTimer == 0) {
                WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag = 1;
            }
            WaterLevelSensorB.MiddleWaterLeveProtectTimer = 30;
            WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 0;

        } else if (WaterLevelSensorB.waterLeveState == MID_WATER_LEVEL) {
            if (WaterLevelSensorB.MiddleWaterLeveProtectTimer == 0) {
                WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
                WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 1;
            }

        } else if (WaterLevelSensorB.waterLeveState == HIGH_WATER_LEVEL) {
            WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
            WaterLevelSensorB.LowWaterLeveProtectTimer = 0;
            WaterLevelSensorB.MiddleWaterLeveProtectTimer = 0;
        }

        if (WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag == 1) {
            WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
        }
    } else {

        COM_MCU_SetLow();
        WaterLevelSensorA.isInject = DO_NOT_INJECT_WATER;
        WaterLevelSensorA.countWaterLevel1 = WaterLevelSensorA.setCountWaterLevel;
        WaterLevelSensorA.countWaterLevel2 = WaterLevelSensorA.setCountWaterLevel;
        WaterLevelSensorA.LowWaterLeveProtectTimerOUT_Flag = 0;
        WaterLevelSensorA.MiddleWaterLeveProtectTimerOUT_Flag = 0;
        
        WaterLevelSensorB.isInject = DO_NOT_INJECT_WATER;
        WaterLevelSensorB.countWaterLevel1 = WaterLevelSensorB.setCountWaterLevel;
        WaterLevelSensorB.countWaterLevel2 = WaterLevelSensorB.setCountWaterLevel;
        WaterLevelSensorB.LowWaterLeveProtectTimerOUT_Flag = 0;
        WaterLevelSensorB.MiddleWaterLeveProtectTimerOUT_Flag = 0;
    }

}

void WaterLeveManager_Enable(void) {
    isWaterLeveEnable = WATER_LEVE_ENABLE;
}

void WaterLeveManager_Disenable(void) {
    isWaterLeveEnable = WATER_LEVE_DISENABLE;
}

unsigned char WaterLeveManager_IsInject_A(void) {
        return WaterLevelSensorA.isInject;
}

unsigned char WaterLeveManager_GetLeveState_A(void) {
        return WaterLevelSensorA.waterLeveState;
}

unsigned char WaterLeveManager_IsInject_B(void) {
        return WaterLevelSensorB.isInject;
}

unsigned char WaterLeveManager_GetLeveState_B(void) {
        return WaterLevelSensorB.waterLeveState;
}

//
//void WaterLeveManager_DefaultTimerHandler(void);
//
//unsigned char WATER_LEVE_ScanA1(void);
//unsigned char WATER_LEVE_ScanA2(void);
//unsigned char WATER_LEVE_ScanB1(void);
//unsigned char WATER_LEVE_ScanB2(void);
//
//#define ON_WATER 1
//#define HAVE_WATER 0
//
//#define CHECK_COUNT 1000
//
//static volatile unsigned char isWaterLeveEnable;
//
//void (*WaterLeveManager_TimerHandler)(void);
//
//typedef struct {
//    const enum waterLeve_sensor_names sensor_name;
//    const scanFunction scan1;
//    const scanFunction scan2;
//    unsigned char isWaterLeve1;
//    unsigned char isWaterLeve2;
//    unsigned int setCountWaterLeve;
//    unsigned int countWaterLeve1;
//    unsigned int countWaterLeve2;
//    unsigned char waterLeveState;
//    unsigned char isInject;
//} waterLeve_sensor_t;
//
//static waterLeve_sensor_t waterLeve_sensor[WATER_LEVE_SENSORS] = {
//    {Sensor_A, WATER_LEVE_ScanA1, WATER_LEVE_ScanA2, HAVE_WATER, HAVE_WATER, CHECK_COUNT, 0, 0, HIGH_WATER_LEVEL},
//    {Sensor_B, WATER_LEVE_ScanB1, WATER_LEVE_ScanB2, HAVE_WATER, HAVE_WATER, CHECK_COUNT * 2, 0, 0, HIGH_WATER_LEVEL}
//};
//
//typedef struct {
//    unsigned char manager_name;
//    waterLeve_sensor_t waterLeveSensor;
//    unsigned char isInject;
//    unsigned int LowWaterLeveProtectTimer;
//    unsigned int MiddleWaterLeveProtectTimer;
//} waterLeveManager_t;
//
//static waterLeveManager_t WaterLeveManager[WATER_LEVE_SENSORS];
//
//unsigned char WATER_LEVE_ScanA1(void) {
//    return WaterLeveA1_pin;
//}
//
//unsigned char WATER_LEVE_ScanA2(void) {
//    return WaterLeveA2_pin;
//}
//
//unsigned char WATER_LEVE_ScanB1(void) {
//    return WaterLeveB1_pin;
//}
//
//unsigned char WATER_LEVE_ScanB2(void) {
//    return WaterLeveB2_pin;
//}
//
//static void GetWaterLeve(waterLeve_sensor_t* sensor) {
//    if (sensor->scan1() == ON_WATER) {
//        if (sensor->countWaterLeve1 != 0) {
//            sensor->countWaterLeve1--;
//        } else {
//            sensor->isWaterLeve1 = ON_WATER;
//        }
//    } else {
//        sensor->countWaterLeve1 = sensor->setCountWaterLeve;
//        sensor->isWaterLeve1 = HAVE_WATER;
//    }
//
//    if (sensor->scan2() == ON_WATER) {
//        if (sensor->countWaterLeve2 != 0) {
//            sensor->countWaterLeve2--;
//        } else {
//            sensor->isWaterLeve2 = ON_WATER;
//        }
//    } else {
//        sensor->countWaterLeve2 = sensor->setCountWaterLeve;
//        sensor->isWaterLeve2 = HAVE_WATER;
//    }
//
//    if ((sensor->isWaterLeve1 == ON_WATER) && (sensor->isWaterLeve2 == ON_WATER)) {
//        sensor->waterLeveState = LOW_WATER_LEVEL;
//    } else if (((sensor->isWaterLeve1 == ON_WATER) && (sensor->isWaterLeve2 == HAVE_WATER)) ||
//            ((sensor->isWaterLeve1 == HAVE_WATER) && (sensor->isWaterLeve2 == ON_WATER))) {
//        sensor->waterLeveState = MID_WATER_LEVEL;
//    } else if ((sensor->isWaterLeve1 == HAVE_WATER) && (sensor->isWaterLeve2 == HAVE_WATER)) {
//        sensor->waterLeveState = HIGH_WATER_LEVEL;
//    }
//}
//
//static void WaterLeveManager_Initialize(enum waterLeve_manager_names name) {
//    waterLeveManager_t* manager = &WaterLeveManager[name];
//
//    manager->manager_name = name;
//    manager->waterLeveSensor = waterLeve_sensor[name];
//    manager->isInject = DO_NOT_INJECT_WATER;
//    manager->LowWaterLeveProtectTimer = 0;
//    manager->MiddleWaterLeveProtectTimer = 0;
//}
//
//static void WaterLeveManager_WaterProtectTimer(enum waterLeve_manager_names name) {
//    waterLeveManager_t* manager = &WaterLeveManager[name];
//    
//    if (manager->LowWaterLeveProtectTimer !=0 ) {
//        manager->LowWaterLeveProtectTimer--;
//    }
//    if (manager->MiddleWaterLeveProtectTimer !=0 ) {
//        manager->MiddleWaterLeveProtectTimer--;
//    }
//}
//
//static void WaterLeveManager_Update_State(enum waterLeve_manager_names name) {
//
//    waterLeveManager_t* manager = &WaterLeveManager[name];
//
//    GetWaterLeve(&manager->waterLeveSensor);
//
//    if (manager->waterLeveSensor.waterLeveState == LOW_WATER_LEVEL) {
//        if (manager->isInject != INJECT_WATER) {
//            manager->LowWaterLeveProtectTimer = 300;
//            manager->isInject = INJECT_WATER;
//        }
//        manager->MiddleWaterLeveProtectTimer = 30;
//
//    } else if (manager->waterLeveSensor.waterLeveState == MID_WATER_LEVEL) {
//        if (manager->MiddleWaterLeveProtectTimer == 0) {
//            manager->isInject = DO_NOT_INJECT_WATER;
//        }
//
//    } else if (manager->waterLeveSensor.waterLeveState == HIGH_WATER_LEVEL) {
//        manager->isInject = DO_NOT_INJECT_WATER;
//        manager->LowWaterLeveProtectTimer = 0;
//        manager->MiddleWaterLeveProtectTimer = 0;
//    }
//
//    if (manager->LowWaterLeveProtectTimer == 0) {
//        manager->isInject = DO_NOT_INJECT_WATER;
//    }
//
//}
//
//void WaterLeveManager_InitializeAll(void) {
//    
//    enum waterLeve_manager_names manager_names;
//    
//    WaterLeveManager_SetTimerHandler(WaterLeveManager_DefaultTimerHandler);
//
//    WaterLeveManager_Enable();
//
//    for (manager_names = 0; manager_names < WATER_LEVE_SENSORS; manager_names++) {
//        WaterLeveManager_Initialize(manager_names);
//    }
//}
//
//void WaterLeveManager_MainLoop(void) {
//
//    enum waterLeve_manager_names manager_names;
//
//    if (isWaterLeveEnable == WATER_LEVE_ENABLE) {
//        COM_MCU_SetHigh();
//        for (manager_names = 0; manager_names < WATER_LEVE_SENSORS; manager_names++) {
//            WaterLeveManager_Update_State(manager_names);
//        }
//    } else {
//        COM_MCU_SetLow();
//        for (manager_names = 0; manager_names < WATER_LEVE_SENSORS; manager_names++) {
//            WaterLeveManager[manager_names].isInject = DO_NOT_INJECT_WATER;
//            WaterLeveManager[manager_names].waterLeveSensor.countWaterLeve1 = WaterLeveManager[manager_names].waterLeveSensor.setCountWaterLeve;
//            WaterLeveManager[manager_names].waterLeveSensor.countWaterLeve2 = WaterLeveManager[manager_names].waterLeveSensor.setCountWaterLeve;
//        }
//    }
//}
//
//unsigned char WaterLeveManager_IsInject(enum waterLeve_manager_names name) {
//    if (name < WATER_LEVE_SENSORS)
//        return WaterLeveManager[name].isInject;
//    else
//        return 0;
//}
//
//unsigned char WaterLeveManager_GetLeveState(enum waterLeve_manager_names name) {
//    if (name < WATER_LEVE_SENSORS)
//        return WaterLeveManager[name].waterLeveSensor.waterLeveState;
//    else
//        return 0;
//}
//
//void WaterLeveManager_Enable(void) {
//    isWaterLeveEnable = WATER_LEVE_ENABLE;
//}
//
//void WaterLeveManager_Disenable(void) {
//    isWaterLeveEnable = WATER_LEVE_DISENABLE;
//}
//
//void WaterLeveManager_RunTimer(void) {
//
//    if (WaterLeveManager_TimerHandler) {
//        WaterLeveManager_TimerHandler();
//    }
//}
//
//void WaterLeveManager_SetTimerHandler(void (* Handler)(void)) {
//    WaterLeveManager_TimerHandler = Handler;
//}
//
//void WaterLeveManager_DefaultTimerHandler(void) {
//
//    enum waterLeve_manager_names manager_names;
//    for (manager_names = 0; manager_names < WATER_LEVE_SENSORS; manager_names++) {
//        WaterLeveManager_WaterProtectTimer(manager_names);
//    }
//}