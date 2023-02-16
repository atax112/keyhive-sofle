 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#include "oled.c"
#include "encoder.c"

// Base layer is the number of layers CYCLE selects from.
#define BASE_LAYERS 1

//enum custom_keycodes {
//    PLACEHOLDER = SAFE_RANGE,  // can always be here (4 bytes)
//    CYCLE                      // cycle through first BASE_LAYERS (62 bytes)
//};

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
	_THIRD
};

// Extra keys are added for rotary encoder support in VIA
#define LAYOUT_via( \
    LA1, LA2, LA3, LA4, LA5, LA6,           RA6, RA5, RA4, RA3, RA2, RA1, \
    LB1, LB2, LB3, LB4, LB5, LB6, LB7, RB7, RB6, RB5, RB4, RB3, RB2, RB1, \
    LC1, LC2, LC3, LC4, LC5, LC6, LE1, RE6, RC6, RC5, RC4, RC3, RC2, RC1, \
    LD1, LD2, LD3, LD4, LD5, LD6, LD7, RD7, RD6, RD5, RD4, RD3, RD2, RD1, \
              LE2, LE3, LE4, LE5, LE6, RE5, RE4, RE3, RE2, RE1 \
    ) \
    { \
        { LA1, LA2, LA3, LA4, LA5, LA6, KC_NO }, \
        { LB1, LB2, LB3, LB4, LB5, LB6, LB7   }, \
        { LC1, LC2, LC3, LC4, LC5, LC6, KC_NO }, \
        { LD1, LD2, LD3, LD4, LD5, LD6, LD7   }, \
        { LE1, LE2, LE3, LE4, LE5, LE6, KC_NO }, \
        { RA1, RA2, RA3, RA4, RA5, RA6, KC_NO }, \
        { RB1, RB2, RB3, RB4, RB5, RB6, RB7   }, \
        { RC1, RC2, RC3, RC4, RC5, RC6, KC_NO }, \
        { RD1, RD2, RD3, RD4, RD5, RD6, RD7   }, \
        { RE1, RE2, RE3, RE4, RE5, RE6, KC_NO } \
    }

//Default keymap. This can be changed in Via. Use oled.c to change beavior that Via cannot change.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_via(
   KC_ESC, KC_1, KC_2, KC_3   , KC_4   , KC_5   ,                             KC_6    , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
   KC_TAB, KC_Q, KC_W, KC_E   , KC_R   , KC_T   , KC_MS_WH_DOWN,       KC_NO, KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
   KC_GRV, KC_A, KC_S, KC_D   , KC_F   , KC_G   , KC_MS_BTN1,          KC_NO, KC_H    , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_BSPC,
  KC_LSFT, KC_Z, KC_X, KC_C   , KC_V   , KC_B   , KC_MS_WH_UP,         KC_NO, KC_N    , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
              KC_LGUI,KC_LALT ,KC_LCTL,MO(_LOWER), KC_SPC,               KC_ENT  ,MO(_RAISE),KC_APP, TG(3), KC_RGUI
),

[_LOWER] = LAYOUT_via(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,       KC_NO, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
  KC_NO, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,   _______,       KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       KC_NO, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                  _______, _______, _______, KC_NO, _______,               _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_via(
  _______, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,                          KC_HOME, KC_INS,  KC_END,  KC_NO, KC_NO, KC_DEL,
  KC_NO, KC_NO , KC_P7, KC_P8 , KC_P9 , KC_PENT,     _______,          KC_NO,  KC_PGUP, KC_NO,   KC_UP  , KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_P4, KC_P5, KC_P6 , KC_PDOT,        _______,          KC_NO,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_BSPC,
  KC_NO, KC_NO, KC_P1 , KC_P2, KC_P3, KC_P0,         _______,          KC_NO,  KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, KC_NO, KC_NO,
           _______, _______, _______, KC_NO, _______,                     _______, _______, KC_NO, KC_NO, KC_NO
),

[_THIRD] = LAYOUT_via(
  KC_NO, KC_P1, KC_P2, KC_P3, KC_P4 , KC_P5,                                   KC_ESC, KC_DEL,  KC_MINS,  KC_SLSH, KC_PIPE, RGB_TOG,
  KC_NO, KC_P6 , KC_P7, KC_P8 , KC_P9 , KC_P0,      _______,           KC_NO,  KC_LSFT, KC_BSPC,   KC_NO, KC_LPRN, KC_RPRN, RGB_VAI,
  KC_NO, KC_NO, KC_S, KC_NO, KC_NO , KC_LSFT,       KC_NO,             KC_NO,  KC_ENT, LCTL(KC_C), LCTL(KC_V), KC_LCBR, KC_RCBR, RGB_VAD,
  KC_NO, KC_NO, KC_NO , KC_UP, LCTL(KC_Z), KC_LCTL, _______,           KC_NO,  KC_MS_BTN3, LCTL(KC_X),  KC_NO, KC_LT, KC_GT, KC_NO,
         KC_LEFT, KC_DOWN, KC_RGHT, KC_LALT, _______,                          KC_MS_BTN1, KC_MS_BTN2, KC_NO, TG(3), KC_PEQL
)

};