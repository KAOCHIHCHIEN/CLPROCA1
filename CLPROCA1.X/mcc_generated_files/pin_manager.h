/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F15386
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TS_5V aliases
#define TS_5V_TRIS                 TRISAbits.TRISA0
#define TS_5V_LAT                  LATAbits.LATA0
#define TS_5V_PORT                 PORTAbits.RA0
#define TS_5V_WPU                  WPUAbits.WPUA0
#define TS_5V_OD                   ODCONAbits.ODCA0
#define TS_5V_ANS                  ANSELAbits.ANSA0
#define TS_5V_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TS_5V_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TS_5V_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TS_5V_GetValue()           PORTAbits.RA0
#define TS_5V_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TS_5V_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TS_5V_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define TS_5V_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define TS_5V_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define TS_5V_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define TS_5V_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TS_5V_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set HotLock_Touch aliases
#define HotLock_Touch_TRIS                 TRISAbits.TRISA1
#define HotLock_Touch_LAT                  LATAbits.LATA1
#define HotLock_Touch_PORT                 PORTAbits.RA1
#define HotLock_Touch_WPU                  WPUAbits.WPUA1
#define HotLock_Touch_OD                   ODCONAbits.ODCA1
#define HotLock_Touch_ANS                  ANSELAbits.ANSA1
#define HotLock_Touch_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define HotLock_Touch_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define HotLock_Touch_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define HotLock_Touch_GetValue()           PORTAbits.RA1
#define HotLock_Touch_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define HotLock_Touch_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define HotLock_Touch_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define HotLock_Touch_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define HotLock_Touch_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define HotLock_Touch_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define HotLock_Touch_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define HotLock_Touch_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TSLED aliases
#define TSLED_TRIS                 TRISAbits.TRISA2
#define TSLED_LAT                  LATAbits.LATA2
#define TSLED_PORT                 PORTAbits.RA2
#define TSLED_WPU                  WPUAbits.WPUA2
#define TSLED_OD                   ODCONAbits.ODCA2
#define TSLED_ANS                  ANSELAbits.ANSA2
#define TSLED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define TSLED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define TSLED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define TSLED_GetValue()           PORTAbits.RA2
#define TSLED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define TSLED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define TSLED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define TSLED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define TSLED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define TSLED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define TSLED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define TSLED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set UV_CK_MCU aliases
#define UV_CK_MCU_TRIS                 TRISAbits.TRISA3
#define UV_CK_MCU_LAT                  LATAbits.LATA3
#define UV_CK_MCU_PORT                 PORTAbits.RA3
#define UV_CK_MCU_WPU                  WPUAbits.WPUA3
#define UV_CK_MCU_OD                   ODCONAbits.ODCA3
#define UV_CK_MCU_ANS                  ANSELAbits.ANSA3
#define UV_CK_MCU_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define UV_CK_MCU_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define UV_CK_MCU_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define UV_CK_MCU_GetValue()           PORTAbits.RA3
#define UV_CK_MCU_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define UV_CK_MCU_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define UV_CK_MCU_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define UV_CK_MCU_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define UV_CK_MCU_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define UV_CK_MCU_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define UV_CK_MCU_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define UV_CK_MCU_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set UVS_MCU aliases
#define UVS_MCU_TRIS                 TRISAbits.TRISA4
#define UVS_MCU_LAT                  LATAbits.LATA4
#define UVS_MCU_PORT                 PORTAbits.RA4
#define UVS_MCU_WPU                  WPUAbits.WPUA4
#define UVS_MCU_OD                   ODCONAbits.ODCA4
#define UVS_MCU_ANS                  ANSELAbits.ANSA4
#define UVS_MCU_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define UVS_MCU_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define UVS_MCU_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define UVS_MCU_GetValue()           PORTAbits.RA4
#define UVS_MCU_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define UVS_MCU_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define UVS_MCU_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define UVS_MCU_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define UVS_MCU_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define UVS_MCU_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define UVS_MCU_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define UVS_MCU_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA5
#define LED3_LAT                  LATAbits.LATA5
#define LED3_PORT                 PORTAbits.RA5
#define LED3_WPU                  WPUAbits.WPUA5
#define LED3_OD                   ODCONAbits.ODCA5
#define LED3_ANS                  ANSELAbits.ANSA5
#define LED3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED3_GetValue()           PORTAbits.RA5
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set WM2_MCU aliases
#define WM2_MCU_TRIS                 TRISAbits.TRISA6
#define WM2_MCU_LAT                  LATAbits.LATA6
#define WM2_MCU_PORT                 PORTAbits.RA6
#define WM2_MCU_WPU                  WPUAbits.WPUA6
#define WM2_MCU_OD                   ODCONAbits.ODCA6
#define WM2_MCU_ANS                  ANSELAbits.ANSA6
#define WM2_MCU_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define WM2_MCU_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define WM2_MCU_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define WM2_MCU_GetValue()           PORTAbits.RA6
#define WM2_MCU_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define WM2_MCU_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define WM2_MCU_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define WM2_MCU_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define WM2_MCU_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define WM2_MCU_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define WM2_MCU_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define WM2_MCU_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set WM1_MCU aliases
#define WM1_MCU_TRIS                 TRISAbits.TRISA7
#define WM1_MCU_LAT                  LATAbits.LATA7
#define WM1_MCU_PORT                 PORTAbits.RA7
#define WM1_MCU_WPU                  WPUAbits.WPUA7
#define WM1_MCU_OD                   ODCONAbits.ODCA7
#define WM1_MCU_ANS                  ANSELAbits.ANSA7
#define WM1_MCU_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define WM1_MCU_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define WM1_MCU_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define WM1_MCU_GetValue()           PORTAbits.RA7
#define WM1_MCU_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define WM1_MCU_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define WM1_MCU_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define WM1_MCU_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define WM1_MCU_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define WM1_MCU_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define WM1_MCU_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define WM1_MCU_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set Cold_Touch aliases
#define Cold_Touch_TRIS                 TRISBbits.TRISB0
#define Cold_Touch_LAT                  LATBbits.LATB0
#define Cold_Touch_PORT                 PORTBbits.RB0
#define Cold_Touch_WPU                  WPUBbits.WPUB0
#define Cold_Touch_OD                   ODCONBbits.ODCB0
#define Cold_Touch_ANS                  ANSELBbits.ANSB0
#define Cold_Touch_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define Cold_Touch_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define Cold_Touch_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define Cold_Touch_GetValue()           PORTBbits.RB0
#define Cold_Touch_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define Cold_Touch_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define Cold_Touch_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define Cold_Touch_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define Cold_Touch_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define Cold_Touch_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define Cold_Touch_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define Cold_Touch_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set Hot_Touch aliases
#define Hot_Touch_TRIS                 TRISBbits.TRISB1
#define Hot_Touch_LAT                  LATBbits.LATB1
#define Hot_Touch_PORT                 PORTBbits.RB1
#define Hot_Touch_WPU                  WPUBbits.WPUB1
#define Hot_Touch_OD                   ODCONBbits.ODCB1
#define Hot_Touch_ANS                  ANSELBbits.ANSB1
#define Hot_Touch_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define Hot_Touch_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define Hot_Touch_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define Hot_Touch_GetValue()           PORTBbits.RB1
#define Hot_Touch_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define Hot_Touch_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define Hot_Touch_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define Hot_Touch_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define Hot_Touch_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define Hot_Touch_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define Hot_Touch_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define Hot_Touch_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set Warm_Touch aliases
#define Warm_Touch_TRIS                 TRISBbits.TRISB2
#define Warm_Touch_LAT                  LATBbits.LATB2
#define Warm_Touch_PORT                 PORTBbits.RB2
#define Warm_Touch_WPU                  WPUBbits.WPUB2
#define Warm_Touch_OD                   ODCONBbits.ODCB2
#define Warm_Touch_ANS                  ANSELBbits.ANSB2
#define Warm_Touch_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define Warm_Touch_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define Warm_Touch_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define Warm_Touch_GetValue()           PORTBbits.RB2
#define Warm_Touch_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define Warm_Touch_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define Warm_Touch_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define Warm_Touch_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define Warm_Touch_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define Warm_Touch_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define Warm_Touch_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define Warm_Touch_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set CSET2 aliases
#define CSET2_TRIS                 TRISBbits.TRISB3
#define CSET2_LAT                  LATBbits.LATB3
#define CSET2_PORT                 PORTBbits.RB3
#define CSET2_WPU                  WPUBbits.WPUB3
#define CSET2_OD                   ODCONBbits.ODCB3
#define CSET2_ANS                  ANSELBbits.ANSB3
#define CSET2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define CSET2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define CSET2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define CSET2_GetValue()           PORTBbits.RB3
#define CSET2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define CSET2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define CSET2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define CSET2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define CSET2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define CSET2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define CSET2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define CSET2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LED12V aliases
#define LED12V_TRIS                 TRISBbits.TRISB5
#define LED12V_LAT                  LATBbits.LATB5
#define LED12V_PORT                 PORTBbits.RB5
#define LED12V_WPU                  WPUBbits.WPUB5
#define LED12V_OD                   ODCONBbits.ODCB5
#define LED12V_ANS                  ANSELBbits.ANSB5
#define LED12V_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LED12V_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LED12V_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LED12V_GetValue()           PORTBbits.RB5
#define LED12V_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LED12V_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LED12V_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LED12V_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LED12V_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define LED12V_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define LED12V_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LED12V_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISBbits.TRISB6
#define LED4_LAT                  LATBbits.LATB6
#define LED4_PORT                 PORTBbits.RB6
#define LED4_WPU                  WPUBbits.WPUB6
#define LED4_OD                   ODCONBbits.ODCB6
#define LED4_ANS                  ANSELBbits.ANSB6
#define LED4_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LED4_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LED4_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LED4_GetValue()           PORTBbits.RB6
#define LED4_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define LED4_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set WH1_MCU aliases
#define WH1_MCU_TRIS                 TRISCbits.TRISC0
#define WH1_MCU_LAT                  LATCbits.LATC0
#define WH1_MCU_PORT                 PORTCbits.RC0
#define WH1_MCU_WPU                  WPUCbits.WPUC0
#define WH1_MCU_OD                   ODCONCbits.ODCC0
#define WH1_MCU_ANS                  ANSELCbits.ANSC0
#define WH1_MCU_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define WH1_MCU_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define WH1_MCU_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define WH1_MCU_GetValue()           PORTCbits.RC0
#define WH1_MCU_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define WH1_MCU_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define WH1_MCU_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define WH1_MCU_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define WH1_MCU_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define WH1_MCU_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define WH1_MCU_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define WH1_MCU_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set FULL_MCU aliases
#define FULL_MCU_TRIS                 TRISCbits.TRISC1
#define FULL_MCU_LAT                  LATCbits.LATC1
#define FULL_MCU_PORT                 PORTCbits.RC1
#define FULL_MCU_WPU                  WPUCbits.WPUC1
#define FULL_MCU_OD                   ODCONCbits.ODCC1
#define FULL_MCU_ANS                  ANSELCbits.ANSC1
#define FULL_MCU_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define FULL_MCU_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define FULL_MCU_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define FULL_MCU_GetValue()           PORTCbits.RC1
#define FULL_MCU_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define FULL_MCU_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define FULL_MCU_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define FULL_MCU_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define FULL_MCU_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define FULL_MCU_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define FULL_MCU_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define FULL_MCU_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set AllOnOff aliases
#define AllOnOff_TRIS                 TRISCbits.TRISC2
#define AllOnOff_LAT                  LATCbits.LATC2
#define AllOnOff_PORT                 PORTCbits.RC2
#define AllOnOff_WPU                  WPUCbits.WPUC2
#define AllOnOff_OD                   ODCONCbits.ODCC2
#define AllOnOff_ANS                  ANSELCbits.ANSC2
#define AllOnOff_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define AllOnOff_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define AllOnOff_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define AllOnOff_GetValue()           PORTCbits.RC2
#define AllOnOff_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define AllOnOff_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define AllOnOff_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define AllOnOff_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define AllOnOff_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define AllOnOff_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define AllOnOff_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define AllOnOff_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set HotWaterOut aliases
#define HotWaterOut_TRIS                 TRISCbits.TRISC3
#define HotWaterOut_LAT                  LATCbits.LATC3
#define HotWaterOut_PORT                 PORTCbits.RC3
#define HotWaterOut_WPU                  WPUCbits.WPUC3
#define HotWaterOut_OD                   ODCONCbits.ODCC3
#define HotWaterOut_ANS                  ANSELCbits.ANSC3
#define HotWaterOut_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define HotWaterOut_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define HotWaterOut_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define HotWaterOut_GetValue()           PORTCbits.RC3
#define HotWaterOut_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define HotWaterOut_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define HotWaterOut_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define HotWaterOut_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define HotWaterOut_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define HotWaterOut_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define HotWaterOut_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define HotWaterOut_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set AC1_MCU aliases
#define AC1_MCU_TRIS                 TRISCbits.TRISC4
#define AC1_MCU_LAT                  LATCbits.LATC4
#define AC1_MCU_PORT                 PORTCbits.RC4
#define AC1_MCU_WPU                  WPUCbits.WPUC4
#define AC1_MCU_OD                   ODCONCbits.ODCC4
#define AC1_MCU_ANS                  ANSELCbits.ANSC4
#define AC1_MCU_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define AC1_MCU_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define AC1_MCU_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define AC1_MCU_GetValue()           PORTCbits.RC4
#define AC1_MCU_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define AC1_MCU_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define AC1_MCU_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define AC1_MCU_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define AC1_MCU_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define AC1_MCU_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define AC1_MCU_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define AC1_MCU_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set AC2_MCU aliases
#define AC2_MCU_TRIS                 TRISCbits.TRISC5
#define AC2_MCU_LAT                  LATCbits.LATC5
#define AC2_MCU_PORT                 PORTCbits.RC5
#define AC2_MCU_WPU                  WPUCbits.WPUC5
#define AC2_MCU_OD                   ODCONCbits.ODCC5
#define AC2_MCU_ANS                  ANSELCbits.ANSC5
#define AC2_MCU_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define AC2_MCU_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define AC2_MCU_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define AC2_MCU_GetValue()           PORTCbits.RC5
#define AC2_MCU_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define AC2_MCU_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define AC2_MCU_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define AC2_MCU_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define AC2_MCU_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define AC2_MCU_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define AC2_MCU_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define AC2_MCU_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set AC3_MCU aliases
#define AC3_MCU_TRIS                 TRISCbits.TRISC6
#define AC3_MCU_LAT                  LATCbits.LATC6
#define AC3_MCU_PORT                 PORTCbits.RC6
#define AC3_MCU_WPU                  WPUCbits.WPUC6
#define AC3_MCU_OD                   ODCONCbits.ODCC6
#define AC3_MCU_ANS                  ANSELCbits.ANSC6
#define AC3_MCU_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define AC3_MCU_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define AC3_MCU_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define AC3_MCU_GetValue()           PORTCbits.RC6
#define AC3_MCU_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define AC3_MCU_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define AC3_MCU_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define AC3_MCU_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define AC3_MCU_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define AC3_MCU_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define AC3_MCU_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define AC3_MCU_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set AC4_MCU aliases
#define AC4_MCU_TRIS                 TRISCbits.TRISC7
#define AC4_MCU_LAT                  LATCbits.LATC7
#define AC4_MCU_PORT                 PORTCbits.RC7
#define AC4_MCU_WPU                  WPUCbits.WPUC7
#define AC4_MCU_OD                   ODCONCbits.ODCC7
#define AC4_MCU_ANS                  ANSELCbits.ANSC7
#define AC4_MCU_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define AC4_MCU_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define AC4_MCU_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define AC4_MCU_GetValue()           PORTCbits.RC7
#define AC4_MCU_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define AC4_MCU_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define AC4_MCU_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define AC4_MCU_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define AC4_MCU_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define AC4_MCU_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define AC4_MCU_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define AC4_MCU_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set ColdWaterOut aliases
#define ColdWaterOut_TRIS                 TRISDbits.TRISD0
#define ColdWaterOut_LAT                  LATDbits.LATD0
#define ColdWaterOut_PORT                 PORTDbits.RD0
#define ColdWaterOut_WPU                  WPUDbits.WPUD0
#define ColdWaterOut_OD                   ODCONDbits.ODCD0
#define ColdWaterOut_ANS                  ANSELDbits.ANSD0
#define ColdWaterOut_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define ColdWaterOut_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define ColdWaterOut_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define ColdWaterOut_GetValue()           PORTDbits.RD0
#define ColdWaterOut_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define ColdWaterOut_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define ColdWaterOut_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define ColdWaterOut_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define ColdWaterOut_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define ColdWaterOut_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define ColdWaterOut_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define ColdWaterOut_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set WarmWaterOut aliases
#define WarmWaterOut_TRIS                 TRISDbits.TRISD1
#define WarmWaterOut_LAT                  LATDbits.LATD1
#define WarmWaterOut_PORT                 PORTDbits.RD1
#define WarmWaterOut_WPU                  WPUDbits.WPUD1
#define WarmWaterOut_OD                   ODCONDbits.ODCD1
#define WarmWaterOut_ANS                  ANSELDbits.ANSD1
#define WarmWaterOut_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define WarmWaterOut_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define WarmWaterOut_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define WarmWaterOut_GetValue()           PORTDbits.RD1
#define WarmWaterOut_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define WarmWaterOut_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define WarmWaterOut_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define WarmWaterOut_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define WarmWaterOut_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define WarmWaterOut_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define WarmWaterOut_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define WarmWaterOut_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set SyncWaterOut aliases
#define SyncWaterOut_TRIS                 TRISDbits.TRISD2
#define SyncWaterOut_LAT                  LATDbits.LATD2
#define SyncWaterOut_PORT                 PORTDbits.RD2
#define SyncWaterOut_WPU                  WPUDbits.WPUD2
#define SyncWaterOut_OD                   ODCONDbits.ODCD2
#define SyncWaterOut_ANS                  ANSELDbits.ANSD2
#define SyncWaterOut_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define SyncWaterOut_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define SyncWaterOut_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define SyncWaterOut_GetValue()           PORTDbits.RD2
#define SyncWaterOut_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define SyncWaterOut_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define SyncWaterOut_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define SyncWaterOut_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define SyncWaterOut_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define SyncWaterOut_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define SyncWaterOut_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define SyncWaterOut_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set MDWaterOut aliases
#define MDWaterOut_TRIS                 TRISDbits.TRISD3
#define MDWaterOut_LAT                  LATDbits.LATD3
#define MDWaterOut_PORT                 PORTDbits.RD3
#define MDWaterOut_WPU                  WPUDbits.WPUD3
#define MDWaterOut_OD                   ODCONDbits.ODCD3
#define MDWaterOut_ANS                  ANSELDbits.ANSD3
#define MDWaterOut_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define MDWaterOut_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define MDWaterOut_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define MDWaterOut_GetValue()           PORTDbits.RD3
#define MDWaterOut_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define MDWaterOut_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define MDWaterOut_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define MDWaterOut_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define MDWaterOut_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define MDWaterOut_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define MDWaterOut_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define MDWaterOut_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set AC5_MCU aliases
#define AC5_MCU_TRIS                 TRISDbits.TRISD4
#define AC5_MCU_LAT                  LATDbits.LATD4
#define AC5_MCU_PORT                 PORTDbits.RD4
#define AC5_MCU_WPU                  WPUDbits.WPUD4
#define AC5_MCU_OD                   ODCONDbits.ODCD4
#define AC5_MCU_ANS                  ANSELDbits.ANSD4
#define AC5_MCU_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define AC5_MCU_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define AC5_MCU_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define AC5_MCU_GetValue()           PORTDbits.RD4
#define AC5_MCU_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define AC5_MCU_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define AC5_MCU_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define AC5_MCU_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define AC5_MCU_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define AC5_MCU_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define AC5_MCU_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define AC5_MCU_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set CSET3 aliases
#define CSET3_TRIS                 TRISDbits.TRISD5
#define CSET3_LAT                  LATDbits.LATD5
#define CSET3_PORT                 PORTDbits.RD5
#define CSET3_WPU                  WPUDbits.WPUD5
#define CSET3_OD                   ODCONDbits.ODCD5
#define CSET3_ANS                  ANSELDbits.ANSD5
#define CSET3_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define CSET3_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define CSET3_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define CSET3_GetValue()           PORTDbits.RD5
#define CSET3_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define CSET3_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define CSET3_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define CSET3_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define CSET3_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define CSET3_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define CSET3_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define CSET3_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set RSET3 aliases
#define RSET3_TRIS                 TRISDbits.TRISD6
#define RSET3_LAT                  LATDbits.LATD6
#define RSET3_PORT                 PORTDbits.RD6
#define RSET3_WPU                  WPUDbits.WPUD6
#define RSET3_OD                   ODCONDbits.ODCD6
#define RSET3_ANS                  ANSELDbits.ANSD6
#define RSET3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define RSET3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define RSET3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define RSET3_GetValue()           PORTDbits.RD6
#define RSET3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define RSET3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define RSET3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define RSET3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define RSET3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define RSET3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define RSET3_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define RSET3_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set RD7 procedures
#define RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()              PORTDbits.RD7
#define RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define RD7_SetPullup()             do { WPUDbits.WPUD7 = 1; } while(0)
#define RD7_ResetPullup()           do { WPUDbits.WPUD7 = 0; } while(0)
#define RD7_SetAnalogMode()         do { ANSELDbits.ANSD7 = 1; } while(0)
#define RD7_SetDigitalMode()        do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISEbits.TRISE0
#define LED2_LAT                  LATEbits.LATE0
#define LED2_PORT                 PORTEbits.RE0
#define LED2_WPU                  WPUEbits.WPUE0
#define LED2_OD                   ODCONEbits.ODCE0
#define LED2_ANS                  ANSELEbits.ANSE0
#define LED2_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED2_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED2_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED2_GetValue()           PORTEbits.RE0
#define LED2_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED2_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISEbits.TRISE1
#define LED1_LAT                  LATEbits.LATE1
#define LED1_PORT                 PORTEbits.RE1
#define LED1_WPU                  WPUEbits.WPUE1
#define LED1_OD                   ODCONEbits.ODCE1
#define LED1_ANS                  ANSELEbits.ANSE1
#define LED1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LED1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LED1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LED1_GetValue()           PORTEbits.RE1
#define LED1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LED1_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set WH2_MCU aliases
#define WH2_MCU_TRIS                 TRISEbits.TRISE2
#define WH2_MCU_LAT                  LATEbits.LATE2
#define WH2_MCU_PORT                 PORTEbits.RE2
#define WH2_MCU_WPU                  WPUEbits.WPUE2
#define WH2_MCU_OD                   ODCONEbits.ODCE2
#define WH2_MCU_ANS                  ANSELEbits.ANSE2
#define WH2_MCU_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define WH2_MCU_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define WH2_MCU_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define WH2_MCU_GetValue()           PORTEbits.RE2
#define WH2_MCU_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define WH2_MCU_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define WH2_MCU_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define WH2_MCU_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define WH2_MCU_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define WH2_MCU_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define WH2_MCU_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define WH2_MCU_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

