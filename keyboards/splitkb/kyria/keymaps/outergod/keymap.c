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

enum layers {
    _DVORAK = 0,
    _QWERTY,
    _MAC,
    _NAV,
    _SYM1,
    _SYM2,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define DVORAK DF(_DVORAK)
#define MAC TG(_MAC)

#define SYM1 MO(_SYM1)
#define SYM2 MO(_SYM2)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define GUI_ESC MT(MOD_LGUI, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define GUI_MINS MT(MOD_RGUI, KC_MINUS)
#define ALT_TAB MT(MOD_LALT, KC_TAB)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   | ' "  | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
     KC_GRAVE,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                        KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_SLASH,
     CTL_ESC , KC_A ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                        KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
     SC_LSPO ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_LBRC, NAV   ,     FKEYS  , KC_RBRC, KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , SC_RSPC,
                                 ADJUST, KC_LGUI, ALT_TAB, KC_SPC , SYM1  ,     SYM2   , KC_ENT ,KC_RALT, KC_RGUI, KC_APP
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_GRAVE, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     SC_LSPO , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC, NAV   ,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, SC_RSPC,
                                 ADJUST, KC_LGUI, ALT_TAB, KC_SPC , SYM1  ,     SYM2   , KC_ENT ,KC_RALT, KC_RGUI, KC_APP
    ),

