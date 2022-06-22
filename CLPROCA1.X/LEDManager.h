/* 
 * File:   mLED.h
 * Author: KaoChihChien
 *
 * Created on May 21, 2021, 8:22 AM
 */

#ifndef MLED_H
#define	MLED_H

#ifdef	__cplusplus
extern "C" {
#endif

#define OFF_MODE 0
#define ON_MODE 1
#define FLASH_MODE 2
    
    #define LED_NAMES_COUNT 6
    enum mLED_names
    {
        mLed_1 = 0,
        mLed_2 = 1,
        mLed_3 = 2,
        mLed_4 = 3,
        mLed_12V = 4,
        mLed_Common = 5,
    };
    
#define LED_1_ON()     do { LEDManager_SetLEDState(mLed_1, ON_MODE); } while(0)
#define LED_1_OFF()    do { LEDManager_SetLEDState(mLed_1, OFF_MODE); } while(0)
#define LED_1_FLASH()  do { LEDManager_SetLEDState(mLed_1, FLASH_MODE); } while(0)

#define LED_2_ON()     do { LEDManager_SetLEDState(mLed_2, ON_MODE); } while(0)
#define LED_2_OFF()    do { LEDManager_SetLEDState(mLed_2, OFF_MODE); } while(0)
#define LED_2_FLASH()  do { LEDManager_SetLEDState(mLed_2, FLASH_MODE); } while(0)

#define LED_3_ON()     do { LEDManager_SetLEDState(mLed_3, ON_MODE); } while(0)
#define LED_3_OFF()    do { LEDManager_SetLEDState(mLed_3, OFF_MODE); } while(0)
#define LED_3_FLASH()  do { LEDManager_SetLEDState(mLed_3, FLASH_MODE); } while(0)

#define LED_4_ON()     do { LEDManager_SetLEDState(mLed_4, ON_MODE); } while(0)
#define LED_4_OFF()    do { LEDManager_SetLEDState(mLed_4, OFF_MODE); } while(0)
#define LED_4_FLASH()  do { LEDManager_SetLEDState(mLed_4, FLASH_MODE); } while(0)

#define LED_12V_ON()     do { LEDManager_SetLEDState(mLed_12V, ON_MODE); } while(0)
#define LED_12V_OFF()    do { LEDManager_SetLEDState(mLed_12V, OFF_MODE); } while(0)
#define LED_12V_FLASH()  do { LEDManager_SetLEDState(mLed_12V, FLASH_MODE); } while(0)

#define LED_SYS_ON()     do { LEDManager_SetLEDState(mLed_Common, ON_MODE); } while(0)
#define LED_SYS_OFF()    do { LEDManager_SetLEDState(mLed_Common, OFF_MODE); } while(0)
#define LED_SYS_FLASH()  do { LEDManager_SetLEDState(mLed_Common, FLASH_MODE); } while(0)

void LEDManager_Initialize(void);
void LEDManager_MainLoop(void);
void LEDManager_SetLEDState(enum mLED_names name, unsigned char states);
unsigned char LEDManager_GetLEDCommon(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MLED_H */

