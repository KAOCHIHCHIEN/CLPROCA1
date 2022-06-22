#include "mcc_generated_files/pin_manager.h"
#include "UVManager.h"

#define UV_CK_TIMER 2

static uint8_t UV_Run_flag;

static uint8_t uv_error_count;
static uint8_t uv_ck_flag;

static uint8_t hasHot_flag;

static uint8_t uv_error;

static uint8_t UV_CK_time;

void mUV_Initialize(uint8_t hasHot) {
    UVS_MCU_LAT = 0;
    uv_error = 0;
    uv_error_count = 0;
    uv_ck_flag = 0;
    UV_CK_time = UV_CK_TIMER;
    hasHot_flag = hasHot;
}


void mUV_Timer(void) {
    if (UV_CK_time != 0) {
        UV_CK_time--;
    }
}

void mUV_Loop(void) {

    if (hasHot_flag) {
        if (ColdWaterOut_LAT | WarmWaterOut_LAT) {

            UVS_MCU_LAT = 1;

            if (UV_CK_time == 0) {
                if (UV_CK_MCU_PORT) {
                    if (!uv_ck_flag) {
                        uv_ck_flag = 1;
                        uv_error_count++;
                        if (uv_error_count > 5) {
                            if (!uv_error) {
                                uv_error = 1;
                            }
                        }
                    }
                } else {
                    uv_error_count = 0;
                    uv_error = 0;
                }
            }
        } else {
            uv_ck_flag = 0;
            UVS_MCU_LAT = 0;
            UV_CK_time = UV_CK_TIMER;
        }
    } else {

        if (ColdWaterOut_LAT | WarmWaterOut_LAT | HotWaterOut_LAT) {

            UVS_MCU_LAT = 1;

            if (UV_CK_time == 0) {
                if (UV_CK_MCU_PORT) {
                    if (!uv_ck_flag) {
                        uv_ck_flag = 1;
                        uv_error_count++;
                        if (uv_error_count > 5) {
                            if (!uv_error) {
                                uv_error = 1;
                            }
                        }
                    }
                } else {
                    uv_error_count = 0;
                    uv_error = 0;
                }
            }
        } else {
            uv_ck_flag = 0;
            UVS_MCU_LAT = 0;
            UV_CK_time = UV_CK_TIMER;
        }
    }

    if (uv_error) {
        if (!UV_CK_MCU_PORT) {
            uv_error_count = 0;
            uv_error = 0;
        }
    }
}

uint8_t mUV_CK_Error(void){
    return uv_error;
}