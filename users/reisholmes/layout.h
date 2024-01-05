// Include custom layouts
#include "custom_layout.h"

// Layers
#define BSE 0
#define LWR 1
#define RSE 2
#define ADJ 3
#define SYM 4
#define GME 5

/// These are called in the wrapper-<kbname>.json file under "layout"
/// Look in the original keyboard folder for list of available layouts
#define LAYOUT_33_w(...) LAYOUT_33_split_space(__VA_ARGS__)
#define LAYOUT_30key_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_36key_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_babyv_w(...) LAYOUT_2u(__VA_ARGS__)
#define LAYOUT_cisne_w(...) LAYOUT_0(__VA_ARGS__)
#define LAYOUT_corne_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_lechiffre_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_lily58_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ffkb_w(...) LAYOUT_ffkb(__VA_ARGS__)
#define LAYOUT_minibaen_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_modelv_w(...) LAYOUT_2x3u(__VA_ARGS__)
#define LAYOUT_moonboot_w(...) LAYOUT_split(__VA_ARGS__)
#define LAYOUT_monorail2_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_phoenixortho_w(...) LAYOUT_ortho_2x3u(__VA_ARGS__)
#define LAYOUT_reviung41_w(...) LAYOUT_reviung41(__VA_ARGS__)
#define LAYOUT_ristretto_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_rainkeeb_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_sofle_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_v4n_w(...)  LAYOUT(__VA_ARGS__)
#define LAYOUT_vault35rp_w(...)  LAYOUT(__VA_ARGS__)

// Home row mod-tap macros
/// Home row mods are added to layers in wrapper-<kbname>.json 
/// under layer name add "HRM<Alias>(layer_name)" e.g. 
/// Rainkeeb has: #define HRMRK(k) LAYOUT_rainkeeb(k)
/// So we add: "HRMRK(RAINKEEB_BASE)" in wrapper-rainkeeb.json
#define HRML(k1,k2,k3,k4) LSFT_T(k1),LCTL_T(k2),LGUI_T(k3),LALT_T(k4)
#define HRMR(k1,k2,k3,k4) RALT_T(k1),RGUI_T(k2),RCTL_T(k3),RSFT_T(k4)

// Define Mods for 3x6 unique keyboard layouts
// Allows us to do mods in one place and then specify layout such as:
// __BASE_MOD_L1__, __BASE_L1__, UNIQUE/INDIVIDUAL KEYS, __BASE_R1__, __BASE_MOD_R1__ 
#define __BASE_MOD_L1__  KC_LBRC
#define __BASE_MOD_L2__  LSFT_T(KC_GRV)
#define __BASE_MOD_L3__  LCTL_T(KC_MINS)

#define __BASE_MOD_R1__  KC_RBRC
#define __BASE_MOD_R2__  RSFT_T(KC_QUOT)
#define __BASE_MOD_R3__  RCTL_T(KC_EQL)

// Base Layer QWERTY Layout
#define __BASE_NUMROW_L__	KC_LBRC, KC_1, KC_2, KC_3, KC_4, KC_5
#define __BASE_L1__	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T
#define __BASE_L2__	KC_A,	KC_S,	KC_D,	KC_F,	KC_G
#define __BASE_L3__	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B

#define __BASE_NUMROW_R__  KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC
#define __BASE_R1__	KC_Y,	KC_U,	KC_I,		KC_O,	KC_P
#define __BASE_R2__	KC_H,	KC_J,	KC_K,		KC_L,	KC_SCLN
#define __BASE_R3__	KC_N,	KC_M, 	KC_COMM,	KC_DOT,	KC_SLSH

// Base Layer Bottom Row
// 1 = Lower, 2 = Raise, 3 = Adjust, 4 = Symbols
#define __BASE_2KEY_L_BOT__ LT(3, KC_TAB), LT(2, KC_BSPC)
#define __BASE_2KEY_R_BOT__	LT(1, KC_SPC), LT(4, KC_DEL)
#define __BASE_3KEY_L_BOT__ LT(3, KC_ESC), LT(3, KC_TAB), LT(2, KC_BSPC)
#define __BASE_3KEY_R_BOT__	LT(1, KC_SPC), LT(4, KC_DEL), LT(4, KC_BSLS)
#define __BASE_4KEY_L_BOT__ KC_MINS, LT(3, KC_ESC), LT(3, KC_TAB), LT(2, KC_BSPC)
#define __BASE_4KEY_R_BOT__	LT(1, KC_SPC), LT(4, KC_DEL), LT(4, KC_BSLS), KC_EQL
#define __BASE_5KEY_L_BOT__ KC_MINS, KC_LGUI,  LT(3, KC_ESC), LT(3, KC_TAB), LT(2, KC_BSPC)
#define __BASE_5KEY_R_BOT__	LT(1, KC_SPC), LT(4, KC_DEL), LT(4, KC_BSLS), KC_RGUI, TG(5)

