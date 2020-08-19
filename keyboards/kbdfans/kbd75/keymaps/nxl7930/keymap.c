#include QMK_KEYBOARD_H

/* Emulating the wonderful example from the docs (cluboard/66/keymaps/default/keymap.c)
 * 
 * Each layer gets a name for readability, then use in the matrix below.
 * The underscores don't mean anything, but it looks professional, so keeping them in.
 * My strategy here is to have a base layer with normal stuff, including computer controls
 * The original function keys are then on an overlay, this also has backlight and underglow
 * Greek and some mathematical symbols I also want on another layer
 * For these I'm choosing the basis unicode mode from the docs + UC_WINC using WinCompose
*/

#define _BL 0
#define _FGL 1
#define _SL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Keymap _BL: Base Layer (Default Layer)
	[_BL] = LAYOUT(
		KC_ESC, KC_MUTE,  KC_VOLD, KC_VOLU, KC_F4,   BL_STEP, KC_BRID, KC_BRIU, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CALC, MO(_SL), KC_DEL,
		KC_GRV, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_HOME,
		KC_TAB, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
		KC_CAPS,KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
		KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,            KC_END,
		KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,  KC_SPC,  KC_SPC,                    KC_RALT, MO(_FGL),KC_RCTL, KC_LEFT, KC_DOWN,          KC_RGHT),

	// Keymap _FGL: Function & Greek Layer; Overlay Base Layer with Fcn keys and frequently used math characters
	[_FGL] = LAYOUT(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PAUS, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______,
		_______, KC_Q,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, KC_A,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, KC_Z,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______,          _______, _______, _______,                   _______, _______, _______, _______, _______,          _______),

	// Keymap _SL: Keyboard Settings Layer; for configuring the keyboard backlight and underglow
	[_SL] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
		_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______, _______, _______,          _______,
		_______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,                   _______,
		_______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, BL_BRTG, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______,          _______, _______, _______,                   _______, _______, _______, _______, _______,          _______)

};
