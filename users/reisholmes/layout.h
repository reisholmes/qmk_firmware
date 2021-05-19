/* Copyright (C) 2021 @filterpaper
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Tap hold shortcuts and layout wrapper macros.
 * Ortholinears and split Corne board share the top 3x12 layout
 */

#pragma once


// Tap hold macro keys for keymap[]
#define RST(X) RSFT_T(X)
#define LST(X) LSFT_T(X)
#define LCT(X) LCTL_T(X)
#define RCT(X) RCTL_T(X)
#define LGT(X) LGUI_T(X)
#define RGT(X) RGUI_T(X)
#define TAT(X) LALT_T(X)
#define AGT(X) RALT_T(X)


// Base layout wrapper macros
#define LAYOUT_wrapper_split_3x6_3(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_wrapper_reviung39(...) LAYOUT_reviung39(__VA_ARGS__)
#define LAYOUT_wrapper_all(...) LAYOUT_all(__VA_ARGS__)


// Shared 3x12
/* Qwerty
   * ,-----------------------------------------.---,-----------------------------------------.
   * | [    |   Q  |   W  |   E  |   R  |T/LALT|   |Y/RALT|   U  |   I  |   O  |   P  | ]    |
   * |------+------+------+------+------+------|   |------+------+------+------+------+------|
   * |`/LSFT|   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |'/RSFT|
   * |------+------+------+------+------+------|   |------+------+------+------+------+------|
   * |-/LCTR|Z/LGUI|X/LALT|   C  |   V  |   B  |   |   N  |   M  |   ,  |./RALT|/_RGUI|=/RCTR|
   * `------+------+------+------+------+------+---+------+------+------+------+------+------'
*/
#define QWERTY \
	KC_LBRC,      KC_Q,      KC_W, 		KC_E, KC_R, TAT(KC_T),      AGT(KC_Y),   KC_U, KC_I,    KC_O, 		 KC_P,    	   KC_RBRC, \
    LST(KC_GRV),  KC_A,      KC_S, 		KC_D, KC_F, KC_G,           KC_H,        KC_J, KC_K,	KC_L,		 KC_SCLN,	   RST(KC_QUOT), \
	LCT(KC_MINS), LGT(KC_Z), TAT(KC_X), KC_C, KC_V, KC_B,           KC_N, 		 KC_M, KC_COMM, AGT(KC_DOT), RGT(KC_SLSH), RCT(KC_EQL)

/* Lower
   * ,-----------------------------------------.---,-----------------------------------------.
   * |Vol Up|  Esc | Copy | W_Up |  CUT | PASTE|   | Home | PgDn | PgUp | End  |M_Btn3| Next |
   * |------+------+------+------+------+------|   |-------------+------+------+------+------|
   * |Vol Do|  Tab | W_Le | W_Do | W_Ri |M_Btn3|   | Left | Down |  Up  | Rght |M_Btn2| Prev |
   * |------+------+------+------+------+------|   |-------------+------+------+------+------|
   * | Mute | Ctrl | Shift| Gui  |M_Btn1|M_Btn2|   | M_Le | M_Do | M_Up | M_Ri |M_Btn1| Play |
   * `------+------+------+------+------+------+---+------+------+------+------+------+------'
*/
#define LOWER \
    KC_VOLU, KC_ESC,  KC_COPY, KC_WH_U, KC_CUT,  KC_PASTE,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BTN3, KC_MNXT, \
    KC_VOLD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN2, KC_MPRV, \
    KC_MUTE, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_MPLY

/* Raise
   * ,-----------------------------------------.---,-----------------------------------------.
   * |   |  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |-------------+------+------+------+------|   |------+------+------+------+------+------|
   * |   .  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  |   ,  |
   * |-------------+------+------+------+------|   |------+------+------+------+------+------|
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * `------+------+------+------+------+------+---+------+------+------+------+------+------'
*/
#define RAISE \
    KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_DOT,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COMM, \
    KC_F11,  KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12

/* Adjust
   * ,-----------------------------------------.---,-----------------------------------------.
   * |      |      |      |      |      |PrtScr|   | Minus|  P7  |  P8  |  P9  | Slash|NumLck|
   * |-------------+------+------+------+------|   |------+------+------+------+------+------|
   * |      |RgbRMo|RgbHui|RgbSai|RgbVai|BrghUp|   |  P0  |  P4  |  P5  |  P6  | Dot  |CapLck|
   * |-------------+------+------+------+------|   |------+------+------+------+------+------|
   * |RbgTog|RgbMod|RbgHud|RgbSad|RgbVad|BrghDo|   | Plus |  P1  |  P2  |  P3  | Ast  |ScrLck|
   * `------+------+------+------+------+------+---+------+------+------+------+------+------'
*/
#define ADJUST \
    _______,  _______, _______, _______, _______, KC_PSCR,      KC_PMNS, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_NLCK, \
    _______, RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU,      KC_P0,   KC_P4, KC_P5, KC_P6, KC_PDOT, KC_CAPS, \
    RGB_TOG, RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID,      KC_PPLS, KC_P1, KC_P2, KC_P3, KC_PAST, KC_SLCK


