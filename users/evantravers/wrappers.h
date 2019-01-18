#pragma once
#include "evantravers.h"
/*
 * This is completely ripped off of @drashna's incredible work.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)


#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR,    KC_ASTR,     KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS,    KC_PLUS,     KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        ___________________BLANK___________________
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT



#define _________________ADJUST_L1_________________        RESET,   DEBUG,  RGB_TOG, RGB_MOD, RGB_HUI
#define _________________ADJUST_L2_________________        _______, MU_MOD, AU_ON,   AU_OFF,  _______
#define _________________ADJUST_L3_________________        MUV_DE,  MUV_IN, MU_ON,   MU_OFF,  MI_ON

#define _________________ADJUST_R1_________________        RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD
#define _________________ADJUST_R2_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_R3_________________        MI_OFF, TERM_ON, TERM_OFF, _______, _______
