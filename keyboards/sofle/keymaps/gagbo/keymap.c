#include QMK_KEYBOARD_H
#include "gagbo.h"

#define KC_QWERTY DF(_QWERTY)
#define KC_HRM_OS DF(_HRM_OS)
#define KC_HRM_HW DF(_HRM_HW)
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


enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _HRM_OS,
    _HRM_HW,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_HRM_OS] = LAYOUT(
  KC_GRV        , KC_1,         KC_2     , KC_3   , KC_4   , KC_5   ,                              KC_6   ,  KC_7        ,KC_8      , KC_9   , KC_0       , KC_EQL         ,
  KC_TAB        , KC_Q,         KC_W     , KC_E,    KC_R,    KC_T   ,                              KC_Y,     KC_U     ,    KC_I  ,    KC_O ,   KC_P       , KC_MINS      ,
  LCTL_T(KC_ESC), HOME_A, HOME_S,  HOME_D,  HOME_F  ,  KC_G,                                         KC_H   ,  HOME_J     ,    HOME_K,    HOME_L , HOME_SCLN ,  RCTL_T(KC_QUOT),
  KC_LSFT       , KC_Z ,        HOME_X,    KC_C  ,  KC_V   , KC_B  ,  KC_MUTE                    , KC_MPLY,      KC_N     , KC_M,    KC_COMMA,    HOME_DOT      ,   KC_SLSH, KC_RSFT,
                                    KC_DEL, KC_EQL, KC_BSLS, KC_SPC, MO(_LOWER),   /****/    MO(_RAISE),  KC_BSPC, KC_ENT, KC_LBRC, KC_RBRC
),

[_HRM_HW] = LAYOUT(
  KC_GRV        , KC_1,         KC_2     , KC_3   , KC_4   , KC_5   ,                              KC_6   ,  KC_7        ,KC_8      , KC_9   , KC_0       , KC_EQL         ,
  KC_TAB        , KC_Q,         KC_W     , KC_F,    KC_P,    KC_B   ,                              KC_J,     KC_L     ,    KC_O  ,    KC_Y ,   KC_SCLN       , KC_MINS      ,
  LCTL_T(KC_ESC), HOME_A, HOME_CR,  HOME_CS,  HOME_CT  ,  KC_G,                                         KC_M   ,  HOME_CN,    HOME_CE,    HOME_CI, HOME_CU ,  RCTL_T(KC_QUOT),
  KC_LSFT       , KC_Z ,        HOME_X,    KC_C  ,  KC_D   , KC_V  ,  KC_MUTE                    , KC_MPLY,      KC_K     , KC_H,    KC_COMMA,    HOME_DOT      ,   KC_SLSH, KC_RSFT,
                                    KC_DEL, KC_EQL, KC_BSLS, KC_SPC, MO(_LOWER),   /****/    MO(_RAISE),  KC_BSPC, KC_ENT, KC_LBRC, KC_RBRC
),

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctl  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Esc  |    | Clmk  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  [   | LAlt | Esc  |Space | /LOWER  /       \ Ent  \  |RAISE | Del  | RAlt |  ]   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_GRV,           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,           KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LCTL,          KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,    KC_HRM_OS, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                         KC_LBRC, KC_LALT,  KC_ESC, KC_SPC, MO(_LOWER), /**/   KC_ENT,  MO(_RAISE), KC_DEL, KC_RALT, KC_RBRC
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Sclk | Pause| PrSc |                    | Home | PgDn | PgUp | End  | Del  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  |  Alt | Ctrl | Shift| CAPS |-------.    ,-------| Left | Down |  Up  | Rght | Ret  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | AltGr|      |      |      |-------|    |-------|      |      |      |      | Bspc |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,
  XXXXXXX, XXXXXXX, XXXXXXX,  KC_SCLN, KC_PAUSE,  KC_PSCR,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_F12,
  XXXXXXX, KC_LGUI, KC_LALT,  KC_LCTL,  KC_LSFT,  CW_TOGG,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT, _______,
  _______, KC_SPC, KC_RALT,  XXXXXXX,  XXXXXXX,  XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, _______, _______, KC_BSPC, _______,
                    _______, _______, _______,  _______,     _______,    _______, _______, _______, _______, _______
),

/* RAISE (Ergol/Qwerty-Lafayette symbol layer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  GUI |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | GUI  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Alt  |   1  |   [  |   ]  |   $  |   %  |                    |   ^  |   &  |   *  |   '  |   0  | Alt  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctl  |  {   |   (  |   )  |   }  |   =  |-------.    ,-------|   +  |   -  |   <  |   >  |   "  | Ctl  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Sft  |  ~   |   `  |   |  |   _  |   /  |-------|    |-------|   \  |   @  |   #  |   !  |   ?  | Sft  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |  F11 |  F12 |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    KC_LGUI,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_RGUI,
    KC_LALT, KC_1,    KC_LBRC, KC_RBRC,  KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_0,   KC_LALT,
    KC_LCTL, LGUI_T(KC_LCBR), LALT_T(KC_LPRN), LCTL_T(KC_RPRN), LSFT_T(KC_RCBR),  KC_EQL,                        KC_PLUS, RSFT_T(KC_MINS), RCTL_T(KC_LABK), LALT_T(KC_RABK), RGUI_T(KC_DQUO), KC_RCTL,
    KC_LSFT, KC_TILD, RALT_T(KC_GRV),  KC_PIPE, KC_UNDS,  KC_SLSH, _______,     _______, KC_BSLS, KC_AT,   KC_HASH, RALT_T(KC_EXLM), KC_QUES,  KC_RSFT,
                    KC_F11, KC_F12, _______, _______, _______,       _______, _______, _______, _______, _______
),

/* ADJUST (BT and RGB are reserved but unused on the Sofle here)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | HRMOS| HRMHW|Qwerty|      | PScr |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | RGB  | RGB  | RGB  | RGB  | RGB  |-------.    ,-------|      | VolD | Mute | VolU |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  BT  |  BT  |  BT  |  BT  |  BT  |-------|    |-------|      | Prev | Play | Next |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  QK_BOOT,  XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_HRM_OS, KC_HRM_HW, KC_QWERTY, XXXXXXX,   KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  _______, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, _______,    _______, KC_MRWD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MFFD, _______,
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
        case _HRM_HW:
            oled_write_ln_P(PSTR("HardW"), false);
            break;
        case _HRM_OS:
            oled_write_ln_P(PSTR("SoftW"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _HRM_HW:
        case _HRM_OS:
            oled_write_P(PSTR("Clmk\n\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwrt\n\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("NumFn\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n\n"), false);
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

