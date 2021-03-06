# Summary
This is my personal *userspace* for [QMK Firmware](https://github.com/qmk/qmk_firmware). It is setup as a self-contained folder that avoids placing `keymap.c` source files deep inside QMK's sub-directories. All customisation required to build firmwares are configured within this space in the following manner:

* Store [QMK Configurator](https://config.qmk.fm/#/) exported layouts or wrapper based macro key map in JSON format.
* Create `rules.mk`, `config.h` and shared source codes in this folder, with `#ifdef` preprocessors for unique keyboard or feature specific functions.
* Run `qmk flash` on JSON layout files to build a custom firmware for each board.
* See my [standalone userspace](https://filterpaper.github.io/qmk/userspace) guide for more details.

## Setup
Clone the QMK firmware, followed by this repository into `users/filterpaper`:
```sh
git clone https://github.com/qmk/qmk_firmware qmk_firmware
git clone https://github.com/filterpaper/qmk_userspace qmk_firmware/users/filterpaper
```

# Supported Keyboards
![corneplanck](https://github.com/filterpaper/filterpaper.github.io/raw/main/images/corneplanck.png)

* [BM40 HS RGB](../../keyboards/bm40hsrgb) — Per-key RGB matrix indicators.
* [Planck rev6](../../keyboards/planck) — RGB underglow layer and modifier indicators.
* [Corne Keyboard (CRKBD)](../../keyboards/crkbd) — Typing animation and graphical indicators on OLEDs.
* [The Mark: 65](../../keyboards/boardsource/the_mark) — RGB underglow layer and modifier indicators.

# File Listing
File | Description
---- | -----------
rules.mk | QMK compile rules and hardware feature selection
config.h | QMK configuration variables and options, see [configuring QMK](../../docs/config_options.md)
filterpaper.h | User specific variables and options
filterpaper.c | Mainj source with macro functions, see [custom quantum functions](../../docs/custom_quantum_functions.md)
rgb-matrix.c | RGB matrix effect and custom codes, see [RGB matrix lighting](../../docs/feature_rgb_matrix.md)
mod-status.c | Graphical layer and modifier status indicators (adds ~4018 bytes)
luna-status.c | Luna and Felix the dog WPM animation and modifier indicators for primary OLED (adds ~6202 bytes)
bongocat.c | Bongocat animation using differential pixels
oledfont.c | Corne logo, コルネ katakana name, fonts and icon images
layout.h | Key map macro wrapper for shared ortholinear and Corne layouts
json/ | Folder of supported keyboard layouts
animation_frames/ | Folder of Bongocat animation images
archive/ | Archived files of original codes and layouts

# Code Snippets
## Light configured layers keys
```c
if (get_highest_layer(layer_state); > COLEMAK) {
    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            if (g_led_config.matrix_co[row][col] != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col, row}) != KC_TRNS) {
                rgb_matrix_set_color(g_led_config.matrix_co[row][col], RGB_LAYER);
            }
        }
    }
}
```
Code loops through every row and column on a per-key RGB board, scanning for configured keys (not `KC_TRANS`) and lighting that index location. It is configured to activate on non-default layers. This can be further customised using layer `switch` condition inside the last `if` statement.

## Tap hold macros
```c
#define W_TH LT(0, KC_W)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case W_TH:
        // Send W on single tap
        if (record->tap.count) {
            if (record->event.pressed) { register_code(KC_W); }
            else { unregister_code(KC_W); }
        // Send macro string on hold
        } else if (record->event.pressed) { SEND_STRING(":wq"); }
        return false;
    }
    return true; // continue with unmatched keycodes
}
```
Tap hold shortcut can be found in QMK's [tap dance feature](../../docs/feature_tap_dance.md) but replicated here inside `process_record_user()` with layer tap (`LT()`) and tapping term delay. It uses less firmware space than `TAP_DANCE_ENABLE` (~35 bytes per macro). Key macro `W_TH` replaces `KC_W` on the key map (`keymap[]`). The `if-else` statements are in a `#define TAP_HOLD(_tap_, _hold_)` macro.

## Caps word
```c
void process_caps_word(uint16_t keycode, keyrecord_t const *record) {
    // Get base key code of mod or layer tap with bitmask
    if (((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX) ||
       (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX)) &&
       (record->tap.count)) { keycode = keycode & 0xFF; }
    // Toggle caps lock with the following key codes
    switch (keycode) {
    case KC_ESC:
    case KC_SPC:
    case KC_ENT:
    case KC_TAB:
    case KC_DOT:
    case KC_COMM:
    case KC_GESC:
        if (record->event.pressed) { tap_code(KC_CAPS); }
    }
}
```
Function is called inside `process_record_user` when caps lock is enabled to turn it off after completing a word—because caps lock is rarely used beyond capitalising one word. The first `switch` statement performs a bitwise *AND* to filter base key codes (that ranges from 0x00-0xFF) from mod/layer taps to support toggle keys on a different layer. Written by the `#ergonomics` enthusiasts of splitkb.com discord.

# Build Commands
QMK will read "keyboard" and "keymap" values from the JSON file to build the firmware:
```sh
qmk flash ~/qmk_firmware/users/filterpaper/json/bm40.json
qmk flash ~/qmk_firmware/users/filterpaper/json/planck.json
qmk flash ~/qmk_firmware/users/filterpaper/json/corne.json
qmk flash ~/qmk_firmware/users/filterpaper/json/mark65.json
```

# Building Corne Keyboard (CRKBD)
## Corne split setup
Corne is configured with EE_HANDS for controllers to read left or right values off EEPROM, allowing USB-C cable to be used on either side. These are one-time flash commands to write left and right handedness bootloader into Elite-C MCUs:
```sh
qmk flash -kb crkbd/rev1/common -km default -bl dfu-split-left
qmk flash -kb crkbd/rev1/common -km default -bl dfu-split-right
```
Subsequently, the same firmware binary can be flashed normally to both sides. See [split keyboard features](../../docs/feature_split_keyboard.md) for details.

## Compiling with OLED display
QMK's split common `transport.c` code limits type of data sent the secondary (non-USB) controller. Animation on the secondary display can only be driven by WPM while keyboard status is limited to modifier state. My code can be built with the following `rules.mk` options:
### Key press driven Bongocat
Default Corne keyboard is built with Bongocat animation on primary display driven by key presses with simple modifier state on secondary OLED:
```
qmk compile corne.json
```
Bongocat code uses spacing-saving pixel differences to animate, with left and right-aligned animation arrays to support `EE_HANDS` configuration. Arrays for one of the sides (and its associated `if-else` statements) can be removed to save additional space.
### WPM driven Bongocat
Keyboard layer and modifier status on primary OLED with Bongocat animation on secondary, driven by WPM:
```
qmk compile -e WPM=yes corne.json
```
### Primary dog status
Luna the dog animation status on primary OLED with Bongocat on secondary, both driven by WPM:
```
qmk compile -e WPM=yes -e DOG=LUNA corne.json
```
White Felix the dog can be built with `DOG=FELIX`.

## Tiny build
Minimal firmware with no OLED support can be built with `TINY=yes` preprocessor:
```
qmk compile -e TINY=yes corne.json
```

## Corne logo file
Images in `glcdfont.c` can be viewed and edited with:
* [Helix Font Editor](https://helixfonteditor.netlify.app/)
* [QMK Logo Editor](https://joric.github.io/qle/)
* [image2cpp](https://javl.github.io/image2cpp/)

# Layout macro wrapper
Text-based layout (in `keymap.c` format) editing is supported with the use of preprocessor macros. Each layer, in text format, is created as a preprocessor macro for viewing and editing inside `layout.h`, example of one layer:
```c
#define RAISE \
	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,        KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,          KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
	_______, _______, _______, _______, S(G(A(KC_V))), _______, _______, _______, _______, _______, _______, _______

#define CORNERAISE                             _______, MO(4),   _______, _______, _______, _______
```
The wrapper layout name for each keyboard should be a macro mapped to the real layout inside `layout.h`, like this Corne example:
```c
#define LAYOUT_wrapper_split_3x6_3(...) LAYOUT_split_3x6_3(__VA_ARGS__)
```
Finally the keyboard's JSON file can be created by referencing the key code macros of each layer, along with the layout macro at the bottom:
```c
{
    "author": "",
    "documentation": "Wrapper based keymap",
    "keyboard": "crkbd/rev1/common",
    "keymap": "filterpaper",
    "layers": [
        [ "QWERTY", "CORNEQWERTY" ],
        [ "LOWER", "CORNELOWER" ],
        [ "RAISE", "CORNERAISE" ],
        [ "ADJUST", "CORNEBLANK" ],
    ],
    "layout": "LAYOUT_wrapper_split_3x6_3",
    "notes": "",
    "version": 1
}
```
The build process will construct a transient `keymap.c` from JSON file into the format `[0] = LAYOUT_wrapper_split_3x6_3(QWERTY, CORNEQWERTY)`, and C preprocessor will use macros inside `layout.h` to expand that into the full layout key code for compilation.
