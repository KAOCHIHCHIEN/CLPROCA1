/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F15386
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

// ver : 1.3

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr2.h"
#include "delay.h"
#include "WaterLeveManager.h"
#include "mKey.h"
#include "ACSenserManager.h"
#include "BZManager.h"
#include "LEDManager.h"
#include "UVManager.h"

void Fan_control(void);
void SET_ck(void);
void mTest_Mode(void);

#define MHZ 1

#define SET_LED_FLASH_TIME_500MS 5

#define SET_LED_FLASH_TIME_200MS 2

#define SET_LED_FLASH_TIME_100MS 1

#define FAN_OUT_DELAY_TIME 300 * MHZ
unsigned int fan_out_delay;

uint8_t SET1_flag;
uint8_t SET2_flag;
uint8_t SET3_flag;
uint8_t SET4_flag;
uint8_t SET5_flag;
uint8_t SET6_flag;
uint8_t SET7_flag;
uint8_t SET8_flag;
uint8_t SET9_flag;

#define KEY4_SET SET9_flag 
#define SYNC_SET SET8_flag 
#define TDON_SET SET7_flag
#define CONTINUOUS_WATER_SET SET6_flag
//#define HOT_DELAY_SET SET6_flag
#define UV_SET SET5_flag 
#define PUH_SET SET4_flag
#define MLK_SET SET3_flag
#define HOT_SET SET2_flag
#define HAETING_LED SET1_flag

#define RUN_Mode 0
#define TEST_Mode 1
uint8_t show_mode = RUN_Mode;

static uint8_t WaterIsInject;
static uint8_t WaterSDIsInject;

//#define UV_CK_TIMER 2 * MHZ
//uint8_t UV_CK_time;
//uint8_t UV_CK_flag;
uint8_t UV_CK_err_flag;
//uint8_t UV_on_flag;
//uint8_t UV_bz_f_err_flag;
//uint8_t uv_error_count;
uint8_t err_bz_flag;

#define Second_300 300 * MHZ
#define Second_180 180 * MHZ
#define Second_30 30 * MHZ
#define Second_20 20 * MHZ


#define WATER_OUT_PROTECTION_TIMER 60 * MHZ
uint16_t Water_out_protection_time;

uint8_t All_Butter_Pull_time;
uint8_t k2_Butter_Pull_time;

uint16_t MODE_TEST_TIME;

uint8_t Full_flag;

uint16_t m_hot_lock_time;

#define BUTTON_SLEEP_TIMER 10 * MHZ
uint8_t m_key_sleep_time;
uint8_t CK_SODA_Timer;

static uint8_t ck_AC_HEATING_flag;
static uint8_t ck_AC_COOL_flag;
static uint8_t ck_AC_chilling_flag;
static uint8_t ck_AC_Hot_flag;
static uint8_t ck_AC_SODA_flag;

uint16_t FAN_adc_v;
uint16_t FANdutyValue;
uint8_t LED_SC_Count;
uint8_t timer_1s_t;

#define FULL_CK_TIMER 5 * MHZ
uint8_t Full_ck_time;

#define LSS_CK_TIMER 5 * MHZ
uint8_t LSS_ck_time;

#define SODA_WATER_CLEAN_TIMER 2 * MHZ
uint8_t soda_water_clean_time;

uint8_t hot_water_on_off_flag;
uint8_t warm_water_on_off_flag;
uint8_t cold_water_on_off_flag;

#define SYNC_CLOD_DELAY_OFF_TIMER 4000
uint16_t sync_cold_water_delay_off_time;

#define HOT_KEY_DELAY_TIMER 3 * MHZ
uint8_t HOT_BUTTON_delay;

uint16_t PW_ADC_val, PW_ADC_val_tmp;

uint8_t timer_100ms_t;

uint8_t waterLevelDetectDelayTimer;
uint8_t waterLevelDetect_flag;
uint8_t waterLevelBootDetect_flag;

uint8_t soda_water_clean_flag;

uint8_t SyncWaterOutDelayTimer;

void Timer_100ms_irq(void) {
    timer_100ms_t = ~timer_100ms_t;
    LEDManager_MainLoop();
    BZ_MainLoop();
}

void Fan_control(void) {

    int16_t X, Y;

    PW_ADC_val = ADC_GetConversion(FAN_ADC);

    if (PW_ADC_val_tmp > PW_ADC_val) {
        PW_ADC_val_tmp--;
    } else if (PW_ADC_val_tmp < PW_ADC_val) {
        PW_ADC_val_tmp++;
    }

    X = (int16_t) PW_ADC_val_tmp;

    Y = -10 * X + 2270;
    if (Y > 500) {
        FANdutyValue = 500;
    } else if (Y < 35) {
        FANdutyValue = 35;
    } else {
        FANdutyValue = (uint16_t) Y;
    }

    PWM5_LoadDutyValue(FANdutyValue);
}

void TMR0_1s_irq(void) {

    WaterLeveManager_WaterProtectTimer();

    ACSenserManager_RunTimer();

    if (m_hot_lock_time != 0) {
        m_hot_lock_time--;
    }

    if (m_key_sleep_time != 0) {
        m_key_sleep_time--;
    }

    if (soda_water_clean_time != 0) {
        soda_water_clean_time--;
    }

    if (fan_out_delay != 0) {
        fan_out_delay--;
    }

    mUV_Timer();

    if (Full_ck_time != 0) {
        Full_ck_time--;
    }
    if (LSS_ck_time != 0) {
        LSS_ck_time--;
    }
    if (HOT_BUTTON_delay != 0) {
        HOT_BUTTON_delay--;
    }
    if (Water_out_protection_time != 0) {
        Water_out_protection_time--;
    }
    if (MODE_TEST_TIME != 0) {
        MODE_TEST_TIME--;
    }
    if (waterLevelDetectDelayTimer != 0) {
        waterLevelDetectDelayTimer--;
    }

    if (SyncWaterOutDelayTimer != 0) {
        SyncWaterOutDelayTimer--;
    }
    
    if (CK_SODA_Timer != 0) {
        CK_SODA_Timer--;
    }
    

    //    if (sync_cold_water_delay_off_time != 0) {
    //        sync_cold_water_delay_off_time--;
    //    }

}