// get/set LSS_MCU aliases
#define LSS_MCU_TRIS                 TRISFbits.TRISF0
#define LSS_MCU_LAT                  LATFbits.LATF0
#define LSS_MCU_PORT                 PORTFbits.RF0
#define LSS_MCU_WPU                  WPUFbits.WPUF0
#define LSS_MCU_OD                   ODCONFbits.ODCF0
#define LSS_MCU_ANS                  ANSELFbits.ANSF0
#define LSS_MCU_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define LSS_MCU_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define LSS_MCU_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define LSS_MCU_GetValue()           PORTFbits.RF0
#define LSS_MCU_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define LSS_MCU_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define LSS_MCU_SetPullup()          do { WPUFbits.WPUF0 = 1; } while(0)
#define LSS_MCU_ResetPullup()        do { WPUFbits.WPUF0 = 0; } while(0)
#define LSS_MCU_SetPushPull()        do { ODCONFbits.ODCF0 = 0; } while(0)
#define LSS_MCU_SetOpenDrain()       do { ODCONFbits.ODCF0 = 1; } while(0)
#define LSS_MCU_SetAnalogMode()      do { ANSELFbits.ANSF0 = 1; } while(0)
#define LSS_MCU_SetDigitalMode()     do { ANSELFbits.ANSF0 = 0; } while(0)

