/* 
 * File:   mBZ.h
 * Author: KaoChihChien
 *
 * Created on 2021?3?4?, ?? 8:30
 */

#ifndef MBZ_H
#define	MBZ_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/nco1.h"

#define BZ NCO1CONbits.N1EN

    void BZ_user_pushKey(unsigned int ms);
    void BZ_user_relockKey(void);

    void BZ_InitializeAll(void);
    void BZ_MainLoop(void);
    void BZ_RunSet(unsigned char setCount, unsigned int setTime);
    void BZ_release(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* MBZ_H */

