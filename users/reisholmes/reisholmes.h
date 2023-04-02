#pragma once
#include QMK_KEYBOARD_H

// Layer and mod tap bitmasks
// 0xFF00 bitmask
#define LT0_MASK 0x4000
#define LT1_MASK 0x4100
#define LT2_MASK 0x4200
#define LT3_MASK 0x4300
#define CTL_T_MASK 0x6100
#define SFT_T_MASK 0x6200
#define ALT_T_MASK 0x6400
#define GUI_T_MASK 0x6800
// 0xF000 bitmask
#define LT_MASK LT0_MASK
#define LMOD_T_MASK 0x6000
#define RMOD_T_MASK 0x7000

/** \brief Key Actions
 * (kc >> 8) & 0x1F) for mod bits
 *
 * Mod bits:    43210
 *   bit 0      ||||+- Control
 *   bit 1      |||+-- Shift
 *   bit 2      ||+--- Alt
 *   bit 3      |+---- Gui
 *   bit 4      +----- LR flag(Left:0, Right:1)
 */
/*
enum mods_bit {
	MOD_LCTL = 0x01,
	MOD_LSFT = 0x02,
	MOD_LALT = 0x04,
	MOD_LGUI = 0x08,
	MOD_RCTL = 0x11,
	MOD_RSFT = 0x12,
	MOD_RALT = 0x14,
	MOD_RGUI = 0x18,
}; */
