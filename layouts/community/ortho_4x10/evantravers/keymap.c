#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "evantravers.h"

extern keymap_config_t keymap_config;

#define LAYOUT_ortho_4x10_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x10_wrapper( \
    K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     \
    K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     \
    K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
#define LAYOUT_ortho_4x10_base_wrapper(...)       LAYOUT_ortho_4x10_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Should I take the outer thumb key and move it to pinky row for this? */

  [_QWERTY] = LAYOUT_ortho_4x10_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
    _______, _______, ______LH_THUMBS______,     ______RH_THUMBS______, _______, _______
  ),

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
