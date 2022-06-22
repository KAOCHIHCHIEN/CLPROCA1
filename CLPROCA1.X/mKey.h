/* 
 * File:   mKey.h
 * Author: KaoChihChien
 *
 * Created on January 21, 2021, 11:43 AM
 */

#ifndef MKEY_H
#define	MKEY_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef unsigned char sfr_byte;
    
typedef struct { // ?????
    unsigned char p0 : 1;
    unsigned char p1 : 1;
    unsigned char p2 : 1;
    unsigned char p3 : 1;
    unsigned char p4 : 1;
    unsigned char p5 : 1;
    unsigned char p6 : 1;
    unsigned char p7 : 1;
} p_bits;

typedef union { // ?????
    p_bits bits; // ??????
    sfr_byte byte;
} button_type;

unsigned char hot_led_flag;
unsigned char cool_led_flag;
unsigned char sod_led_flag;
unsigned char HotLock_led_flag;

#define HOT_BUTTON_LED_ON() do { hot_led_flag = 1; } while(0)
#define HOT_BUTTON_LED_OFF() do { hot_led_flag = 0; } while(0)
#define HOT_BUTTON_LED_SET(x) do { hot_led_flag = x; } while(0)

#define COLD_BUTTON_LED_ON() do { cool_led_flag = 1; } while(0)
#define COLD_BUTTON_LED_OFF() do { cool_led_flag = 0; } while(0)
#define COLD_BUTTON_LED_SET(x) do { cool_led_flag = x; } while(0)

#define WARM_BUTTON_LED_ON() do { sod_led_flag = 1; } while(0)
#define WARM_BUTTON_LED_OFF() do { sod_led_flag = 0; } while(0)
#define WARM_BUTTON_LED_SET(x) do { sod_led_flag = x; } while(0)

#define HOTLOCK_BUTTON_LED_ON() do { HotLock_led_flag = 1; } while(0)
#define HOTLOCK_BUTTON_LED_OFF() do { HotLock_led_flag = 0; } while(0)
#define HOTLOCK_BUTTON_LED_SET(x) do { HotLock_led_flag = x; } while(0)

#define TC_LED_B() do { TSLED_LAT = 1; } while(0)
#define TC_LED_G() do { TSLED_LAT = 0; } while(0)

unsigned char hot_button_flag;
unsigned char cool_button_flag;
unsigned char soda_button_flag;
unsigned char HotLock_button_flag;
unsigned char all_on_button_flag;
unsigned char k2_button_flag;

#define LOCK_BUTTON() HotLock_button_flag
#define HOT_BUTTON() hot_button_flag
#define COLD_BUTTON() cool_button_flag
#define WARM_BUTTON() soda_button_flag
#define SET_BUTTON() set_button_flag
#define ALL_BUTTON() all_on_button_flag
#define K2_BUTTON() k2_button_flag

#define RE_LOCK_BUTTON() do { HotLock_button_flag = 0; } while(0)
#define RE_HOT_BUTTON() do { hot_button_flag = 0; } while(0)
#define RE_COLD_BUTTON() do { cool_button_flag = 0; } while(0)
#define RE_WARM_BUTTON() do { soda_button_flag = 0; } while(0)
#define RE_SET_BUTTON() do { set_button_flag = 0; } while(0)
#define RE_ALL_BUTTON() do { all_on_button_flag = 0; } while(0)
#define RE_K2_BUTTON() do { k2_button_flag = 0; } while(0)

void CK_Buttons_key4(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MKEY_H */

