/* Copyright 2015-2017 Jack Humbert
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
#include "action_layer.h"

#define LOWER     MO(_LOWER)
#define RAISE     MO(_RAISE)
#define CTRL_ESC  TD(TD_CTRL_ESC)
#define TAB_SK    LT(_SKETCH, KC_TAB)
#define SCRNSHT   LSFT(LGUI(KC_4))
#define ZOOMIN    LGUI(KC_PLUS)
#define ZOOMOUT   LGUI(KC_MINS)

extern keymap_config_t keymap_config;

enum {
  TD_CTRL_ESC,
  TD_SHIFT_ENTER,
};

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SKETCH,
  _GAMING,
  _ADJUST
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC]    = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | F19  | Ctrl | Alt  | GUI  |Lower | Space| Space|Raise | GUI  | Alt  | Ctrl | Enter|
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = {
    {TAB_SK,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC},
    {CTRL_ESC, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT},
    {KC_F19,   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,  RAISE, KC_RGUI, KC_RALT, KC_RCTL, KC_F19}
  },

  /* Gaming
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   1  |   2  |   3  |   4  |   5  |      |      |      |      |      | Leave|
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |   Q  |   W  |   E  |   R  |   I  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   A  |   S  |   D  |   F  | Esc  |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Enter|   Z  |   X  |   C  |   V  | Space|      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_GAMING] = {
    {KC_TAB,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_QWERTY)},
    {CTRL_ESC, KC_Q,  KC_W,  KC_E,  KC_R,  KC_I,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_LSFT,  KC_A,  KC_S,  KC_D,  KC_F,  KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_ENT,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO}
},

/* Sketch
 * This is an attempt to make some of the shortcuts I use in Sketch.app easier
 * on a planck/lets split.
 *
 * The left hand should handle selection/zooming, and the right hand should
 * handle moving/aligment.
 *
 * ,-----------------------------------------------------------------------------------.
 * |      | CMD+1| CMD+2| CMD+3| CMD+4| CMD+5|      |      |      | Up   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |SCRST |      | ZOOM-| ZOOM+|      |      | Left | Down | Right|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SKETCH] = {
  {_______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), _______, _______, KC_UP,   _______,  _______, _______},
  {_______, _______,    SCRNSHT,    ZOOMOUT,    ZOOMIN,     _______,    _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______},
  {_______, _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______,  _______, _______},
  {_______, _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______,  _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,  KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |GAMING|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Sketch|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, TO(_GAMING)},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
}


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
