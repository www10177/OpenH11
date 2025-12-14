#pragma once

// OLED config - 30 second timeout, with logo and layer display
// Raw HID (host-side layer detection) is disabled for lower latency
#define OLED_FONT_H "./lib/glcdfont.c"
#ifdef OLED_ENABLE
    /* Mapping I2C2 for OLED */
    #define I2C1_SCL_PIN B10
    #define I2C1_SDA_PIN B11
    #define I2C_DRIVER I2CD2
    #define OLED_TIMEOUT 30000  // 30 seconds
#endif

// #define DEBUG_MATRIX_SCAN_RATE
// #define DEBUG