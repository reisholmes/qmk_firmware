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


// Cisne
#define HRMCISNE(k) LAYOUT_cisne(k)
#define LAYOUT_cisne( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,	\
    L10, L11, L12, L13, L14, L15,           R17, R18, R19, R20, R21, R22,	\
    L20, L21, L22, L23, L24, L25,           R26, R27, R28, R29, R30, R31, R32,	\
              L31, L32, L34,				R36, R37, R39, R311	\
) \
    L00, L01, L02, L03, L04, L05,			R00, R01, R02, R03, R04, R05,	\
	L10, HRML(L11, L12, L13, L14), L15,		R17, HRMR(R18, R19, R20, R21), R22,	\
	L20, L21, L22, L23, L24, L25,  			R26, R27, R28, R29, R30, R31, R32,	\
              L31, L32, L34,				R36, R37, R39, R311

#define CISNE_BASE \
	__BASE_MOD_L1__, __BASE_L1__, __BASE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __BASE_L2__, __BASE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __BASE_L3__, KC_COPY, __BASE_R3__, __BASE_MOD_R3__, \
	__BASE_3KEY_L_BOT__, MT(MOD_LSFT, KC_BSPC), __BASE_3KEY_R_BOT__

#define CISNE_LOWER \
	__BASE_MOD_L1__, __LOWER_L1__, __LOWER_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __LOWER_L2__, __LOWER_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __LOWER_L3__, KC_COPY, __LOWER_R3__, __BASE_MOD_R3__, \
	__LOWER_3KEY_L_BOT__, MT(MOD_LSFT, KC_BSPC), __LOWER_3KEY_R_BOT__

#define CISNE_RAISE \
	__BASE_MOD_L1__, __RAISE_L1__, __RAISE_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __RAISE_L2__, __RAISE_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __RAISE_L3__, KC_PSTE, __RAISE_R3__, __BASE_MOD_R3__, \
	__RAISE_3KEY_L_BOT__, MT(MOD_LSFT, KC_BSPC), __RAISE_3KEY_R_BOT__

#define CISNE_ADJUST \
	__BASE_MOD_L1__, __ADJUST_L1__, __ADJUST_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __ADJUST_L2__, __ADJUST_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __ADJUST_L3__, KC_COPY, __ADJUST_R3__, __BASE_MOD_R3__, \
	__ADJUST_3KEY_L_BOT__, MT(MOD_LSFT, KC_BSPC), __ADJUST_3KEY_R_BOT__

#define CISNE_SYMBOLS \
	__BASE_MOD_L1__, __SYMBOLS_L1__, __SYMBOLS_R1__, __BASE_MOD_R1__, \
	__BASE_MOD_L2__, __SYMBOLS_L2__, __SYMBOLS_R2__, __BASE_MOD_R2__, \
	__BASE_MOD_L3__, __SYMBOLS_L3__, KC_COPY, __SYMBOLS_R3__, __BASE_MOD_R3__, \
	__SYMBOLS_3KEY_L_BOT__, MT(MOD_LSFT, KC_BSPC), __SYMBOLS_3KEY_R_BOT__

// Vault35rp
// Uses an encoder in top right and also has an extra defined key in layout on bot
#define HRMVAULT35RP(k) LAYOUT_vault35rp(k)
#define LAYOUT_vault35rp( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, \
          K301, K302, K303, K304, K305, K306, K307  \
) \
	K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010, \
    HRML(K100,  K101,  K102,  K103),  K104,  K105,  HRMR(K106,  K107,  K108,  K109), \
    K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209, \
    K301,  K302,  K303,  K304,  K305,  K306,  K307

#define VAULT35RP_BASE \
	__BASE_L1__, __BASE_R1__, KC_BSPC, \
	__BASE_L2__, __BASE_R2__, \
	__BASE_L3__, __BASE_R3__, \
	__BASE_3KEY_L_BOT__, KC_SPACE, __BASE_3KEY_R_BOT__

#define VAULT35RP_LOWER \
	__LOWER_L1__, __LOWER_R1__, KC_BSPC, \
	__LOWER_L2__, __LOWER_R2__, \
	__LOWER_L3__, __LOWER_R3__, \
	__LOWER_3KEY_L_BOT__, KC_SPACE, __LOWER_3KEY_R_BOT__

#define VAULT35RP_RAISE \
	__RAISE_L1__, __RAISE_R1__, KC_BSPC, \
	__RAISE_L2__, __RAISE_R2__, \
	__RAISE_L3__, __RAISE_R3__, \
	__RAISE_3KEY_L_BOT__, KC_SPACE, __RAISE_3KEY_R_BOT__

#define VAULT35RP_ADJUST \
	__ADJUST_L1__, __ADJUST_R1__, KC_BSPC, \
	__ADJUST_L2__, __ADJUST_R2__, \
	__ADJUST_L3__, __ADJUST_R3__, \
	__ADJUST_3KEY_L_BOT__, KC_SPACE, __ADJUST_3KEY_R_BOT__

#define VAULT35RP_SYMBOLS \
	__SYMBOLS_L1__, __SYMBOLS_R1__, KC_BSPC, \
	__SYMBOLS_L2__, __SYMBOLS_R2__, \
	__SYMBOLS_L3__, __SYMBOLS_R3__, \
	__SYMBOLS_3KEY_L_BOT__, KC_SPACE, __SYMBOLS_3KEY_R_BOT__
