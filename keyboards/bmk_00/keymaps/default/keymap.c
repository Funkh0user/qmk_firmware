#include "bmk_00.h"

enum encoder_names {
  DIAL,
};

enum layers {
    _NUM,
    _ALT,
    _NA,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NUM] = KEYMAP(
        KC_NUM,    KC_PSLS,    KC_PAST,  KC_PMNS,
        KC_P7,     KC_P8,      KC_P9,
        KC_P4,     KC_P5,      KC_P6,    KC_PPLS,
        KC_P1,     KC_P2,      KC_P3,
        KC_P0,                 KC_PDOT,  KC_PENT
    ),

	[_ALT] = KEYMAP(
		KC_NLCK,    KC_SLSH,    KC_ASTR,    KC_MINS,
		KC_HOME,    KC_NO,      KC_PGUP,
		KC_NO,      KC_5,       KC_NO,      KC_PLUS,
		KC_END,     KC_NO,      KC_PGDN,
		KC_INS,     KC_DEL,     KC_ENT),

	[_NA] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _NUM:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _ALT:
            oled_write_P(PSTR("ALT\n"), false);
            break;
        case _NA:
            oled_write_P(PSTR("NA\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif


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
