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

// Key and layout wrapper macros
#include "layout.h"

// Common QMK settings
// Tapping Terms
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAP_CODE_DELAY 50
#define LAYER_STATE_8BIT // 8-layer limit, saves ~462 bytes
// #define GRAVE_ESC_SHIFT_OVERRIDE

#ifdef RGBLIGHT_ENABLE
#  undef RGBLED_NUM
#  if defined(KEYBOARD_reviung39)
#     define RGB_DI_PIN D3
#     define RGBLED_NUM 11
#  else
#  	define RGBLED_NUM 27
#  endif
#  define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#  define RGBLIGHT_HUE_STEP 8
#  define RGBLIGHT_SAT_STEP 8
#  define RGBLIGHT_VAL_STEP 5
#  define RGBLIGHT_LIMIT_VAL 120
#  define RGBLIGHT_ANIMATIONS
#  define RGBLIGHT_SLEEP
#endif

#ifdef RGB_MATRIX_ENABLE
// #  define RGB_DISABLE_TIMEOUT 180000
// #  define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
//#  define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#  define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#  define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120    // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#  define RGB_MATRIX_HUE_STEP 8
#  define RGB_MATRIX_SAT_STEP 8
#  define RGB_MATRIX_VAL_STEP 5
#  define RGB_MATRIX_SPD_STEP 10
#  define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE

/* https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix
   If uncommented that means it's enabled */
//#  define DISABLE_RGB_MATRIX_SOLID_COLOR             // Static single hue, no speed support
#  define DISABLE_RGB_MATRIX_ALPHAS_MODS             // Static dual hue, speed is hue for secondary hue
#  define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN        // Static gradient top to bottom, speed controls how much gradient changes
#  define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT     // Static gradient left to right
#  define DISABLE_RGB_MATRIX_BREATHING               // Single hue brightness cycling animation
#  define DISABLE_RGB_MATRIX_BAND_SAT                // Single hue band fading saturation scrolling left to right
#  define DISABLE_RGB_MATRIX_BAND_VAL                // Single hue band fading brightness scrolling left to right
#  define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT       // Single hue 3 blade spinning pinwheel fades saturation
#  define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL       // Single hue 3 blade spinning pinwheel fades brightness
#  define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT         // Single hue spinning spiral fades saturation
#  define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL         // Single hue spinning spiral fades brightness
#  define DISABLE_RGB_MATRIX_CYCLE_ALL               // Full keyboard solid hue cycling through full gradient
#  define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT        // Full gradient scrolling left to right
#  define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN           // Full gradient scrolling top to bottom
#  define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#  define DISABLE_RGB_MATRIX_CYCLE_OUT_IN            // Full gradient scrolling out to in
#  define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL       // Full dual gradients scrolling out to in
#  define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradent Chevron shapped scrolling left to right
#  define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL          // Full gradient spinning pinwheel around center of keyboard
#  define DISABLE_RGB_MATRIX_CYCLE_SPIRAL            // Full gradient spinning spiral around center of keyboard
#  define DISABLE_RGB_MATRIX_DUAL_BEACON             // Full gradient spinning around center of keyboard
#  define DISABLE_RGB_MATRIX_RAINBOW_BEACON          // Full tighter gradient spinning around center of keyboard
#  define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS       // Full dual gradients spinning two halfs of keyboard
#  define DISABLE_RGB_MATRIX_RAINDROPS               // Randomly changes a single key's hue
#  define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS     // Randomly changes a single key's hue and saturation
#  define DISABLE_RGB_MATRIX_HUE_BREATHING
#  define DISABLE_RGB_MATRIX_HUE_PENDULUM
#  define DISABLE_RGB_MATRIX_HUE_WAVE

#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS // for the heatmap effect
#  ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define DISABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
#    define DISABLE_RGB_MATRIX_DIGITAL_RAIN   // That famous computer simulation
#  endif

#  define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#  ifdef RGB_MATRIX_KEYPRESSES
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
//#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE            // *Static single hue, pulses keys hit to shifted hue then fades to current hue
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#    define DISABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
#    define DISABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
#    define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
#  endif
#endif // RGB_MATRIX_ENABLE

#ifdef MOUSEKEY_ENABLE
#	define MOUSEKEY_DELAY 0
#	define MOUSEKEY_INTERVAL 16
#	define MOUSEKEY_MAX_SPEED 7
#	define MOUSEKEY_TIME_TO_MAX 40
#	define MOUSEKEY_WHEEL_DELAY 0
#	define MOUSEKEY_WHEEL_INTERVAL 50
#	define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

#ifdef SPLIT_KEYBOARD
// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_split_keyboard
// #	define EE_HANDS
#	define SPLIT_TRANSPORT_MIRROR
#   define SPLIT_USB_DETECT
#   define SPLIT_USB_TIMEOUT 2000
#	define SELECT_SOFT_SERIAL_SPEED 1
// Top right corner of right-side Corne
#	define BOOTMAGIC_LITE_ROW_RIGHT 4
#	define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#ifdef OLED_DRIVER_ENABLE
#	define OLED_TIMEOUT 20000
#	define OLED_DISABLE_TIMEOUT // Prevent matrix_changed triggering oled_on()
#	define OLED_UPDATE_INTERVAL 50
#	define OLED_FONT_H "users/reisholmes/oledfont.c"
#	ifndef WPM_ENABLE
#		define SPLIT_MODS_ENABLE
#	endif
#endif
