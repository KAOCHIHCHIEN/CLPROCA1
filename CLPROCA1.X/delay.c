#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include <stdint.h>

void delay_1ms(uint16_t milliseconds) {
    while (milliseconds--) {
        CLRWDT();
        __delay_ms(1);
    }
}
