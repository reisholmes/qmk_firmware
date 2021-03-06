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

#pragma once
#include QMK_KEYBOARD_H

// Layer references
enum layers { DEF, LWR, RSE, ADJ };

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
