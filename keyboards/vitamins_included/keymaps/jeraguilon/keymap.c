#include QMK_KEYBOARD_H

#define TG_NKRO MAGIC_TOGGLE_NKRO


// Layer names

enum layer_names {
    _QWERTY,
    _LOWER,
    _NAV,
    _MNG,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  NAV,
  MNG,
};

#define SPC_LWR LT(_LOWER, KC_SPC)
#define LFT_LWR LT(_LOWER, KC_LEFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |TabNav|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |GUI   | Lower|  MNG |   Space/Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  LT(_NAV, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,        KC_U,         KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,               KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,        KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,        KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  KC_LCTRL,             KC_LGUI, KC_LALT, KC_MENU, LOWER,   MNG,     SPC_LWR,    SPC_LWR,  LOWER, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |QK_BOOT |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNKRO|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
  _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,  KC_COMM,  KC_DOT, _______,  KC_PGUP,
  TG_NKRO, _______, _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
),



/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Audoff Audon |      |      |      |      |RGBMOD|
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] =  LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,  _______, KC_END,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Manage
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Audoff Audon |      |      |      |      |RGBMOD|
 * `-----------------------------------------------------------------------------------'
 */
[_MNG] =  LAYOUT_ortho_4x12(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI,  RGB_TOG,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, RGB_VAD, RGB_SAD, RGB_HUD,  RGB_MOD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RGB_HUD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
)




};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _NAV, _MNG);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _NAV, _MNG);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_LOWER, _NAV, _MNG);
      } else {
        layer_off(_NAV);
        update_tri_layer(_LOWER, _NAV, _MNG);
      }
      return false;
      break;
    case MNG:
      if (record->event.pressed) {
        layer_on(_MNG);
      } else {
        layer_off(_MNG);
      }
      return false;
      break;
  }
  return true;
}
