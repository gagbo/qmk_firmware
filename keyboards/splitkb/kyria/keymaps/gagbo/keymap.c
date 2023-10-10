/* Copyright 2021 Gerry Agbobada <gagbobada@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "gagbo.h"

enum layers {
    _QWERTY = 0,
    _CMK_FR,
    // Left Thumb
    _MEDIA,
    _NAV,
    _MOUSE,
    // Right Thumb
    _NUM,
    _SYM, // Unused; use chording with shift instead
    _FUN,
    //
    // _PAD, // Probably unused; use num instead
};

#define QWERTY   DF(_QWERTY)
#define CMK_FR   DF(_CMK_FR)

/** Bottom Row */
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)

// Left-hand home row mods
//// Common
#define HOME_A LGUI_T(KC_A)
#define HOME_X RALT_T(KC_X)
//// For Colemak-fr on the OS
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
// For "Colemak-fr on hardware", "QWERTY on OS" situations
#define HOME_CR LALT_T(KC_R)
#define HOME_CS LCTL_T(KC_S)
#define HOME_CT LSFT_T(KC_T)

// Right-hand home row mods
//// Common
#define HOME_DOT RALT_T(KC_DOT)
//// For Colemak-fr on the OS
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)
// For "Colemak-fr on hardware", "QWERTY on OS" situations
#define HOME_CN RSFT_T(KC_N)
#define HOME_CE RCTL_T(KC_E)
#define HOME_CI LALT_T(KC_I)
#define HOME_CU RGUI_T(KC_U)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |    [   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |   -  | Media|  |  Fun |  =   |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Del  |      | Space|  Tab |LShift|  |RShift| Enter| Bksp |      |  ]}  |
 *                        |      | Nav  |      |      |      |  |      |      |      | Num  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT_kyria(
  KC_GRV,           KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,                      /**/                   KC_Y,    KC_U, KC_I,    KC_O,     KC_P,      KC_LBRC,
  LCTL_T(KC_ESC),   HOME_A, HOME_S,  HOME_D, KC_F,    KC_G,                      /**/                  KC_H,  KC_J, HOME_K,  HOME_L,   HOME_SCLN, RCTL_T(KC_QUOT),
  KC_LSFT,          KC_Z,   HOME_X,  KC_C,   KC_V,    KC_B, KC_MINS, TG(_MEDIA), /**/    TG(_FUN), KC_EQL, KC_N,    KC_M, KC_COMM, HOME_DOT, KC_SLSH,   KC_RSFT,
                                      KC_DEL, KC_LSFT, MO(_NAV), KC_SPC, KC_TAB, /**/    KC_ENT, KC_BSPC, MO(_NUM), KC_RSFT, KC_RBRC
    ),

/*
 * Alt Base Layer: Colemak FR
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   O  |   Y  | ;  : |    [   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   U  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |   -  | Media|  |  Fun |  =   |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Del  |      | Space|  Tab |LShift|  |RShift| Enter| Bksp |      |  ]}  |
 *                        |      | Nav  |      |      |      |  |      |      |      | Num  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CMK_FR] = LAYOUT_kyria(
  KC_GRV,           KC_Q,   KC_W,    KC_F,   KC_P,    KC_B,                    /**/                    KC_J,    KC_L, KC_O,    KC_Y,     KC_SCLN,      KC_LBRC,
  LCTL_T(KC_ESC),   HOME_A, HOME_CR,  HOME_CS, KC_T,  KC_G,                    /**/                    KC_M,  KC_N, HOME_CE,  HOME_CI,   HOME_CU, RCTL_T(KC_QUOT),
  KC_LSFT,          KC_Z,   HOME_X,  KC_C,   KC_D,    KC_V, KC_MINS, TG(_MEDIA),/**/     TG(_FUN), KC_EQL, KC_K,    KC_H, KC_COMM, HOME_DOT, KC_SLSH,   KC_RSFT,
                                      KC_DEL, KC_LSFT, MO(_NAV), KC_SPC, KC_TAB, /**/    KC_ENT, KC_BSPC, MO(_NUM), KC_RSFT, KC_RBRC
    ),

// Left thumb
[_MEDIA] = LAYOUT_kyria(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                  /**/                         RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                  /**/                          KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_RALT, XXXXXXX, QWERTY,   CMK_FR, XXXXXXX, _______,/**/       _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, /**/      KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
),
[_NAV] = LAYOUT_kyria(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    /**/                         KC_PSTE, KC_COPY,  KC_CUT,  KC_UNDO,  KC_AGAIN, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   /**/                         KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, KC_CAPS, _______,
  _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, /**/       _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, _______,
                             _______, _______, _______, _______, _______, /**/       KC_ENT, KC_BSPC, KC_DEL, _______, _______
),
[_MOUSE] = LAYOUT_kyria(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    /**/                         KC_PSTE, KC_COPY,  KC_CUT,  KC_UNDO,  KC_AGAIN, _______,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                  /**/                         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,   XXXXXXX, _______, _______,/**/       _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
                              _______, _______, _______, _______, _______, /**/       KC_BTN2, KC_BTN1, KC_BTN3, _______, _______
),


// Right thumb
[_NUM] = LAYOUT_kyria(
  _______, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                      /**/                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                      /**/                  XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  _______, KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS, _______, _______,   /**/   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______,
                      _______,  _______, KC_DOT, KC_0, KC_MINS, /**/   _______, _______, _______, _______, _______
),
[_SYM] = LAYOUT_kyria(
  _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      /**/                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      /**/                  XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______,   /**/   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______,
                               _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, /**/   _______, _______, _______, _______, _______
),
[_FUN] = LAYOUT_kyria(
  KC_LALT, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                  /**/                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                  /**/                      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, XXXXXXX,/**/    _______, XXXXXXX, CMK_FR, QWERTY, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
                            _______, _______, KC_APP, KC_SPC,  KC_TAB,  /**/    _______, _______, _______, _______, _______
)

// Other
// [_PAD] = LAYOUT_kyria(
//   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                  /**/                         KC_NUM, KC_P7, KC_P8,  KC_P9, KC_PAST, KC_PSLS,
//   _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_SCRL,                  /**/                         KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PMNS,
//   _______, XXXXXXX, KC_RALT, XXXXXXX, KC_APP,  KC_PAUS, _______, _______,/**/       _______, _______, KC_P0, KC_P1, KC_P2, KC_P3,  KC_PEQL, XXXXXXX,
//                              _______, _______, _______, _______, _______,/**/       _______, _______, _______, _______, _______
// ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_kyria(
//       _______, _______, _______, _______, _______, _______,                   /**/                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                   /**/                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// NOTE: Deactivating kyria logo since oled is broken with my poor desoldering

// static void render_kyria_logo(void) {
//     static const char PROGMEM kyria_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
//         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
//         0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
//     };
//     oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
// }

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.4 "), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _CMK_FR:
            oled_write_ln_P(PSTR("CmkFr"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _CMK_FR:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media RGB\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Fun\n"), false);
            break;
        // case _PAD:
        //     oled_write_P(PSTR("Numpad\n"), false);
        //     break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        // NOTE: Deactivating this half since I broke the oled screen there

        // render_kyria_logo();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif
