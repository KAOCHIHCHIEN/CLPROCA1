#include "BZManager.h"
#include "mcc_generated_files/mcc.h"
#include "delay.h"

typedef struct {
    unsigned int set_bz_timer;
    unsigned int bz_off_on_timer;
    unsigned char bz_count;
    unsigned char bz_fs;
    unsigned char bz_lock_fs;
} bz_t;

static bz_t BZManager;

static void BZ_ON(void) {
    BZ = 1;
}

static void BZ_OFF(void) {
    BZ = 0;
}

static void BZ_Initialize(void) {
    BZManager.bz_count = 0;
    BZManager.bz_fs = 0;
    BZManager.bz_lock_fs = 0;
    BZ_OFF();
}

void BZ_user_pushKey(unsigned int ms) {
    BZ_ON();
    delay_1ms(ms);
    BZ_OFF();
}

void BZ_user_relockKey(void) {
    BZ_ON();
    delay_1ms(140);
    BZ_OFF();
    delay_1ms(230);
    BZ_ON();
    delay_1ms(140);
    BZ_OFF();
}

void BZ_InitializeAll(void) {
    BZ_Initialize();
}

void BZ_release(void) {
    BZManager.bz_count = 0;
    BZManager.bz_fs = 0;
    BZManager.bz_lock_fs = 0;
    BZ_OFF();
}

void BZ_RunSet(unsigned char setCount, unsigned int setTime) {
    if (!BZManager.bz_lock_fs) {
        BZManager.bz_off_on_timer = setTime;
        BZManager.set_bz_timer = setTime;
        BZManager.bz_count = setCount;
        BZManager.bz_fs = 1;
        BZManager.bz_lock_fs = 1;
    }
}

void BZ_MainLoop(void) {
    if (BZManager.bz_count != 0) {
        if (BZManager.bz_fs) {
            BZ_ON();
            if (BZManager.bz_off_on_timer != 0) {
                BZManager.bz_off_on_timer--;
            } else {
                BZManager.bz_count--;
                if (BZManager.bz_count == 0) {
                    BZ_OFF();
                    return;
                }
                BZManager.bz_fs = 0;
                BZManager.bz_off_on_timer = BZManager.set_bz_timer;
            }
        } else {
            BZ_OFF();
            if (BZManager.bz_off_on_timer != 0) {
                BZManager.bz_off_on_timer--;
            } else {
                BZManager.bz_fs = 1;
                BZManager.bz_off_on_timer = BZManager.set_bz_timer;
            }
        }
    } else {
        BZManager.bz_lock_fs = 0;
    }
}