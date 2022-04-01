/* Copyright 2015-2017 Jack Humbert
 * Modified by KeyPCB for the Fractal keyboard
 * Modified by @evantravers for preonic
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "evantravers.h"
#include "rev3.h"

#define LAYOUT_preonic_2x2u_wrapper(...) LAYOUT_preonic_2x2u(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_preonic_2x2u(
  ESC_F19, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_QWERTY),
  TAB_SK,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, SYMBL,   KC_LGUI, KC_LALT,          KC_SPC,  KC_SPC,           KC_RALT, KC_RGUI, CNTRL,   KC_RCTL
),

[_QWERTY] = LAYOUT_preonic_2x2u_wrapper(
  ESC_F19, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_GAMING),
  TAB_SK,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
  KC_LCTL, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_SFTENT,
  KC_LCTL, SYMBL,   KC_LGUI, ESC_F19,          SYMBL,   CNTRL,            QUOTE_SK,KC_RGUI, CNTRL,   KC_RCTL
),

[_SYMBL] = LAYOUT_preonic_2x2u_wrapper(
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _________________SYMBL_L1__________________, _________________SYMBL_R1__________________, KC_PGUP,
  _______, _________________SYMBL_L2__________________, _________________SYMBL_R2__________________, KC_PGDN,
  _______, _________________SYMBL_L3__________________, _________________SYMBL_R3__________________, _______,
  _______, _______, _______, _______,          _______, _______,          KC_DQUO, _______, _______, _______
),

[_CNTRL] = LAYOUT_preonic_2x2u_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  _________________CNTRL_L1__________________, _________________CNTRL_R1__________________, KC_DEL,
  KC_DEL,  _________________CNTRL_L2__________________, _________________CNTRL_R2__________________, KC_BSLS,
  _______, _________________CNTRL_L3__________________, _________________CNTRL_R3__________________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD
),

[_ADJUST] = LAYOUT_preonic_2x2u_wrapper(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, KC_DEL,
  _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, _______,
  _______, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_SHORTCUTS] = LAYOUT_preonic_2x2u_wrapper(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
  _______, _______________SHORTCUTS_L1________________, _______________SHORTCUTS_R1________________, KC_DEL,
  _______, _______________SHORTCUTS_L2________________, _______________SHORTCUTS_R2________________, _______,
  _______, _______________SHORTCUTS_L3________________, _______________SHORTCUTS_R3________________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