// get/set RF1 procedures
#define RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define RF1_GetValue()              PORTFbits.RF1
#define RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define RF1_SetPullup()             do { WPUFbits.WPUF1 = 1; } while(0)
#define RF1_ResetPullup()           do { WPUFbits.WPUF1 = 0; } while(0)
#define RF1_SetAnalogMode()         do { ANSELFbits.ANSF1 = 1; } while(0)
#define RF1_SetDigitalMode()        do { ANSELFbits.ANSF1 = 0; } while(0)

// get/set FAN_ADC aliases
#define FAN_ADC_TRIS                 TRISFbits.TRISF2
#define FAN_ADC_LAT                  LATFbits.LATF2
#define FAN_ADC_PORT                 PORTFbits.RF2
#define FAN_ADC_WPU                  WPUFbits.WPUF2
#define FAN_ADC_OD                   ODCONFbits.ODCF2
#define FAN_ADC_ANS                  ANSELFbits.ANSF2
#define FAN_ADC_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define FAN_ADC_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define FAN_ADC_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define FAN_ADC_GetValue()           PORTFbits.RF2
#define FAN_ADC_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define FAN_ADC_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define FAN_ADC_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define FAN_ADC_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define FAN_ADC_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define FAN_ADC_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define FAN_ADC_SetAnalogMode()      do { ANSELFbits.ANSF2 = 1; } while(0)
#define FAN_ADC_SetDigitalMode()     do { ANSELFbits.ANSF2 = 0; } while(0)

