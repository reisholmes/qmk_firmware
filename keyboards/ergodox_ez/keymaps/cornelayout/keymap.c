#include QMK_KEYBOARD_H
#include "version.h"

// Layers
#define _BASE 0
#define _LO 1
#define _RA 2


enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

// Mod-Taps
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
#define LST(X) LSFT_T(X)
#define RST(X) RSFT_T(X)
#define LCT(X) LCTL_T(X)
#define RCT(X) RCTL_T(X)
#define LGT(X) LGUI_T(X)
#define RGT(X) RGUI_T(X)
#define TAT(X) LALT_T(X)
#define AGT(X) RALT_T(X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   [    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  `/SFT |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '/SFT |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | -/LCTR |Z/LGUI|X/LALT|   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |./LALT|/_RGUI| =/RCTR |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |  Esc | Tab  |                                       |  DEL |   \  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Bspc/|      |------|       |------|        |Spc/Up|
 *                                 | Lo   |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  // left hand
  _______,        _______,    _______,  _______,  _______,  _______,     _______,              _______,  _______,  _______,  _______,     _______,  _______,  _______,
  KC_LBRC,           KC_Q,       KC_W,     KC_E,     KC_R,     KC_T,     _______,              _______,     KC_Y,     KC_U,     KC_I,        KC_O,     KC_P,      KC_RBRC,
  LST(KC_GRV),       KC_A,       KC_S,  KC_D,        KC_F,     KC_G,                                        KC_H,     KC_J,     KC_K,        KC_L,  KC_SCLN,      RST(KC_QUOT),
  LCT(KC_MINS), LGT(KC_Z),  TAT(KC_X),  KC_C,        KC_V,     KC_B,     _______,              _______,     KC_N,     KC_M,  KC_COMM, TAT(KC_DOT),  RGT(KC_SLSH), RCT(KC_EQL),
  _______,         ______,   ________,  LT_ESC,    KC_TAB,                                                 S_DEL,  KC_BSLS,  _______, _______, _______,
                                                                  _______, _______,                _______, _______,
                                                                           _______,                _______,
                                                          LT_BSPC, _______, _______,               _______, _______, LT_SPC,
),
/* Lower
   * ,-------------------------------------------------.           ,-----------------------------------------------.
   * |        |      |      |      |      |    |      |           |      |      |      |      |      |      |      |
   * |--------+------+------+------+------+-----------|           |------+------+------+------+------+------+------|
   * |Vol Up|  Esc | Copy | W_Up |  CUT | PASTE|      |           |      | PgUp |M_Btn1| M_Up |M_Btn2|M_Btn3| Next |
   * |------+------+------+------+------+------|      |           |-------------+------+------+------+------|------|
   * |Vol Do|  Tab | W_Le | W_Do | W_Ri |M_Btn3|------|           |      | Home | M_Le | M_Do | M_Ri | End  | Prev |
   * |------+------+------+------+------+------|      |           |      |-------------+------+------+------+------|
   * | Mute | Ctrl | Shift| Gui  |M_Btn1|M_Btn2|      |           |      | PgDN | Left | Down |  Up  | Rght | Play |
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  DEL |   \  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |  Ent |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [_LO] = LAYOUT (
    _______, _______, _______, _______, _______, _______,     _______,                  _______, _______, _______, _______, _______, _______, _______,
    KC_VOLU, KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,       _______,                  _______, KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_MNXT, \
    KC_VOLD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3,                                        KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  KC_MPRV, \
    KC_MUTE, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2,     _______,                  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, \
    _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
                                                              _______,  _______,    _______, _______,
                                                                        _______,    _______,
                                                      _______, _______, _______,    _______, _______, KC_ENT \
  ),
  /* Raise

   * ,-------------------------------------------------.           ,-----------------------------------------------.
   * |        |      |      |      |      |    |      |           |      |      |      |      |      |      |      |
   * |--------+------+------+------+------+-----------|           |------+------+------+------+------+------+------|
   * |   |  |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |------+------+------+------+------+------|      |           |-------------+------+------+------+------|------|
   * |   .  |   1  |   2  |   3  |   4  |   5  |------|           |      |   6  |   7  |   8  |   9  |   0  |   ,  |
   * |------+------+------+------+------+------|      |           |      |-------------+------+------+------+------|
   * |  F11 |  F1 |  F2   |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                     |  DEL |   \  |      |      |      |
   *   `----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |  Ent |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
   */
  [_RA] = LAYOUT (
    _______, _______, _______, _______, _______, _______,     _______,         _______, _______, _______, _______, _______, _______, _______,
    KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,       _______,         _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_DOT,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COMM, \
    KC_F11,  KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,         _______,         _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
                                                    _______,  _______,        _______, _______,
                                                              _______,        _______,
                                             KC_ENT, _______, _______,        _______, _______, _______, \


  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
