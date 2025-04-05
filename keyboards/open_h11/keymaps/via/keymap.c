#include QMK_KEYBOARD_H
#include "lib/layer_status/layer_status.h"
 enum layer_names {
     DJMAX,
 };
 
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [DJMAX] = LAYOUT(
    KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J,
    QK_BOOT, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_V, KC_W, KC_X, KC_Y, KC_Z
  )
  
 
 
 };
 
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_layer_status();

    return true;
}
#endif