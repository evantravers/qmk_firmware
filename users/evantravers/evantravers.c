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

#include "evantravers.h"

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC]    = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
  [TD_PREV_NEXT]   = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_MRWD),
  [TD_SCRNST]      = ACTION_TAP_DANCE_DOUBLE(LGUI(LSFT(LCTL(KC_4))), LGUI(LSFT(KC_4)))
};
