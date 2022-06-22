/* 
 * File:   mUV.h
 * Author: KaoChihChien
 *
 * Created on May 21, 2021, 11:25 AM
 */

#ifndef MUV_H
#define	MUV_H

#ifdef	__cplusplus
extern "C" {
#endif

    void mUV_Timer(void);
    void mUV_Loop(void);
    void mUV_Initialize(uint8_t hasHot);
    uint8_t mUV_CK_Error(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MUV_H */

