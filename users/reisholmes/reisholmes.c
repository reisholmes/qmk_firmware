#include "reisholmes.h"

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_GRV):
            return TAPPING_TERM - 20;
        case LSFT_T(KC_A):
            return TAPPING_TERM - 20;
        case RSFT_T(KC_SCLN):
            return TAPPING_TERM - 20;
        default:
            // Increase for tap hold macros
            return ((keycode & 0xFF00) == LT0_MASK) ? TAPPING_TERM + 80 : TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Disable for home row mods
    return ((keycode & 0xF000) == LMOD_T_MASK) ? false : true;
}
#endif

#ifdef ENCODER_ENABLE
// https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
// layer state examples too: https://github.com/HanSolo71/qmk_firmware/blob/master/keyboards/keebio/quefrency/keymaps/MyKeymap/keymap.c
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
	#if defined(KEYBOARD_cisne|KEYBOARD_kiserdesigns_madeline)
		if (index != 0) return 1;

		int cur_layer = biton32(layer_state);
		if (cur_layer == 3) {
			if (clockwise) {
				if (!is_alt_tab_active) {
					is_alt_tab_active = true;
					register_code(KC_LALT);
				}
				alt_tab_timer = timer_read();
				tap_code16(KC_TAB);
			} else {
				if (!is_alt_tab_active) {
					is_alt_tab_active = true;
					register_code(KC_LALT);
				}
				alt_tab_timer = timer_read();
				tap_code16(S(KC_TAB));
			}
			return false;
		} 
		else if (cur_layer == 2) {
			clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
		}
		else {
			clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
		}
   		return 1;

	#else
		if (clockwise) {
			if (!is_alt_tab_active) {
				is_alt_tab_active = true;
				register_code(KC_LALT);
			}
			alt_tab_timer = timer_read();
			tap_code16(KC_TAB);
		} else {
			if (!is_alt_tab_active) {
				is_alt_tab_active = true;
				register_code(KC_LALT);
			}
			alt_tab_timer = timer_read();
			tap_code16(S(KC_TAB));
		}
		return false;
	#endif
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1250) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}
#endif