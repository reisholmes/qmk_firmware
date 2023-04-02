# Disable unused features
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ENCODER_ENABLE = no
GRAVE_ESC_ENABLE = no 
KEY_LOCK_ENABLE = no
LEADER_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
STENO_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
TERMINAL_ENABLE = no
UNICODE_ENABLE = no
VELOCIKEY_ENABLE = no
VIA_ENABLE = no
WPM_ENABLE = no

# Common features enabled
BOOTMAGIC_ENABLE 	= yes
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes # Makes hex file smaller but breaks legacy macros
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes


# Main source file
SRC += reisholmes.c

# Corne keyboard features
ifeq ($(KEYBOARD) $(TINY), crkbd/rev1 yes)
	MOUSEKEY_ENABLE = yes
# Primary status with secondary WPM-driven animation
else ifeq ($(KEYBOARD) $(WPM), crkbd/rev1 yes)
    #https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options
    #DEBOUNCE_TYPE 			= sym_eager_pr
	DEBOUNCE_TYPE			= sym_defer_pk
	MOUSEKEY_ENABLE    		= yes
	OPT_DEFS += -DLEFTCAT
	OLED_ENABLE				= yes
	RGB_MATRIX_ENABLE  		= yes
	WPM_ENABLE 		   		= yes
	SRC += bongocat.c oled-icons.c

# My corne has eyes-c on left and pro-micro on right
	ifeq ($(RIGHT), yes)
		BOOTLOADER = caterina
	else
		BOOTLOADER = atmel-dfu
	endif

# Primary OLED option
#	ifneq ($(DOG),)
#		SRC += luna-status.c
#		OPT_DEFS += -D${DOG}
#	else
#		SRC += oled-icons.c
#	endif
# Primary tap-driven animation with secondary mod status
else ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
	OLED_ENABLE = yes
	SRC += oled-icons.c bongocat.c
endif

# Reviung39 keyboard features
ifeq ($(strip $(KEYBOARD)), reviung/reviung39)
	RGBLIGHT_ENABLE = yes
	OLED_ENABLE 	= no
endif

# Reviung41 keyboard features
ifeq ($(strip $(KEYBOARD)), reviung/reviung41)
	BOOTLOADER 		= caterina
	RGBLIGHT_ENABLE	= yes
	OLED_ENABLE 	= no
endif

# BabyV keyboard features
ifeq ($(strip $(KEYBOARD)), eyeohdesigns/babyv)
	BACKLIGHT_ENABLE	= yes
	RGBLIGHT_ENABLE 	= yes
	OLED_ENABLE 		= no
endif

# Rainkeeb keyboard features
ifeq ($(strip $(KEYBOARD)), rainkeebs/rainkeeb)
	BOOTLOADER 			= atmel-dfu
	MCU 				= atmega32u4
	ENCODER_ENABLE		= yes
	OLED_ENABLE 		= yes
	SRC += rainkeeb-status.c
	WPM_ENABLE			= yes
endif

# RISTRETTO keyboard features
ifeq ($(strip $(KEYBOARD)), ristretto)
	BOOTLOADER 			= atmel-dfu
	MCU 				= atmega32u4
	OLED_ENABLE 	    = yes
	WPM_ENABLE 		   	= yes
	SRC += bongocat.c
endif

# Minibaen keyboard features
ifeq ($(strip $(KEYBOARD)), minibaen)
	BOOTLOADER 		 = atmel-dfu
	ENCODER_ENABLE   = yes
	OLED_ENABLE 	 = no
endif

# underscore33 keyboard features
ifeq ($(strip $(KEYBOARD)), underscore33/rev2)
	BOOTLOADER 		 = atmel-dfu
	OLED_ENABLE 	 = no
	RGBLIGHT_ENABLE  = yes
endif

# phoenix ortho
ifeq ($(strip $(KEYBOARD)), checkerboards/phoenix45_ortho)
	ENCODER_ENABLE 	= yes
endif

# ffkb
ifeq ($(strip $(KEYBOARD)), ffkb/rgbmatrix_ec11)
	ENCODER_ENABLE 	= yes
	OLED_DRIVER_ENABLE	= no
	RGB_MATRIX_ENABLE = yes
	RGBLIGHT_ENABLE = no
endif

# v4n4g0n
ifeq ($(strip $(KEYBOARD)), thevankeyboards/v4n4g0n)
	SRC += v4n4g0n.c
	COMBO_ENABLE = no
endif

# v4n4g0rth0n
ifeq ($(strip $(KEYBOARD)), v4n4g0rth0n/v2)
	SRC += v4n4g0rth0n.c
	COMBO_ENABLE = no
endif

# le chiffre
ifeq ($(strip $(KEYBOARD)), tominabox1/le_chiffre/rev2)
	ENCODER_ENABLE = yes
	RGB_MATRIX_ENABLE = yes
	SRC += lechiffre.c
endif 

# lily58
ifeq ($(strip $(KEYBOARD)), lily58/rev1)
	ENCODER_ENABLE			= yes
	MOUSEKEY_ENABLE    		= yes
	OPT_DEFS += -DLEFTCAT
	OLED_ENABLE				= yes
	RGBLIGHT_ENABLE 		= yes
	WPM_ENABLE 		   		= yes
	SRC += bongocat.c oled-icons.c
endif

# sofle
ifeq ($(strip $(KEYBOARD)), sofle/rev2)
	ENCODER_ENABLE			= yes
	MOUSEKEY_ENABLE    		= yes
	OPT_DEFS += -DLEFTCAT
	OLED_ENABLE				= yes
	RGBLIGHT_ENABLE 		= yes
	WPM_ENABLE 		   		= yes
	SRC += bongocat.c oled-icons.c
endif

ifeq ($(strip $(KEYBOARD)), ferris/0_1 || ferris/0_2/compact)
	MCU = atmega32u4
	BOOTLOADER = atmel-dfu
endif