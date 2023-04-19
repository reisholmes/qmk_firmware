#pragma once

// Key and layout wrapper macros
#include "layout.h"

// Common QMK settings
// Reduce size for things not being used
// https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT // 8-layer limit, saves ~462 bytes

// Tapping Terms
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 185
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define USB_SUSPEND_WAKEUP_DELAY 200

#ifdef RGBLIGHT_ENABLE
#  undef RGBLED_NUM
#  if defined(KEYBOARD_reviung_reviung39) | (KEYBOARD_reviung_reviung41)
#   define RGB_DI_PIN D3
#   define RGBLED_NUM 11
#  elif defined(KEYBOARD_eyeohdesigns_babyv)
#   define RGB_DI_PIN B7
#	define RGBLED_NUM 12
#   define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#  elif defined(KEYBOARD_thevankeyboards_minivan)
#    undef RGBLED_NUM
#	 define RGBLED_NUM 20
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 5
#    define RGBLIGHT_LIMIT_VAL 255
#    define RGBLIGHT_ANIMATIONS
#  elif defined(KEYBOARD_crkbd_rev1)
#    undef RGBLED_NUM
#    define RGBLED_NUM 54
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT {27, 27}
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 5
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_ANIMATIONS
#  elif defined(KEYBOARD_underscore33_rev2)
#    undef RGBLED_NUM
#    define RGBLED_NUM 20
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 5
#    define RGBLIGHT_LIMIT_VAL 255
#    define RGBLIGHT_ANIMATIONS
#  elif defined(KEYBOARD_lily58_rev1)
#    undef RGBLED_NUM
#    define RGBLED_NUM 16
#    define RGBLED_SPLIT {8,8}
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 5
#    define RGBLIGHT_LIMIT_VAL 160
#	 define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#    define RGBLIGHT_DEFAULT_HUE 180
#  elif defined(KEYBOARD_sofle_rev2)
#    undef RGBLED_NUM
	#define RGB_DI_PIN D3
	#define RGBLED_NUM 74
	#define RGBLED_SPLIT {37,37}
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 5
#    define RGBLIGHT_LIMIT_VAL 160
#	 define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT
#    define RGBLIGHT_DEFAULT_HUE 180
#  else 
#  	define RGBLED_NUM 27
#   define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#   define RGBLIGHT_HUE_STEP 8
#   define RGBLIGHT_SAT_STEP 8
#   define RGBLIGHT_VAL_STEP 5
#   define RGBLIGHT_LIMIT_VAL 120
#	define RGBLIGHT_EFFECT_STATIC_GRADIENT
#   define RGBLIGHT_EFFECT_BREATHING
#   define RGBLIGHT_SLEEP
#  endif
#endif

#ifdef RGB_MATRIX_ENABLE
#  if defined(KEYBOARD_ffkb_rgbmatrix_ec11)
#    undef DRIVER_LED_TOTAL
#    undef RGB_MATRIX_CENTER
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_DRIVER = WS2812
#    define DRIVER_LED_TOTAL 42
#    define RGB_MATRIX_CENTER {100, 32}
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#  elif defined(KEYBOARD_tominabox1_le_chiffre_rev2)
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#  else
//   #  define RGB_DISABLE_TIMEOUT 180000
//   https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
//   #  define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#    define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120    // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 5
#    define RGB_MATRIX_SPD_STEP 10
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_BREATHING
#  endif
// RGB effects are now opt in: https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#  define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#  if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE            // *Static single hue, pulses keys hit to shifted hue then fades to current hue
#  endif
#endif // RGB_MATRIX_ENABLE

#ifdef MOUSEKEY_ENABLE
#	define MOUSEKEY_DELAY 0
#	define MOUSEKEY_INTERVAL 16
#	define MOUSEKEY_MAX_SPEED 8
#	define MOUSEKEY_TIME_TO_MAX 40
#	define MOUSEKEY_WHEEL_DELAY 0
#	define MOUSEKEY_WHEEL_INTERVAL 50
#	define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

#ifdef SPLIT_KEYBOARD
// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_split_keyboard
#	define MASTER_LEFT
#   if defined(KEYBOARD_crkbd_rev1)
#		undef DEBOUNCE
#		define DEBOUNCE 10
#		define BOOTMAGIC_LITE_ROW    0
#		define BOOTMAGIC_LITE_COLUMN 0
#		define BOOTMAGIC_LITE_ROW_RIGHT    4
#		define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#		define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#	endif
#	if defined(OLED_ENABLE)
#		define SPLIT_MODS_ENABLE
#		define SPLIT_LED_STATE_ENABLE
#		define SPLIT_LAYER_STATE_ENABLE
//#		define SPLIT_WPM_ENABLE
#	endif
//#   define SPLIT_USB_TIMEOUT 500
//#	define SELECT_SOFT_SERIAL_SPEED 1
// Top right corner of right-side Corne
//#	define BOOTMAGIC_LITE_ROW_RIGHT 4
//#	define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#ifdef OLED_ENABLE
#   if defined(KEYBOARD_rainkeeb)
#	  define OLED_TIMEOUT 60000
#   else
#	  define OLED_TIMEOUT 60000
#	  define OLED_DISABLE_TIMEOUT // Prevent matrix_changed triggering oled_on()
#	  define OLED_UPDATE_INTERVAL 50
#	  define OLED_BRIGHTNESS 180
#	  define OLED_FONT_H "oledfont.c"
#	  ifndef WPM_ENABLE
#		define SPLIT_MODS_ENABLE
#	  endif
#   endif
#endif

//Encoder support
#ifdef ENCODER_ENABLE
	#  if defined(KEYBOARD_rainkeeb)
		#define ENCODERS_PAD_A { B2 }
		#define ENCODERS_PAD_B { B6 }
		#define ENCODER_RESOLUTION 4
	#  endif
	#  if defined(KEYBOARD_lily58_rev1)
		#define ENCODERS_PAD_A { F5 }
		#define ENCODERS_PAD_B { F4 }
		// Enable if encoder is on the left side
		//#define ENCODER_DIRECTION_FLIP
	#  endif
	#  if defined(KEYBOARD_cisne)
		#define ENCODERS_PAD_A { D2 }
		#define ENCODERS_PAD_B { D3 }
	#  endif
#endif

#ifdef COMBO_ENABLE
#	define COMBO_TERM 25
#	define COMBO_ONLY_FROM_LAYER 0
#endif