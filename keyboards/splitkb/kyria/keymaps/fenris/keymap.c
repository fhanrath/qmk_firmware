/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "fenris.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WM_KILL:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                SEND_STRING("q");
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            break;
        case WM_FLOAT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                SEND_STRING(" ");
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            break;
        case MAC_MUTE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_LALT);
                SEND_STRING("m");
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            break;
        case MAC_KILL:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_ESC);
                unregister_code(KC_ESC);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            break;
        case MAC_FSCR:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                SEND_STRING("f");
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            break;
        case MAC_EUR:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
                SEND_STRING("2");
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            break;
        case UML_A_M:
            if (record->event.pressed) {
                register_code(KC_LALT);
                SEND_STRING("u");
                unregister_code(KC_LALT);
                SEND_STRING("a");
            }
            break;
        case UML_U_M:
            if (record->event.pressed) {
                register_code(KC_LALT);
                SEND_STRING("u");
                unregister_code(KC_LALT);
                SEND_STRING("u");
            }
            break;
        case UML_O_M:
            if (record->event.pressed) {
                register_code(KC_LALT);
                SEND_STRING("u");
                unregister_code(KC_LALT);
                SEND_STRING("o");
            }
            break;
    }
    return true;
}


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   D  |   V  | ALT  | MUTE |  |Float | RALT |   K  |   H  | ,  < | . >  | /  ? |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Nav  |Umlaut| Space| LGUI |  |Enter | Shift|Symbol|Number| MAC  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAKDH] = LAYOUT(
     KC_ESC  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                           KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     KC_TAB  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                           KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , KC_QUOT,
     KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LALT,WM_MUTE,     WM_FLOAT  , KC_RALT, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_MINS,
                                 KC_NO ,  MO_NAV,  MO_UML, KC_SPC ,KC_LGUI,     KC_ENTER  , KC_LSFT, MO_SYM, MO_NUM, TO_MAC
    ),
    
