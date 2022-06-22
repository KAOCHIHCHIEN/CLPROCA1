#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "LEDManager.h"

static unsigned char SYS_COMMON_LED;

static void Led_1_Control(unsigned char states) {
    if (states == OFF_MODE) {
        LED1_LAT = 0;
    } else if (states == ON_MODE) {
        LED1_LAT = 1;
    } else if (states == FLASH_MODE) {
        LED1_LAT = ~LED1_LAT;
    }
}

static void Led_2_Control(unsigned char states) {
    if (states == OFF_MODE) {
        LED2_LAT = 0;
    } else if (states == ON_MODE) {
        LED2_LAT = 1;
    } else if (states == FLASH_MODE) {
        LED2_LAT = ~LED2_LAT;
    }
}

static void Led_3_Control(unsigned char states) {
    if (states == OFF_MODE) {
        LED3_LAT = 0;
    } else if (states == ON_MODE) {
        LED3_LAT = 1;
    } else if (states == FLASH_MODE) {
        LED3_LAT = ~LED3_LAT;
    }
}

static void Led_4_Control(unsigned char states) {
    if (states == OFF_MODE) {
        LED4_LAT = 0;
    } else if (states == ON_MODE) {
        LED4_LAT = 1;
    } else if (states == FLASH_MODE) {
        LED4_LAT = ~LED4_LAT;
    }
}

static void Led_12V_Control(unsigned char states) {
    if (states == OFF_MODE) {
        LED12V_LAT = 0;
    } else if (states == ON_MODE) {
        LED12V_LAT = 1;
    } else if (states == FLASH_MODE) {
        LED12V_LAT = ~LED12V_LAT;
    }
}

static void Led_Common_Control(unsigned char states) {
    if (states == OFF_MODE) {
        SYS_COMMON_LED = 0;
    } else if (states == ON_MODE) {
        SYS_COMMON_LED = 1;
    } else if (states == FLASH_MODE) {
        SYS_COMMON_LED = ~SYS_COMMON_LED;
    }
}

typedef void(*mLed_Function)(unsigned char);

typedef struct {
    const enum mLED_names mLed_name;
    const mLed_Function mLed_func;
    unsigned char LedOnOffState;
    unsigned char LedFlashTimer;
    unsigned char SetLedFlashTimer;
} mLED_t;

static mLED_t LEDManager[LED_NAMES_COUNT] = {
    {mLed_1, Led_1_Control, OFF_MODE, 10, 10},
    {mLed_2, Led_2_Control, OFF_MODE, 10, 10},
    {mLed_3, Led_3_Control, OFF_MODE, 10, 10},
    {mLed_4, Led_4_Control, OFF_MODE, 10, 10},
    {mLed_12V, Led_12V_Control, OFF_MODE, 10, 10},
    {mLed_Common, Led_Common_Control, OFF_MODE, 3, 3},
};

void LEDManager_Initialize(void) {
    
}

static void LED_State_Update(enum mLED_names name) {
    mLED_t* LED = &LEDManager[name];

    if (LED->LedOnOffState == FLASH_MODE) {
        if (LED->LedFlashTimer != 0) {
            LED->LedFlashTimer--;
        } else {
            LED->mLed_func(LED->LedOnOffState);
            LED->LedFlashTimer = LED->SetLedFlashTimer;
        }
    } else {
        LED->mLed_func(LED->LedOnOffState);
    }
    
}

void LEDManager_MainLoop(void) {

    enum mLED_names led_name;

    for (led_name = 0; led_name < LED_NAMES_COUNT; led_name++) {
        LED_State_Update(led_name);
    }
}

void LEDManager_SetLEDState(enum mLED_names name, unsigned char states) {
    mLED_t* LED = &LEDManager[name];
    LED->LedOnOffState = states;
}

unsigned char LEDManager_GetLEDCommon(void) {
    return SYS_COMMON_LED;
}