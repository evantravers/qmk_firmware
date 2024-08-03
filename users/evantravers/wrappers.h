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
#define LAYOUT_ortho_4x10_wrapper(...)       LAYOUT_ortho_4x10(__VA_ARGS__)


#define ______LH_THUMBS______                              ESC_F19, SYMBL, TAB_SK
#define ______RH_THUMBS______                              KC_ENT, CNTRL, QUOTE_SK

#define ____LH_THUMBS_SYM____                              _______,    _______, _______
#define ____RH_THUMBS_SYM____                              _______, _______, KC_DQUO
#define ____LH_THUMBS_SHT____                              _______, MUTE, _______
#define ____RH_THUMBS_SHT____                              _______,    _______, _______

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ___________________BLANK___________________        _______, _______, _______, _______, _______
#define ______________MUSIC_______________                 KC_MPLY, KC_VOLD, KC_VOLU, PREV_NEXT
#define ______________ARROWS______________                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT



#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN)
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH



#define _________________SYMBL_L1__________________        KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE
#define _________________SYMBL_L2__________________        KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV
#define _________________SYMBL_L3__________________        KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD

#define _________________SYMBL_R1__________________        KC_CIRC, KC_UNDS, KC_PLUS, KC_SLSH, CW_TOGG
#define _________________SYMBL_R2__________________        KC_DQUO, KC_MINS, KC_EQL,  KC_ASTR, KC_COLN
#define _________________SYMBL_R3__________________        KC_AMPR, KC_QUES, KC_LT,   KC_GT,   KC_BSLS



#define _________________CNTRL_L1__________________        ________________NUMBER_LEFT________________
#define _________________CNTRL_L2__________________        ___________________BLANK___________________ // TODO: Prime real estate here.
#define _________________CNTRL_L3__________________        ___________________BLANK___________________ // TODO: Prime real estate here.

#define _________________CNTRL_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________CNTRL_R2__________________        ______________ARROWS______________, _______
#define _________________CNTRL_R3__________________        ___________________BLANK___________________ // TODO: Prime real estate here.



#define _________________ADJUST_L1_________________        QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI
#define _________________ADJUST_L2_________________        _________________FUNC_LEFT_________________
#define _________________ADJUST_L3_________________        _________________FUNC_RIGHT________________

#define _________________ADJUST_R1_________________        RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD
#define _________________ADJUST_R2_________________        _______, _______, _______, _______, _______ // TODO: Prime real estate here.
#define _________________ADJUST_R3_________________        _______, ______________MUSIC_______________



#define _______________SHORTCUTS_L1________________        KC_1,     KC_2,   KC_3,   KC_4, KC_5 // Do I really use these numbers?
#define _______________SHORTCUTS_L2________________        WIN_MUTE, SCRNST, ZOOMIN, TABN, HFWD
#define _______________SHORTCUTS_L3________________        KC_SPC,   KC_ENT, ZOOMOUT,TABP, HBCK

#define _______________SHORTCUTS_R1________________        KC_BSPC, KC_7, KC_8, KC_9, PASS
#define _______________SHORTCUTS_R2________________        KC_0,    KC_4, KC_5, KC_6, KC_TAB
#define _______________SHORTCUTS_R3________________        _______, KC_1, KC_2, KC_3, KC_DOT

#define QEND_L1 TAB_SK
#define QEND_L2 CTRL_ESC
#define QEND_L3 KC_LSFT

#define QEND_R1 KC_BSPC
#define QEND_R2 KC_QUOT
#define QEND_R3 KC_SFTENT

#define REND_L1 KC_GRV
#define REND_L2 KC_ESC
#define REND_L3 _______

#define REND_R1 _______
#define REND_R2 KC_BSLS
#define REND_R3 _______

#define LEND_L1 KC_TILD
#define LEND_L2 KC_CAPS
#define LEND_L3 _______

#define LEND_R1 _______
#define LEND_R2 KC_PIPE
#define LEND_R3 _______
