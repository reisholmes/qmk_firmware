// Copyright 2023 haizeus (@haizeus)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Define encoder pads */

#define TAP_CODE_DELAY 10

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

// #define ENCODER_DIRECTION_FLIP

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

// /* RGB Stuff */
// #define RGB_DI_PIN GP29
// #define DRIVER_LED_TOTAL 22
// #define RGBLED_NUM 22
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 125
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS * 3/4

#define ENABLE_RGB_MATRIX_BREATHING
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
//#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_KEYPRESSES
