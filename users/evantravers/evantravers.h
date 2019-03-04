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
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

#define LOWER     MO(_LOWER)
#define RAISE     MO(_RAISE)
#define SHORTCUTS MO(_SHORTCUTS)
#define CTRL_ESC  TD(TD_CTRL_ESC)
#define TAB_SK    LT(_SHORTCUTS, KC_TAB)
#define TAB_GAM   LT(_GAMING_SHORTCUTS, KC_TAB)
#define ZOOMIN    LGUI(KC_PLUS)
#define ZOOMOUT   LGUI(KC_MINS)
#define SW_WIND   LGUI(KC_GRV)
#define SCRNST    LGUI(LSFT(LCTL(KC_4)))
#define PREV_NEXT TD(TD_PREV_NEXT)

enum {
  TD_CTRL_ESC,
  TD_PREV_NEXT
};

/* Define layer names */
enum userspace_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _GAMING,
  _ADJUST,
  _SHORTCUTS,
  _GAMING_SHORTCUTS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC]    = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
  [TD_PREV_NEXT]   = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_MRWD)
};

