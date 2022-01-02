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
        default:
            return true;
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