/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    TMR1_SetInterruptHandler(TMR0_1s_irq); // 1s

    TMR0_SetInterruptHandler(Timer_100ms_irq); // 50 ms

    PWM5_LoadDutyValue(35);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    CLRWDT();

    BZ_InitializeAll();

    LEDManager_Initialize();

    delay_1ms(500);

    TS_5V_SetLow();

    LED_12V_ON();

    SET_ck();
    /*
    while (1) {
        CLRWDT();
        
        SET_ck();
        
        AllOnOff_SetHigh();
        
        HotWaterOut_LAT = SET1_flag;
        ColdWaterOut_LAT = SET2_flag;
        WarmWaterOut_LAT = SET3_flag;
        SyncWaterOut_LAT = SET4_flag;
        MDWaterOut_LAT = SET5_flag;
        LED1_LAT = SET6_flag;
        LED2_LAT = SET7_flag;
        LED3_LAT = SET8_flag;
        LED4_LAT = SET9_flag;
        
    }
     */
    //    i2c_button.byte = I2C1_Read1ByteRegister(EEPROM_DEVICE_ADDRESS, TOUCH_BUTTON_ADDR);

    while (!(HotLock_Touch_GetValue() & Hot_Touch_GetValue() & Warm_Touch_GetValue() & Cold_Touch_GetValue())) {

    }

    HOTLOCK_BUTTON_LED_ON();
    //    BZ_RunSet(1, 2);
    CK_Buttons_key4();
    BZ_user_pushKey(100);
    delay_1ms(500);

    HOTLOCK_BUTTON_LED_OFF();

    TC_LED_G();
    LED_12V_OFF();
    //    LED12V_LAT = 0;
    HOT_BUTTON_LED_ON();
    //    BZ_RunSet(1, 2);
    CK_Buttons_key4();
    BZ_user_pushKey(100);
    delay_1ms(500);
    HOT_BUTTON_LED_OFF();

    TC_LED_B();
    LED_12V_ON();
    //    LED12V_LAT = 1;
    WARM_BUTTON_LED_ON();
    CK_Buttons_key4();
    delay_1ms(500);
    WARM_BUTTON_LED_OFF();

    TC_LED_G();
    LED_12V_OFF();
    //    LED12V_LAT = 0;
    COLD_BUTTON_LED_ON();
    CK_Buttons_key4();
    delay_1ms(500);
    COLD_BUTTON_LED_OFF();

    LED_1_OFF();
    LED_2_OFF();
    LED_3_OFF();
    LED_4_OFF();

    Water_out_protection_time = 0;

    ck_AC_HEATING_flag = 0;
    ck_AC_COOL_flag = 0;
    ck_AC_chilling_flag = 0;
    ck_AC_Hot_flag = 0;
    ck_AC_SODA_flag = 0;

    RE_HOT_BUTTON();
    RE_WARM_BUTTON();
    RE_COLD_BUTTON();
    //    All_Butter_flag = 0;

    Full_ck_time = FULL_CK_TIMER;
    Full_flag = 0;

    ACSenserManager_InitializeAll();

    FANdutyValue = 24;
    fan_out_delay = 0;

    LED_SC_Count = 0;

    LSS_ck_time = LSS_CK_TIMER;

    mUV_Initialize(HOT_SET);
    //    UV_CK_time = 0;
    //    UV_CK_flag = 0;
    //    UV_CK_err_flag = 0;
    //    uv_error_count = 0;

    soda_water_clean_time = SODA_WATER_CLEAN_TIMER;

    WaterLeveManager_Initialize();

    m_key_sleep_time = BUTTON_SLEEP_TIMER;

    HOT_BUTTON_delay = 0;
    All_Butter_Pull_time = 0;
    MODE_TEST_TIME = 0;

    hot_water_on_off_flag = 0;
    warm_water_on_off_flag = 0;
    cold_water_on_off_flag = 0;
    err_bz_flag = 0;
    m_hot_lock_time = 0;
    timer_100ms_t = 0;

    PW_ADC_val_tmp = ADC_GetConversion(FAN_ADC);

    show_mode = RUN_Mode;

    waterLevelDetectDelayTimer = 0;
    waterLevelDetect_flag = 0;
    waterLevelBootDetect_flag = 0;

    soda_water_clean_flag = 0;
    
    CK_SODA_Timer = 0;

    while (1) {
        // Add your application code
        //        SET_ck();

        CK_Buttons_key4();

        /* BUTTON CK */
        CLRWDT();

        if (KEY4_SET) {
            // 4 key
            if (PUH_SET) {
                if (HOT_SET) {

                    if (LOCK_BUTTON()) {
                        hot_water_on_off_flag = 0;
                        warm_water_on_off_flag = 0;
                        cold_water_on_off_flag = 0;
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        m_hot_lock_time = BUTTON_SLEEP_TIMER;
                        BZ_user_relockKey();
                        RE_LOCK_BUTTON();
                        RE_HOT_BUTTON();
                        RE_WARM_BUTTON();
                        RE_COLD_BUTTON();
                    }

                    if (m_hot_lock_time != 0) {

                        HOTLOCK_BUTTON_LED_OFF();

                        if (CONTINUOUS_WATER_SET) {
                            if (hot_water_on_off_flag) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                m_hot_lock_time = BUTTON_SLEEP_TIMER;
                                HOT_BUTTON_LED_ON();
                            } else {
                                HOT_BUTTON_LED_OFF();
                            }
                            if (HOT_BUTTON()) {
                                if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                } else {
                                    hot_water_on_off_flag = 1;
                                    HOT_BUTTON_LED_ON();
                                }
                                BZ_user_pushKey(100);
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                m_hot_lock_time = BUTTON_SLEEP_TIMER;
                                RE_HOT_BUTTON();
                            }
                        } else {
                            HOT_BUTTON_LED_OFF();
                            if (HOT_BUTTON()) {
                                if (!hot_water_on_off_flag) {
                                    hot_water_on_off_flag = 1;
                                    BZ_user_pushKey(100);
                                }
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                m_hot_lock_time = BUTTON_SLEEP_TIMER;
                            } else {
                                hot_water_on_off_flag = 0;
                            }
                        }

                    } else { // if (m_hot_lock_time != 0)
                        if (HOT_BUTTON()) {
                            hot_water_on_off_flag = 0;
                            warm_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                            HOTLOCK_BUTTON_LED_SET(timer_100ms_t);
                            BZ_RunSet(1, 1);
                        } else {
                            if (TDON_SET) {
                                HOTLOCK_BUTTON_LED_OFF();
                            } else {
                                HOTLOCK_BUTTON_LED_ON();
                            }
                            if (!CONTINUOUS_WATER_SET) {
                                HOT_BUTTON_LED_OFF();
                                WARM_BUTTON_LED_OFF();
                                COLD_BUTTON_LED_OFF();
                            }
                        }
                    }
                } else { // if (HOT_SET)
                    HOTLOCK_BUTTON_LED_OFF();

                    if (CONTINUOUS_WATER_SET) {
                        if (hot_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            HOT_BUTTON_LED_ON();
                        } else {
                            HOT_BUTTON_LED_OFF();
                        }
                        if (HOT_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                hot_water_on_off_flag = 1;
                                HOT_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_HOT_BUTTON();
                        }
                    } else {
                        HOT_BUTTON_LED_OFF();
                        if (HOT_BUTTON()) {
                            if (!hot_water_on_off_flag) {
                                hot_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        } else {
                            hot_water_on_off_flag = 0;
                        }
                    }
                } // if (HOT_SET) END

                if (CONTINUOUS_WATER_SET) {
                    if (warm_water_on_off_flag) {
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        WARM_BUTTON_LED_ON();
                    } else {
                        WARM_BUTTON_LED_OFF();
                    }
                    if (WARM_BUTTON()) {
                        if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                            hot_water_on_off_flag = 0;
                            warm_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                        } else {
                            warm_water_on_off_flag = 1;
                            WARM_BUTTON_LED_ON();
                        }
                        BZ_user_pushKey(100);
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        RE_WARM_BUTTON();
                    }

                    if (cold_water_on_off_flag) {
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        COLD_BUTTON_LED_ON();
                    } else {
                        COLD_BUTTON_LED_OFF();
                    }
                    if (COLD_BUTTON()) {
                        if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                            hot_water_on_off_flag = 0;
                            warm_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                        } else {
                            cold_water_on_off_flag = 1;
                            COLD_BUTTON_LED_ON();
                        }
                        BZ_user_pushKey(100);
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        RE_COLD_BUTTON();
                    }

                } else { // if (CONTINUOUS_WATER_SET)
                    WARM_BUTTON_LED_OFF();
                    COLD_BUTTON_LED_OFF();
                    if (WARM_BUTTON()) {
                        if (!warm_water_on_off_flag) {
                            warm_water_on_off_flag = 1;
                            BZ_user_pushKey(100);
                        }

                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                    }// cold
                    else if (COLD_BUTTON()) {
                        if (!cold_water_on_off_flag) {
                            cold_water_on_off_flag = 1;
                            BZ_user_pushKey(100);
                        }
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                    } else {
                        warm_water_on_off_flag = 0;
                        cold_water_on_off_flag = 0;
                    }
                } // if (CONTINUOUS_WATER_SET)


            } else { // if (PUH_SET)
                if (LOCK_BUTTON()) {
                    m_key_sleep_time = BUTTON_SLEEP_TIMER;
                    m_hot_lock_time = BUTTON_SLEEP_TIMER;
                    BZ_user_relockKey();
                    RE_LOCK_BUTTON();
                    RE_HOT_BUTTON();
                    RE_WARM_BUTTON();
                    RE_COLD_BUTTON();
                }

                if (m_key_sleep_time != 0) {

                    HOTLOCK_BUTTON_LED_OFF();

                    if (CONTINUOUS_WATER_SET) {

                        if (hot_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            HOT_BUTTON_LED_ON();
                        } else {
                            HOT_BUTTON_LED_OFF();
                        }
                        if (HOT_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                hot_water_on_off_flag = 1;
                                HOT_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_HOT_BUTTON();
                        }

                        if (warm_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            WARM_BUTTON_LED_ON();
                        } else {
                            WARM_BUTTON_LED_OFF();
                        }
                        if (WARM_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                warm_water_on_off_flag = 1;
                                WARM_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_WARM_BUTTON();
                        }

                        if (cold_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            COLD_BUTTON_LED_ON();
                        } else {
                            COLD_BUTTON_LED_OFF();
                        }
                        if (COLD_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                cold_water_on_off_flag = 1;
                                COLD_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_COLD_BUTTON();
                        }

                    } else { // if (CONTINUOUS_WATER_SET)

                        HOT_BUTTON_LED_OFF();
                        WARM_BUTTON_LED_OFF();
                        COLD_BUTTON_LED_OFF();

                        if (HOT_BUTTON()) {
                            if (!hot_water_on_off_flag) {
                                hot_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        }//warm 
                        else if (WARM_BUTTON()) {
                            if (!warm_water_on_off_flag) {
                                warm_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        }// cold 
                        else if (COLD_BUTTON()) {
                            if (!cold_water_on_off_flag) {
                                cold_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        } else {
                            hot_water_on_off_flag = 0;
                            warm_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                        }
                    }
                } else {
                    if (HOT_BUTTON() | WARM_BUTTON() | COLD_BUTTON()) {
                        HOTLOCK_BUTTON_LED_SET(timer_100ms_t);
                        BZ_RunSet(1, 1);
                    } else {
                        if (TDON_SET) {
                            HOTLOCK_BUTTON_LED_OFF();
                        } else {
                            HOTLOCK_BUTTON_LED_ON();
                        }
                        HOT_BUTTON_LED_OFF();
                        WARM_BUTTON_LED_OFF();
                        COLD_BUTTON_LED_OFF();
                    }
                }
            } // if (PUH_SET) END

        } else {
            // 3 key
            HOTLOCK_BUTTON_LED_OFF();

            if (PUH_SET) {

                if (CONTINUOUS_WATER_SET) {
                    if (HOT_SET) {
                        if (m_key_sleep_time != 0) {
                            TC_LED_G();

                            if (m_hot_lock_time != 0) {
                                if (hot_water_on_off_flag) {
                                    m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                    m_hot_lock_time = BUTTON_SLEEP_TIMER;
                                    COLD_BUTTON_LED_ON();
                                } else {
                                    COLD_BUTTON_LED_OFF();
                                }
                                if (COLD_BUTTON()) {
                                    if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                        hot_water_on_off_flag = 0;
                                        warm_water_on_off_flag = 0;
                                        cold_water_on_off_flag = 0;
                                    } else {
                                        hot_water_on_off_flag = 1;
                                        COLD_BUTTON_LED_ON();
                                    }
                                    BZ_user_pushKey(100);
                                    m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                    RE_COLD_BUTTON();
                                }

                            } else {
                                if (TDON_SET) {
                                    COLD_BUTTON_LED_OFF();
                                } else {
                                    COLD_BUTTON_LED_ON();
                                }

                                if (COLD_BUTTON()) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                    m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                    m_hot_lock_time = BUTTON_SLEEP_TIMER;
                                    COM_MCU_SetHigh();
                                    RE_HOT_BUTTON();
                                    RE_WARM_BUTTON();
                                    RE_COLD_BUTTON();
                                    BZ_user_relockKey();
                                }
                            }
                            if (cold_water_on_off_flag) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                HOT_BUTTON_LED_ON();
                            } else {
                                HOT_BUTTON_LED_OFF();
                            }
                            if (HOT_BUTTON()) {
                                if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                } else {
                                    cold_water_on_off_flag = 1;
                                    HOT_BUTTON_LED_ON();
                                }
                                BZ_user_pushKey(100);
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                RE_HOT_BUTTON();
                            }

                            if (warm_water_on_off_flag) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                WARM_BUTTON_LED_ON();
                            } else {
                                WARM_BUTTON_LED_OFF();
                            }
                            if (WARM_BUTTON()) {
                                if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                } else {
                                    warm_water_on_off_flag = 1;
                                    WARM_BUTTON_LED_ON();
                                }
                                BZ_user_pushKey(100);
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                RE_WARM_BUTTON();
                            }
                        } else {
                            if (TDON_SET) {
                                HOT_BUTTON_LED_OFF();
                                WARM_BUTTON_LED_OFF();
                                COLD_BUTTON_LED_OFF();
                            } else {
                                HOT_BUTTON_LED_ON();
                                WARM_BUTTON_LED_ON();
                                COLD_BUTTON_LED_ON();
                            }

                            if (UV_CK_err_flag) {
                                if (LED12V_LAT) {
                                    TC_LED_B();
                                } else {
                                    TC_LED_G();
                                }
                            } else {
                                TC_LED_B();
                            }


                            if (HOT_BUTTON() | WARM_BUTTON() | COLD_BUTTON()) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                COM_MCU_SetHigh();
                            }
                        }

                    } else {
                        if (m_key_sleep_time != 0) {
                            TC_LED_G();

                            if (cold_water_on_off_flag) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                HOT_BUTTON_LED_ON();
                            } else {
                                HOT_BUTTON_LED_OFF();
                            }
                            if (HOT_BUTTON()) {
                                if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                } else {
                                    cold_water_on_off_flag = 1;
                                    HOT_BUTTON_LED_ON();
                                }
                                BZ_user_pushKey(100);
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                RE_HOT_BUTTON();
                            }

                            if (warm_water_on_off_flag) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                WARM_BUTTON_LED_ON();
                            } else {
                                WARM_BUTTON_LED_OFF();
                            }
                            if (WARM_BUTTON()) {
                                if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                } else {
                                    warm_water_on_off_flag = 1;
                                    WARM_BUTTON_LED_ON();
                                }
                                BZ_user_pushKey(100);
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                RE_WARM_BUTTON();
                            }

                            if (hot_water_on_off_flag) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                COLD_BUTTON_LED_ON();
                            } else {
                                COLD_BUTTON_LED_OFF();
                            }
                            if (COLD_BUTTON()) {
                                if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                    hot_water_on_off_flag = 0;
                                    warm_water_on_off_flag = 0;
                                    cold_water_on_off_flag = 0;
                                } else {
                                    hot_water_on_off_flag = 1;
                                    COLD_BUTTON_LED_ON();
                                }
                                BZ_user_pushKey(100);
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                RE_COLD_BUTTON();
                            }

                        } else {
                            if (TDON_SET) {
                                HOT_BUTTON_LED_OFF();
                                WARM_BUTTON_LED_OFF();
                                COLD_BUTTON_LED_OFF();
                            } else {
                                HOT_BUTTON_LED_ON();
                                WARM_BUTTON_LED_ON();
                                COLD_BUTTON_LED_ON();
                            }

                            //TSLED_SetHigh();
                            if (UV_CK_err_flag) {
                                if (LED12V_LAT) {
                                    TC_LED_B();
                                } else {
                                    TC_LED_G();
                                }
                            } else {
                                TC_LED_B();
                            }

                            if (HOT_BUTTON() | WARM_BUTTON() | COLD_BUTTON()) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                COM_MCU_SetHigh();
                            }
                        }
                    }
                } else {
                    if (HOT_SET) {
                        if (m_hot_lock_time != 0) {
                            COLD_BUTTON_LED_OFF();
                            if (COLD_BUTTON()) {//3 key for Hot
                                if (!hot_water_on_off_flag) {
                                    hot_water_on_off_flag = 1;
                                    BZ_user_pushKey(100);
                                }

                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                m_hot_lock_time = BUTTON_SLEEP_TIMER;
                            } else {
                                hot_water_on_off_flag = 0;
                            }
                        } else { // if (m_hot_lock_time != 0)
                            if (TDON_SET) {
                                COLD_BUTTON_LED_OFF();
                            } else {
                                COLD_BUTTON_LED_ON();
                            }

                            if (COLD_BUTTON()) {
                                m_key_sleep_time = BUTTON_SLEEP_TIMER;
                                m_hot_lock_time = BUTTON_SLEEP_TIMER;
                                COM_MCU_SetHigh();
                                RE_HOT_BUTTON();
                                RE_WARM_BUTTON();
                                RE_COLD_BUTTON();
                                BZ_user_relockKey();
                            }
                        }

                        // Cold
                        if (HOT_BUTTON()) {
                            if (!cold_water_on_off_flag) {
                                cold_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        }//warm 
                        else if (WARM_BUTTON()) {
                            if (!warm_water_on_off_flag) {
                                warm_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        } else {
                            warm_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                        }

                        if (m_key_sleep_time != 0) {
                            TC_LED_G();
                            WARM_BUTTON_LED_OFF();
                            HOT_BUTTON_LED_OFF();
                        } else {
                            if (UV_CK_err_flag) {
                                if (LED12V_LAT) {
                                    TC_LED_B();
                                } else {
                                    TC_LED_G();
                                }
                            } else {
                                TC_LED_B();
                            }
                            if (TDON_SET) {
                                WARM_BUTTON_LED_OFF();
                                HOT_BUTTON_LED_OFF();
                            } else {
                                WARM_BUTTON_LED_ON();
                                HOT_BUTTON_LED_ON();
                            }
                        }
                    } else { //  if (HOT_SET)
                        if (m_key_sleep_time != 0) {
                            TC_LED_G();
                            HOT_BUTTON_LED_OFF();
                            WARM_BUTTON_LED_OFF();
                            COLD_BUTTON_LED_OFF();
                        } else {
                            if (UV_CK_err_flag) {
                                if (LED12V_LAT) {
                                    TC_LED_B();
                                } else {
                                    TC_LED_G();
                                }
                            } else {
                                TC_LED_B();
                            }
                            if (TDON_SET) {
                                HOT_BUTTON_LED_OFF();
                                WARM_BUTTON_LED_OFF();
                                COLD_BUTTON_LED_OFF();
                            } else {
                                HOT_BUTTON_LED_ON();
                                WARM_BUTTON_LED_ON();
                                COLD_BUTTON_LED_ON();
                            }
                        }
                        if (HOT_BUTTON()) {//3 key for cold
                            if (!cold_water_on_off_flag) {
                                cold_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        }//3 key for hot
                        else if (COLD_BUTTON()) {
                            if (!hot_water_on_off_flag) {
                                hot_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        }//warm 
                        else if (WARM_BUTTON()) {
                            if (!warm_water_on_off_flag) {
                                warm_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        } else {
                            warm_water_on_off_flag = 0;
                            hot_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                        }
                    }
                }
            } else { // if (PUH_SET)

                if (m_key_sleep_time != 0) {

                    TC_LED_G();

                    if (CONTINUOUS_WATER_SET) {

                        if (cold_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            HOT_BUTTON_LED_ON();
                        } else {
                            HOT_BUTTON_LED_OFF();
                        }
                        if (HOT_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                cold_water_on_off_flag = 1;
                                HOT_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_HOT_BUTTON();
                        }

                        if (warm_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            WARM_BUTTON_LED_ON();
                        } else {
                            WARM_BUTTON_LED_OFF();
                        }
                        if (WARM_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                warm_water_on_off_flag = 1;
                                WARM_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_WARM_BUTTON();
                        }

                        if (hot_water_on_off_flag) {
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            COLD_BUTTON_LED_ON();
                        } else {
                            COLD_BUTTON_LED_OFF();
                        }
                        if (COLD_BUTTON()) {
                            if (hot_water_on_off_flag | warm_water_on_off_flag | cold_water_on_off_flag) {
                                hot_water_on_off_flag = 0;
                                warm_water_on_off_flag = 0;
                                cold_water_on_off_flag = 0;
                            } else {
                                hot_water_on_off_flag = 1;
                                COLD_BUTTON_LED_ON();
                            }
                            BZ_user_pushKey(100);
                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                            RE_COLD_BUTTON();
                        }

                    } else {
                        HOT_BUTTON_LED_OFF();
                        WARM_BUTTON_LED_OFF();
                        COLD_BUTTON_LED_OFF();

                        if (COLD_BUTTON()) { //3 key for cold
                            if (!hot_water_on_off_flag) {
                                hot_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        }//warm 
                        else if (WARM_BUTTON()) {
                            if (!warm_water_on_off_flag) {
                                warm_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        } else if (HOT_BUTTON()) {//3 key for Hot
                            if (!cold_water_on_off_flag) {
                                cold_water_on_off_flag = 1;
                                BZ_user_pushKey(100);
                            }

                            m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        } else {
                            hot_water_on_off_flag = 0;
                            warm_water_on_off_flag = 0;
                            cold_water_on_off_flag = 0;
                        }
                    }
                } else {

                    if (TDON_SET) {
                        HOT_BUTTON_LED_OFF();
                        WARM_BUTTON_LED_OFF();
                        COLD_BUTTON_LED_OFF();
                    } else {
                        HOT_BUTTON_LED_ON();
                        WARM_BUTTON_LED_ON();
                        COLD_BUTTON_LED_ON();
                    }

                    //TSLED_SetHigh();
                    if (UV_CK_err_flag) {
                        if (LED12V_LAT) {
                            TC_LED_B();
                        } else {
                            TC_LED_G();
                        }
                    } else {
                        TC_LED_B();
                    }

                    if (HOT_BUTTON() | WARM_BUTTON() | COLD_BUTTON()) {
                        m_key_sleep_time = BUTTON_SLEEP_TIMER;
                        COM_MCU_SetHigh();
                        RE_HOT_BUTTON();
                        RE_WARM_BUTTON();
                        RE_COLD_BUTTON();
                        BZ_user_relockKey();
                    }
                }
            }
        }

        if (ALL_BUTTON()) {
            if (show_mode == RUN_Mode) {
                All_Butter_Pull_time++;
                BZ_user_pushKey(100);
                delay_1ms(600);
                if (All_Butter_Pull_time > 2) {
                    BZ_user_pushKey(1000);
                    MODE_TEST_TIME = 10;
                    show_mode = TEST_Mode;
                    mTest_Mode();

                    RE_ALL_BUTTON();
                }
            } else {
                RE_ALL_BUTTON();
            }

        } else {
            RE_ALL_BUTTON();
            All_Butter_Pull_time = 0;
        }


        /* BUTTON CK END */

        /* Water OUT */
        CLRWDT();
        // Water out protection
        if (HotWaterOut_LAT | WarmWaterOut_LAT | ColdWaterOut_LAT) {
            if (Water_out_protection_time == 0) {
                warm_water_on_off_flag = 0;
                hot_water_on_off_flag = 0;
                cold_water_on_off_flag = 0;
                HotWaterOut_LAT = 0;
                WarmWaterOut_LAT = 0;
                ColdWaterOut_LAT = 0;
                RE_HOT_BUTTON();
                RE_WARM_BUTTON();
                RE_COLD_BUTTON();
                BZ = 1;
                delay_1ms(500);
                BZ = 0;
                delay_1ms(500);
                BZ = 1;
                delay_1ms(500);
                BZ = 0;
            }
        } else {
            Water_out_protection_time = WATER_OUT_PROTECTION_TIMER;
        }

        // HOT OUT
        if (hot_water_on_off_flag) {
            HotWaterOut_LAT = 1;
        } else {
            if (HotWaterOut_LAT) {
                HOT_BUTTON_delay = HOT_KEY_DELAY_TIMER;
            }
            HotWaterOut_LAT = 0;
        }

        // WARM OUT
        if (warm_water_on_off_flag) {
            if (HOT_BUTTON_delay != 0) {
                WarmWaterOut_LAT = 0;
            } else {
                WarmWaterOut_LAT = 1;
            }

        } else {
            WarmWaterOut_LAT = 0;
        }

        // COLD OUT
        if (cold_water_on_off_flag) {
            if (HOT_BUTTON_delay != 0) {
                ColdWaterOut_LAT = 0;
            } else {
                ColdWaterOut_LAT = 1;
            }
        } else {
            ColdWaterOut_LAT = 0;
        }

        // SODA Water Clean
        //        if (MLK_SET) {
        //            if (ck_AC_SODA_flag) {
        //                if (HOT_SET) {
        //                    if (!WarmWaterOut_LAT) {
        //                        if (soda_water_clean_time == 0) {
        //                            if (SYNC_SET) {
        //                                MDWaterOut_LAT = 0;
        //                                ColdWaterOut_LAT = 1;
        //                                delay_1ms(500);
        //                                SyncWaterOut_LAT = 0;
        //                                delay_1ms(500);
        //                                ColdWaterOut_LAT = 0;
        //                            } else {
        //                                MDWaterOut_LAT = 0;
        //                                ColdWaterOut_LAT = 1;
        //                                delay_1ms(1000);
        //                                ColdWaterOut_LAT = 0;
        //                            }
        //                        }
        //                        soda_water_clean_time = SODA_WATER_CLEAN_TIMER;
        //                    }
        //                } else {
        //                    if (!HotWaterOut_LAT) {
        //                        if (soda_water_clean_time == 0) {
        //                            if (SYNC_SET) {
        //                                MDWaterOut_LAT = 0;
        //                                ColdWaterOut_LAT = 1;
        //                                delay_1ms(500);
        //                                SyncWaterOut_LAT = 0;
        //                                delay_1ms(500);
        //                                ColdWaterOut_LAT = 0;
        //                            } else {
        //                                MDWaterOut_LAT = 0;
        //                                ColdWaterOut_LAT = 1;
        //                                delay_1ms(1000);
        //                                ColdWaterOut_LAT = 0;
        //                            }
        //                        }
        //                        soda_water_clean_time = SODA_WATER_CLEAN_TIMER;
        //                    }
        //                }
        //            } else {
        //                soda_water_clean_time = SODA_WATER_CLEAN_TIMER;
        //            }
        //        }

        // SODA Water Clean
        if (MLK_SET) {
            if (ck_AC_SODA_flag) {
                if (HOT_SET) {
                    if (WarmWaterOut_LAT) {
                        if (soda_water_clean_time == 0) {
                            soda_water_clean_flag = 1;
                        }
                    } else {
                        if (soda_water_clean_flag) {
                            //                            if (SYNC_SET) {
                            //                                soda_water_clean_flag = 0;
                            //                                MDWaterOut_LAT = 0;
                            //                                ColdWaterOut_LAT = 1;
                            //                                delay_1ms(1800);
                            //                                ColdWaterOut_LAT = 0;
                            //                            } else {
                            soda_water_clean_flag = 0;
                            MDWaterOut_LAT = 0;
                            ColdWaterOut_LAT = 1;
                            delay_1ms(1500);
                            ColdWaterOut_LAT = 0;
                            //                            }
                        }
                        soda_water_clean_time = SODA_WATER_CLEAN_TIMER;
                    }
                } else {
                    if (HotWaterOut_LAT) {
                        if (soda_water_clean_time == 0) {
                            soda_water_clean_flag = 1;
                        }
                    } else {
                        if (soda_water_clean_flag) {
                            //                            if (SYNC_SET) {
                            //                                soda_water_clean_flag = 0;
                            //                                MDWaterOut_LAT = 0;
                            //                                ColdWaterOut_LAT = 1;
                            //                                delay_1ms(1800);
                            //                                ColdWaterOut_LAT = 0;
                            //
                            //                            } else {
                            soda_water_clean_flag = 0;
                            MDWaterOut_LAT = 0;
                            ColdWaterOut_LAT = 1;
                            delay_1ms(1500);
                            ColdWaterOut_LAT = 0;
                            //                            }
                        }
                        soda_water_clean_time = SODA_WATER_CLEAN_TIMER;
                    }
                }
            }
        }

        // Sync OUT Water
        if (SYNC_SET) {
            // MD Water OUT
            if (WaterSDIsInject == INJECT_WATER) {
                if (ColdWaterOut_LAT) {
                    MDWaterOut_LAT = 0;
                } else {
                    MDWaterOut_LAT = 1;
                }
            } else {
                MDWaterOut_LAT = 0;
            }

            // Yellow (Sync) Water OUT
            //            if (HotWaterOut_LAT | ColdWaterOut_LAT | WarmWaterOut_LAT | MDWaterOut_LAT) {
            //                SyncWaterOut_SetHigh();
            //            } else {
            //                SyncWaterOut_SetLow();
            //            }
            if (MDWaterOut_LAT | ColdWaterOut_LAT | WarmWaterOut_LAT | HotWaterOut_LAT) {
                SyncWaterOut_LAT = 1;
                SyncWaterOutDelayTimer = 4;
            } else {
                if (SyncWaterOutDelayTimer == 0) {
                    SyncWaterOut_LAT = 0;
                }
            }

        } else {
            // Yellow (Sync) Water OUT
            if (WaterIsInject == INJECT_WATER) {
                SyncWaterOut_LAT = 1;
            } else {
                SyncWaterOut_LAT = 0;
            }

            // MD Water OUT
            if (ck_AC_SODA_flag) {
                if (WaterSDIsInject == INJECT_WATER) {
                    if (HotWaterOut_LAT | ColdWaterOut_LAT | WarmWaterOut_LAT | SyncWaterOut_LAT) {
                        MDWaterOut_LAT = 0;
                    } else {
                        MDWaterOut_LAT = 1;
                    }
                } else {
                    MDWaterOut_LAT = 0;
                }
            } else {
                MDWaterOut_LAT = 0;
            }
        }
        /* Water OUT END */

        /* ALL ON OFF CK */
        if (MDWaterOut_LAT | SyncWaterOut_LAT | ColdWaterOut_LAT | WarmWaterOut_LAT | HotWaterOut_LAT) {
            AllOnOff_SetHigh();
        } else {
            AllOnOff_SetLow();
        }
        /* ALL ON OFF CK END*/

        /* UV CK */
        CLRWDT();
        if (UV_SET) {
            mUV_Loop();
            if (mUV_CK_Error()) {
                if (!UV_CK_err_flag) {
                    UV_CK_err_flag = 1;
                    err_bz_flag = 1;
                    BZ_RunSet(8, 10);
                }
            } else {
                UV_CK_err_flag = 0;
            }
            if (UV_CK_err_flag) {
                if (m_key_sleep_time != 0) {
                    if (WarmWaterOut_LAT | ColdWaterOut_LAT) {
                        if (!err_bz_flag) {
                            err_bz_flag = 1;
                            BZ_RunSet(2, 10);
                        }
                    }
                } else {
                    err_bz_flag = 0;
                }
            }
        }

        //        if (UV_SET) {
        //            if (HOT_SET) {
        //                if (ColdWaterOut_LAT | WarmWaterOut_LAT) {
        //                    UV_on_flag = 1;
        //                } else {
        //                    UV_on_flag = 0;
        //                }
        //            } else {
        //                if (ColdWaterOut_LAT | WarmWaterOut_LAT | HotWaterOut_LAT) {
        //                    UV_on_flag = 1;
        //                } else {
        //                    UV_on_flag = 0;
        //                }
        //            }
        //            if (UV_on_flag) {
        //                UVS_MCU_LAT = 1;
        //                if (UV_CK_time == 0) {
        //                    if (UV_CK_MCU_PORT) {
        //                        if (!UV_CK_flag) {
        //                            UV_CK_flag = 1;
        //
        //                            if (uv_error_count < 5) {
        //                                uv_error_count++;
        //                            } else {
        //                                UV_CK_err_flag = 1;
        //                                err_bz_flag = 1;
        //                            }
        //                        }
        //
        //                    } else {
        //                        UV_CK_flag = 1;
        //                        uv_error_count = 0;
        //                        UV_CK_err_flag = 0;
        //                        UV_bz_f_err_flag = 0;
        //                    }
        //                }
        //            } else {
        //                UVS_MCU_LAT = 0;
        //                UV_CK_flag = 0;
        //                UV_CK_time = UV_CK_TIMER;
        //            }
        //
        //            if (UV_CK_err_flag) {
        //                if (!UV_CK_MCU_PORT) {
        //                    UV_CK_err_flag = 0;
        //                    UV_bz_f_err_flag = 0;
        //                    uv_error_count = 0;
        //                }
        //            }
        //            //            else {
        //            //                LED_UV = ~UV_CK_MCU_PORT;
        //            //            }
        //        } else {
        //            UVS_MCU_LAT = 0;
        //            //            LED_UV = 0;
        //        }
        /* UV CK END */

        /* Water Level CK */
        CLRWDT();

        if (SYNC_SET) {
            if (m_key_sleep_time != 0) {
                WaterLeveManager_Enable();
            } else {
                if (WaterSDIsInject == DO_NOT_INJECT_WATER) {
                    WaterLeveManager_Disenable();
                }
            }
            WaterSDIsInject = WaterLeveManager_IsInject_B();
            WaterLeveManager_Sync_MainLoop();
        } else {

            if (m_key_sleep_time != 0) {
                WaterLeveManager_Enable();
                CK_SODA_Timer = 10;
            } else {
                if (WaterIsInject == DO_NOT_INJECT_WATER && WaterSDIsInject == DO_NOT_INJECT_WATER) {
                    if (CK_SODA_Timer == 0) {
                        WaterLeveManager_Disenable();
                    }
                    
                } else {
                    CK_SODA_Timer = 10;
                }
            }
            WaterIsInject = WaterLeveManager_IsInject_A();
            WaterSDIsInject = WaterLeveManager_IsInject_B();
            WaterLeveManager_MainLoop();
        }
        /* Water Level CK END */



        /* PW ADC and FAN */
        CLRWDT();
        if (ck_AC_chilling_flag) {
            PWM5_ON();
            fan_out_delay = FAN_OUT_DELAY_TIME;
        } else {
            if (fan_out_delay != 0) {
            } else {
                PWM5_OFF();
            }
        }
        if (PWM5_IsStart()) {
            if (ADC_IsConversionDone()) {
                Fan_control();
            }
        }
        /* PW ADC and FAN END */

        /* AC CK */
        CLRWDT();
        ACSenserManager_MainLoop();
        ck_AC_HEATING_flag = ACSenserManager_GetPortState(AC_HEATING);
        ck_AC_SODA_flag = ACSenserManager_GetPortState(AC_SODA);
        ck_AC_COOL_flag = ACSenserManager_GetPortState(AC_COOL);
        ck_AC_chilling_flag = ACSenserManager_GetPortState(AC_CHILLING);
        ck_AC_Hot_flag = ACSenserManager_GetPortState(AC_HOT);
        /* AC CK END*/

        /* LED */
        if (ck_AC_chilling_flag) {
            //                LED_CHILLING_ON();
            LED_1_ON();
        } else {
            //                LED_CHILLING_OFF();
            LED_1_OFF();
        }

        if (ck_AC_COOL_flag) {
            LED_2_ON();
            //                LED_COOL_ON();
            //                LED_COOL = 1;
        } else {
            LED_2_OFF();
            //                LED_COOL_OFF();
            //                LED_COOL = 0;
        }

        if (!HAETING_LED) {
            // UV
            if (UV_SET) {
                if (UV_CK_err_flag) {
                    LED_3_FLASH();
                    //                        LED_UV_FLASH();
                } else {
                    if (UV_CK_MCU_PORT) {
                        LED_3_OFF();
                        //                            LED_UV_OFF();
                    } else {
                        LED_3_ON();
                        //                            LED_UV_ON();
                    }
                }
            }
        } else {
            // HEATING
            if (ck_AC_HEATING_flag) {
                LED_3_ON();
                //                    LED_HEATING_ON();
            } else {
                LED_3_OFF();
                //                    LED_HEATING_OFF();
            }
        }

        if (HOT_SET) {
            // HOT
            if (ck_AC_Hot_flag) {
                LED_4_ON();
                //                    LED_HOT_ON();
            } else {
                LED_4_OFF();
                //                    LED_HOT_OFF();
            }
        } else {
            // SODA
            if (ck_AC_SODA_flag) {
                LED_4_ON();
                //                    LED_SODA_ON();
            } else {
                LED_4_OFF();
                //                    LED_SODA_OFF();
            }
        }

        if (UV_CK_err_flag) {
            LED_12V_FLASH();
        } else {
            LED_12V_ON();
        }
        /* LED END */


        /* FULL Water CK */
        CLRWDT();
        if (!FULL_MCU_PORT) {
            if (Full_ck_time == 0) {
                BZ_RunSet(8, 10);
                Full_flag = 1;
                RE_HOT_BUTTON();
                RE_WARM_BUTTON();
                RE_COLD_BUTTON();
                RE_LOCK_BUTTON();
                //                All_Butter_flag = 0;
                HotWaterOut_LAT = 0;
                WarmWaterOut_LAT = 0;
                ColdWaterOut_LAT = 0;
                SyncWaterOut_LAT = 0;
                MDWaterOut_LAT = 0;
                HOT_SW_MCU_LAT = 0;
                while (Full_flag) {

                    CLRWDT();

                    CK_Buttons_key4();

                    ACSenserManager_MainLoop();
                    ck_AC_HEATING_flag = ACSenserManager_GetPortState(AC_HEATING);
                    ck_AC_SODA_flag = ACSenserManager_GetPortState(AC_SODA);
                    ck_AC_COOL_flag = ACSenserManager_GetPortState(AC_COOL);
                    ck_AC_chilling_flag = ACSenserManager_GetPortState(AC_CHILLING);
                    ck_AC_Hot_flag = ACSenserManager_GetPortState(AC_HOT);
                    /* AC CK END*/
                    /* PW ADC and FAN */
                    CLRWDT();
                    if (ck_AC_chilling_flag) {
                        PWM5_ON();
                        fan_out_delay = FAN_OUT_DELAY_TIME;
                    } else {
                        if (fan_out_delay != 0) {
                        } else {
                            PWM5_OFF();
                        }
                    }
                    if (PWM5_IsStart()) {
                        if (ADC_IsConversionDone()) {
                            Fan_control();
                        }
                    }
                    /* PW ADC and FAN END */

                    LED_12V_FLASH();

                    if (HOT_BUTTON() | WARM_BUTTON() | COLD_BUTTON() | LOCK_BUTTON()) {
                        RE_HOT_BUTTON();
                        RE_WARM_BUTTON();
                        RE_COLD_BUTTON();
                        BZ_RunSet(4, 20);
                    }

                    if (FULL_MCU_PORT) {
                        Full_flag = 0;
                        LED_12V_ON();
                        BZ_release();
                        soda_water_clean_time = SODA_WATER_CLEAN_TIMER;
                    }
                }
            }
        } else {
            Full_ck_time = FULL_CK_TIMER;
            Full_flag = 0;
        }

        /* FULL Water CK END */

        /* LSS Water CK */
        CLRWDT();
        if (!LSS_MCU_PORT) {
            if (LSS_ck_time == 0) {
                BZ_RunSet(8, 3);
                RE_HOT_BUTTON();
                RE_WARM_BUTTON();
                RE_COLD_BUTTON();
                RE_LOCK_BUTTON();
                //                All_Butter_flag = 0;
                HotWaterOut_LAT = 0;
                WarmWaterOut_LAT = 0;
                ColdWaterOut_LAT = 0;
                SyncWaterOut_LAT = 0;
                MDWaterOut_LAT = 0;
                HOT_SW_MCU_LAT = 0;
                LED_12V_OFF();
                LED1_LAT = 0;
                LED_1_OFF();
                LED2_LAT = 0;
                LED_2_OFF();
                LED3_LAT = 0;
                LED_3_OFF();
                LED4_LAT = 0;
                LED_4_OFF();
                //                PWM5_LoadDutyValue(0);
                HOT_SW_MCU_LAT = 1;
                delay_1ms(1000);
                HOT_SW_MCU_LAT = 0;
                delay_1ms(1000);
                HOT_SW_MCU_LAT = 1;
                delay_1ms(500);
                HOT_SW_MCU_LAT = 0;
                delay_1ms(500);
                HOT_SW_MCU_LAT = 1;
                delay_1ms(500);
                HOT_SW_MCU_LAT = 0;
                delay_1ms(1000);
                HOT_SW_MCU_LAT = 1;
                delay_1ms(1000);
                HOT_SW_MCU_LAT = 0;
                AllOnOff_LAT = 0;
                LED_SYS_FLASH();
                TC_LED_B();
                while (1) {
                    CLRWDT();

                    CK_Buttons_key4();

                    ACSenserManager_MainLoop();
                    ck_AC_HEATING_flag = ACSenserManager_GetPortState(AC_HEATING);
                    ck_AC_SODA_flag = ACSenserManager_GetPortState(AC_SODA);
                    ck_AC_COOL_flag = ACSenserManager_GetPortState(AC_COOL);
                    ck_AC_chilling_flag = ACSenserManager_GetPortState(AC_CHILLING);
                    ck_AC_Hot_flag = ACSenserManager_GetPortState(AC_HOT);
                    /* AC CK END*/
                    /* PW ADC and FAN */
                    CLRWDT();
                    if (ck_AC_chilling_flag) {
                        PWM5_ON();
                        fan_out_delay = FAN_OUT_DELAY_TIME;
                    } else {
                        if (fan_out_delay != 0) {
                        } else {
                            PWM5_OFF();
                        }
                    }
                    if (PWM5_IsStart()) {
                        if (ADC_IsConversionDone()) {
                            Fan_control();
                        }
                    }
                    /* PW ADC and FAN END */

                    LED_12V_FLASH();
                    HOT_BUTTON_LED_SET(LEDManager_GetLEDCommon());
                    WARM_BUTTON_LED_SET(LEDManager_GetLEDCommon());
                    COLD_BUTTON_LED_SET(LEDManager_GetLEDCommon());
                    HOTLOCK_BUTTON_LED_SET(LEDManager_GetLEDCommon());
                    if (HOT_BUTTON() | WARM_BUTTON() | COLD_BUTTON() | LOCK_BUTTON()) {
                        BZ_RunSet(4, 3);
                        RE_HOT_BUTTON();
                        RE_WARM_BUTTON();
                        RE_COLD_BUTTON();
                        RE_LOCK_BUTTON();
                    }
                }
            }
        } else {
            LSS_ck_time = LSS_CK_TIMER;
        }
        /* LSS Water CK END */
    }
}

void SET_ck(void) {
    /* SET CK */
    uint16_t ckSetCount;

    CSET1_SetLow();
    delay_1ms(10);
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET1_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET1_flag = 1;
    } else {
        SET1_flag = 0;
    }
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET2_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET4_flag = 1;
    } else {
        SET4_flag = 0;
    }
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET3_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET7_flag = 1;
    } else {
        SET7_flag = 0;
    }
    CSET1_SetHigh();

    CSET2_SetLow();
    delay_1ms(10);
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET1_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET2_flag = 1;
    } else {
        SET2_flag = 0;
    }
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET2_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET5_flag = 1;
    } else {
        SET5_flag = 0;
    }
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET3_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET8_flag = 1;
    } else {
        SET8_flag = 0;
    }
    CSET2_SetHigh();

    CSET3_SetLow();
    delay_1ms(10);
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET1_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET3_flag = 1;
    } else {
        SET3_flag = 0;
    }
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET2_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET6_flag = 1;
    } else {
        SET6_flag = 0;
    }
    ckSetCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (!RSET3_PORT) {
            ckSetCount++;
        }
    }
    if (ckSetCount > 900) {
        SET9_flag = 1;
    } else {
        SET9_flag = 0;
    }
    CSET3_SetHigh();

    /* SET CK END */
}

