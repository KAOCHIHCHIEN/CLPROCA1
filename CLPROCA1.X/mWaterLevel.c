
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mcc.h"
#include "mWaterLevel.h"

uint16_t s_low_count, s_hi_count;
uint16_t sh_low_count, sh_hi_count;

void ck_water_INIT(void) {
    sh_hi_count = CK_WATER_LEVEL_COUNT;
    sh_low_count = CK_WATER_LEVEL_COUNT;
    
    s_hi_count = CK_S_WATER_LEVEL_COUNT;
    s_low_count = CK_S_WATER_LEVEL_COUNT;
       
}

uint8_t ck_water1_level(void) {

    uint8_t water_level_mode;
    uint8_t s_hi_flag, s_low_flag;

    COM_MCU_SetHigh();
    
    if (WH1_MCU_PORT) {
        if(s_hi_count <= CK_S_WATER_LEVEL_COUNT) {
            s_hi_count++;
        }
    } else {
        if (s_hi_count != 0) {
            s_hi_count--;
        }
        
    }
    if (WM1_MCU_PORT) {
        if (s_low_count <= CK_S_WATER_LEVEL_COUNT) {
            s_low_count++;
        }
    } else {
        if (s_low_count != 0) {
            s_low_count--;
        }
    }

    if (s_hi_count > CK_S_WATER_LEVEL_COUNT/2) {
        s_hi_flag = 1;
    } else {
        s_hi_flag = 0;
    }
    if (s_low_count > CK_S_WATER_LEVEL_COUNT/2) {
        s_low_flag = 1;
    } else {
        s_low_flag = 0;
    }
    
    if ((s_hi_flag == 1) && (s_low_flag == 1)) {
            water_level_mode = LOW_WATER_LEVEL;
    } else if (((s_hi_flag == 1) && (s_low_flag == 0)) ||
            ((s_hi_flag == 0) && (s_low_flag == 1))) {
        water_level_mode = MID_WATER_LEVEL;
    } else if ((s_hi_flag == 0) && (s_low_flag == 0)) {
        water_level_mode = HIGH_WATER_LEVEL;
    }
    return water_level_mode;
}

uint8_t ck_water2_level(void) {

    uint8_t water_SD_level_mode;
    
    uint8_t sh_hi_flag, sh_low_flag;

    COM_MCU_SetHigh();

    if (WH2_MCU_PORT) {
        if(sh_hi_count < CK_WATER_LEVEL_COUNT) {
            sh_hi_count++;
        }
    } else {
        if (sh_hi_count != 0) {
            sh_hi_count--;
        }
        
    }
    if (WM2_MCU_PORT) {
        if (sh_low_count < CK_WATER_LEVEL_COUNT) {
            sh_low_count++;
        }
    } else {
        if (sh_low_count != 0) {
            sh_low_count--;
        }
    }

    if (sh_hi_count > (CK_WATER_LEVEL_COUNT - 100)) {
        sh_hi_flag = 1;
    } else {
        sh_hi_flag = 0;
    }
    if (sh_low_count > (CK_WATER_LEVEL_COUNT- 100)) {
        sh_low_flag = 1;
    } else {
        sh_low_flag = 0;
    }

    if ((sh_hi_flag == 1) && (sh_low_flag == 1)) {
            water_SD_level_mode = LOW_WATER_LEVEL;
    } else if (((sh_hi_flag == 1) && (sh_low_flag == 0)) ||
            ((sh_hi_flag == 0) && (sh_low_flag == 1))) {
        water_SD_level_mode = MID_WATER_LEVEL;
    } else if ((sh_hi_flag == 0) && (sh_low_flag == 0)) {
        water_SD_level_mode = HIGH_WATER_LEVEL;
    }

    return water_SD_level_mode;
}