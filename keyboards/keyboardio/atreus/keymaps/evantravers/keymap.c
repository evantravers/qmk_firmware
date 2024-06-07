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
    _________________QWERTY_L3_________________, _______, _______, _________________QWERTY_R3_________________,
       _______, _______, _______, ______LH_THUMBS______,  ______RH_THUMBS______, _______, _______, _______ \
  ),
  [_SYMBL] = LAYOUT_wrapper(
    _________________SYMBL_L1__________________,                    _________________SYMBL_R1__________________,
    _________________SYMBL_L2__________________,                    _________________SYMBL_R2__________________,
    _________________SYMBL_L3__________________, _______,  _______, _________________SYMBL_R3__________________,
       _______, _______, _______, ____LH_THUMBS_SYM____,  ____RH_THUMBS_SYM____, _______, _______, _______ \
  ),
  [_CNTRL] = LAYOUT_wrapper(
    _________________CNTRL_L1__________________,                    _________________CNTRL_R1__________________,
    _________________CNTRL_L2__________________,                    _________________CNTRL_R2__________________,
    _________________CNTRL_L3__________________, _______,  _______, _________________CNTRL_R3__________________,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
  [_ADJUST] = LAYOUT_wrapper(
    _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,
    _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________, _______,  _______, _________________ADJUST_R3_________________,
     KC_F12, KC_DEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_GAMING) \
  ),

  [_SHORTCUTS] = LAYOUT_wrapper(
    _______________SHORTCUTS_L1________________,                    _______________SHORTCUTS_R1________________,
    _______________SHORTCUTS_L2________________,                    _______________SHORTCUTS_R2________________,
    _______________SHORTCUTS_L3________________, _______,  _______, _______________SHORTCUTS_R3________________,
       _______, _______, _______, ____LH_THUMBS_SHT____,  ____RH_THUMBS_SHT____, _______, _______, _______ \
  ),

  [_GAMING] = LAYOUT_wrapper(
    ________________NUMBER_LEFT________________,                    ________________NUMBER_RIGHT_______________,
    TAB_ESC, KC_Q,    KC_W,    KC_E,    KC_R,                       _______, _______, _______, _______, _______,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,   KC_LALT,      KC_T, _______, _______, _______, _______, _______,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_SPC, MO(_GAMING2), KC_V, _______, _______, _______, _______, TO(_QWERTY) \
  ),

  [_GAMING2] = LAYOUT_wrapper(
    ________________NUMBER_RIGHT_______________,                   _________________FUNC_LEFT_________________,
    KC_O,    KC_I,    KC_U, KC_Y, KC_T,                            _________________FUNC_RIGHT________________,
    KC_L,    KC_K,    KC_J, KC_H, KC_G,          KC_V,    _______, _______, _______, _______, _______, _______,
    KC_P,    _______, KC_M, KC_N, KC_B,          _______, _______, _______, _______, _______, _______, _______ \
  )
};

/*https://github.com/winterNebs/qmk_firmware/blob/5d55f9b3ce3d57a65ee9860cd317f0d9001aa7e2/users/winternebs/winternebs.c#L25*/
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_QWERTY)) {
        return true;
    }
    return false;
}
