#include "mcc_generated_files/mcc.h"
#include "mKey.h"

button_type Button;

#define PULL_DELAY_TIME 500
#define P_DELAY_TIME 500

unsigned int other_delay_time;

unsigned int k2_delay_time;
unsigned int hot_delay_time;
unsigned int hotLock_delay_time;
unsigned int cool_delay_time;
unsigned int soda_delay_time;
unsigned int all_delay_time;
unsigned char button_push_flag;

void CK_Buttons_key4(void) {

    HotLock_Touch_SetDigitalInput();
    Hot_Touch_SetDigitalInput();
    Warm_Touch_SetDigitalInput();
    Cold_Touch_SetDigitalInput();

    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();

    Button.bits.p0 = HotLock_Touch_GetValue();
    Button.bits.p1 = Hot_Touch_GetValue();
    Button.bits.p2 = Warm_Touch_GetValue();
    Button.bits.p3 = Cold_Touch_GetValue();

    Button.bits.p4 = 1;
    Button.bits.p5 = 1;
    Button.bits.p6 = 1;
    Button.bits.p7 = 1;

    if (hot_led_flag) {
        Hot_Touch_SetDigitalOutput();
        Hot_Touch_SetLow();
    }
    if (cool_led_flag) {
        Cold_Touch_SetDigitalOutput();
        Cold_Touch_SetLow();
    }
    if (sod_led_flag) {
        Warm_Touch_SetDigitalOutput();
        Warm_Touch_SetLow();
    }
    if (HotLock_led_flag) {
        HotLock_Touch_SetDigitalOutput();
        HotLock_Touch_SetLow();
    }
    
    // HOT LOCK
    if (Button.byte == 0xFE) {
        if (hotLock_delay_time != 0) {
            hotLock_delay_time--;
        } else {
            if (!button_push_flag) {
                button_push_flag = 1;
                HotLock_button_flag = 1;
            }
        }

    }// Hot
    else if (Button.byte == 0xFD) {
        if (hot_delay_time != 0) {
            hot_delay_time--;
        } else {
            if (!button_push_flag) {
                button_push_flag = 1;
                hot_button_flag = 1;
            }
        }

    }// sod
    else if (Button.byte == 0xFB) {
        if (soda_delay_time != 0) {
            soda_delay_time--;
        } else {
            if (!button_push_flag) {
                button_push_flag = 1;
                soda_button_flag = 1;
            }
        }
    }// cool
    else if (Button.byte == 0xF7) {
        if (cool_delay_time != 0) {
            cool_delay_time--;
        } else {
            if (!button_push_flag) {
                cool_button_flag = 1;
                button_push_flag = 1;
            }
        }
    } // key2
    else if (Button.byte == 0xF5) {
        if (k2_delay_time != 0) {
            k2_delay_time--;
        } else {
            if (!button_push_flag) {
                k2_button_flag = 1;
                button_push_flag = 1;
            }
        }
    }
    else if (Button.byte == 0xF1) {
        if (all_delay_time != 0) {
            all_delay_time--;
        } else {
            if (!button_push_flag) {
                all_on_button_flag = 1;
                button_push_flag = 1;
            } else {
                if (k2_button_flag == 1) {
                    k2_button_flag = 2;
                }
            }
        }
    } // ALL OFF
    else if (Button.byte == 0xFF) {
        hot_delay_time = PULL_DELAY_TIME;
        cool_delay_time = PULL_DELAY_TIME;
        soda_delay_time = PULL_DELAY_TIME;
        hotLock_delay_time = PULL_DELAY_TIME;
        all_delay_time = PULL_DELAY_TIME;
        k2_delay_time = PULL_DELAY_TIME;
        other_delay_time = P_DELAY_TIME;
        k2_button_flag = 0;
        hot_button_flag = 0;
        cool_button_flag = 0;
        soda_button_flag = 0;
        HotLock_button_flag = 0;
        all_on_button_flag = 0;
        button_push_flag = 0;
    } else {
        if (other_delay_time != 0) {
            other_delay_time--;
        } else {
            button_push_flag = 1;
            hot_delay_time = PULL_DELAY_TIME;
            cool_delay_time = PULL_DELAY_TIME;
            soda_delay_time = PULL_DELAY_TIME;
            hotLock_delay_time = PULL_DELAY_TIME;
            all_delay_time = PULL_DELAY_TIME;
            k2_delay_time = PULL_DELAY_TIME;
        }
    }
    
    if (hot_button_flag) {
        if (Button.bits.p1) {
            hot_button_flag = 0;
        }
    }
    if (soda_button_flag) {
        if (Button.bits.p2) {
            soda_button_flag = 0;
        }
    }
    if (cool_button_flag) {
        if (Button.bits.p3) {
            cool_button_flag = 0;
        }
    }
}