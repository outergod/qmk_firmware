/* Copyright 2022 Alexander Dorn
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

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

#define CTL_QUOT MT(MOD_RCTL, KC_QUOT)

enum preonic_layers {
  QWERTY,
  DVORAK,
  FUNCTION
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_preonic_grid(
KC_GRV,  KC_1,             KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
KC_TAB,  KC_Q,             KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
KC_LCTL, KC_A,             KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_QUOT,
KC_LSFT, KC_Z,             KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
KC_RGUI, TD(TD_ESC_CAPS),  KC_MINS, TT(2),   KC_LALT, KC_SPC,  KC_ENT,  KC_RALT, DF(1),   KC_BSPC, KC_DEL,  KC_RGUI
),

    [DVORAK] = LAYOUT_preonic_grid(
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
KC_TRNS, KC_QUOT,          KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
KC_LCTL, KC_A,             KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_RCTL,
KC_LSFT, KC_SCLN,          KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_TRNS,
KC_TRNS, KC_TRNS,          KC_TRNS, TT(2),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(0),   KC_TRNS, KC_TRNS, KC_TRNS
),

    [FUNCTION] = LAYOUT_preonic_grid(
KC_F11,  KC_F1,            KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_EQL,
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, KC_TRNS,
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_NO,   KC_END,  KC_TRNS, KC_TRNS,
KC_TRNS, KC_LGUI,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

/*
  Preonic LEDs visible from the top:
    6 5 4 3
    7 8 1 2

  The two numbers: starting LED number, number of LEDs
*/
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_WHITE}
);
const rgblight_segment_t PROGMEM dvorak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_RED}
);
const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    dvorak_layer,
    function_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(QWERTY, true);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(QWERTY, layer_state_cmp(state, QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(DVORAK, layer_state_cmp(state, DVORAK));
    rgblight_set_layer_state(FUNCTION, layer_state_cmp(state, FUNCTION));
    return state;
}