// Lower Layer
/// 'Sel_KC' is LeftShift + LeftControl + Keycode
/*
   * | Next | Sel_L| Sel_H| Sel_E| Sel_R|   		| Home | PgDn | PgUp | End  |M_Btn3|
   * | Play | W_Le | W_Do | W_Up | W_Ri |   		| Left | Down |  Up  | Rght |M_Btn1|
   * | Prev | Cut  | Copy | Pste | xxxx |	 		| M_Le | M_Do | M_Up | M_Ri |M_Btn2|
*/
#define __LOWER_NUMROW_L__	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define __LOWER_L1__ KC_MNXT,	C(S(KC_LEFT)),	S(KC_HOME),		S(KC_END),		C(S(KC_RGHT))
#define __LOWER_L2__ KC_MPLY,	KC_WH_L,		KC_WH_D,		KC_WH_U,		KC_WH_R 
#define	__LOWER_L3__ KC_MPRV,	KC_CUT,			KC_COPY,		KC_PSTE,		KC_TRNS

#define __LOWER_NUMROW_R__ 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define __LOWER_R1__ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BTN3
#define __LOWER_R2__ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN1
#define __LOWER_R3__ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2

// Lower Layer Bot Row
#define __LOWER_2KEY_L_BOT__ KC_ESC,	KC_ENT
#define __LOWER_2KEY_R_BOT__ KC_TRNS,	KC_TRNS
#define __LOWER_3KEY_L_BOT__ KC_TRNS,	KC_ESC,		KC_ENT
#define __LOWER_3KEY_R_BOT__ KC_TRNS,	KC_TRNS,	KC_TRNS
#define __LOWER_4KEY_L_BOT__ KC_TRNS,   KC_TRNS,	KC_ESC,		KC_ENT
#define __LOWER_4KEY_R_BOT__ KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
#define __LOWER_5KEY_L_BOT__ KC_TRNS,	KC_TRNS,    KC_TRNS,	KC_ESC,		KC_ENT
#define __LOWER_5KEY_R_BOT__ KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS

// Raise Layer
/* Raise
   * |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  |
   * |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  |  F10 |
*/
#define __RAISE_NUMROW_L__	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define __RAISE_L1__	KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC      
#define __RAISE_L2__	KC_1,    KC_2,  KC_3,    KC_4,    KC_5
#define __RAISE_L3__	KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5

#define __RAISE_NUMROW_R__	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define __RAISE_R1__	KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define __RAISE_R2__	KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __RAISE_R3__	KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

// Raise Layer Bot Row
#define __RAISE_2KEY_L_BOT__ KC_F11,	KC_TRNS
#define __RAISE_2KEY_R_BOT__ KC_ENT,	KC_F12
#define __RAISE_3KEY_L_BOT__ KC_TRNS,	KC_F11,		KC_TRNS
#define __RAISE_3KEY_R_BOT__ KC_ENT,	KC_F12,		KC_TRNS
#define __RAISE_4KEY_L_BOT__ KC_TRNS,	KC_TRNS,	KC_F11,		KC_TRNS
#define __RAISE_4KEY_R_BOT__ KC_ENT,	KC_F12,		KC_TRNS,	KC_TRNS
#define __RAISE_5KEY_L_BOT__ KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_F11,		KC_TRNS
#define __RAISE_5KEY_R_BOT__ KC_ENT,	KC_F12,		KC_TRNS,	KC_TRNS,	KC_TRNS

// Adjust Layer
/* Adjust
   * |      |Qwerty|Gaming|	     |	    |   |	   |	  |	     |		|	   |
   * |RgbTog|	   |NumLck|Reset |PrtScr|   | Minus|  P7  |  P8  |  P9  | Slash|
   * |RgbRMo|RgbHui|RgbSai|RgbVai|RgbSpi|   |  P0  |  P4  |  P5  |  P6  | Dot  |
   * |RgbMod|RbgHud|RgbSad|RgbVad|RgbSpd|   | Plus |  P1  |  P2  |  P3  | Ast  |
*/
#define __ADJUST_NUMROW_L__  KC_NO,	TG(0),	TG(5),	KC_NO, KC_NO, KC_NO
#define __ADJUST_L1__	RGB_TOG,    KC_NO,		KC_NUM,		QK_BOOT,		KC_PSCR      
#define __ADJUST_L2__	RGB_RMOD,   RGB_HUI,	RGB_SAI,	RGB_VAI,	RGB_SPI
#define __ADJUST_L3__	RGB_MOD,    RGB_HUD,	RGB_SAD,	RGB_VAD,	RGB_SPD

