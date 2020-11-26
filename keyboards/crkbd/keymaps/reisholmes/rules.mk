# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE  = no  # Virtual DIP switch configuration(+1000)
CONSOLE_ENABLE    = no  # Console for debug(+400)
COMMAND_ENABLE    = no  # Commands for debug and configuration
BACKLIGHT_ENABLE  = no  # Enable keyboard backlight functionality
MIDI_ENABLE       = no  # MIDI controls
AUDIO_ENABLE      = no  # Audio output on port C6
BLUETOOTH_ENABLE  = no  # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE   = no  # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no  # Enable one-hand typing
COMMAND_ENABLE    = no
UNICODE_ENABLE    = no  # Unicode

RGB_MATRIX_ENABLE = WS2812
EXTRAKEY_ENABLE     = yes # Audio control and System control(+450)
NKRO_ENABLE       	= yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
WPM_ENABLE 		  	= yes
LTO_ENABLE 			= yes     # Makes hex file smaller
MOUSEKEY_ENABLE   	= yes # Mouse keys(+4700)
OLED_DRIVER_ENABLE 	= yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# Elite C ..
BOOTLOADER = qmk-dfu

# Get some firmware space back
LINK_TIME_OPTIMIZATION_ENABLE = yes
SPACE_CADET_ENABLE = no

ifeq ($(strip $(RGB_MATRIX_SPLIT_RIGHT)), yes)
    OPT_DEFS += -DRGB_MATRIX_SPLIT_RIGHT
endif
