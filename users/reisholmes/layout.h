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
#define LAYOUT_corne_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_lechiffre_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_lily58_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ffkb_w(...) LAYOUT_ffkb(__VA_ARGS__)
#define LAYOUT_minibaen_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_modelv_w(...) LAYOUT_2x3u(__VA_ARGS__)
#define LAYOUT_phoenixortho_w(...) LAYOUT_ortho_2x3u(__VA_ARGS__)
#define LAYOUT_reviung41_w(...) LAYOUT_reviung41(__VA_ARGS__)
#define LAYOUT_ristretto_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_rainkeeb_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_v4n_w(...)  LAYOUT(__VA_ARGS__)
#define LAYOUT_sofle_w(...) LAYOUT(__VA_ARGS__)

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
#define __ADJUST_L1__	RGB_TOG,    KC_NO,		KC_NUM,		RESET,		KC_PSCR      
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

// More Custom Keymaps here

// Rainkeeb
#define HRMRK(k) LAYOUT_rainkeeb(k)
#define LAYOUT_rainkeeb( \
    K00, K10, K01, K11, K02,      K13, K03, K14, K04, K15, \
    K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, \
    K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, \
    K60, K70, K61, K72,      K62,      K73, K64, K74, K65  \
) \
	K00, 	  K10, K01, K11,  K02,      K13,      K03, K14, K04, K15,  \
    HRML(K20, K30, K21, K31), K22, K32, K23, HRMR(K33, K24, K34, K25), \
    K40, 	  K50, K41, K51,  K42, K52, K43,      K53, K44, K54, K45,  \
    K60, 	  K70, K61, K72,       K62,           K73, K64, K74, K65

#define RAINKEEB_BASE \
	__BASE_L1__, __BASE_R1__, \
	__BASE_L2__, KC_MUTE, __BASE_R2__, \
	__BASE_L3__, KC_MPLY, __BASE_R3__, \
	KC_MINS, __BASE_3KEY_L_BOT__, LT(4,KC_QUOT), __BASE_3KEY_R_BOT__, KC_EQL

#define RAINKEEB_LOWER \
	__LOWER_L1__, __LOWER_R1__, \
	__LOWER_L2__, _______, __LOWER_R2__, \
	__LOWER_L3__, _______, __LOWER_R3__, \
	KC_TRNS, __LOWER_3KEY_L_BOT__, KC_TRNS, __LOWER_3KEY_R_BOT__, KC_TRNS

#define RAINKEEB_RAISE \
	__RAISE_L1__, __RAISE_R1__, \
	__RAISE_L2__, _______, __RAISE_R2__, \
	__RAISE_L3__, _______, __RAISE_R3__, \
	KC_TRNS, __RAISE_3KEY_L_BOT__, KC_TRNS, __RAISE_3KEY_R_BOT__, KC_TRNS

#define RAINKEEB_ADJUST \
	__ADJUST_L1__, __ADJUST_R1__, \
	__ADJUST_L2__, _______, __ADJUST_R2__, \
	__ADJUST_L3__, _______, __ADJUST_R3__, \
	KC_TRNS, __ADJUST_3KEY_L_BOT__, KC_TRNS, __ADJUST_3KEY_R_BOT__, KC_TRNS

#define RAINKEEB_SYMBOLS \
	__SYMBOLS_L1__, __SYMBOLS_R1__, \
	__SYMBOLS_L2__, _______, __SYMBOLS_R2__, \
	__SYMBOLS_L3__, _______, __SYMBOLS_R3__, \
	KC_TRNS, __SYMBOLS_3KEY_L_BOT__, KC_TRNS, __SYMBOLS_3KEY_R_BOT__, KC_TRNS

#define R41_LOWER_BOTROW \
	__LOWER_2KEY_L_BOT__, KC_ESC, __LOWER_2KEY_R_BOT__

// Reviung41
#define R41_BASE_BOTROW \
	__BASE_2KEY_L_BOT__, KC_ESC, __BASE_2KEY_R_BOT__
#define R41_LOWER_BOTROW \
	__LOWER_2KEY_L_BOT__, KC_ESC, __LOWER_2KEY_R_BOT__
#define R41_RAISE_BOTROW \
	__RAISE_2KEY_L_BOT__, KC_ESC, __RAISE_2KEY_R_BOT__
