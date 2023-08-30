/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "rgb_matrix_map.h"

enum custom_layers {
    _WIN,
    _FN1,
    _MAC,
    _WIN_FN2,
    _WIN_FN3,
    _SC2,
};

enum custom_keycodes {
    ae = SAFE_RANGE,
    AE,
    oe,
    OE,
    ue,
    UE,
    ss
};

char *alt_codes[] = {
    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_2)), // Alt+132 → ä
    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_2)), // Alt+142 → Ä

    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_8)), // Alt+148 → ö
    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3)), // Alt+153 → Ö

    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_9)), // Alt+129 → ü
    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_4)), // Alt+154 → Ü

    SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_5)), // Alt+225 → ß
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_WIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,            KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,           KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,            KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,  KC_UP,   KC_END,
        KC_LCTL, MO(3),   KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_LALT, KC_LGUI,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_SC2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_NO,   _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_WIN_FN2] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ue,    KC_NO, oe,    KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,
        KC_NO, ae,    ss,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,
        MO(_WIN_FN3), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,                      KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_WIN_FN3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UE,    KC_NO, OE,    KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,
        KC_NO, AE,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,
        KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,                      KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_FN1] = LAYOUT(
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,
        KC_NO, KC_NO, TO(_WIN), KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,        KC_NO,
        KC_NO, KC_NO, TO(_SC2), KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,        KC_NO,          KC_NO,
        KC_NO,        KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, TO(_MAC), KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,                         KC_MPLY,                         KC_NO, KC_NO, KC_NO, KC_MPRV, KC_NO, KC_MNXT
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed)
        return true;

    switch(keycode) {
        case ae:
            send_string(alt_codes[0]);
            return false;
        case AE:
            send_string(alt_codes[1]);
            return false;
        case oe:
            send_string(alt_codes[2]);
            return false;
        case OE:
            send_string(alt_codes[3]);
            return false;
        case ue:
            send_string(alt_codes[4]);
            return false;
        case UE:
            send_string(alt_codes[5]);
            return false;
        case ss:
            send_string(alt_codes[6]);
            return false;
        default:
            return true;
    }
}

#ifdef RGB_MATRIX_ENABLE
#define RGB_ZERG 40, 1, 55

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case _MAC:
            rgb_matrix_set_color_all(RGB_OFF);
            break;
        case _SC2:
            rgb_matrix_set_color_all(RGB_OFF);
            rgb_matrix_set_color(LED_1, RGB_ZERG);
            rgb_matrix_set_color(LED_2, RGB_ZERG);
            rgb_matrix_set_color(LED_3, RGB_ZERG);
            rgb_matrix_set_color(LED_4, RGB_ZERG);
            rgb_matrix_set_color(LED_5, RGB_ZERG);
            rgb_matrix_set_color(LED_6, RGB_ZERG);
            rgb_matrix_set_color(LED_7, RGB_ZERG);
            rgb_matrix_set_color(LED_8, RGB_ZERG);
            rgb_matrix_set_color(LED_9, RGB_ZERG);
            rgb_matrix_set_color(LED_0, RGB_ZERG);
            rgb_matrix_set_color(LED_Q, RGB_ZERG);
            rgb_matrix_set_color(LED_W, RGB_ZERG);
            rgb_matrix_set_color(LED_E, RGB_ZERG);
            rgb_matrix_set_color(LED_R, RGB_ZERG);
            rgb_matrix_set_color(LED_T, RGB_ZERG);
            rgb_matrix_set_color(LED_A, RGB_ZERG);
            rgb_matrix_set_color(LED_S, RGB_ZERG);
            rgb_matrix_set_color(LED_D, RGB_ZERG);
            rgb_matrix_set_color(LED_F, RGB_ZERG);
            rgb_matrix_set_color(LED_G, RGB_ZERG);
            rgb_matrix_set_color(LED_Z, RGB_ZERG);
            rgb_matrix_set_color(LED_X, RGB_ZERG);
            rgb_matrix_set_color(LED_C, RGB_ZERG);
            rgb_matrix_set_color(LED_V, RGB_ZERG);
            rgb_matrix_set_color(LED_B, RGB_ZERG);

            rgb_matrix_set_color(LED_F1, RGB_ZERG);
            rgb_matrix_set_color(LED_F2, RGB_ZERG);
            rgb_matrix_set_color(LED_F3, RGB_ZERG);
            rgb_matrix_set_color(LED_F4, RGB_ZERG);
            rgb_matrix_set_color(LED_F5, RGB_ZERG);
            rgb_matrix_set_color(LED_F6, RGB_ZERG);

            rgb_matrix_set_color(LED_ESC, RGB_ZERG);
            rgb_matrix_set_color(LED_GRV, RGB_ZERG);
            rgb_matrix_set_color(LEB_TAB, RGB_ZERG);
            rgb_matrix_set_color(LED_LSFT, RGB_ZERG);
            rgb_matrix_set_color(LED_LCTL, RGB_ZERG);
            rgb_matrix_set_color(LED_LALT, RGB_ZERG);
            rgb_matrix_set_color(LED_SPC, RGB_ZERG);
            break;
        case _WIN_FN2:
            rgb_matrix_set_color_all(RGB_OFF);
            rgb_matrix_set_color(LED_A, RGB_RED);
            rgb_matrix_set_color(LED_O, RGB_RED);
            rgb_matrix_set_color(LED_U, RGB_RED);
            rgb_matrix_set_color(LED_S, RGB_RED);
            rgb_matrix_set_color(LED_LSFT, RGB_RED);
            break;
        case _WIN_FN3:
            rgb_matrix_set_color_all(RGB_OFF);
            rgb_matrix_set_color(LED_A, RGB_RED);
            rgb_matrix_set_color(LED_O, RGB_RED);
            rgb_matrix_set_color(LED_U, RGB_RED);
            break;
    }

    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        rgb_matrix_set_color(LED_L1, RGB_RED);
        rgb_matrix_set_color(LED_L2, RGB_RED);
        rgb_matrix_set_color(LED_L3, RGB_RED);
        rgb_matrix_set_color(LED_L4, RGB_RED);
        rgb_matrix_set_color(LED_L5, RGB_RED);
        rgb_matrix_set_color(LED_L6, RGB_RED);
        rgb_matrix_set_color(LED_L7, RGB_RED);
        rgb_matrix_set_color(LED_CAPS, RGB_RED);
    }
    return false;
};

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
