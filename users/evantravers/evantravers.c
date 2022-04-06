/*
Copyright 2019 Evan Travers <evantravers@gmail.com> @evantravers

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "evantravers.h"
#include "features/caps_word.h"

uint32_t user_key_timer;
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC]    = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
  [TD_TAB_ESC]     = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
  [TD_PREV_NEXT]   = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_MRWD),
  [TD_SCRNST]      = ACTION_TAP_DANCE_DOUBLE(LGUI(LSFT(LCTL(KC_4))), LGUI(LSFT(KC_4))),
  [TD_MUTE]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_GRV), LGUI(LSFT(KC_M))),
  [TD_SPCRET]      = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT)
};

#ifdef AUDIO_ENABLE
float gaming[][2] = SONG(AG_SWAP_SOUND);
float qwerty[][2] = SONG(UNICODE_LINUX);
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }

    switch (keycode) {
        case TO(_GAMING):
#ifdef AUDIO_ENABLE
            PLAY_SONG (gaming);
#endif
        return true; break;
        case TO(_QWERTY):
#ifdef AUDIO_ENABLE
            PLAY_SONG (qwerty);
#endif
        return true; break;
        case ESC_F19:
            if (record->event.pressed) {
                user_key_timer = timer_read();
                register_code(KC_F19);
            } else {
                unregister_code(KC_F19);
                if (timer_elapsed(user_key_timer) < get_tapping_term(keycode, record)) {
                    tap_code(KC_ESC);
                }
            }
            return false; break;
        default:
            return true; // Process all other keycodes normally
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBL, _CNTRL, _ADJUST);
}
