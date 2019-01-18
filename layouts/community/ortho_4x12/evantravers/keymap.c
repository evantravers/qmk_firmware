#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "evantravers.h"

extern keymap_config_t keymap_config;

#define LAYOUT_ortho_4x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
    TAB_SK,   K01,     K02,     K03,     K04,   K05,    K06,    K07,   K08,     K09,     K0A,     KC_BSPC, \
    CTRL_ESC, K11,     K12,     K13,     K14,   K15,    K16,    K17,   K18,     K19,     K1A,     KC_QUOT, \
    KC_LSFT,  K21,     K22,     K23,     K24,   K25,    K26,    K27,   K28,     K29,     K2A,     KC_SFTENT, \
    KC_F19,   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_RGUI, KC_RALT, KC_RCTL, SHORTCUTS \
  )
#define LAYOUT_ortho_4x12_base_wrapper(...)       LAYOUT_ortho_4x12_base(__VA_ARGS__)

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | F19  | Ctrl | Alt  | GUI  |Lower | Space| Space|Raise | GUI  | Alt  | Ctrl | SCUTS|
 * `-----------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12_wrapper(
    TAB_SK,   _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    CTRL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSFT,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_SFTENT,
    KC_F19,   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,     KC_SPC, RAISE, KC_RGUI, KC_RALT, KC_RCTL,     SHORTCUTS
  ),

  [_LOWER] = LAYOUT_ortho_4x12_wrapper(
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_BSPC,
    KC_CAPS, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_RAISE] = LAYOUT_ortho_4x12_wrapper(
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_BSPC,
    KC_DEL,  _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_ADJUST] = LAYOUT_ortho_4x12_wrapper(
    _______, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, TO(_GAMING),
    _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, _______,
    _______, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, BL_STEP,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
};
