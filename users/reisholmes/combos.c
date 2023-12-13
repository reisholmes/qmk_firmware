const uint16_t PROGMEM esc[]         = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM singlequote[] = {RCTL_T(KC_L), RSFT_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM minus[]       = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM backslash[]   = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
	COMBO(esc, KC_ESC),
	COMBO(singlequote, KC_QUOT),
	COMBO(minus, KC_MINS),
	COMBO(backslash, KC_BSLS),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);