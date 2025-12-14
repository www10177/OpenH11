// Keyboard code - minimal overhead
// Raw HID removed. OLED layer logos handled in keymap.c

#include "quantum.h"

#ifdef DEBUG
#include "print.h"
#endif

// Force dynamic keymap to reload from compiled keymap on EEPROM init
void eeconfig_init_kb(void) {
    eeconfig_init_user();
}

// Note: OLED rendering is handled by oled_task_user() in keymap.c
// which displays layer-specific logos
