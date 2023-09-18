/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "fenris.h"

// Macros:

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FEN_KILL:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                SEND_STRING("q");
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            break;
    }
    return true;
}

// Tap Dance

tap_dance_action_t tap_dance_actions[] = {
	[TD_NUM_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_sim_finished, num_sim_reset),
	[TD_NAV_UML] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_uml_finished, nav_uml_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SFT_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   TD(TD_NAV_UML),  KC_SPC, KC_LOPT,    KC_ENT,  OS_RSFT,  TD(TD_NUM_SYM)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      COLEMAK, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      XXXXXXX,    KC_4,    KC_5,    KC_6, KC_COMM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                         KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          SPECIAL, _______, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGUP, KC_HOME,   KC_UP, KC_END,   KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_INS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,    _______, _______, SPECIAL
                                      //`--------------------------'  `--------------------------'
  ),

  [_SPECIAL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      COLEMAK,FEN_KILL,    WM_7,    WM_8,    WM_9,    WM_0,                      XXXXXXX, XXXXXXX,   WM_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, WM_LAUN,    WM_4,    WM_5,    WM_6, XXXXXXX,                      XXXXXXX, WM_LEFT, WM_DOWN,WM_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, WM_FSCR,    WM_1,    WM_2,    WM_3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LSFT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_ASTR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,                      XXXXXXX,  KC_EQL,   SPC_E, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                      XXXXXXX, KC_BSLS, KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          SPECIAL, _______, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_UMLAUT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______,   UML_U, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   UML_A, _______,   UML_S, _______, _______,                      _______, _______, _______, _______,   UML_O, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,    _______, _______, SPECIAL
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _NUMBERS:
            //rgb_matrix_sethsv_noeeprom(128, 255, 255);
            rgb_matrix_set_color_all(0, 64, 64);
            break;
        case _NAVIGATION:
            //rgb_matrix_sethsv_noeeprom(159, 255, 255);
            rgb_matrix_set_color_all(0, 15, 63);
            break;
        case _SYMBOL:
            //rgb_matrix_sethsv_noeeprom(95, 255, 255);
            rgb_matrix_set_color_all(0, 63, 14);
            break;
        case _UMLAUT:
            //rgb_matrix_sethsv_noeeprom(52, 255, 255);
            rgb_matrix_set_color_all(49, 63, 0);
            break;
        case _SPECIAL:
            //rgb_matrix_sethsv_noeeprom(0, 255, 255);
            rgb_matrix_set_color_all(63, 0, 0);
            break;
        default:
            //rgb_matrix_sethsv(181, 255, 255);
            rgb_matrix_set_color_all(16, 0, 64);
            break;
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("ColemakDH"), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NAVIGATION:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _UMLAUT:
            oled_write_ln_P(PSTR("Umlaut"), false);
            break;
        case _SPECIAL:
            oled_write_ln_P(PSTR("Special"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

// Determine the current tap dance state
td_state_t cur_dance_tap_hold(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        if (state->interrupted) return TD_SINGLE_TAP_INTERRUPT;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t num_sim_tap_state = {
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void num_sim_finished(tap_dance_state_t *state, void *user_data) {
    num_sim_tap_state.state = cur_dance_tap_hold(state);
    switch (num_sim_tap_state.state) {
        case TD_SINGLE_HOLD:
        case TD_SINGLE_TAP_INTERRUPT:
            layer_on(_SYMBOL);
            break;
        case TD_DOUBLE_HOLD:
        case TD_DOUBLE_SINGLE_TAP:
            layer_on(_NUMBERS);
            break;
        default:
            break;
    }
}

void num_sim_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (num_sim_tap_state.state == TD_SINGLE_HOLD || num_sim_tap_state.state == TD_SINGLE_TAP_INTERRUPT) {
        layer_off(_SYMBOL);
    }
    if (num_sim_tap_state.state == TD_DOUBLE_HOLD || num_sim_tap_state.state == TD_DOUBLE_SINGLE_TAP) {
        layer_off(_NUMBERS);
    }
    num_sim_tap_state.state = TD_NONE;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t nav_uml_tap_state = {
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void nav_uml_finished(tap_dance_state_t *state, void *user_data) {
    nav_uml_tap_state.state = cur_dance_tap_hold(state);
    switch (nav_uml_tap_state.state) {
        case TD_SINGLE_HOLD:
        case TD_SINGLE_TAP_INTERRUPT:
            layer_on(_UMLAUT);
            break;
        case TD_DOUBLE_HOLD:
        case TD_DOUBLE_SINGLE_TAP:
            layer_on(_NAVIGATION);
            break;
        default:
            break;
    }
}

void nav_uml_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (nav_uml_tap_state.state == TD_SINGLE_HOLD || nav_uml_tap_state.state == TD_SINGLE_TAP_INTERRUPT) {
        layer_off(_UMLAUT);
    }
    if (nav_uml_tap_state.state == TD_DOUBLE_HOLD || nav_uml_tap_state.state == TD_DOUBLE_SINGLE_TAP) {
        layer_off(_NAVIGATION);
    }
    nav_uml_tap_state.state = TD_NONE;
}