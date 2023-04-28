/* Copyright 2021 SamuraiKek
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
#include "keymap_nordic.h"

#define NO_ASTR LSFT(NO_APOS)

#define CR_SYMB LT(_SYMB, KC_ENT)
#define DEL_MISC LT(_MISC, KC_DEL)
#define ESC_SYMB LT(_SYMB, KC_ESC)
#define NO_BSLSH ALGR(NO_PLUS)
#define SPC_CTL LCTL_T(KC_SPC)

enum custom_layers {
    _QWERTY,
    _SYMB,
    _MISC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    NO_PLUS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AM,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    NO_AE,   NO_OSLH,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, KC_RSFT,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCTL, KC_LALT, KC_UP,   KC_DOWN, KC_LCMD, KC_SPC,  SPC_CTL,       ESC_SYMB,CR_SYMB, DEL_MISC,KC_LEFT, KC_RGHT, KC_ALGR, NO_APOS
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, KC_EXLM, NO_QUO2, KC_HASH, NO_DLR,  KC_PERC,                         NO_AMPR, NO_SLSH, KC_LPRN, NO_RPRN, NO_EQL,  NO_QUES,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, NO_LPRN, NO_RPRN, NO_AT,   NO_APOS, NO_GRV,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  NO_SLSH, NO_TILD,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, NO_LCBR, NO_RCBR, NO_AMPR, NO_SCLN, NO_EQL,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NO_CIRC, NO_ASTR,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, NO_LBRC, NO_RBRC, NO_PIPE, NO_LESS, NO_GRTR,                         NO_SLSH, NO_BSLSH,NO_SCLN, NO_COLN, NO_UNDS, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,  _______, _______, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MISC] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,  _______, _______, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  )
};