#define __ADJUST_NUMROW_R__  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define __ADJUST_R1__	KC_PMNS,	KC_P7,		KC_P8,		KC_P9,		KC_PSLS
#define __ADJUST_R2__	KC_P0,		KC_P4,		KC_P5, 		KC_P6,		KC_PDOT
#define __ADJUST_R3__	KC_PPLS,	KC_P1,		KC_P2,		KC_P3,		KC_PAST

// Adjust Bot Row
#define __ADJUST_2KEY_L_BOT__ KC_TRNS,	KC_BSPC	
#define __ADJUST_2KEY_R_BOT__ KC_SPC,	KC_PENT
#define __ADJUST_3KEY_L_BOT__ KC_TRNS,	KC_TAB,		KC_BSPC
#define __ADJUST_3KEY_R_BOT__ KC_SPC,	KC_PENT,	KC_BSLS
#define __ADJUST_4KEY_L_BOT__ KC_TRNS,	KC_TRNS,	KC_TAB,		KC_BSPC
#define __ADJUST_4KEY_R_BOT__ KC_SPC,	KC_PENT,	KC_BSLS,	KC_TRNS
#define __ADJUST_5KEY_L_BOT__ KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TAB,		KC_BSPC
#define __ADJUST_5KEY_R_BOT__ KC_SPC,	KC_PENT,	KC_BSLS,	KC_TRNS,	KC_TRNS

// Symbols Layer
/* Symbols
   * |   [  |   {  |      |      |      |   |      |      |      |   }  |   ]  |
   * |   `  |      |      |      |      |   |      |      |      |      |   '  |
   * |   -  |      |      |      |      |   |      |      |      |      |   =  |
*/
#define __SYMBOLS_NUMROW_R__  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define __SYMBOLS_L1__ KC_LBRC,	KC_LCBR,	KC_NO,	KC_NO,	KC_NO
#define __SYMBOLS_L2__ KC_GRV,	KC_NO,		KC_NO,	KC_NO,	KC_NO
#define __SYMBOLS_L3__ KC_MINS,	KC_NO,		KC_NO,	KC_NO,	KC_NO	

#define __SYMBOLS_NUMROW_L__  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define __SYMBOLS_R1__ KC_NO,	KC_NO, KC_NO, KC_RCBR,	KC_RBRC
#define __SYMBOLS_R2__ KC_NO,	KC_NO, KC_NO, KC_NO,	KC_SCLN
#define __SYMBOLS_R3__ KC_NO,	KC_NO, KC_NO, KC_NO,	KC_EQL

// Symbols Bot Row
#define __SYMBOLS_2KEY_L_BOT__ KC_TAB,	KC_BSPC
#define __SYMBOLS_2KEY_R_BOT__ KC_SPC,	KC_TRNS
#define __SYMBOLS_3KEY_L_BOT__ KC_ESC,	KC_TAB,		KC_BSPC
#define __SYMBOLS_3KEY_R_BOT__ KC_SPC,	KC_DEL,		KC_TRNS
#define __SYMBOLS_4KEY_L_BOT__ KC_TRNS,	KC_ESC,		KC_TAB,		KC_BSPC
#define __SYMBOLS_4KEY_R_BOT__ KC_SPC,	KC_DEL,		KC_TRNS,	KC_TRNS
#define __SYMBOLS_5KEY_L_BOT__ KC_TRNS,	KC_TRNS,	KC_ESC,		KC_TAB,		KC_BSPC
#define __SYMBOLS_5KEY_R_BOT__ KC_SPC,	KC_DEL,		KC_TRNS,	KC_TRNS,	KC_TRNS



// Set our standard layout building block for the wrappers below to utilise
#define _BASE \
	__BASE_MOD_L1__, __BASE_L1__, __BASE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __BASE_L2__, __BASE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __BASE_L3__, __BASE_R3__, __BASE_MOD_R3__
#define _BASE_5KEY_BOTROW \
	__BASE_5KEY_L_BOT__, __BASE_5KEY_R_BOT__
#define _BASE_4KEY_BOTROW \
	__BASE_4KEY_L_BOT__, __BASE_4KEY_R_BOT__
#define _BASE_3KEY_BOTROW \
	__BASE_3KEY_L_BOT__, __BASE_3KEY_R_BOT__
