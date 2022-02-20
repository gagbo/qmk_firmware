#include QMK_KEYBOARD_H
#include "gagbo.h"

#define KC_QWERTY DF(_QWERTY)
#define KC_COLEMAK DF(_COLEMAK)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
    _MEDIA,
    _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,           KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LCTL,          KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,    KC_COLEMAK, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                         KC_LBRC, KC_LALT,  KC_ESC, MO(_NAV), KC_SPC, /**/   KC_ENT,  MO(_FUN), KC_DEL, KC_RALT, KC_RBRC
),
/*
 * COLEMAK
 * cf BuJo
 */

[_COLEMAK] = LAYOUT(
  KC_GRV,          KC_1,         KC_2,          KC_3,          KC_4,          KC_5,                                          KC_6,     KC_7,          KC_8,          KC_9,           KC_0,       KC_BSPC,
  KC_TAB,          KC_Q,         KC_W,          KC_F,          KC_P,          KC_B,                                          KC_J,     KC_L,          KC_U,          KC_Y,           KC_SCLN,    KC_BSLS,
  LCTL_T(KC_ESC),  HOME_CMK_A,   HOME_CMK_R,    HOME_CMK_S,    HOME_CMK_T,    KC_G,                                          KC_M, HOME_CMK_N,        HOME_CMK_E,    HOME_CMK_I,     HOME_CMK_O, RCTL_T(KC_QUOT),
  KC_LSFT,         KC_Z,         RALT_T(KC_X),  KC_C,          KC_D,          KC_V,       KC_MUTE,            /**/ KC_MPLY,  KC_K,     KC_H,          KC_COMM,       RALT_T(KC_DOT), KC_SLSH,    KC_RSFT,
                                 KC_LGUI, KC_LALT,  LT(_MEDIA, KC_ESC), LT(_NAV, KC_TAB), LT(_MOUSE, KC_SPC), /**/ LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL),       KC_RALT,       KC_RGUI
),
/* NAV
 * cf BuJo
 */
[_NAV] = LAYOUT(
  KC_ESC,  _______, _______, _______, _______, _______,                         _______, _______,  _______, _______, _______, _______,
  KC_LALT, _______, _______, _______, _______, _______,                         KC_INS,  KC_HOME,  KC_UP,   KC_END,  KC_PGUP, _______,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                         KC_CAPS, KC_LEFT,  KC_DOWN, KC_RGHT, KC_PGDN, _______,
  _______, _______, KC_RALT, _______, _______, _______, _______,       _______, KC_AGIN, KC_PASTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
                    _______, _______, _______, _______, _______,       KC_ENT, KC_BSPC, KC_DEL, _______, _______
),
/* MOUSE
 * cf BuJo
 */
[_MOUSE] = LAYOUT(
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_WH_L, KC_MS_U,  KC_WH_R, KC_WH_U, XXXXXXX,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                         XXXXXXX, KC_MS_L, KC_MS_D,  KC_MS_R, KC_WH_D, XXXXXXX,
  _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, _______,       _______, KC_AGIN, KC_PASTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
                    _______, _______, _______, _______, _______,       KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
),
/* MEDIA
 * cf BuJo
 */
[_MEDIA] = LAYOUT(
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                         XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,       KC_MSTP, KC_MPLY, KC_MUTE, _______, KC_PSCR
),
/* NUM
 * cf BuJo
 */
[_NUM] = LAYOUT(
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LALT, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                       XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
                    _______, _______, KC_DOT,  KC_0,    KC_MINS,    _______, _______, _______, _______, _______
),
/* SYM
 * cf BuJo
 */
[_SYM] = LAYOUT(
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LALT, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                         XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
                    _______, _______, KC_LPRN, KC_RPRN, KC_UNDS,       _______, _______, _______, _______, _______
),
/* FUN
 * cf BuJo
 */
[_FUN] = LAYOUT(
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LALT, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                      XXXXXXX, KC_COLEMAK, KC_QWERTY, XXXXXXX, XXXXXXX, RESET,
  KC_LCTL, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                      XXXXXXX, KC_RSFT,    KC_RCTL,   KC_LALT, KC_RGUI, XXXXXXX,
  _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,    _______, XXXXXXX, XXXXXXX,    XXXXXXX,   KC_RALT, XXXXXXX, XXXXXXX,
                    _______, _______, KC_APP,  KC_TAB,  KC_SPC,     _______, _______, _______, _______, _______
)
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_ln_P(PSTR("Sofle"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Fun\nMeta\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR("CAPS ON"), false);
    } else {
        oled_write_ln_P(PSTR("Caps Off"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

