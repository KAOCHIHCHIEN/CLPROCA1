
#include "ACSenserManager.h"

#define CK_AC_TIME 2
#define CK_AC_COUNT 10

void ACSenserManager_DefaultTimerHandler(void);

typedef unsigned char(*scanFunction)(void);

void (*ACSenserManager_TimerHandler)(void);

typedef struct {
    const enum ac_sensor_names sensor_name;
    const scanFunction scan;
    unsigned char count;
    unsigned char time;
    unsigned char flag;
} ac_sensor_t;

static ac_sensor_t ac_sensor[AC_SENSORS] = {
    {AC_HEATING, ac_get_heating, 0, 0, 0},
    {AC_SODA, ac_get_soda, 0, 0, 0},
    {AC_COOL, ac_get_cool, 0, 0, 0},
    {AC_CHILLING, ac_get_chilling, 0, 0, 0},
    {AC_HOT, ac_get_hot, 0, 0, 0}
};

unsigned char ac_get_heating(void) {
    return AC1_MCU_PORT;
}

unsigned char ac_get_soda(void) {
    return AC2_MCU_PORT;
}

unsigned char ac_get_cool(void) {
    return AC3_MCU_PORT;
}

unsigned char ac_get_chilling(void) {
    return AC4_MCU_PORT;
}

unsigned char ac_get_hot(void) {
    return AC5_MCU_PORT;
}

static void ACSenserManager_Timer(enum ac_sensor_names name) {
    ac_sensor_t* manager = &ac_sensor[name];
    
    if (manager->time !=0 ) {
        manager->time--;
    }
}

static void AC_Update_State(enum ac_sensor_names name) {
    ac_sensor_t* sensor = &ac_sensor[name];

    if (!sensor->scan()) {
        if (sensor->count != 0) {
            sensor->count--;
        } else {
            sensor->flag = 1;
        }
        sensor->time = CK_AC_TIME;
    } else {
        if (sensor->time == 0) {
            sensor->flag = 0;
            sensor->count = CK_AC_COUNT;
        }
    }
}

static void ACSenser_Initialize(enum ac_sensor_names name) {
    ac_sensor_t* manager = &ac_sensor[name];
    
    manager->count = 0;
    manager->flag = 0;
    manager->time = 0; 
}

void ACSenserManager_InitializeAll(void) {
    
    enum ac_sensor_names manager_names;

    ACSenserManager_SetTimerHandler(ACSenserManager_DefaultTimerHandler);

    for (manager_names = 0; manager_names < AC_SENSORS; manager_names++) {
        ACSenser_Initialize(manager_names);
    }
}

void ACSenserManager_MainLoop(void) {

    enum ac_sensor_names manager_names;

    for (manager_names = 0; manager_names < AC_SENSORS; manager_names++) {
        AC_Update_State(manager_names);
    }
}

unsigned char ACSenserManager_GetPortState(enum ac_sensor_names name) {
    if (name < AC_SENSORS)
        return ac_sensor[name].flag;
    else
        return 0;
}

void ACSenserManager_RunTimer(void) {

    if (ACSenserManager_TimerHandler) {
        ACSenserManager_TimerHandler();
    }
}

void ACSenserManager_SetTimerHandler(void (* Handler)(void)) {
    ACSenserManager_TimerHandler = Handler;
}

void ACSenserManager_DefaultTimerHandler(void) {

    enum ac_sensor_names manager_names;
    for (manager_names = 0; manager_names < AC_SENSORS; manager_names++) {
        ACSenserManager_Timer(manager_names);
    }
}