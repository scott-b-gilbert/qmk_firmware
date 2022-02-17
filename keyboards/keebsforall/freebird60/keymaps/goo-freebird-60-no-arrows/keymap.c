/* Copyright 2020 KnoblesseOblige
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

#define CTL_ESC  LCTL_T(KC_ESC)    // Tap for ESC, hold for CTRL

// Macros
enum {
    DESK_RIGHT = SAFE_RANGE, 
    DESK_LEFT,
    QUICK_NOTE,
    CTRL_ALT_DEL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,    KC_6,    KC_7,   KC_8,     KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,   KC_F,  KC_G,    KC_H,    KC_J,   KC_K,     KC_L,   KC_SCLN, KC_QUOT, KC_ENTER,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,    KC_N,    KC_M,   KC_COMMA, KC_DOT, KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                             MO(1),  KC_RGUI, KC_RALT, KC_RCTL
    ),
    [1] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,      KC_F10,  KC_F11,  KC_F12,  CTRL_ALT_DEL, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______,   QUICK_NOTE, _______, _______, _______, KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, KC_PGDN,
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, DESK_LEFT, DESK_RIGHT, _______, KC_UP,
        KC_MUTE, KC_VOLD, _______, _______, _______,                                                   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		// be sure to add the keycode to the enum at the top of the file
		switch(keycode) {
			// DESK_RIGHT will do move desktop to the right  
			case DESK_RIGHT:
				register_code(KC_LCTL);
				register_code(KC_LGUI);
				tap_code_delay(KC_RIGHT, 200);
				unregister_code(KC_LCTL);
				unregister_code(KC_LGUI);
				break;
				// DESK_LEFT will do move desktop to the left
			case DESK_LEFT:
				register_code(KC_LCTL);
				register_code(KC_LGUI);
				tap_code_delay(KC_LEFT, 200);
				unregister_code(KC_LCTL);
				unregister_code(KC_LGUI);
				break;
				// QUICK_NOTE will do Open quicknote in OneNote
			case QUICK_NOTE:
				register_code(KC_LALT);
				register_code(KC_LGUI);
				tap_code_delay(KC_N, 200);
				unregister_code(KC_LALT);
				unregister_code(KC_LGUI);
				break;
			case CTRL_ALT_DEL:
				register_code(KC_LCTL);
				register_code(KC_LALT);
				tap_code_delay(KC_DEL, 200);
				unregister_code(KC_LCTL);
				unregister_code(KC_LALT);
				break;
		}
	}
	return true;
};