void mTest_Mode(void) {

    CLRWDT();

    while (show_mode == TEST_Mode) {

        if (KEY4_SET) {
            HOT_BUTTON_LED_SET(HotWaterOut_LAT);
            WARM_BUTTON_LED_SET(WarmWaterOut_LAT);
            COLD_BUTTON_LED_SET(ColdWaterOut_LAT);
        } else {
            HOT_BUTTON_LED_SET(ColdWaterOut_LAT);
            WARM_BUTTON_LED_SET(WarmWaterOut_LAT);
            COLD_BUTTON_LED_SET(HotWaterOut_LAT);
        }

        CK_Buttons_key4();

        AllOnOff_SetHigh();

        CLRWDT();

        if (HOT_BUTTON()) {
            if (HotWaterOut_LAT | WarmWaterOut_LAT | ColdWaterOut_LAT) {
                HotWaterOut_LAT = WarmWaterOut_LAT = ColdWaterOut_LAT = 0;
                MODE_TEST_TIME = 0;
                BZ_user_pushKey(100);
            } else {
                MODE_TEST_TIME = 240;
                BZ_user_pushKey(100);
                if (KEY4_SET) {
                    HotWaterOut_LAT = 1;
                } else {
                    ColdWaterOut_LAT = 1;
                }
            }

            RE_HOT_BUTTON();

        } else if (WARM_BUTTON()) {
            if (HotWaterOut_LAT | WarmWaterOut_LAT | ColdWaterOut_LAT) {
                HotWaterOut_LAT = WarmWaterOut_LAT = ColdWaterOut_LAT = 0;
                MODE_TEST_TIME = 0;
                BZ_user_pushKey(100);
            } else {
                MODE_TEST_TIME = 240;
                BZ_user_pushKey(100);
                WarmWaterOut_LAT = 1;
            }

            RE_WARM_BUTTON();

        } else if (COLD_BUTTON()) {
            if (HotWaterOut_LAT | WarmWaterOut_LAT | ColdWaterOut_LAT) {
                HotWaterOut_LAT = WarmWaterOut_LAT = ColdWaterOut_LAT = 0;
                MODE_TEST_TIME = 0;
                BZ_user_pushKey(100);
            } else {
                MODE_TEST_TIME = 240;
                BZ_user_pushKey(100);
                if (KEY4_SET) {
                    ColdWaterOut_LAT = 1;
                } else {
                    HotWaterOut_LAT = 1;
                }
            }

            RE_COLD_BUTTON();
        }

        // SODA
        ACSenserManager_MainLoop();
        ck_AC_SODA_flag = ACSenserManager_GetPortState(AC_SODA);

        if (MODE_TEST_TIME == 0) {

            HotWaterOut_LAT = 0;
            MDWaterOut_LAT = 0;
            WarmWaterOut_LAT = 0;
            ColdWaterOut_LAT = 0;
            SyncWaterOut_LAT = 0;

            RE_LOCK_BUTTON();
            RE_HOT_BUTTON();
            RE_WARM_BUTTON();
            RE_COLD_BUTTON();

            //            LED_CHILLING = 0;
            //            LED_COOL = 0;
            //            LED_HEATING = 0;
            //            LED_UV = 0;
            //            LED_HOT = 0;
            //            LED_SODA = 0;


            m_key_sleep_time = 0;

            soda_water_clean_time = SODA_WATER_CLEAN_TIMER;

            BZ_user_pushKey(500);
            delay_1ms(300);
            BZ_user_pushKey(500);
            show_mode = RUN_Mode;

        } else {

            WaterLeveManager_Enable();
            WaterLeveManager_MainLoop();
            WaterIsInject = WaterLeveManager_IsInject_A();
            WaterSDIsInject = WaterLeveManager_IsInject_B();

            if (SYNC_SET) {
                if (HotWaterOut_LAT | WarmWaterOut_LAT | ColdWaterOut_LAT | MDWaterOut_LAT) {
                    SyncWaterOut_LAT = 1;
                } else {
                    SyncWaterOut_LAT = 0;
                }
            } else {
                if (MDWaterOut_LAT == 0) {
                    if (WaterIsInject == INJECT_WATER) {
                        // NO Water
                        SyncWaterOut_LAT = 1;
                    } else {
                        // Has Water
                        SyncWaterOut_LAT = 0;
                    }
                }
            }
            // SODA Water
            if (ck_AC_SODA_flag) {

                if (WaterSDIsInject == INJECT_WATER) {
                    // NO Water
                    if (SYNC_SET) {
                        MDWaterOut_LAT = 1;
                    } else {
                        if (SyncWaterOut_LAT == 0) {
                            MDWaterOut_LAT = 1;
                        }
                    }
                } else {
                    MDWaterOut_LAT = 0;
                }
            } else {
                MDWaterOut_LAT = 0;
            }
        }
    }
}




/**
 End of File
 */