#define R41_ADJUST_BOTROW \
	__ADJUST_2KEY_L_BOT__, KC_ESC, __ADJUST_2KEY_R_BOT__
#define R41_SYMBOLS_BOTROW \
	__SYMBOLS_2KEY_L_BOT__, KC_ESC, __SYMBOLS_2KEY_R_BOT__


// Phoenix Ortho 2x3u layout
#define HRMPO(k) LAYOUT_phoenixortho(k)
#define LAYOUT_phoenixortho( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, \
    k30, k31, k32,      k34,                k38, k39,      k3B, k3C \
) \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, \
    HRML(k10, k11, k12, k13), k14, k15, k16, k17, k18, HRMR(k19, k1A, k1B, k1C), \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, \
    k30, k31, k32, 	k34, k38, k39, k3B, k3C

#define PHOENIXORTHO_BASE \
	__BASE_L1__, __BASE_MOD_L1__, KC_MNXT, __BASE_MOD_R1__, __BASE_R1__, \
	__BASE_L2__, __BASE_MOD_L2__, KC_MPLY, __BASE_MOD_R2__, __BASE_R2__, \
	__BASE_L3__, __BASE_MOD_L3__, KC_MPRV, __BASE_MOD_R3__, __BASE_R3__, \
	KC_NO, __BASE_3KEY_L_BOT__, __BASE_3KEY_R_BOT__, KC_NO

#define PHOENIXORTHO_LOWER \
	__LOWER_L1__, __BASE_MOD_L1__, _______, __BASE_MOD_R1__, __LOWER_R1__, \
	__LOWER_L2__, __BASE_MOD_L2__, _______, __BASE_MOD_R2__, __LOWER_R2__, \
	__LOWER_L3__, __BASE_MOD_L3__, _______, __BASE_MOD_R3__, __LOWER_R3__, \
	KC_NO, __LOWER_3KEY_L_BOT__, __LOWER_3KEY_R_BOT__, KC_NO

#define PHOENIXORTHO_RAISE \
	__RAISE_L1__, __BASE_MOD_L1__, _______, __BASE_MOD_R1__, __RAISE_R1__, \
	__RAISE_L2__, __BASE_MOD_L2__, _______, __BASE_MOD_R2__, __RAISE_R2__, \
	__RAISE_L3__, __BASE_MOD_L3__, _______, __BASE_MOD_R3__, __RAISE_R3__, \
	KC_NO, __RAISE_3KEY_L_BOT__, __RAISE_3KEY_R_BOT__, KC_NO

#define PHOENIXORTHO_ADJUST \
	__ADJUST_L1__, __BASE_MOD_L1__, _______, __BASE_MOD_R1__, __ADJUST_R1__, \
	__ADJUST_L2__, __BASE_MOD_L2__, _______, __BASE_MOD_R2__, __ADJUST_R2__, \
	__ADJUST_L3__, __BASE_MOD_L3__, _______, __BASE_MOD_R3__, __ADJUST_R3__, \
	KC_NO, __ADJUST_3KEY_L_BOT__, __ADJUST_3KEY_R_BOT__, KC_NO

#define PHOENIXORTHO_SYMBOLS \
	__SYMBOLS_L1__, __BASE_MOD_L1__, _______, __BASE_MOD_R1__, __SYMBOLS_R1__, \
	__SYMBOLS_L2__, __BASE_MOD_L2__, _______, __BASE_MOD_R2__, __SYMBOLS_R2__, \
	__SYMBOLS_L3__, __BASE_MOD_L3__, _______, __BASE_MOD_R3__, __SYMBOLS_R3__, \
	KC_NO, __SYMBOLS_3KEY_L_BOT__, __SYMBOLS_3KEY_R_BOT__, KC_NO
 

// FFKB 3x6 no outside encoders layout
#define HRMFFKB(k) LAYOUT_ffkb3x6(k)
#define LAYOUT_ffkb3x6( \
    K01, K02, K03, K04, K05, K06,           K07, K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15, K16,           K17, K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25, K26,           K27, K28, K29, K2A, K2B, K2C, \
              K32,      K34, K35, K36, K37, K38, K39,      K3B, \
                                    K3A \
) \
	KC_NO, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, KC_NO, \
    KC_NO,	HRML(K12, K13, K14, K15), K16, K17, HRMR(K18, K19, K1A, K1B), KC_NO, \
    KC_NO,	K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, KC_NO, \
		KC_NO,K34, K35, K36, K37, K38, K39, KC_NO, K3A

