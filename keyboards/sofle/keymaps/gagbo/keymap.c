#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "gagbo.h"

#define KC_QWERTY DF(_QWERTY)
#define KC_COLEMAK DF(_COLEMAK_FR)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK_FR,
    _NAV,
    _NUM,
    _SYM,
    _FUNCTION,
};

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define FKEYS    MO(_FUNCTION)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | RAlt |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Ctl-'|
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * |FKeys |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Nav  |Space | / Num   /       \  Sym \  | Bspc | LSft |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_GRV,           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  OS_RALT,
  KC_TAB,           KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  LCTL_T(KC_ESC),   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  RCTL_T(KC_QUOT),
  FKEYS ,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,    KC_MPLY, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                         XXXXXXX, XXXXXXX,   NAV  , KC_SPC,  NUM  , /**/   SYM  , KC_BSPC, OS_SHFT, XXXXXXX, XXXXXXX
),

/*
 * Colemak FR
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | RAlt |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   O  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CtlEsc|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   U  | Ctl-'|
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * | FKeys|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Nav  |Space | /  Num  /       \  Sym \  | Bspc | LSft |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAK_FR] = LAYOUT(
  KC_GRV,         KC_1, KC_2, KC_3, KC_4, KC_5,                              KC_6,  KC_7,KC_8, KC_9, KC_0, OS_RALT,
  KC_TAB,         KC_Q, KC_W, KC_F, KC_P, KC_B,                              KC_J,     KC_L,    KC_O,    KC_Y,   KC_SCLN, KC_BSPC,
  LCTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_G,                   KC_M,  KC_N,    KC_E,    KC_I, KC_U,  RCTL_T(KC_QUOT),
  FKEYS  ,        KC_Z, KC_X, KC_C, KC_D, KC_V,  KC_MUTE, KC_MPLY,      KC_K, KC_H,    KC_COMMA,    KC_DOT,   KC_SLSH, KC_ENT,
                         XXXXXXX, XXXXXXX,  NAV  , KC_SPC,  NUM  , /**/   SYM  , KC_BSPC, OS_SHFT, XXXXXXX, XXXXXXX
),

/* Nav
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      | PrSc |                    | Home | PgDn | PgUp | End  | VolUp| Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  |  Alt | Ctrl | Shift| CAPS |-------.    ,-------| Left | Down |  Up  | Rght | VolDn| Ins  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | AltGr|      |      |      |-------|    |-------| Pause|M Prev|M Play|M Next|VolMut| PrtSc|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,
  XXXXXXX, _______, XXXXXXX,  _______, _______,  KC_PSCR,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, KC_DEL,
  XXXXXXX, OS_GUI, OS_ALT,  OS_CTRL,  OS_SHFT,  CW_TOGG,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_INS,
  _______, _______, OS_RALT,  XXXXXXX,  XXXXXXX,  XXXXXXX, _______,    _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                    _______, _______, _______,  _______,     _______,    _______, _______, _______, _______, _______
),

/* Sym (Ergol/Qwerty-Lafayette symbol layer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Alt  |   1  |   [  |   ]  |   $  |   %  |                    |   ^  |   &  |   *  |   '  |   0  | Alt  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctl  |  {   |   (  |   )  |   }  |   =  |-------.    ,-------|   +  |   -  |   <  |   >  |   "  | Ctl  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Sft  |  ~   |   `  |   |  |   _  |   /  |-------|    |-------|   \  |   @  |   #  |   !  |   ?  | Sft  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Enter /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    KC_LALT, KC_1,    KC_LBRC, KC_RBRC,  KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_0,   KC_LALT,
    KC_LCTL, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,  KC_EQL,                        KC_PLUS, KC_MINS, KC_LABK, KC_RABK, KC_DQUO, KC_RCTL,
    KC_LSFT, KC_TILD, KC_GRV,  KC_PIPE, KC_UNDS,  KC_SLSH, _______,     _______, KC_BSLS, KC_AT,   KC_HASH, KC_EXLM, KC_QUES,  KC_RSFT,
                    _______, _______, _______, _______,  KC_ENT,       _______, _______, _______, _______, _______
),

/* Num 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  %   |                    |  .   |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  |  Alt | Ctrl | Shift|      |-------.    ,-------|  *   |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | RAlt |      |      |      |-------|    |-------|  =   |   1  |   2  |   3  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \Enter \  | Bksp |  0   |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC,                      KC_DOT ,  KC_7  ,  KC_8  ,  KC_9  , KC_MINS, _______,
  XXXXXXX, OS_GUI , OS_ALT , OS_CTRL, OS_SHFT, XXXXXXX,                      KC_ASTR,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS, _______,
  _______, XXXXXXX, OS_RALT, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, KC_EQL ,  KC_1  ,  KC_2  ,  KC_3  , KC_SLSH, _______,
                    _______, _______, _______, _______,  _______,   KC_ENT , KC_BSPC, KC_0, _______, _______
),

/* Function
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Qwerty|Colmak|      |MacWin| PScr |                    |      |  F7  |  F8  |  F9  |  F12 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  GUI |  Alt | Ctrl | Shift|      |-------.    ,-------|      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  RGB |  RGB |  RGB |  RGB |  RGB |-------|    |-------|      |  F1  |  F2  |  F3  |  F10 |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FUNCTION] = LAYOUT(
  QK_BOOT,  XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_QWERTY, KC_COLEMAK, XXXXXXX, CG_TOGG,   KC_PSCR,                      XXXXXXX,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F12, XXXXXXX,
  XXXXXXX,  OS_GUI ,  OS_ALT ,  OS_CTRL,   OS_SHFT,   XXXXXXX,                      XXXXXXX,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F11, XXXXXXX,
  _______, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, _______,    _______, XXXXXXX,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F10, _______,
                                _______, _______, _______, _______,  _______,     _______, _______, _______, _______, _______
)

};
// clang-format on

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
    if (is_mac_the_default()) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK_FR:
            oled_write_ln_P(PSTR("HardW"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_FR:
            oled_write_P(PSTR("Clmk\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwrt\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Fun\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR("CAPS"), false);
    } else {
        oled_write_ln_P(PSTR("    "), false);
    }

    if (is_gui_held()) {
        oled_write_P(PSTR("G"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }
    if (is_alt_held()) {
        oled_write_P(PSTR("A"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }
    if (is_ctrl_held()) {
        oled_write_P(PSTR("C"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }
    if (is_shift_held()) {
        oled_write_P(PSTR("S"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }
    if (is_ralt_held()) {
        oled_write_P(PSTR("Gr"), false);
    } else {
        oled_write_P(PSTR("  "), false);
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

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case NAV:
        // case FKEYS:
        case NUM:
        // case SYM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case NAV:
        case FKEYS:
        case NUM:
        case SYM:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_RALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