#define _BASE_2KEY_BOTROW \
	__BASE_2KEY_L_BOT__, __BASE_2KEY_R_BOT__

#define _LOWER \
	__BASE_MOD_L1__, __LOWER_L1__, __LOWER_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __LOWER_L2__, __LOWER_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __LOWER_L3__, __LOWER_R3__, __BASE_MOD_R3__
#define _LOWER_5KEY_BOTROW \
	__LOWER_5KEY_L_BOT__, __LOWER_5KEY_R_BOT__
#define _LOWER_4KEY_BOTROW \
	__LOWER_4KEY_L_BOT__, __LOWER_4KEY_R_BOT__
#define _LOWER_3KEY_BOTROW \
	__LOWER_3KEY_L_BOT__, __LOWER_3KEY_R_BOT__
#define _LOWER_2KEY_BOTROW \
	__LOWER_2KEY_L_BOT__, __LOWER_2KEY_R_BOT__

#define _RAISE \
	__BASE_MOD_L1__, __RAISE_L1__, __RAISE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __RAISE_L2__, __RAISE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __RAISE_L3__, __RAISE_R3__, __BASE_MOD_R3__
#define _RAISE_5KEY_BOTROW\
	__RAISE_5KEY_L_BOT__, __RAISE_5KEY_R_BOT__
#define _RAISE_4KEY_BOTROW\
	__RAISE_4KEY_L_BOT__, __RAISE_4KEY_R_BOT__
#define _RAISE_3KEY_BOTROW\
	__RAISE_3KEY_L_BOT__, __RAISE_3KEY_R_BOT__
#define _RAISE_2KEY_BOTROW\
	__RAISE_2KEY_L_BOT__, __RAISE_2KEY_R_BOT__

#define _ADJUST \
	__BASE_MOD_L1__, __ADJUST_L1__, __ADJUST_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __ADJUST_L2__, __ADJUST_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __ADJUST_L3__, __ADJUST_R3__, __BASE_MOD_R3__
#define _ADJUST_5KEY_BOTROW \
	__ADJUST_5KEY_L_BOT__, __ADJUST_5KEY_R_BOT__
#define _ADJUST_4KEY_BOTROW \
	__ADJUST_4KEY_L_BOT__, __ADJUST_4KEY_R_BOT__
#define _ADJUST_3KEY_BOTROW \
	__ADJUST_3KEY_L_BOT__, __ADJUST_3KEY_R_BOT__
#define _ADJUST_2KEY_BOTROW \
	__ADJUST_2KEY_L_BOT__, __ADJUST_2KEY_R_BOT__

#define _SYMBOLS \
	__BASE_MOD_L1__, __SYMBOLS_L1__, __SYMBOLS_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __SYMBOLS_L2__, __SYMBOLS_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __SYMBOLS_L3__, __SYMBOLS_R3__, __BASE_MOD_R3__
#define _SYMBOLS_5KEY_BOTROW \
	__SYMBOLS_5KEY_L_BOT__, __SYMBOLS_5KEY_R_BOT__
#define _SYMBOLS_4KEY_BOTROW \
	__SYMBOLS_4KEY_L_BOT__, __SYMBOLS_4KEY_R_BOT__
#define _SYMBOLS_3KEY_BOTROW \
	__SYMBOLS_3KEY_L_BOT__, __SYMBOLS_3KEY_R_BOT__
#define _SYMBOLS_2KEY_BOTROW \
	__SYMBOLS_2KEY_L_BOT__, __SYMBOLS_2KEY_R_BOT__				


// 36keys
/// Defined in the wrapper-<kbname>.json file as: HRM(_layer_)
#define HRM(k) HRM_TAPHOLD(k)
#define HRM_TAPHOLD( \
	k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, \
	k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, \
	k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36 \
) \
	k01,      k02, k03, k04, k05,  k06, k07,      k08, k09, k10, k11,  k12, \
	k13, HRML(k14, k15, k16, k17), k18, k19, HRMR(k20, k21, k22, k23), k24, \
	k25,      k26, k27, k28, k29,  k30, k31,   	  k32, k33, k34, k35,  k36

// 36 to 30-key conversion
/// Defined in the wrapper-<kbname>.json file as: C_30(HRM(_layer_))
#define C_30(k) SPLIT_36_TO_30(k)
#define SPLIT_36_TO_30( \
	k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, \
	k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, \
	k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36 \
) \
	     k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, \
	     k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, \
	     k26, k27, k28, k29, k30, k31, k32, k33, k34, k35