#define FFKB_BASE \
	KC_NO, __BASE_L1__, __BASE_R1__, KC_NO, \
	KC_NO, __BASE_L2__, __BASE_R2__, KC_NO, \
	KC_NO, __BASE_L3__, __BASE_R3__, KC_NO, \
	KC_NO, __BASE_3KEY_L_BOT__, __BASE_3KEY_R_BOT__, KC_NO, LALT(KC_TAB)

#define FFKB_LOWER \
	KC_NO, __LOWER_L1__, __LOWER_R1__, KC_NO, \
	KC_NO, __LOWER_L2__, __LOWER_R2__, KC_NO, \
	KC_NO, __LOWER_L3__, __LOWER_R3__, KC_NO, \
	KC_NO, __LOWER_3KEY_L_BOT__, __LOWER_3KEY_R_BOT__, KC_NO, LALT(KC_TAB)

#define FFKB_RAISE \
	KC_NO, __RAISE_L1__, __RAISE_R1__, KC_NO, \
	KC_NO, __RAISE_L2__, __RAISE_R2__, KC_NO, \
	KC_NO, __RAISE_L3__, __RAISE_R3__, KC_NO, \
	KC_NO, __RAISE_3KEY_L_BOT__, __RAISE_3KEY_R_BOT__, KC_NO, LALT(KC_TAB)

#define FFKB_ADJUST \
	KC_NO, __ADJUST_L1__, __ADJUST_R1__, KC_NO, \
	KC_NO, __ADJUST_L2__, __ADJUST_R2__, KC_NO, \
	KC_NO, __ADJUST_L3__, __ADJUST_R3__, KC_NO, \
	KC_NO, __ADJUST_3KEY_L_BOT__, __ADJUST_3KEY_R_BOT__, KC_NO, LALT(KC_TAB)

#define FFKB_SYMBOLS \
	KC_NO, __SYMBOLS_L1__, __SYMBOLS_R1__, KC_NO, \
	KC_NO, __SYMBOLS_L2__, __SYMBOLS_R2__, KC_NO, \
	KC_NO, __SYMBOLS_L3__, __SYMBOLS_R3__, KC_NO, \
	KC_NO, __SYMBOLS_3KEY_L_BOT__, __SYMBOLS_3KEY_R_BOT__, KC_NO, LALT(KC_TAB)


// v4n4g0n - game layer
// Puts keyboard into a more standard layout for gaming
#define _GAME_V4N \
	KC_ESC, 	__BASE_L1__,	__BASE_R1__, 	KC_BSPC, \
	KC_TAB, 	__BASE_L2__,	__BASE_R2__, 	RSFT_T(KC_ENT), \
	KC_LSFT,	__BASE_L3__,	__BASE_R3__, 	KC_RCTL

#define _GAME_V4N_4KEY_BOTROW \
	KC_LGUI, KC_F1, KC_LALT, KC_BSPC, KC_SPC, KC_RALT, KC_DEL, TG(5)
#define _GAME_V4N_5KEY_BOTROW \
	KC_LCTL, KC_LGUI, KC_F1, KC_LALT, KC_BSPC, KC_SPC, KC_RALT, KC_DEL, KC_RGUI, TG(5)

// v4n4g0n - numrow
#define __BASE_V4N_NUMROW__  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6
#define __LOWER_V4N_NUMROW__  KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL
#define __RAISE_V4N_NUMROW__  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6
#define __ADJUST_V4N_NUMROW__  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define __SYMBOLS_V4N_NUMROW__  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS


// lily58
#define HRMLILY58(k) LAYOUT_lily58(k)
#define LAYOUT_lily58( \
	L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
	L10, L11, L12, L13, L14, L15,     		R10, R11, R12, R13, R14, R15,  \
	L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
	L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
	               L41, L42, L43, L44, R41, R42, R43, R44  \
) \
	 L00, L01, L02, L03, L04, L05,     R00, R01, R02, R03, R04, R05, \
	 L10, L11, L12, L13, L14, L15,     R10, R11, R12, R13, R14, R15, \
	 L20, HRML(L21, L22, L23, L24), L25,     R20, HRMR(R21, R22, R23, R24), R25, \
	 L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
	 L41, L42, L43, L44, R41, R42, R43, R44

