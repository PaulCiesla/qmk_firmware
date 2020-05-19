#include "mechmini.h"
#include "keymap_extras/keymap_german.h"

#define _BL 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BL] = KEYMAP_2U_SPACE_ORTHO(
		KC_ESC,          KC_Q,     KC_W,      KC_E,    KC_R,    KC_T,     DE_Z,   KC_U,     KC_I,     KC_O,     KC_P,    KC_BSPC, //how to get Del on shift?
		KC_TAB,          KC_A,     KC_S,      KC_D,    KC_F,    KC_G,     KC_H,   KC_J,     KC_K,     KC_L,     DE_HASH, KC_ENT,
        LSFT_T(KC_CAPS), DE_Y,     KC_X,      KC_C,    KC_V,    KC_B,     KC_N,   KC_M,     DE_COMM,  DE_DOT,   KC_UP,   DE_SLSH, //how to get bslash on shift?
		KC_LCTL,         KC_LGUI,  KC_LALT,   KC_APP,  MO(1),       KC_SPC,       MO(2),    DE_ALGR,  KC_LEFT,  KC_DOWN, KC_RGHT),

	[_FN1] = KEYMAP_2U_SPACE_ORTHO(
        DE_CIRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,
		_______, DE_PLUS, DE_MINS, DE_EQL,  _______, _______, DE_LBRC, DE_RBRC, DE_LCBR, DE_RCBR, DE_ACUT, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, DE_LESS, KC_PGUP, DE_MORE,
		_______, _______, _______, _______, _______,      _______,     MO(3),   _______, KC_HOME, KC_PGDN, KC_END),

	[_FN2] = KEYMAP_2U_SPACE_ORTHO(
        _______, DE_AT,   _______, DE_EURO, _______, _______, _______, DE_UE,   _______, DE_OE,   _______, KC_DEL,
		_______, DE_AE,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, MO(3),        _______,     _______, _______, _______, _______, _______),

    [_FN3] = KEYMAP_2U_SPACE_ORTHO(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, BL_TOGG, BL_STEP, BL_INC,  BL_DEC,  _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_MPRV, KC_MPLY, KC_MNXT,
        RESET,   _______, _______, _______, _______,      _______,     _______, _______, KC_VOLD, KC_MUTE, KC_VOLU),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {
		case 1:
			if (record->event.pressed) {
				return MACRO( D(LCTL), T(C), U(LCTL), END );
			}
			break;
		case 2:
			if (record->event.pressed) {
				return MACRO( D(LCTL), T(V), U(LCTL), END );
			}
			break;
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
