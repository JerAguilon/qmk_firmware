#include QMK_KEYBOARD_H

#define _STANDARD 0
#define _NAVIGATION 1
#define _MANAGEMENT 2
#define _GAMING 3

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_STANDARD] = LAYOUT_60_ansi(
        QK_GESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,         KC_EQL,         KC_BSPC,
        LT(1, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,         KC_RBRC,        KC_BSLS,
        KC_ESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                         KC_ENT,
        KC_LSFT,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                         RSFT_T(KC_UP),
        KC_LCTL,       KC_LGUI, KC_LALT,                     LT(1, KC_SPC),                             TT(1),   LALT_T(KC_LEFT), LT(2, KC_DOWN), RCTL_T(KC_RGHT)
    ),

    [_NAVIGATION] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,  KC_DEL,
        _______, KC_ESC,  C(KC_W), C(KC_E), C(KC_R), C(KC_T), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______,
        KC_CAPS, C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
        _______,          C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B), C(KC_N), _______, _______, _______, _______,          KC_UP,
        _______, TG(3),   _______,                            _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MANAGEMENT] = LAYOUT_60_ansi(
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_GAMING] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP,
        _______, _______, _______,                            KC_SPC,                             _______, KC_LEFT, KC_DOWN, KC_RIGHT
    )};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    /**
     * Refer to dz60rgb_ansi.c
     * { 13, 12, 11,     10,      9,  8,      7,      6,      5,  4,  3,  2,      1,      0 },
     * { 27, 26, 25,     24,     23, 22,     21,     20,     19, 18, 17, 16,     15,     14 },
     * { 40, 39, 38,     37,     36, 35,     34,     33,     32, 31, 30, 29, NO_LED,     28 },
     * { 52, 51, 50,     49,     48, 47,     46,     45,     44, 43, 42, 41, NO_LED, NO_LED },
     * { 60, 59, 58, NO_LED, NO_LED, 57, NO_LED, NO_LED, NO_LED, 56, 55, 54, NO_LED,     53 }
     */
    rgb_matrix_set_color_all(0, 0, 0);
    switch (get_highest_layer(layer_state)) { // special handling per layer
        case 3:
            RGB_MATRIX_INDICATOR_SET_COLOR(59, 255, 255, 255);
            break;
    }
}
