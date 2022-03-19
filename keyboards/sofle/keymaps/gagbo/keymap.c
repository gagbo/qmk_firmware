#include QMK_KEYBOARD_H
#include "gagbo.h"

#define KC_QWERTY DF(_QWERTY)
#define KC_COLEMAK DF(_COLEMAK)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
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
                         KC_LBRC, KC_LALT,  KC_ESC, KC_SPC, MO(_LOWER), /**/   KC_ENT,  MO(_RAISE), KC_DEL, KC_RALT, KC_RBRC
),
/*
 * COLEMAK
 * cf BuJo
 */

[_COLEMAK] = LAYOUT(
  KC_GRV,          KC_1,         KC_2,          KC_3,          KC_4,          KC_5,                                          KC_6,     KC_7,          KC_8,          KC_9,           KC_0,       KC_BSPC,
  KC_TAB,          KC_Q,         KC_W,          KC_F,          KC_P,          KC_B,                                          KC_J,     KC_L,          KC_U,          KC_Y,           KC_SCLN,    KC_DEL,
  LCTL_T(KC_ESC),  KC_A,         KC_R,          KC_S,          KC_T,          KC_G,                                          KC_M,     KC_N,          KC_E,          KC_I,           KC_O, RCTL_T(KC_QUOT),
  KC_LSFT,         KC_Z,         KC_X,          KC_C,          KC_D,          KC_V,       KC_MUTE,            /**/ KC_MPLY,  KC_K,     KC_H,          KC_COMM,       KC_DOT,         KC_SLSH,    KC_RSFT,
                                 KC_LGUI, KC_LALT,  LT(_LOWER, KC_ESC), KC_SPC, KC_TAB, /**/ KC_ENT, KC_BSPC, LT(_RAISE, KC_DEL),       KC_RALT,       KC_RGUI
),
/* LOWER
 * cf BuJo
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_F12,
  KC_LALT, KC_GRV,  KC_7,    KC_8,    KC_9,    XXXXXXX,                      XXXXXXX, XXXXXXX, KC_EQL, KC_LPRN, KC_RPRN, KC_BSLS,
  KC_LCTL, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_DOT,                       XXXXXXX, XXXXXXX, KC_MINS, KC_LBRC, KC_RBRC, XXXXXXX,
  KC_LSFT,   KC_0,  KC_1,    KC_2,    KC_3,    KC_0, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______,  _______,    _______,    _______, _______, _______, _______, _______
),
/* RAISE
 * cf BuJo
 */
[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_F12,
  KC_LALT, KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_PLUS, KC_LPRN, KC_RPRN, KC_PIPE,
  KC_LCTL, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_UNDS, KC_LCBR, KC_RCBR, XXXXXXX,
  KC_LSFT, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * cf BuJo
 */
[_ADJUST] = LAYOUT(
  KC_ESC,  XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LALT, XXXXXXX, KC_COLEMAK, KC_QWERTY, XXXXXXX,   KC_PSCR,                      XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
  KC_LCTL, KC_MPRV,  KC_VOLD,   KC_VOLU,   KC_MNXT,   KC_SLCK,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  _______, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PAUS, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,  _______,     _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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
        case _LOWER:
            oled_write_P(PSTR("Lower\n\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n\n"), false);
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