// Last row
//                   Esc/Adjust,   Tab/LShift,  Bks/Raise           Spc/Lower,    Del/RShift,  Backslash
#define CORNEQWERTY  LT(3,KC_ESC), LST(KC_TAB), LT(2,KC_BSPC),      LT(1,KC_SPC), RST(KC_DEL), KC_BSLS
//						Bks/Raise	   Tab/Adjust    Spc/Lower
#define REVIUNG39QWERTY LT(2,KC_BSPC), LT(3,KC_TAB), LT(1,KC_SPC)

#define CORNELOWER  _______, _______,  KC_ENT, _______, _______, _______
#define REVIUNG39LOWER KC_ESC, RST(KC_DEL),  _______

#define CORNERAISE  _______, _______, _______, KC_ENT,  _______, _______
#define REVIUNG39RAISE _______, _______, KC_ENT

#define CORNEADJUST XXXXXXX, _______, KC_BSPC, KC_SPC, KC_DEL,  KC_PENT
#define REVIUNG39ADJUST _______, _______, KC_BSLS


// Boardsource The Mark 65
/*
#define MARK_QWERTY \
KC_ESC,  KC_1,        KC_2,        KC_3,        KC_4,         KC_5,     KC_6,    KC_7,        KC_8,        KC_9,        KC_0,           KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_VOLU, \
KC_TAB,  Q_TH,        W_TH,        KC_E,        KC_R,         KC_T,     KC_Y,    KC_U,        KC_I,        KC_O,        KC_P,           KC_LBRC, KC_RBRC, KC_BSPC,          KC_VOLD, \
KC_CAPS, SFT_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), GUI_T(KC_F),  KC_G,     KC_H,    GUI_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), SFT_T(KC_SCLN), KC_QUOT, KC_ENT,                    KC_MUTE, \
KC_LSFT, KC_LSFT,     KC_Z,        KC_X,        KC_C,         KC_V,     KC_B,    KC_N,        M_TH,        COMM_TH,     DOT_TH,         KC_SLSH, KC_RSFT,          KC_UP,            \
KC_LALT, KC_LCTL,     KC_LGUI,                  LT(2,KC_SPC),           KC_SPC,               RSFT_T(KC_SPC),           KC_RGUI,        KC_RCTL, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
#define MARK_COLEMAK \
_______, _______,     _______,     _______,     _______,      _______,  _______, _______,     _______,     _______,     _______,        _______, _______, _______, _______, _______, \
_______, _______,     _______,     KC_F,        KC_P,         KC_G,     KC_J,    KC_L,        KC_U,        KC_Y,        KC_SCLN,        _______, _______, _______,          _______, \
_______, _______,     ALT_T(KC_R), CTL_T(KC_S), GUI_T(KC_T),  KC_D,     _______, GUI_T(KC_N), CTL_T(KC_E), ALT_T(KC_I), SFT_T(KC_O),    _______, _______,                   _______, \
_______, _______,     _______,     _______,     _______,      _______,  KC_B,    KC_K,        _______,     _______,     _______,        _______, _______,          _______,          \
_______, _______,     _______,                  _______,                _______,              _______,                  _______,        _______, _______, _______, _______, _______
#define MARK_LAYER2 \
_______, KC_F1,      KC_F2,        KC_F3,       KC_F4,        KC_F5,    KC_F6,   KC_F7,       KC_F8,       KC_F9,       KC_F10,         KC_F11,  KC_F12,  _______, KC_HOME, KC_PGUP, \
_______, _______,    _______,      _______,     _______,      _______,  _______, _______,     _______,     _______,     _______,        _______, _______, KC_DEL,           KC_PGDN, \
_______, _______,    _______,      _______,     _______,      _______,  KC_LEFT, KC_DOWN,     KC_UP,       KC_RGHT,     _______,        _______, _______,                   KC_END,  \
_______, _______,    _______,      _______,     _______, S(G(A(KC_V))), _______, _______,     _______,     _______,     _______,        _______, _______,          _______,          \
_______, _______,    _______,                   _______,                _______,              MO(3),                    _______,        _______, _______, _______, _______, _______
#define MARK_LAYER3 \
RESET,   _______,    _______,      _______,     _______,      _______,  _______, _______,     _______,     _______,     _______,        _______, _______, _______, TG(1),   _______, \
_______, _______,    _______,      _______,     _______,      _______,  _______, _______,     _______,     _______,     _______,        _______, _______, _______,          _______, \
_______, _______,    _______,      _______,     _______,      _______,  KC_HOME, KC_PGDN,     KC_PGUP,     KC_END,      _______,        _______, _______,                   _______, \
_______, _______, A(G(KC_EJCT)),   _______,     _______,      _______,  _______, _______,     _______,     _______,     _______,     C(G(KC_Q)), _______,          _______,          \
_______, _______,    _______,                   _______,                _______,              _______,                  _______,        _______, _______, _______, _______, _______
*/