// lily58 - layers (encoder on left only)
#define LILY58_BASE \
	__BASE_NUMROW_L__, __BASE_NUMROW_R__, \
	__BASE_MOD_L1__, __BASE_L1__,  __BASE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __BASE_L2__,  __BASE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __BASE_L3__, KC_MUTE, SGUI(KC_S), __BASE_R3__, __BASE_MOD_R3__, \
	_BASE_4KEY_BOTROW

#define LILY58_LOWER \
	__LOWER_NUMROW_L__, __LOWER_NUMROW_R__, \
	__BASE_MOD_L1__, __LOWER_L1__,  __LOWER_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __LOWER_L2__,  __LOWER_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __LOWER_L3__, KC_MUTE, SGUI(KC_S), __LOWER_R3__, __BASE_MOD_R3__, \
	_LOWER_4KEY_BOTROW

#define LILY58_RAISE \
	__RAISE_NUMROW_L__, __RAISE_NUMROW_R__, \
	__BASE_MOD_L1__, __RAISE_L1__,  __RAISE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __RAISE_L2__,  __RAISE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __RAISE_L3__, KC_MUTE, SGUI(KC_S), __RAISE_R3__, __BASE_MOD_R3__, \
	_RAISE_4KEY_BOTROW

#define LILY58_ADJUST \
	__ADJUST_NUMROW_L__, __ADJUST_NUMROW_R__, \
	__BASE_MOD_L1__, __ADJUST_L1__,  __ADJUST_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __ADJUST_L2__,  __ADJUST_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __ADJUST_L3__, KC_MUTE, SGUI(KC_S), __ADJUST_R3__, __BASE_MOD_R3__, \
	_ADJUST_4KEY_BOTROW

#define LILY58_SYMBOLS \
	__SYMBOLS_NUMROW_L__, __SYMBOLS_NUMROW_R__, \
	__BASE_MOD_L1__, __SYMBOLS_L1__,  __SYMBOLS_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __SYMBOLS_L2__,  __SYMBOLS_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __SYMBOLS_L3__, KC_MUTE, SGUI(KC_S), __SYMBOLS_R3__, __BASE_MOD_R3__, \
	_SYMBOLS_4KEY_BOTROW

#define LILY58_GAME \
	__BASE_NUMROW_L__, __BASE_NUMROW_R__, \
	KC_ESC, __BASE_L1__,  __BASE_R1__, KC_BSPC, \
	KC_TAB, __BASE_L2__,  __BASE_R2__, RSFT_T(KC_ENT), \
	KC_LSFT, __BASE_L3__, KC_MUTE, SGUI(KC_S), __BASE_R3__, KC_RCTL, \
	_BASE_4KEY_BOTROW

// LeChiffre+ - has encoder in middle so custom layout required
// Due to the weird way this is wired/laid out in the rev2
// We define top row as LeftAlphas, LowerRightMod, Encoder, RightAlphas - yet to find reason for this
// It also shifts the home row mods left by one to correct for this
// Nothing else seems affected
#define HRMLECHI(k) LAYOUT_lechiffre(k)
#define LAYOUT_lechiffre( \
  K00, K01, K02, K03, K04, K38, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
            K32,      K34,      K35,      K37       \
) \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, HRML(K11, K12, K13, K14), K15, K16, HRMR(K17, K18, K19, \
  K20), K21, K22, K23, K24, K25, K26, K27, K28, K29, \
   K32,  K34, K35,  K37, K38

#define LECHI_BASE \
	__BASE_L1__, LT(4, KC_DEL), KC_MUTE, __BASE_R1__,  \
	__BASE_L2__, __BASE_R2__, \
	__BASE_L3__, __BASE_R3__, \
    LT(3, KC_TAB), LT(2, KC_BSPC), LT(1, KC_SPC)

#define LECHI_LOWER \
	__LOWER_L1__,  KC_MUTE, __LOWER_R1__, \
	__LOWER_L2__, __LOWER_R2__, \
	__LOWER_L3__, __LOWER_R3__, \
	KC_ESC,	KC_ENT, KC_TRNS, KC_TRNS

#define LECHI_RAISE \
	__RAISE_L1__, KC_MUTE, __RAISE_R1__, \
	__RAISE_L2__, __RAISE_R2__, \
	__RAISE_L3__, __RAISE_R3__, \
	KC_F11,	KC_TRNS, KC_ENT, KC_TRNS

