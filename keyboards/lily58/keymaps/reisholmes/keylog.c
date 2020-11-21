#include "layers.h"

// Define our range for keylogging on master OLED and our right OLED logo
#ifdef OLED_DRIVER_ENABLE
static char     keylog_str[6] = {};
static uint16_t log_timer = 0;
static const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
// Used for OLED timeout
uint16_t oled_timer;
#endif

// Keylogging function used for displaying on master OLED
void add_keylog(uint16_t keycode) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }

  for (uint8_t i = 4; i > 0; --i) {
    keylog_str[i] = keylog_str[i - 1];
  }

  if (keycode < 60) {
    keylog_str[0] = code_to_name[keycode];
  }

  log_timer = timer_read();
}

void update_log(void) {
  if (timer_elapsed(log_timer) > 750) {
    add_keylog(0);
  }
}


// adds keylog and allows layer persistance when switched
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
      add_keylog(keycode);
      oled_timer = timer_read();
    }
  #endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QW);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GA);
      }
      return false;
      break;
    case DIS_MUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_M) SS_UP(X_LSFT) SS_UP(X_LCTL));
      }
      return false;
      break;
    case DIS_DEAF:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_D) SS_UP(X_LSFT) SS_UP(X_LCTL));
      }
      return false;
      break;
  }
  return true;
};
