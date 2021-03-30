# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE 	= no # Virtual DIP switch configuration
CONSOLE_ENABLE 		= no # Console for debug
COMMAND_ENABLE 		= no # Commands for debug and configuration
BACKLIGHT_ENABLE 	= no # Enable keyboard backlight functionality
MIDI_ENABLE 		= no # MIDI controls
AUDIO_ENABLE 		= no # Audio output on port C6
BLUETOOTH_ENABLE 	= no # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE 	= no # Enable one-hand typing
UNICODE_ENABLE   	= no # Unicode
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE 	= no       # Breathing sleep LED during USB suspend
MOUSEKEY_ENABLE   	= no # Mouse keys(+4700)

EXTRAKEY_ENABLE     = yes # Audio control and System control(+450)
NKRO_ENABLE       	= yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
WPM_ENABLE 		  	= yes
LTO_ENABLE 			= yes # Makes hex file smaller
RGBLIGHT_ENABLE 	= yes # Enable WS2812 RGB underlight.
ENCODER_ENABLE 		= yes
OLED_DRIVER_ENABLE	= yes # OLED display

# Get some firmware space back
LINK_TIME_OPTIMIZATION_ENABLE = yes
SPACE_CADET_ENABLE = no

# If you want to change the display of OLED, you need to change here
# SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

ifeq ($(strip $(RGB_MATRIX_SPLIT_RIGHT)), yes)
    OPT_DEFS += -DRGB_MATRIX_SPLIT_RIGHT
endif
