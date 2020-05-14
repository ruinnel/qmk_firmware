/* Copyright 2019
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

enum layers {
  _BASE = 0,
  _FN1,
};

// define Custom Keycode
enum {
     KC_M_NEXT_TAB = SAFE_RANGE,
     KC_M_PREV_TAB,
     KC_M_WP_UP,
     KC_M_WP_DOWN,
     KC_M_WP_LEFT,
     KC_M_WP_RIGHT,
     KC_M_WP_FULL,
     KC_M_WP_RECOVER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MO(_FN1),        KC_P8,           KC_P9,           KC_PMNS,
    KC_P4,           KC_P5,           KC_P6,           KC_PPLS,
    KC_P1,           KC_M_WP_RECOVER, KC_M_WP_UP,      KC_M_WP_FULL,
    _______,         KC_M_WP_LEFT,    KC_M_WP_DOWN,    KC_M_WP_RIGHT
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    _______,  KC_PAST,  KC_PSLS,  _______,
    BL_TOGG,  BL_DEC,   BL_INC,   BL_STEP,
    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,
    RGB_SAI,  RGB_SAD,  _______,  RESET
  )
};

// MT(MOD_LCTL|MOD_LGUI, KC_UP)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_M_WP_UP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_UP) SS_UP(X_LGUI) SS_UP(X_LCTL));
      } else {
        // skip
      }
      break;
    case KC_M_WP_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_DOWN) SS_UP(X_LGUI) SS_UP(X_LCTL));
      } else {
        // skip
      }
      break;
    case KC_M_WP_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LCTL));
      } else {
        // skip
      }
      break;
    case KC_M_WP_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LCTL));
      } else {
        // skip
      }
      break;
    case KC_M_WP_FULL:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_ENTER) SS_UP(X_LGUI) SS_UP(X_LCTL));
      } else {
        // skip
      }
      break;
    case KC_M_WP_RECOVER:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_UP(X_LCTL));
      } else {
        // skip
      }
      break;
  }
  return true;
};