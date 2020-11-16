#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* Definitions for a split keyboard */
#define USE_SERIAL_PD2
#define FORCE_NKRO

/* Macro and tapping behaviour */
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#define TAPPING_TERM 170
//#define TAPPING_FORCE_HOLD

// Underglow
#undef RGBLED_NUM
#ifdef RGBLIGHT_ENABLE
  #define RGBLED_NUM 16
  #define RGBLED_SPLIT {8,8}
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_SLEEP
#endif

// Encoder
#ifdef ENCODER_ENABLE
  #define ENCODERS_PAD_A { F5 }
  #define ENCODERS_PAD_B { F4 }
  // Enable if encoder is on the left side
  // #define ENCODER_DIRECTION_FLIP
#endif

#ifdef OLED_DRIVER_ENABLE
#  define OLED_DISABLE_TIMEOUT
#  define OLED_FONT_H "keyboards/lily58/keymaps/reisholmes/glcdfont.c"
#endif

/* Mouse Settings */
#ifdef MOUSEKEY_ENABLE
#  define MOUSEKEY_INTERVAL 16
#  define MOUSEKEY_DELAY 0
#  define MOUSEKEY_TIME_TO_MAX 60
#  define MOUSEKEY_MAX_SPEED 7
#  define MOUSEKEY_WHEEL_DELAY 0
#  define MOUSEKEY_WHEEL_MAX_SPEED 2
#  define MOUSEKEY_WHEEL_TIME_TO_MAX 6
#endif

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#   undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#   undef LOCKING_RESYNC_ENABLE
#endif
