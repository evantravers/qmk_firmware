#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "evantravers.h"

const uint16_t PROGMEM apos_combo[] = {RALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM hyper_combo[] = {LGUI_T(KC_A), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    COMBO(apos_combo, KC_QUOT),
    COMBO(hyper_combo, KC_F19),
    COMBO(esc_combo, KC_ESC),
};

extern keymap_config_t keymap_config;

#define LAYOUT_ortho_4x10_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x10_wrapper( \
    K01, K02, K03,     K04,     K05, K06,     K07,     K08, K09, K0A, \
    K11, K12, K13,     K14,     K15, K16,     K17,     K18, K19, K1A, \
    K21, K22, K23,     K24,     K25, K26,     K27,     K28, K29, K2A, \
    ___, ___, ______LH_THUMBS______, ______RH_THUMBS______, ___, ___  \
  )
#define LAYOUT_ortho_4x10_base_wrapper(...) LAYOUT_ortho_4x10_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Should I take the outer thumb key and move it to pinky row for this? */

  [_QWERTY]    = LAYOUT_ortho_4x10_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
    _______, _______, ______LH_THUMBS______, ______RH_THUMBS______, _______, _______ \
  ),

  [_SYMBL]     = LAYOUT_ortho_4x10_wrapper(
    _________________SYMBL_L1__________________, _________________SYMBL_R1__________________,
    _________________SYMBL_L2__________________, _________________SYMBL_R2__________________,
    _________________SYMBL_L3__________________, _________________SYMBL_R3__________________,
    _______, _______, ____LH_THUMBS_SYM____, ____RH_THUMBS_SYM____, _______, _______ \
  ),

  [_CNTRL]     = LAYOUT_ortho_4x10_wrapper(
    _________________CNTRL_L1__________________, _________________CNTRL_R1__________________,
    _________________CNTRL_L2__________________, _________________CNTRL_R2__________________,
    _________________CNTRL_L3__________________, _________________CNTRL_R3__________________,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_ADJUST]    = LAYOUT_ortho_4x10_wrapper(
    _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
    _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________, _________________ADJUST_R3_________________,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_SHORTCUTS] = LAYOUT_ortho_4x10_wrapper(
    _______________SHORTCUTS_L1________________, _______________SHORTCUTS_R1________________,
    _______________SHORTCUTS_L2________________, _______________SHORTCUTS_R2________________,
    _______________SHORTCUTS_L3________________, _______________SHORTCUTS_R3________________,
    _______, _______, ____LH_THUMBS_SHT____, ____RH_THUMBS_SHT____, _______, _______ \
  )
};

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case CNTRL:
    case SYMBL:
      return false;
    default:
      return true;
  }
};

/*https://github.com/winterNebs/qmk_firmware/blob/5d55f9b3ce3d57a65ee9860cd317f0d9001aa7e2/users/winternebs/winternebs.c#L25*/
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_QWERTY)) {
        return true;
    }
    return false;
}
