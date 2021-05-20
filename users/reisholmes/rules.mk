# Disable unused features
VIA_ENABLE = no
WPM_ENABLE = no
NKRO_ENABLE = no
AUDIO_ENABLE = no
STENO_ENABLE = no
LEADER_ENABLE = no
UNICODE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
TERMINAL_ENABLE = no
KEY_LOCK_ENABLE = no
RGBLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
SLEEP_LED_ENABLE = no
TAP_DANCE_ENABLE = no
VELOCIKEY_ENABLE = no
SWAP_HANDS_ENABLE = no
RGB_MATRIX_ENABLE = no
SPACE_CADET_ENABLE = no

# Common features
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes # Makes hex file smaller but breaks legacy macros 
#OPT_DEFS += -DCAPSWORD_ENABLE

# Main source file
SRC += reisholmes.c

# Corne keyboard features
ifeq ($(KEYBOARD) $(TINY), crkbd/rev1/common yes)
	MOUSEKEY_ENABLE = yes
# Primary status with secondary WPM-driven animation
else ifeq ($(KEYBOARD) $(WPM), crkbd/rev1/common yes)
    #https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options
	MOUSEKEY_ENABLE    		= yes
	NO_USB_STARTUP_CHECK	= yes
	OLED_DRIVER_ENABLE		= yes
	RGB_MATRIX_ENABLE  		= yes
	WPM_ENABLE 		   		= yes
	SRC += bongocat.c

# My corne has elite-c on left and pro-micro on right
	ifeq ($(RIGHT), yes)
		BOOTLOADER = caterina
	else
		BOOTLOADER = atmel-dfu
	endif

# Primary OLED option
	ifneq ($(DOG),)
		SRC += luna-status.c
		OPT_DEFS += -D${DOG}
	else
		SRC += mod-status.c
	endif
# Primary tap-driven animation with secondary mod status
else ifeq ($(strip $(KEYBOARD)), crkbd/rev1/common)
	MOUSEKEY_ENABLE = yes
	OLED_DRIVER_ENABLE = yes
	SRC += mod-status.c bongocat.c
endif

# Reviung39 keyboard features
ifeq ($(KEYBOARD) $(REVIUNG39), reviung39 yes)
	MOUSEKEY_ENABLE 	= yes
	RGBLIGHT_ENABLE 	= yes
	OLED_DRIVER_ENABLE 	= no
endif