// /*
//  * Adjust layer: MacOS
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |LGUI/ESC|      |      |      |      |      |      |                              |      |      |      |      |RGUI / -|
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      | Ctrl |      |      |  |      |      | Ctrl |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
    [_MAC] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      GUI_ESC, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, GUI_MINS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_LCTL, _______, _______, _______, _______, _______, _______, KC_RCTL, KC_MCTL
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_SCRL, KC_CAPS, KC_PAUSE,KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, KC_NUM,  _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM1] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM2] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RCTL, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak| Mac  |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, DVORAK ,   MAC,   _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |LGUI/ESC|      |      |      |      |      |      |                              |      |      |      |      |RGUI / -|
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      | Ctrl |      |      |  |      |      | Ctrl |      |      |
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

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        static const char PROGMEM apple[] = {0x20,0x04,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev3.1\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer((layer_state | default_layer_state) & ~((layer_state_t)1 << _MAC))) {
            case _DVORAK:
                oled_write_P(PSTR("Dvorak"), false);
                break;
            case _QWERTY:
                oled_write_P(PSTR("QWERTY"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav"), false);
                break;
            case _SYM1:
            case _SYM2:
                oled_write_P(PSTR("Sym"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined"), false);
        }

        if (layer_state_is(_MAC)) {
            oled_write_P(apple, false);
        }

        oled_write_P(PSTR("\n"), false);

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM demonic_eye[] = {
            0x00, 0x00, 0x00, 0x40, 0x42, 0x42, 0x84, 0x84, 0x88, 0x98, 0x00, 0x00, 0x00, 0x0f, 0x30, 0x40,
            0xc0, 0x00, 0x01, 0x01, 0x01, 0x03, 0x02, 0x00, 0x00, 0x04, 0x0c, 0x19, 0x39, 0x21, 0xc6, 0x8f,
            0x09, 0x18, 0x10, 0x10, 0x10, 0x30, 0x30, 0x30, 0x00, 0x00, 0x30, 0xe0, 0xc0, 0xf3, 0xf3, 0xf0,
            0xf0, 0xf8, 0xfe, 0xfb, 0xff, 0x7e, 0x3c, 0x3c, 0x3c, 0x3c, 0xbe, 0x3f, 0x3f, 0xbf, 0x3f, 0x3f,
            0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3c, 0x3e, 0x3e, 0x7f, 0x77, 0xf2, 0xfc, 0xfc, 0xfc, 0xc3, 0xc3,
            0x60, 0x30, 0x2c, 0x30, 0x50, 0x90, 0x08, 0x0c, 0x0c, 0x0c, 0x32, 0x1b, 0x0d, 0xc4, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xc0, 0x44, 0x1f, 0x19, 0x31, 0x21, 0xc0, 0x40, 0x40, 0x02, 0x00, 0x00,
            0x0c, 0x04, 0x02, 0x00, 0x80, 0x80, 0x80, 0x8c, 0x8c, 0x80, 0x81, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x10, 0x10, 0x10, 0x10, 0x18, 0x08, 0x08, 0x08, 0x0c, 0x01, 0x03, 0x02, 0x04, 0x0c, 0x30, 0x40,
            0xc1, 0x83, 0xf0, 0xc0, 0x80, 0x00, 0x70, 0x38, 0x0e, 0x18, 0x30, 0x20, 0x40, 0x40, 0x81, 0x03,
            0x03, 0x06, 0x8c, 0xc8, 0x70, 0xb8, 0xcc, 0xf4, 0xf8, 0xfc, 0x3c, 0x3f, 0x1f, 0x0f, 0xc7, 0x43,
            0x03, 0xcb, 0x3d, 0x3c, 0x3c, 0x84, 0x42, 0x00, 0x04, 0x1c, 0x23, 0x23, 0x60, 0xe4, 0x64, 0x24,
            0xec, 0xa0, 0xb3, 0xe3, 0xc2, 0x42, 0x44, 0x8c, 0x84, 0x80, 0x80, 0x01, 0x01, 0x03, 0x03, 0x07,
            0x0f, 0x1e, 0x3c, 0x7c, 0xfe, 0xff, 0xf4, 0xe4, 0xec, 0x1c, 0x0c, 0x0c, 0x02, 0x03, 0x00, 0x00,
            0x3c, 0x6c, 0x32, 0x33, 0x31, 0x14, 0x43, 0xc6, 0x9e, 0x01, 0xc0, 0x40, 0x40, 0x00, 0x10, 0x18,
            0x0c, 0x00, 0x00, 0x00, 0x41, 0x40, 0x60, 0x60, 0x60, 0x60, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x03, 0x02, 0x10, 0x1c, 0x08, 0x18, 0x20, 0xc0, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x40,
            0xc0, 0x80, 0x80, 0x81, 0xf9, 0x0f, 0x02, 0x04, 0x04, 0x0c, 0x0c, 0x18, 0x18, 0x00, 0x09, 0x1b,
            0x1e, 0x0e, 0xf3, 0xfc, 0xfe, 0xff, 0x3f, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x02, 0x45, 0x2e,
            0x5e, 0x44, 0x82, 0x02, 0x01, 0x00, 0x00, 0x01, 0x03, 0x06, 0x18, 0x30, 0x00, 0x00, 0x00, 0x03,
            0x03, 0x01, 0x03, 0x01, 0x00, 0x01, 0x01, 0x00, 0x02, 0x45, 0x3f, 0x37, 0x4e, 0xfc, 0xc0, 0xf0,
            0x7c, 0x70, 0xa0, 0xa0, 0xb1, 0x03, 0x0f, 0x3f, 0xff, 0xff, 0x30, 0x84, 0xcc, 0xe0, 0x1c, 0x04,
            0x84, 0x86, 0xc3, 0x43, 0x43, 0x03, 0x23, 0x23, 0x03, 0x83, 0xc4, 0x4c, 0xc8, 0x60, 0x22, 0x30,
            0x10, 0x18, 0x0c, 0x10, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x38, 0x3c,
            0x00, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x03, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0xc2, 0xc0, 0x00, 0x01, 0xbf, 0xc1, 0x83, 0x83, 0x03, 0x03, 0x43, 0x02, 0x02, 0xc2, 0xc3, 0xc1,
            0xff, 0xfd, 0xff, 0xff, 0xff, 0x03, 0x80, 0x80, 0x0c, 0x04, 0x3e, 0x06, 0xfc, 0x03, 0x00, 0x60,
            0xc0, 0xc0, 0xc3, 0x82, 0x00, 0x04, 0x04, 0xc0, 0xe0, 0x88, 0x04, 0x04, 0x8e, 0xfe, 0xff, 0xff,
            0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x20, 0x00, 0x00, 0x86, 0x83, 0xc7, 0xff,
            0xff, 0xfc, 0x00, 0x03, 0x03, 0x0c, 0x04, 0x04, 0x00, 0x03, 0xfe, 0xff, 0xff, 0xfe, 0xfd, 0xfd,
            0x17, 0x1f, 0x40, 0x60, 0xc0, 0xf0, 0x59, 0x4d, 0x4d, 0x05, 0x20, 0x30, 0x38, 0x0c, 0x00, 0x02,
            0x02, 0x02, 0x02, 0x00, 0x00, 0x04, 0x00, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x83, 0x83, 0x83, 0x03, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60,
            0x30, 0x30, 0x30, 0x10, 0x01, 0x11, 0xa1, 0xa1, 0xa1, 0xe1, 0x01, 0x00, 0x00, 0x47, 0x3f, 0x0f,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x01, 0x01, 0x00, 0x00, 0x00, 0x40, 0xdf, 0xe6, 0xc0, 0x20,
            0xe3, 0xf3, 0xc1, 0x11, 0x04, 0x84, 0x00, 0x01, 0x03, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f,
            0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x03, 0x01, 0x00, 0x02, 0x32, 0x21, 0x21, 0x20, 0x20, 0xfc, 0xfd,
            0x7d, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x0f,
            0xfe, 0xe0, 0x20, 0x38, 0x7f, 0x2c, 0x38, 0x38, 0x30, 0xb0, 0x38, 0x3c, 0xd4, 0x18, 0x0c, 0xc4,
            0x08, 0x0e, 0x03, 0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x60, 0x30, 0x08, 0x08, 0x08, 0x04, 0x24, 0x34, 0x1d, 0x05, 0x02, 0x03, 0x01, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x19, 0x31, 0x63, 0x00, 0x01, 0x80, 0xc0, 0x80, 0x88, 0x0c, 0x1c, 0x0c, 0x3c, 0x3c,
            0xfd, 0xdf, 0x3f, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x33, 0x01, 0x03, 0x03,
            0x0f, 0x3d, 0x30, 0x70, 0x70, 0xd0, 0xce, 0x03, 0x30, 0x38, 0x00, 0x00, 0x20, 0x20, 0x38, 0x30,
            0x10, 0x10, 0x10, 0x90, 0x80, 0x8c, 0xc0, 0xc0, 0xc0, 0x40, 0x38, 0x3c, 0x3e, 0x1f, 0x03, 0x01,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0x7f, 0x3f, 0xc7, 0xc2, 0x84, 0x86,
            0x83, 0x01, 0x00, 0x04, 0x0c, 0x80, 0x00, 0x00, 0x07, 0x03, 0x00, 0x04, 0x03, 0x00, 0x00, 0x03,
            0x00, 0x80, 0xc0, 0x40, 0x20, 0x20, 0x10, 0xc0, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x03,
            0x10, 0x10, 0x10, 0x0c, 0x0c, 0x0c, 0x1c, 0x38, 0x38, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0xe0,
            0x60, 0x38, 0x04, 0x00, 0x02, 0x03, 0x3b, 0x21, 0x61, 0x41, 0x21, 0x33, 0x32, 0x1a, 0x80, 0x80,
            0x00, 0x09, 0x20, 0xc1, 0xcd, 0xdd, 0x7d, 0xfd, 0xff, 0xfb, 0xf0, 0xe0, 0xc0, 0x40, 0x00, 0x80,
            0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x13, 0x33, 0x67, 0x47, 0xc7,
            0x87, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0,
            0xe0, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0x3f, 0xff, 0x7f, 0x53, 0xcc, 0xc7, 0x87, 0x03, 0x0f, 0x0d,
            0x1b, 0x33, 0x42, 0x46, 0x02, 0x40, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x3c, 0xd8, 0x30, 0x20, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f,
            0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0xc0, 0x40, 0x08, 0x10, 0x08, 0x0c, 0x03, 0x03,
            0x00, 0x70, 0x00, 0x00, 0x81, 0xc3, 0x67, 0x37, 0x1b, 0x0b, 0x0d, 0xdd, 0xfc, 0x0c, 0x1f, 0x3f,
            0xff, 0xff, 0xff, 0xfe, 0xfe, 0x7e, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8,
            0xf9, 0xf9, 0xfd, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xe6, 0xde, 0xff, 0x3f, 0xff, 0xcf, 0xcf,
            0x67, 0x43, 0x83, 0x03, 0x03, 0x03, 0x30, 0x30, 0x60, 0xc0, 0x80, 0x01, 0x03, 0x03, 0x04, 0x0c,
            0x18, 0x30, 0xc1, 0x81, 0x08, 0x00, 0x03, 0x06, 0x0c, 0x18, 0x10, 0xb0, 0xa0, 0x20, 0x00, 0x00,
            0x02, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x30, 0x20, 0x20, 0x00
        };
        size_t demonic_eye_size = sizeof(demonic_eye);
        // clang-format on
        if (rand() % 20 == 0) {
            char PROGMEM distorted[demonic_eye_size];
            memcpy(distorted, demonic_eye, demonic_eye_size);
            for (size_t i = 0; i < demonic_eye_size; i++) {
                for (int j = 1; j < 256; j <<= 1) {
                    if (rand() % 20 == 0) {
                        distorted[i] ^= j;
                    }
                }
            }

            oled_write_raw_P(distorted, demonic_eye_size);
        } else {
            oled_write_raw_P(demonic_eye, demonic_eye_size);
        }
    }

    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DEL);
        } else {
            tap_code(KC_BSPC);
        }
    }

    return false;
}
#endif
