#pragma once
#include QMK_KEYBOARD_H

#include <stdio.h>
#include "wrapped_rows.h"
#include "keymap_bepo.h"

enum custom_keycodes {
    KC_AGRV = SAFE_RANGE,
    KC_EGRV,
    KC_EACU,
    KC_ECIR,
    KC_UGRV,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

#define KC_EUR ALGR(KC_5)

#define RESC LT(_SYM, KC_ESC)
#define BP_EA BP_EACU
#define BP_AG BP_AGRV
#define BP_EG BP_EGRV
#define BP_DC BP_DCIR
#define BP_AP BP_QUOT
#define BP_CO BP_COMM
#define BP_DT BP_DOT
#define BP_DOL BP_DLR

#define LS KC_LSFT

/* Home row mods */
/** BÉPO */
// Left-hand home row mods
#define HOME_BP_A LGUI_T(BP_A)
#define HOME_BP_U LALT_T(BP_U)
#define HOME_BP_I LCTL_T(BP_I)
#define HOME_BP_E LSFT_T(BP_E)
// Right-hand home row mods
#define HOME_BP_T RSFT_T(BP_T)
#define HOME_BP_S RCTL_T(BP_S)
#define HOME_BP_R LALT_T(BP_R)
#define HOME_BP_N RGUI_T(BP_N)

/** Colemak-DH */
// Left-hand home row mods
#define HOME_CMK_A LGUI_T(KC_A)
#define HOME_CMK_R LALT_T(KC_R)
#define HOME_CMK_S LCTL_T(KC_S)
#define HOME_CMK_T LSFT_T(KC_T)
// Right-hand home row mods
#define HOME_CMK_N RSFT_T(KC_N)
#define HOME_CMK_E RCTL_T(KC_E)
#define HOME_CMK_I LALT_T(KC_I)
#define HOME_CMK_O RGUI_T(KC_O)

/** Numbers */
// Left-hand home row mods Layer LOWER
#define HOME_1 LGUI_T(BP_1)
#define HOME_2 LALT_T(BP_2)
#define HOME_3 LCTL_T(BP_3)
#define HOME_4 LSFT_T(BP_4)
// Right-hand home row mods Layer LOWER
#define HOME_7 RSFT_T(BP_7)
#define HOME_8 RCTL_T(BP_8)
#define HOME_9 LALT_T(BP_9)
#define HOME_0 RGUI_T(BP_0)

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record);

// wrapper for using what's in wrapped_rows.h
#define LAYOUT_kyria(...) LAYOUT(__VA_ARGS__)
