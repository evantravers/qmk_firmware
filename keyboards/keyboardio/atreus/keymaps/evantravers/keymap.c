// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "evantravers.h"

#define LAYOUT_atreus_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                   KTA, KTB, KTC, KTD                 \
  ) \
  LAYOUT_wrapper( \
    K01, K02, K03, K04, K05,           K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15,           K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25,           K26, K27, K28, K29, K2A, \
    ___, ___, ___, ___, KTA, KTB, KTC, KTD, ___, ___, ___, ___  \
  )
#define LAYOUT_atreus_base_wrapper(...)       LAYOUT_atreus_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    _________________QWERTY_L1_________________,                   _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________,                   _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, KC_GRV,  KC_BSLS, _________________QWERTY_R3_________________,
       KC_F19, _______, _______, ______LH_THUMBS______,  ______RH_THUMBS______, _______, _______, _______ \
  ),
  [_LOWER] = LAYOUT_wrapper(
    _________________LOWER_L1__________________,                    _________________LOWER_R1__________________,
    _________________LOWER_L2__________________,                    _________________LOWER_R2__________________,
    _________________LOWER_L3__________________, _______,  _______, _________________LOWER_R3__________________,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
  [_RAISE] = LAYOUT_wrapper(
    _________________RAISE_L1__________________,                    _________________RAISE_R1__________________,
    _________________RAISE_L2__________________,                    _________________RAISE_R2__________________,
    _________________RAISE_L3__________________, _______,  _______, _________________RAISE_R3__________________,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
  [_ADJUST] = LAYOUT_wrapper(
    _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,
    _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________, _______,  _______, _________________ADJUST_R3_________________,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
