#include "evantravers.h"

extern uint8_t is_master;

#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    TAB_SK,   K01, K02, K03, K04, K05,      K06, K07, K08, K09, K0A, KC_BSPC, \
    CTRL_ESC, K11, K12, K13, K14, K15,      K16, K17, K18, K19, K1A, KC_QUOT, \
    KC_F19,   K21, K22, K23, K24, K25,      K26, K27, K28, K29, K2A, SHORTCUTS, \
                ______LH_THUMBS______,      ______RH_THUMBS______ \
  )
#define LAYOUT_crkbd_base_wrapper(...)       LAYOUT_crkbd_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_crkbd_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_SYMBL] = LAYOUT_wrapper(
    LEND_L1, _________________SYMBL_L1__________________,                    _________________SYMBL_R1__________________, LEND_R1,
    LEND_L2, _________________SYMBL_L2__________________,                    _________________SYMBL_R2__________________, LEND_R2,
    LEND_L3, _________________SYMBL_L3__________________,                    _________________SYMBL_R3__________________, LEND_R3,
                                         ____LH_THUMBS_SYM____,        ____RH_THUMBS_SYM____
  ),

  [_CNTRL] = LAYOUT_crkbd_base_wrapper( \
    _________________CNTRL_L1__________________, _________________CNTRL_R1__________________,
    _________________CNTRL_L2__________________, _________________CNTRL_R2__________________,
    _________________CNTRL_L3__________________, _________________CNTRL_R3__________________
  ),

  [_ADJUST] = LAYOUT_crkbd_base_wrapper(
    _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
    _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________, _________________ADJUST_R3_________________
  ),

  [_SHORTCUTS] = LAYOUT_crkbd_base_wrapper(
    _______________SHORTCUTS_L1________________, _______________SHORTCUTS_R1________________,
    _______________SHORTCUTS_L2________________, _______________SHORTCUTS_R2________________,
    _______________SHORTCUTS_L3________________, _______________SHORTCUTS_R3________________
  )
};
// clang-format on
