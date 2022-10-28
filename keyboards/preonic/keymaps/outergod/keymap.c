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
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

enum preonic_layers {
  DVORAK,
  FUNCTION,
  QWERTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT_preonic_1x2uC(
KC_GRV,  KC_1,             KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
KC_TAB,  KC_QUOT,          KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
KC_LCTL, KC_A,             KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_RCTL,
KC_LSFT, KC_SCLN,          KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
KC_RGUI, TD(TD_ESC_CAPS),  TT(1),   KC_DEL,  KC_LALT,      KC_SPC,      KC_RALT, KC_BSPC, TT(1),   KC_ENT,  KC_RGUI
),

    [FUNCTION] = LAYOUT_preonic_1x2uC(
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS,          KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_EQL,
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MINS,
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_NO,   KC_END,  KC_TRNS, KC_TRNS,
KC_LGUI, KC_TRNS,          TO(0),   KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, TO(2),   KC_TRNS, KC_LGUI
),

    [QWERTY] = LAYOUT_preonic_1x2uC(
KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_Q,             KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_I,    KC_O,    KC_U,    KC_P,    KC_TRNS,
KC_TRNS, KC_A,             KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
KC_TRNS, KC_Z,             KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
KC_TRNS, KC_TRNS,          TO(2),   KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, TO(0),   KC_TRNS, KC_TRNS
),
};

/*
  Preonic LEDs visible from the top:
    6 5 4 3
    7 8 1 2

  The two numbers: starting LED number, number of LEDs
*/
const rgblight_segment_t PROGMEM dvorak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_WHITE}
);
const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_BLUE}
);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    dvorak_layer,
    function_layer,
    qwerty_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(DVORAK, true);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(DVORAK, layer_state_cmp(state, DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(FUNCTION, layer_state_cmp(state, FUNCTION));
    rgblight_set_layer_state(QWERTY, layer_state_cmp(state, QWERTY));
    return state;
}
