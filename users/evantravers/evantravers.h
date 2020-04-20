/*
Copyright 2019 Evan Travers <evantravers@gmail.com> @evantravers

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

#define LOWER     LT(_LOWER, KC_SPC)
#define RAISE     LT(_RAISE, KC_SPC)
#define SHORTCUTS MO(_SHORTCUTS)
#define CTRL_ESC  TD(TD_CTRL_ESC)
#define TAB_SK    LT(_SHORTCUTS, KC_TAB)
#define ZOOMIN    LGUI(KC_PLUS)
#define ZOOMOUT   LGUI(KC_MINS)
#define TABN      LSFT(LGUI(KC_RBRC))
#define TABP      LSFT(LGUI(KC_LBRC))
#define HBCK      LGUI(KC_LBRC)
#define HFWD      LGUI(KC_RBRC)
#define SW_WIND   LGUI(KC_GRV)
#define SCRNST    TD(TD_SCRNST)
#define PREV_NEXT TD(TD_PREV_NEXT)

#define ALT_ESC   MT(MOD_LALT, KC_ESC)
#define ALT_ENT   MT(MOD_RALT, KC_ENT)
#define GUI_BSPC  MT(MOD_LGUI, KC_BSPC)
#define GUI_DEL   MT(MOD_RGUI, KC_DEL)
#define PASS      LGUI(KC_BSLS)

enum {
  TD_CTRL_ESC,
  TD_PREV_NEXT,
  TD_SCRNST
};

/* Define layer names */
enum userspace_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SHORTCUTS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC]    = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
  [TD_PREV_NEXT]   = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_MRWD),
  [TD_SCRNST]      = ACTION_TAP_DANCE_DOUBLE(LGUI(LSFT(LCTL(KC_4))), LGUI(LSFT(KC_4)))
};

