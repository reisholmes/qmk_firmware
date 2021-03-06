#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  CUSTOM_MACRO_WORDSELECT,
  CUSTOM_MACRO_LINESELECT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

/* Keymap 1: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  1   |  2   |   3  |   4  |  5   | LALT(F4) |   | LCTL(F5) |  6   |   7  |   8  |   9  |   0  |  MINS  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |  TG1 |           |  TG2 |   Y  |  U   |   I  |  O   |  P   |  NUHS  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |  L   |   ;  |   ENT  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LSFT  |   Z  |   X  |   C  |   V  |   B  | OSL1 |           |  MO1 |   N  |   M  | COMM |  DOT | SLSH |  LSFT  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTL(GRV) | ALT(QUOT) | LGUI | UP  | DOWN |                            |LEFT | RIGHT |  LBRC  | RBRV |  APP |
 *   `------------------------------------------'                              `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | PMNS | PPLS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PGUP |       | EQL  |      |      |
 *                                 |  ENT | DEL  |------|       |------| BSPC | SPC  |
 *                                 |      |      | PGDN |       | BSLS |      |      |
 *                                 `--------------------'       `--------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_F4,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(1),
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, OSL(1),
           LCTL_T(KC_GRV), LALT_T(KC_QUOT), KC_LGUI, KC_UP, KC_DOWN,
						KC_HOME, KC_END,
										KC_PGUP,
					    KC_ENT, KC_DEL, KC_PGDN,
        // right hand
        KC_F5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        TG(2), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NUHS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        MO(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
            KC_LEFT, KC_RIGHT, KC_LBRC, KC_RBRC, KC_APP,
						KC_PMNS, KC_PPLS,
										KC_EQL,
						KC_BSLS, KC_BSPC, KC_SPC
    ),

/* Keymap 1: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  | LALT(F4) |   | LCTL(F5) |  F6  |  F7  |  F8  |  F9  | F10  |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  PLAY  | EXLM |  @   | LCBR | RCBR | PIPE |      |           |      |  UP  |  7   |   8  |   9  |  *   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  NEXT  | HASH |  DLR | LPRN | RPRN |  GRV |------|           |------| DOWN |  4   |   5  |   6  | PMNS |   ENT  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LSFT  | PERC | CIRC | LBRC | RBRC | TILD |      |           |      | AMPR |   1  |   2  |   3  | PPLS |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ____ | LOCK | CUT  | COPY | PSTE |                                       | PSLS |  DOT |   0  | PEQL |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SWRD | SLNE |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox( // layer 1 : symbols
       // left hand
       KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, LALT(KC_F4),
       KC_MPLY, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
	   KC_MNXT, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,
	   KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
			KC_TRNS, LGUI(KC_L), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),
						CUSTOM_MACRO_WORDSELECT, CUSTOM_MACRO_LINESELECT,
									KC_TRNS,
						KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       LCTL(KC_F5), KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
       KC_TRNS, KC_UP, KC_7, KC_8, KC_9, KC_PAST, KC_F12,
	   KC_DOWN, KC_4, KC_5, KC_6, KC_PMNS, KC_ENT,
       KC_TRNS, KC_AMPR, KC_1, KC_2, KC_3, KC_PPLS, KC_TRNS,
            KC_PSLS, KC_DOT, KC_0, KC_PEQL, KC_TRNS,
       						KC_TRNS, KC_TRNS,
									KC_TRNS,
						KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	// word select
	  case CUSTOM_MACRO_WORDSELECT:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LCTRL));
          layer_off(SYMB);
        }
        return false;
        break;
	// word select
	  case CUSTOM_MACRO_LINESELECT:
		if (record->event.pressed) {
		  SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_UP(X_LSHIFT));
		  layer_off(SYMB);
		}
		return false;
		break;
    // dynamically generate these. Currently not used
      case EPRM:
        if (record->event.pressed)
        {
          eeconfig_init();
        }
        return false;
        break;
      case VRSN:
        if (record->event.pressed)
        {
          SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        return false;
        break;
      case RGB_SLD:
        if (record->event.pressed)
        {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

//CapsLock Light
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
