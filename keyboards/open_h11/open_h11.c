#include "quantum.h"

// OLED animation
#include "lib/logo.h"

#ifdef DEBUG
#include "print.h"
#endif
#ifdef OLED_ENABLE


    static uint16_t last_oled_timer;
    static bool first_run = true;

    bool oled_task_kb(void) {
        if (first_run) {
            last_oled_timer= timer_read();
            first_run = false;
            render_logo();
            return true;
        }
        else if ( oled_task_user()){
            last_oled_timer= timer_read();
            return true;
        }

        uint16_t elapsed = timer_elapsed(last_oled_timer);
        if (elapsed < OLED_TIMEOUT)  {
            uint8_t brightness = ( (uint8_t)(OLED_BRIGHTNESS* (1.0 - (float)elapsed / (float)OLED_TIMEOUT)));
            oled_set_brightness( brightness);
            return true;
        } else {
            oled_off();
        }
        return false;
    }
#endif