#define LECHI_ADJUST \
	__ADJUST_L1__, KC_MUTE, __ADJUST_R1__, \
	__ADJUST_L2__, __ADJUST_R2__, \
	__ADJUST_L3__, __ADJUST_R3__, \
	 KC_TRNS, KC_BSPC, KC_SPC, KC_PENT

#define LECHI_SYMBOLS \
	__SYMBOLS_L1__,  KC_MUTE, __SYMBOLS_R1__, \
	__SYMBOLS_L2__, __SYMBOLS_R2__, \
	__SYMBOLS_L3__, __SYMBOLS_R3__, \
	KC_TAB,	KC_BSPC, KC_SPC, KC_TRNS


// Sofle
#define HRMSOFLE(k) LAYOUT_sofle(k)
#define LAYOUT_sofle( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
    L30, L31, L32, L33, L34, L35, L40, R40, R30, R31, R32, R33, R34, R35, \
              L41, L42, L43, L44, L45, R41, R42, R43, R44, R45  \
) \
    L00, L01, L02, L03, L04, L05,			R00, R01, R02, R03, R04, R05, \
	L10, L11, L12, L13, L14, L15,			R10, R11, R12, R13, R14, R15, \
	L20, HRML(L21, L22, L23, L24), L25,  	R20, HRMR(R21, R22, R23, R24), R25, \
	L30, L31, L32, L33, L34, L35, L40, R40, R30, R31, R32, R33, R34, R35, \
              L41, L42, L43, L44, L45, R41, R42, R43, R44, R45


// sofle - layers 
#define SOFLE_BASE \
	__BASE_NUMROW_L__, __BASE_NUMROW_R__, \
	__BASE_MOD_L1__, __BASE_L1__,  __BASE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __BASE_L2__,  __BASE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __BASE_L3__, KC_MUTE, SGUI(KC_S), __BASE_R3__, __BASE_MOD_R3__, \
	_BASE_5KEY_BOTROW

#define SOFLE_LOWER \
	__LOWER_NUMROW_L__, __LOWER_NUMROW_R__, \
	__BASE_MOD_L1__, __LOWER_L1__,  __LOWER_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __LOWER_L2__,  __LOWER_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __LOWER_L3__, KC_MUTE, SGUI(KC_S), __LOWER_R3__, __BASE_MOD_R3__, \
	_LOWER_5KEY_BOTROW

#define SOFLE_RAISE \
	__RAISE_NUMROW_L__, __RAISE_NUMROW_R__, \
	__BASE_MOD_L1__, __RAISE_L1__,  __RAISE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __RAISE_L2__,  __RAISE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __RAISE_L3__, KC_MUTE, SGUI(KC_S), __RAISE_R3__, __BASE_MOD_R3__, \
	_RAISE_5KEY_BOTROW

#define SOFLE_ADJUST \
	__ADJUST_NUMROW_L__, __ADJUST_NUMROW_R__, \
	__BASE_MOD_L1__, __ADJUST_L1__,  __ADJUST_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __ADJUST_L2__,  __ADJUST_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __ADJUST_L3__, KC_MUTE, SGUI(KC_S), __ADJUST_R3__, __BASE_MOD_R3__, \
	_ADJUST_5KEY_BOTROW

#define SOFLE_SYMBOLS \
	__SYMBOLS_NUMROW_L__, __SYMBOLS_NUMROW_R__, \
	__BASE_MOD_L1__, __SYMBOLS_L1__,  __SYMBOLS_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __SYMBOLS_L2__,  __SYMBOLS_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __SYMBOLS_L3__, KC_MUTE, SGUI(KC_S), __SYMBOLS_R3__, __BASE_MOD_R3__, \
	_SYMBOLS_5KEY_BOTROW

#define SOFLE_GAME \
	__BASE_NUMROW_L__, __BASE_NUMROW_R__, \
	KC_ESC, __BASE_L1__,  __BASE_R1__, KC_BSPC, \
	KC_TAB, __BASE_L2__,  __BASE_R2__, RSFT_T(KC_ENT), \
	KC_LSFT, __BASE_L3__, KC_MUTE, SGUI(KC_S), __BASE_R3__, KC_RCTL, \
	_BASE_5KEY_BOTROW
