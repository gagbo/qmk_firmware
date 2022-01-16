#pragma once

#include "keymap_bepo.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

/** Under the screens row */
#define U1 MO(_NAV)
#define U2 KC_ESC
#define U3 KC_DEL
#define U4 MO(_SYM)

#define ___UPPER_ROW___       MO(_SYM), KC_ESC, KC_DEL, MO(_SYM)
// TODO: Make a BÉPO row and a Colemak row, that go to different symbol layers for the different types.
// Using the same symbol layer for both colemak and bépo doesn't work because on the OS side the layouts are also different, so using
// KC_LPRN will very likely _not_ send a '(' if the OS is configured to use the bépo layout

/** Utils */
#define ___________________BLANK5__________________       _______, _______, _______, _______, _______
#define ___________________BLANK6__________________       _______, _______, _______, _______, _______, _______

/** Navigation and media layer */
#define __________________MED_L1___________________       _______, _______, _______, _______, _______
#define __________________MED_L2___________________       _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU
#define __________________MED_L3___________________       _______, _______, _______, KC_MUTE, KC_VOLD

#define __________________NAV_R1___________________       _______,   KC_HOME, KC_UP,   KC_END,  KC_PGUP
#define __________________NAV_R2___________________       _______,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define __________________NAV_R3___________________       _______,   _______,  _______, _______, _______

/** Adjust and Function layer */
#define __________________ADJ_L1___________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __________________ADJ_L2___________________       RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD
#define __________________ADJ_L3___________________       _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD

#define __________________ADJ_R1___________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define __________________ADJ_R2___________________       _______,  _______, _______,  KC_F11,  KC_F12
#define __________________ADJ_R3___________________       ___________________BLANK5__________________


/** Colemak */
#define _________________CMK_DH_L1_________________       KC_TAB,       KC_Q,       KC_W,       KC_F,       KC_P,    KC_B
#define _________________CMK_DH_L2_________________       KC_ESC, HOME_CMK_A, HOME_CMK_R, HOME_CMK_S, HOME_CMK_T,    KC_G
#define _________________CMK_DH_L3_________________       KC_LSFT,      KC_Z,       KC_X,       KC_C,       KC_D,    KC_V

#define _________________CMK_DH_R1_________________       KC_J,          KC_L,          KC_U,          KC_Y,    KC_SCLN, KC_BSPC
#define _________________CMK_DH_R2_________________       KC_M,    HOME_CMK_N,    HOME_CMK_E,    HOME_CMK_I, HOME_CMK_O, KC_QUOT
#define _________________CMK_DH_R3_________________       KC_K,          KC_H,       KC_COMM,        KC_DOT,    KC_SLSH, KC_RSFT

#define ________________CMK_SYM_L1_________________       KC_PLUS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC
#define ________________CMK_SYM_L2_________________       KC_EQL,   HOME_1,  HOME_2,  HOME_3,  HOME_4,    KC_5
#define ________________CMK_SYM_L3_________________       XXXXXXX, KC_ECIR, KC_EGRV, KC_EACU, KC_AGRV, KC_UGRV

#define ________________CMK_SYM_R1_________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS
#define ________________CMK_SYM_R2_________________       KC_6,     HOME_7,  HOME_8,  HOME_9,  HOME_0, KC_UNDS
#define ________________CMK_SYM_R3_________________       KC_TILD, KC_PLUS,  KC_EQL, KC_MINS, _______, _______

/*
// BÉPO
#define ________________BEPO_HOME_L1_______________       KC_ESC,      BP_B,      BP_EA,       BP_P,      BP_O,  BP_EG
#define ________________BEPO_HOME_L2_______________       BP_W,   HOME_BP_A,  HOME_BP_U,  HOME_BP_I, HOME_BP_E,  BP_CO
#define ________________BEPO_HOME_L3_______________       KC_LSFT,    BP_AG,       BP_Y,       BP_X,     BP_DT,   BP_K

#define ________________BEPO_HOME_R1_______________       BP_DC,       BP_V,       BP_D,       BP_L,      BP_J,   BP_Z
#define ________________BEPO_HOME_R2_______________       BP_C,   HOME_BP_T,  HOME_BP_S,  HOME_BP_R, HOME_BP_N,   BP_M
#define ________________BEPO_HOME_R3_______________       BP_AP,       BP_Q,       BP_G,       BP_H,      BP_F, BP_CCED

#define _______________BEPO_SYM_L1_________________       BP_DOL , BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN
#define _______________BEPO_SYM_L2_________________       BP_HASH,  HOME_1,  HOME_2,  HOME_3,  HOME_4,    BP_5
#define _______________BEPO_SYM_L3_________________       BP_PERC, ___________________BLANK5__________________

#define _______________BEPO_SYM_R1_________________       BP_AT, BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL
#define _______________BEPO_SYM_R2_________________       BP_6,  HOME_7,  HOME_8,  HOME_9,  HOME_0, BP_DEG
#define _______________BEPO_SYM_R3_________________       ___________________BLANK5__________________, BP_GRV
*/
