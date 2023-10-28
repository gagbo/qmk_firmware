#include "gagbo.h"

uint8_t mod_state;
uint8_t oneshot_mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
        case KC_AGRV:
            if (record->event.pressed) {
                // Temporarily cancel any active shift
                // to avoid messing with the dead grave shortcut
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                // Tap the dead grave shortcut
                tap_code16(ALGR(KC_GRV));
                // Restore original modifier state
                set_mods(mod_state);
                set_oneshot_mods(oneshot_mod_state);
                // Tap A with the original mod state
                tap_code(KC_A);
            }
            return false;
        case KC_EGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                tap_code16(ALGR(KC_GRV));
                set_mods(mod_state);
                set_oneshot_mods(oneshot_mod_state);
                tap_code(KC_E);
            }
            return false;
        case KC_EACU:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                tap_code16(ALGR(KC_QUOT));
                set_mods(mod_state);
                set_oneshot_mods(oneshot_mod_state);
                tap_code(KC_E);
            }
            return false;
        case KC_ECIR:
            if (record->event.pressed) {
                // Temporarily cancel any active shift
                // to avoid messing with the dead grave shortcut
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                // Tap the dead grave shortcut
                tap_code16(ALGR(KC_CIRC));
                // Restore original modifier state
                set_mods(mod_state);
                set_oneshot_mods(oneshot_mod_state);
                // Tap A with the original mod state
                tap_code(KC_E);
            }
            return false;
        case KC_UGRV:
            if (record->event.pressed) {
                // Temporarily cancel any active shift
                // to avoid messing with the dead grave shortcut
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                // Tap the dead grave shortcut
                tap_code16(ALGR(KC_GRV));
                // Restore original modifier state
                set_mods(mod_state);
                set_oneshot_mods(oneshot_mod_state);
                // Tap A with the original mod state
                tap_code(KC_U);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        // Left hand
        case LGUI_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(KC_GRV):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRV);
                return false;        // Return false to ignore further processing of key
            }
            break;
        // Right hand
        case RSFT_T(KC_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RCTL_T(KC_LABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LABK);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_RABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RABK);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RGUI_T(KC_DQUO):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(KC_EXLM):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EXLM);
                return false;        // Return false to ignore further processing of key
            }
            break;
        default:
            return true;
    }
            return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        // We are adding the semicolon keycode to deal with the case where
        // the Colemak layer is set on the OS level.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_SCLN:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
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
