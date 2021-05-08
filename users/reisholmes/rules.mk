#Unlike keymap.c, the keymaps[] array is excluded from this file because key layout is stored in the .json file.
#Do add the following line into rules.mk for QMK build process to find it during compile time
#Main source file
SRC += reisholmes.c

# Disable unused features
AUDIO_ENABLE					= no # Audio output on port C6
BLUETOOTH_ENABLE  				= no  # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE 				= no # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE					= no # Commands for debug and configurationi
CONSOLE_ENABLE					= no # Console for debug (+400)
KEY_LOCK_ENABLE					= no
LEADER_ENABLE					= no
LINK_TIME_OPTIMIZATION_ENABLE	= yes
MIDI_ENABLE						= no # MIDI controls
NKRO_ENABLE						= no
OLED_DRIVER_ENABLE 				= no
RGB_MATRIX_ENABLE				= no
SLEEP_LED_ENABLE 				= no # Breathing sleep LED during USB suspend
SPACE_CADET_ENABLE				= no
STENO_ENABLE					= no
SWAP_HANDS_ENABLE				= no # Enable one-hand typing
TAP_DANCE_ENABLE 				= no
TERMINAL_ENABLE					= no
UNICODE_ENABLE					= no
VELOCIKEY_ENABLE 				= no
VIA_ENABLE						= no
WPM_ENABLE						= no

# Common features for all keyboards
EXTRAKEY_ENABLE	= yes # Audio control and System control(+450)
LTO_ENABLE		= yes # Makes hex file smaller
MOUSEKEY_ENABLE	= yes # Mouse keys(+4700)
NKRO_ENABLE		= yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE	= yes # RGB underlight

# OLED Features for Lily58Pro, CRKBD
ifeq ($(KEYBOARD) $(WPM), crkbd/rev1/legacy yes)
	OLED_DRIVER_ENABLE 	= yes
	WPM_ENABLE			= yes
	SRC += bongocat.c keylog.c
# CRKBD options for RGB matrix to ensure right hand follows lighting instructions
	ifeq ($(strip $(RGB_MATRIX_SPLIT_RIGHT)), yes)
		RGB_MATRIX_ENABLE = WS2812
	    OPT_DEFS += -DRGB_MATRIX_SPLIT_RIGHT
	endif
endif

# Bootloader selection
BOOTLOADER = qmk-dfu