// get/set COM_MCU aliases
#define COM_MCU_TRIS                 TRISFbits.TRISF3
#define COM_MCU_LAT                  LATFbits.LATF3
#define COM_MCU_PORT                 PORTFbits.RF3
#define COM_MCU_WPU                  WPUFbits.WPUF3
#define COM_MCU_OD                   ODCONFbits.ODCF3
#define COM_MCU_ANS                  ANSELFbits.ANSF3
#define COM_MCU_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define COM_MCU_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define COM_MCU_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define COM_MCU_GetValue()           PORTFbits.RF3
#define COM_MCU_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define COM_MCU_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define COM_MCU_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define COM_MCU_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define COM_MCU_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define COM_MCU_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define COM_MCU_SetAnalogMode()      do { ANSELFbits.ANSF3 = 1; } while(0)
#define COM_MCU_SetDigitalMode()     do { ANSELFbits.ANSF3 = 0; } while(0)

// get/set RSET2 aliases
#define RSET2_TRIS                 TRISFbits.TRISF4
#define RSET2_LAT                  LATFbits.LATF4
#define RSET2_PORT                 PORTFbits.RF4
#define RSET2_WPU                  WPUFbits.WPUF4
#define RSET2_OD                   ODCONFbits.ODCF4
#define RSET2_ANS                  ANSELFbits.ANSF4
#define RSET2_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define RSET2_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define RSET2_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define RSET2_GetValue()           PORTFbits.RF4
#define RSET2_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define RSET2_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define RSET2_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define RSET2_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define RSET2_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define RSET2_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define RSET2_SetAnalogMode()      do { ANSELFbits.ANSF4 = 1; } while(0)
#define RSET2_SetDigitalMode()     do { ANSELFbits.ANSF4 = 0; } while(0)

