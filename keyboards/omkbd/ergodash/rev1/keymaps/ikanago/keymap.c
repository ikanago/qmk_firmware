#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |  ALt |  GUI |||||||| Lower| Enter|      ||||||||      | Space| Raise||||||||  Alt |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
    // Pair:
    // Ctrl/Space
    // Shift/Tab

    // Disjoint:
    // Ctrl/Tab
    // Cmd/Tab
    // Cmd/Space
    // Cmd/Shift
    // Shift/Space
    // Shift/Enter
  [_QWERTY] = LAYOUT( \
    _______, _______, _______, _______,       _______, _______, _______,                             _______,       _______, _______, _______, _______, _______, _______, \
    _______, KC_Q,    KC_W,    KC_E,          KC_R,    KC_T,    _______,                             _______,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
    _______, KC_A,    KC_S,    KC_D,          KC_F,    KC_G,    _______,                             _______,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
    _______, KC_Z,    KC_X,    KC_C,          KC_V,    KC_B,    _______,                             _______,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
    _______, _______, KC_LALT, GUI_T(KC_ESC),          LOWER,   KC_ENT , CTL_T(KC_SPC),     _______, SFT_T(KC_TAB), RAISE,   KC_RALT, _______, _______, _______  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   =  | BSpc |   -  |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  |      |                    |      |   +  |      |   _  |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |||||||| Lower|      |      ||||||||      |      | Raise||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        _______, KC_EQL,  KC_BSPC, KC_MINS, KC_LBRC, KC_RBRC, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,                        _______, KC_PLUS, _______, KC_UNDS, _______, _______, _______, \
    _______, _______, _______, _______,          LOWER,   _______, _______,      _______, _______, RAISE,            _______, _______, _______, _______  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   \  |   `  |   '  |   {  |   [  |      |                    |      | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   |  |   ~  |   "  |   }  |   ]  |      |                    |      | Lng2 | Lng1 |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |||||||| Lower|      |      ||||||||      |      | Raise||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_BSLS, KC_GRV,  KC_QUOT, KC_LCBR, KC_LBRC, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, KC_PIPE, KC_TILD, KC_DQUO, KC_RCBR, KC_RBRC, _______,                        _______, KC_LNG2, KC_LNG1, _______, _______, _______, _______, \
    _______, _______, _______, _______,          LOWER,   _______, _______,      _______, _______, RAISE,            _______, _______, _______, _______  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | F11  | F12  |      |      |      |      |                    |      |      |      |      |      | Reset|      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      | Mute |VolDn |VolUp |PlyPau|NextTr|      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |  F6  |  F7  |  F8  |  F9  | F10  |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F11,  KC_F12,  _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  _______,                       _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, _______, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,                       _______, _______, _______, _______, _______, QK_BOOT, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

// clang-format on

// If this funtion returns true, let QMK send the original events.
// And if it returns false, skip all further processing of the key.
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
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}
