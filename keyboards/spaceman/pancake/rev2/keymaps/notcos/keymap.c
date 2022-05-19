 /* Copyright Spaceman 2021
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
  _DEFAULT,
  _VIM,
  _NUM,
  _I3L,
  _PAD,
  _MOU
};

#define VIM MO(_VIM)
#define NUM MO(_NUM)
#define I3L MO(_I3L)
#define PAD MO(_PAD)
#define MOU MO(_MOU)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = LAYOUT_ortho_4x12(
         KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,     KC_BSPC,
 LCTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,      KC_ENT,
LSFT_T(KC_QUOT),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_MINS),
         KC_DEL, KC_LALT, KC_LGUI,   I3L,     VIM, KC_BSPC,  KC_SPC,     NUM,   KC_NO,   KC_NO,       MOU,        PAD
),

[_VIM] = LAYOUT_ortho_4x12(
    KC_ESC,KC_LCBR,KC_RCBR,LCTL(LSFT(KC_PSCR)),KC_PSCR,KC_GRV,LCTL(LSFT(KC_LEFT)),LCTL(LSFT(KC_DOWN)),LCTL(LSFT(KC_UP)),LCTL(LSFT(KC_RIGHT)),KC_NO,KC_BSPC,
    LCTL_T(KC_TAB),KC_EQL,KC_PLUS,KC_BSLS,KC_PIPE,KC_TILD,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_NO,KC_ENT,
    LSFT_T(KC_QUOT),KC_LBRC,KC_RBRC,LCTL(LSFT(KC_C)),LCTL(LSFT(KC_V)),KC_NO,KC_HOME,KC_PGDN,KC_PGUP,KC_END,KC_NO,RSFT_T(KC_MINS),
    KC_DEL,KC_LALT,KC_LGUI,KC_NO,_______,KC_BSPC,KC_SPC,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO
),
 
[_NUM] = LAYOUT_ortho_4x12(
    KC_ESC,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
    LCTL_T(KC_DOT),KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_ENT,
    LSFT_T(KC_QUOT),KC_APP,KC_LALT,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_COMM,KC_DOT,KC_SLSH,RSFT_T(KC_MINS),
    KC_DEL,KC_LALT,KC_LGUI,KC_NO,KC_NO,KC_BSPC,KC_SPC,_______,KC_NO,KC_NO,KC_NO,KC_NO
),

[_I3L] = LAYOUT_ortho_4x12(
    KC_NO,LSA(KC_Q),KC_NO,LALT(KC_D),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
    KC_NO,LALT(KC_1),LALT(KC_2),LALT(KC_3),LALT(KC_4),LALT(KC_5),LALT(KC_6),LALT(KC_7),LALT(KC_8),LALT(KC_9),LALT(KC_0),LALT(LALT(KC_ENT)),
    KC_LSFT,LALT(KC_R),KC_NO,LALT(KC_V),LALT(KC_H),KC_NO,LALT(KC_J),LALT(KC_K),LALT(KC_L),LALT(KC_SCLN),KC_NO,KC_RSFT,
    KC_DEL,KC_LALT,KC_LGUI,_______,KC_NO,KC_BSPC,LALT(KC_SPC),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO
),

[_PAD] = LAYOUT_ortho_4x12(
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_PMNS,KC_P7,KC_P8,KC_P9,KC_BSPC,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_PMNS,KC_P4,KC_P5,KC_P6,KC_PMNS,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_PMNS,KC_P1,KC_P2,KC_P3,KC_PENT,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_BSPC,KC_SPC,KC_PMNS,KC_P0,KC_P0,KC_PDOT,_______
),

[_MOU] = LAYOUT_ortho_4x12(
    QK_BOOT,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_BTN1,KC_BTN2,KC_NO,KC_NO,KC_NO,
    KC_NO,KC_NO,KC_ACL0,KC_ACL1,KC_ACL2,KC_NO,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_NO,KC_NO,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_WH_D,KC_WH_U,KC_NO,KC_NO,KC_NO,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,_______,KC_NO
)

};