// get/set RSET1 aliases
#define RSET1_TRIS                 TRISFbits.TRISF5
#define RSET1_LAT                  LATFbits.LATF5
#define RSET1_PORT                 PORTFbits.RF5
#define RSET1_WPU                  WPUFbits.WPUF5
#define RSET1_OD                   ODCONFbits.ODCF5
#define RSET1_ANS                  ANSELFbits.ANSF5
#define RSET1_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define RSET1_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define RSET1_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define RSET1_GetValue()           PORTFbits.RF5
#define RSET1_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define RSET1_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define RSET1_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define RSET1_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define RSET1_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define RSET1_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define RSET1_SetAnalogMode()      do { ANSELFbits.ANSF5 = 1; } while(0)
#define RSET1_SetDigitalMode()     do { ANSELFbits.ANSF5 = 0; } while(0)

// get/set CSET1 aliases
#define CSET1_TRIS                 TRISFbits.TRISF6
#define CSET1_LAT                  LATFbits.LATF6
#define CSET1_PORT                 PORTFbits.RF6
#define CSET1_WPU                  WPUFbits.WPUF6
#define CSET1_OD                   ODCONFbits.ODCF6
#define CSET1_ANS                  ANSELFbits.ANSF6
#define CSET1_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define CSET1_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define CSET1_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define CSET1_GetValue()           PORTFbits.RF6
#define CSET1_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define CSET1_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define CSET1_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define CSET1_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define CSET1_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define CSET1_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define CSET1_SetAnalogMode()      do { ANSELFbits.ANSF6 = 1; } while(0)
#define CSET1_SetDigitalMode()     do { ANSELFbits.ANSF6 = 0; } while(0)

// get/set HOT_SW_MCU aliases
#define HOT_SW_MCU_TRIS                 TRISFbits.TRISF7
#define HOT_SW_MCU_LAT                  LATFbits.LATF7
#define HOT_SW_MCU_PORT                 PORTFbits.RF7
#define HOT_SW_MCU_WPU                  WPUFbits.WPUF7
#define HOT_SW_MCU_OD                   ODCONFbits.ODCF7
#define HOT_SW_MCU_ANS                  ANSELFbits.ANSF7
#define HOT_SW_MCU_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define HOT_SW_MCU_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define HOT_SW_MCU_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define HOT_SW_MCU_GetValue()           PORTFbits.RF7
#define HOT_SW_MCU_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define HOT_SW_MCU_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define HOT_SW_MCU_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define HOT_SW_MCU_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define HOT_SW_MCU_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define HOT_SW_MCU_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define HOT_SW_MCU_SetAnalogMode()      do { ANSELFbits.ANSF7 = 1; } while(0)
#define HOT_SW_MCU_SetDigitalMode()     do { ANSELFbits.ANSF7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/