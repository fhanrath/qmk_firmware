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
        case FEN_AE:
            if (record->event.pressed) {
                register_code(KC_ALGR);
                SEND_STRING("q");
                unregister_code(KC_ALGR);
            }
            break;

        case FEN_UE:
            if (record->event.pressed) {
                register_code(KC_ALGR);
                SEND_STRING("y");
                unregister_code(KC_ALGR);
            }
            break;

        case FEN_OE:
            if (record->event.pressed) {
                register_code(KC_ALGR);
                SEND_STRING("p");
                unregister_code(KC_ALGR);
            }
            break;

        case FEN_SZ:
            if (record->event.pressed) {
                register_code(KC_ALGR);
                SEND_STRING("s");
                unregister_code(KC_ALGR);
            }
            break;

        case FEN_EUR:
            if (record->event.pressed) {
                register_code(KC_ALGR);
                SEND_STRING("5");
                unregister_code(KC_ALGR);
            }
            break;
    }
    return true;
}

// Tap Dance

//TODO: doesnt work this way. gointg to bed and trying again tomorrow.

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_NUM_SYM] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, num_sim_finished, num_sim_reset, 100),
	[TD_NAV_UML] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, nav_uml_finished, nav_uml_reset, 100),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       OS_SFT,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  BACKSP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,   MOD_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   TD(TD_NUM_SYM),  KC_SPC, KC_LOPT,    KC_ENT,   OS_SFT,  TD(TD_NUM_SYM)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      COLEMAK, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,    _______, _______, XXXXXXX
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
                                          XXXXXXX, _______, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_ASTR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,                      XXXXXXX,  KC_EQL, FEN_EUR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                      XXXXXXX, KC_PIPE, KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_UMLAUT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______,  FEN_UE, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  FEN_AE, _______, FEN_SZ, _______, _______,                      _______, _______,  _______, _______,  FEN_OE, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(180, 255, 255);
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

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_ENABLE

// Determine the current tap dance state
td_state_t cur_dance_tap_hold(qk_tap_dance_state_t *state) {
    if (!state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t num_sim_tap_state = {
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void num_sim_finished(qk_tap_dance_state_t *state, void *user_data) {
    num_sim_tap_state.state = cur_dance_tap_hold(state);
    switch (num_sim_tap_state.state) {
        case TD_SINGLE_TAP:
            layer_move(_NUMBERS);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_SYMBOL);
            break;
        default:
            break;
    }
}

void num_sim_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (num_sim_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_SYMBOL);
    }
    num_sim_tap_state.state = TD_NONE;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t nav_uml_tap_state = {
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void nav_uml_finished(qk_tap_dance_state_t *state, void *user_data) {
    nav_uml_tap_state.state = cur_dance_tap_hold(state);
    switch (nav_uml_tap_state.state) {
        case TD_SINGLE_TAP:
            layer_move(_NAVIGATION);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_UMLAUT);
            break;
        default:
            break;
    }
}

void nav_uml_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (nav_uml_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_UMLAUT);
    }
    nav_uml_tap_state.state = TD_NONE;
}