/*
 * Number Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |      |  F7  |  F8  |  F9  |  F10 |                              |      |   7  |   8  |   9  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |      |  F4  |  F5  |  F6  |  F11 |                              |      |   4  |   5  |   6  |   ,  |   .    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |      |  F1  |  F2  |  F3  |  F12 | ALT  | MUTE |  |Float | RALT |      |   1  |   2  |   3  |   =  |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  WM  |  WM  | Space| LGUI |  |Enter | Shift|   0  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMBERS] = LAYOUT(
     KC_TRNS , KC_NO,  KC_F7  ,  KC_F8 ,   KC_F9,  KC_F10,                                          KC_NO,   KC_7 ,  KC_8,   KC_9 ,KC_TRNS, KC_TRNS,
     KC_TRNS , KC_NO,  KC_F4  ,  KC_F5 ,   KC_F6,  KC_F11,                                          KC_NO,   KC_4 ,  KC_5,   KC_6 ,KC_COMM, KC_DOT,
     KC_TRNS , KC_NO,  KC_F1  ,  KC_F2 ,   KC_F3,  KC_F12, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_1 ,  KC_2,   KC_3 , KC_EQL, KC_TRNS,
                                 KC_NO ,   MO_WM,   MO_WM, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS, KC_0,   KC_NO, KC_NO
    ),
    
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |      |      |      |      |      |                              |  PGU | HOME |  UP  |  END |  DEL |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |      |      |      |      |      |                              |  PGD | LEFT | DOWN | RIGHT|  INS |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |      |      |      |      |      | ALT  | MUTE |  |Float | RALT |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| LGUI |  |Enter | Shift|  WM  |  WM  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAVIGATION] = LAYOUT(
     KC_TRNS , KC_NO,  KC_NO  ,  KC_NO ,   KC_NO,   KC_NO,                                        KC_PGUP, KC_HOME,  KC_UP,  KC_END, KC_DEL, KC_TRNS,
     KC_TRNS , KC_NO,  KC_NO  ,  KC_NO ,   KC_NO,   KC_NO,                                        KC_PGDN, KC_LEFT,KC_DOWN, KC_RGHT, KC_INS,   KC_NO,
     KC_TRNS , KC_NO,  KC_NO  ,  KC_NO ,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,
                                 KC_NO ,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,MO_WM,   MO_WM,  KC_NO
    ),
    
/*
 * Symbol Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |  !   |  @   |  {   |  }   |  *   |                              |      |      |      |      |      |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |  #   |  $   |  (   |  )   |  `   |                              |      |  =   |  €   |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |  %   |  ^   |  [   |  ]   |  ~   | ALT  | MUTE |  |Float | RALT |      |  \|  |  &   |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  WM  |  WM  | Space| LGUI |  |Enter | Shift|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL] = LAYOUT(
     KC_TRNS ,KC_EXLM,  KC_AT  , KC_LCBR, KC_RCBR, KC_ASTR,                                          KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_TRNS,
     KC_TRNS ,KC_HASH,  KC_DLR , KC_LPRN, KC_RPRN,  KC_GRV,                                          KC_NO,  KC_EQL,  SPC_E,   KC_NO,  KC_NO,   KC_NO,
     KC_TRNS ,KC_PERC,  KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO, KC_BSLS,KC_AMPR,   KC_NO,  KC_NO,   KC_NO,
                                  KC_NO ,   MO_WM,   MO_WM, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO
    ),
    
/*
 * Umlaut Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   Ü  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Ä  |   R  |   ß  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   Ö  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   D  |   V  | ALT  | MUTE |  |Float | RALT |   K  |   H  | ,  < | . >  | /  ? |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| LGUI |  |Enter | Shift|  WM  |  WM  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_UMLAUT] = LAYOUT(
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS,   KC_TRNS ,  UML_U, KC_TRNS,KC_TRNS, KC_TRNS,
     KC_TRNS,   UML_A, KC_TRNS,   UML_S, KC_TRNS, KC_TRNS,                                           KC_TRNS,   KC_TRNS ,KC_TRNS, KC_TRNS,  UML_O, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,      KC_TRNS  , KC_TRNS, KC_TRNS,   KC_TRNS ,KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
                                KC_TRNS,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,      KC_TRNS  , KC_TRNS,   MO_WM,      MO_WM, KC_NO
    ),
    
/*
 * WM Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   | KILL  | VD7 | VD8  | VD9  | VD0  |                              |      |      |  UP  |      |      |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   | LAUN  | VD4 | VD5  | VD6  |      |                              |      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  | FULL  | VD1 | VD2  | VD3  |      | ALT  | MUTE |  |Float | RALT |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| LGUI |  |Enter | Shift|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_WM] = LAYOUT(
     KC_TRNS ,  WM_KILL,    WM_7,   WM_8,    WM_9,    WM_0,                                          KC_NO,   KC_NO,  KC_UP,   KC_NO,  KC_NO, KC_TRNS,
     KC_TRNS ,  WM_LAUN,    WM_4,   WM_5,    WM_6,   KC_NO,                                          KC_NO, KC_LEFT,KC_DOWN, KC_RGHT,  KC_NO,   KC_NO,
     KC_TRNS ,  WM_FSCR,    WM_1,   WM_2,    WM_3,   KC_NO, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,
                                  KC_NO ,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO
    ),/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   D  |   V  | ALT  | MUTE |  |Float | RALT |   K  |   H  | ,  < | . >  | /  ? |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Nav  |Umlaut| Space| LGUI |  |Enter | Shift|Symbol|Number| MAC  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    
    [_COLEMAKDH_MAC] = LAYOUT(
     KC_ESC  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                             KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     KC_TAB  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                             KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , KC_QUOT,
     KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LALT,MAC_MUTE,    KC_NO     , KC_RALT,   KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_MINS,
                              TO_LINUX , MAC_NAV, MAC_UML, KC_SPC , KC_LGUI,    KC_ENTER  , KC_LSFT,MAC_SYM, MAC_NUM, KC_NO
    ),
    
/*
 * Number Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |      |  F7  |  F8  |  F9  |  F10 |                              |      |   7  |   8  |   9  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |      |  F4  |  F5  |  F6  |  F11 |                              |      |   4  |   5  |   6  |   ,  |   .    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |      |  F1  |  F2  |  F3  |  F12 | ALT  | MUTE |  |Float | RALT |      |   1  |   2  |   3  |   =  |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  WM  |  WM  | Space| LGUI |  |Enter | Shift|   0  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMBERS_MAC] = LAYOUT(
     KC_TRNS , KC_NO,  KC_F7  ,  KC_F8 ,   KC_F9,  KC_F10,                                          KC_NO,   KC_7 ,  KC_8,   KC_9 ,KC_TRNS, KC_TRNS,
     KC_TRNS , KC_NO,  KC_F4  ,  KC_F5 ,   KC_F6,  KC_F11,                                          KC_NO,   KC_4 ,  KC_5,   KC_6 ,KC_COMM, KC_DOT,
     KC_TRNS , KC_NO,  KC_F1  ,  KC_F2 ,   KC_F3,  KC_F12, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_1 ,  KC_2,   KC_3 , KC_EQL, KC_TRNS,
                                 KC_NO ,  MAC_WM,  MAC_WM, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS, KC_0,   KC_NO, KC_NO
    ),
    
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |      |      |      |      |      |                              |  PGU | HOME |  UP  |  END |  DEL |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |      |      |      |      |      |                              |  PGD | LEFT | DOWN | RIGHT|  INS |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |      |      |      |      |      | ALT  | MUTE |  |Float | RALT |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| LGUI |  |Enter | Shift|  WM  |  WM  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAVIGATION_MAC] = LAYOUT(
     KC_TRNS , KC_NO,  KC_NO  ,  KC_NO ,   KC_NO,   KC_NO,                                       KC_PGUP, KC_HOME,  KC_UP,  KC_END, KC_DEL, KC_TRNS,
     KC_TRNS , KC_NO,  KC_NO  ,  KC_NO ,   KC_NO,   KC_NO,                                       KC_PGDN, KC_LEFT,KC_DOWN, KC_RGHT, KC_INS,   KC_NO,
     KC_TRNS , KC_NO,  KC_NO  ,  KC_NO ,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,    KC_TRNS  , KC_TRNS, KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,
                                 KC_NO ,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,    KC_TRNS  , KC_TRNS,MAC_WM,  MAC_WM,  KC_NO
    ),
    
/*
 * Symbol Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |  !   |  @   |  {   |  }   |  *   |                              |      |      |      |      |      |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |  #   |  $   |  (   |  )   |  `   |                              |      |  =   |  €   |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |  %   |  ^   |  [   |  ]   |  ~   | ALT  | MUTE |  |Float | RALT |      |  \|  |  &   |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  WM  |  WM  | Space| LGUI |  |Enter | Shift|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL_MAC] = LAYOUT(
     KC_TRNS ,KC_EXLM,  KC_AT  , KC_LCBR, KC_RCBR, KC_ASTR,                                          KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_TRNS,
     KC_TRNS ,KC_HASH,  KC_DLR , KC_LPRN, KC_RPRN,  KC_GRV,                                          KC_NO,  KC_EQL,MAC_EUR,   KC_NO,  KC_NO,   KC_NO,
     KC_TRNS ,KC_PERC,  KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO, KC_BSLS,KC_AMPR,   KC_NO,  KC_NO,   KC_NO,
                                  KC_NO ,  MAC_WM,  MAC_WM, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO
    ),
    
/*
 * Umlaut Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   Ü  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Ä  |   R  |   ß  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   Ö  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   D  |   V  | ALT  | MUTE |  |Float | RALT |   K  |   H  | ,  < | . >  | /  ? |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| LGUI |  |Enter | Shift|  WM  |  WM  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_UMLAUT_MAC] = LAYOUT(
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS,   KC_TRNS ,UML_U_M, KC_TRNS,KC_TRNS, KC_TRNS,
     KC_TRNS, UML_A_M, KC_TRNS,   UML_S, KC_TRNS, KC_TRNS,                                           KC_TRNS,   KC_TRNS ,KC_TRNS, KC_TRNS,UML_O_M, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,      KC_TRNS  , KC_TRNS, KC_TRNS,   KC_TRNS ,KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
                                KC_TRNS,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,      KC_TRNS  , KC_TRNS,  MAC_WM,     MAC_WM, KC_NO
    ),
    
/*
 * WM Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   | KILL  | VD7 | VD8  | VD9  | VD0  |                              |      |      |  UP  |      |      |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   | LAUN  | VD4 | VD5  | VD6  |      |                              |      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTRL  | FULL  | VD1 | VD2  | VD3  |      | ALT  | MUTE |  |Float | RALT |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| LGUI |  |Enter | Shift|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_WM_MAC] = LAYOUT(
     KC_TRNS , MAC_KILL,   MAC_7,  MAC_8,   MAC_9,   MAC_0,                                          KC_NO,   KC_NO,  KC_UP,   KC_NO,  KC_NO, KC_TRNS,
     KC_TRNS , MAC_LAUN,   MAC_4,  MAC_5,   MAC_6,   KC_NO,                                          KC_NO, KC_LEFT,KC_DOWN, KC_RGHT,  KC_NO,   KC_NO,
     KC_TRNS , MAC_FSCR,   MAC_1,  MAC_2,   MAC_3,   KC_NO, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,
                                  KC_NO ,   KC_NO,   KC_NO, KC_TRNS,KC_TRNS,     KC_TRNS   , KC_TRNS,KC_NO,   KC_NO,  KC_NO
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
