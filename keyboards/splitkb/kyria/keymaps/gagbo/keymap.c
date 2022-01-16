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
    _COLEMAK_DH = 0,
    _BEPO,
    _QWERTY,
//    _NAV,
//    _SYM,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
};

#define ADJUST   MO(_ADJUST)
// #define SYM      MO(_SYM)
// #define NAV      MO(_NAV)
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define BEPO   DF(_BEPO)

/** Bottom Row */
#define BR01 KC_LALT
#define BR02 KC_LCTL
#define BR03 KC_BSPC
#define BR04 KC_DEL
#define BR05 LOWER
#define BR06 RAISE
#define BR07 KC_ENT
#define BR08 KC_SPC
#define BR09 KC_RALT
#define BR10 KC_APP

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)

#define SFT_PGUP MT(MOD_LSFT, KC_PGUP)
#define SFT_MINS  MT(MOD_RSFT, KC_MINS)
#define CTL_EQL MT(MOD_RCTL, KC_EQL)
#define ALT_LBRC MT(MOD_LALT, KC_LBRC)
#define GUI_RBRC  MT(MOD_RGUI, KC_RBRC)
#define SFT_UNDS  MT(MOD_RSFT, KC_UNDS)
#define CTL_PLUS MT(MOD_RCTL, KC_PLUS)
#define ALT_LCBR MT(MOD_LALT, KC_LCBR)
#define GUI_RCBR  MT(MOD_RGUI, KC_RCBR)

#define HM_EXLM  MT(MOD_LGUI, KC_EXLM)
#define HM_AT MT(MOD_LALT, KC_AT)
#define HM_HASH MT(MOD_RCTL, KC_HASH)
#define HM_DLR  MT(MOD_LSFT, KC_DLR)

#define HM_AMPR  MT(MOD_RSFT, KC_AMPR)
#define HM_ASTR MT(MOD_RCTL, KC_ASTR)
#define HM_LPRN MT(MOD_LALT, KC_LPRN)
#define HM_RPRN  MT(MOD_LGUI, KC_RPRN)


#define ______________BOTTOM_ROW_BP________________      BR01,   BR02,   BR03, BR04, BR05,  BR06, BR07,  BR08,   BR09,   BR10
#define __UPPER_ROW_BP_       KC_TAB, KC_ESC, FKEYS, MO(RAISE)

#define _______________BOTTOM_ROW__________________     KC_LGUI , KC_RALT, KC_SPC, KC_DEL , LOWER   ,     RAISE , KC_ENT ,KC_SPC, KC_RALT, KC_APP

#define ________________BEPO_HOME_L1_______________       KC_ESC,      BP_B,      BP_EA,       BP_P,      BP_O,  BP_EG
#define ________________BEPO_HOME_L2_______________       BP_W,   HOME_BP_A,  HOME_BP_U,  HOME_BP_I, HOME_BP_E,  BP_CO
#define ________________BEPO_HOME_L3_______________       KC_LSFT,    BP_AG,       BP_Y,       BP_X,     BP_DT,   BP_K

#define ________________BEPO_HOME_R1_______________       BP_DC,       BP_V,       BP_D,       BP_L,      BP_J,   BP_Z
#define ________________BEPO_HOME_R2_______________       BP_C,   HOME_BP_T,  HOME_BP_S,  HOME_BP_R, HOME_BP_N,   BP_M
#define ________________BEPO_HOME_R3_______________       BP_AP,       BP_Q,       BP_G,       BP_H,      BP_F, BP_CCED

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   TAB  |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   ESC  |   A  |   R  |  S   |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |   '    |
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [    |CapsLk|  |FunKey|    ] |   K  |   H  |   ,  |   .  |   /  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI | AltGr| Space| Del  |      |  |      | Enter| Space| AltGr| Menu |
 *                        |      |      |      |      | Lower|  | Raise|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT_kyria(
      _________________CMK_DH_L1_________________,                                    _________________CMK_DH_R1_________________,
      _________________CMK_DH_L2_________________,                                    _________________CMK_DH_R2_________________,
      _________________CMK_DH_L3_________________, KC_LBRC, KC_CAPS, FKEYS, KC_RBRC,  _________________CMK_DH_R3_________________,
                                      _______________BOTTOM_ROW__________________
    ),

/*
 * Base Layer: BÉPO
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   B  |   É  |   P  |   O  |   È  |                              |   ^  |   V  |   D  |   L  |   J  |  | Z   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |  I   |   E  |   ,  |                              |   C  |   T  |   S  |   R  |   N  |   M    |
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   À  |   Y  |   X  |   .  |   K  | Tab  | Esc  |  |F-keys| Raise|   ’  |   Q  |   G  |   H  |   F  |   Ç    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Alt  | Ctrl | Bksp | Del  |      |  |      | Enter| Space| AltGr| Menu |
 *                        |      |      |      |      | Nav  |  | Sym  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BEPO] = LAYOUT_kyria(
      ________________BEPO_HOME_L1_______________,                   ________________BEPO_HOME_R1_______________,
      ________________BEPO_HOME_L2_______________,                   ________________BEPO_HOME_R2_______________,
      ________________BEPO_HOME_L3_______________, __UPPER_ROW_BP_,  ________________BEPO_HOME_R3_______________,
                                      ______________BOTTOM_ROW_BP________________
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI | AltGr| Bksp | Del  |      |  |      | Enter| Space| AltGr| Menu |
 *                        |      |      |      |      | Nav  |  | Sym  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT_kyria(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                      _______________BOTTOM_ROW__________________
    ),

// /*
//  * Nav Layer: Media, navigation
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |  É   |   È  |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |   Ê  |   Ù  |      |   À  |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_NAV] = LAYOUT(
//       _______, _______, KC_EACU, KC_EGRV, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
//       _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
//       _______, KC_EGRV, KC_UGRV, _______, KC_AGRV, _______, _______, KC_SLCK, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Sym Layer: Numbers and symbols
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
//  * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_SYM] = LAYOUT(
//       KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
//      KC_TILD , HM_EXLM,  HM_AT , HM_HASH,  HM_DLR, KC_PERC,                                     KC_CIRC, HM_AMPR, HM_ASTR, HM_LPRN, HM_RPRN, KC_PLUS,
//      KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      |      |      |      |      |        |
 * |        |      |      |      |      |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, BEPO   , _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Raise: Unshifted symbols and navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   1  |   2  |  3   |   4  |  5   |                              |  6   |   7  |   8  |   9  |  0   |  Del   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      | PgUp | Home |                              |      |   -  |   =  |   [  |  ]   |   \    |
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |VolMut| VolDn| VolUp| PgDn |  End |      |      |  |      |      |   ←  |   ↓  |  ↑   |   →  |      |  PrtSc |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
       KC_GRV,    KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                                         KC_6,     KC_7,    KC_8,     KC_9,     KC_0,  KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, SFT_PGUP, KC_HOME,                                      _______, SFT_MINS, CTL_EQL, ALT_LBRC, GUI_RBRC, KC_BSLS,
      _______, KC_MUTE, KC_VOLD, KC_VOLU,  KC_PGDN,  KC_END, _______, _______,  _______, _______, KC_LEFT,  KC_DOWN,   KC_UP,  KC_RGHT,  _______, KC_PSCR,
                                 _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______
    ),

/*
 * Lower: Shifted symbols and custom keycodes
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ~   |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |   (  |   )  |  Del   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |   _  |   +  |   {  |   }  |   |    |
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    Ê   |   Ù  |   É  |   È  |   À  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                      _______, SFT_UNDS, CTL_PLUS, ALT_LCBR, GUI_RCBR, KC_PIPE,
      KC_ECIR, KC_UGRV, KC_EACU, KC_EGRV, KC_AGRV, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,  _______, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______
    ),

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
//       _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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
    oled_write_P(PSTR("Kyria rev1.4 Gerry\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BEPO:
            oled_write_P(PSTR("BEPO\n"), false);
            break;
        case _COLEMAK_DH:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower SAcc\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FKeys\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise UNav\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
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
