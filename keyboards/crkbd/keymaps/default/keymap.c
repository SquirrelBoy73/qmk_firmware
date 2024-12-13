/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>
#include "keymap_japanese.h"

//my globals
bool bCaps = 0;
bool bJpn = 0;

enum layouts{
	L_QWRTY = 0,
	L_JPN,
	L_NAV,
	L_NUM,
	L_SYM,
	L_JSYM,
	L_FUN,
	L_KEEB,
};

enum my_keycodes{
	KEEB = SAFE_RANGE,
	JPN_TG,
};

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t delete_keyoverride = ko_make_basic(MOD_MASK_SHIFT, LT(L_SYM, KC_BSPC), KC_DEL);
const key_override_t del_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_JSYM, KC_BSPC), KC_DEL);

const key_override_t *key_overrides[] = {
	&delete_keyoverride,
    &del_key_override,
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWRTY] = LAYOUT_split_3x6_3(
  //|----------------------------------------------------|         |---------------------------------------------------|
      XXXXXXX,    KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,            KC_Y,   KC_U,    KC_I,    KC_O,     KC_P, XXXXXXX,
  //|----------------------------------------------------|         |---------------------------------------------------|
      XXXXXXX,   CTL_A,    KC_S,   KC_D,   KC_F,    KC_G,            KC_H,   KC_J,    KC_K,    KC_L,  CTL_ENT, XXXXXXX,
  //|----------------------------------------------------|         |---------------------------------------------------|
      XXXXXXX,   WIN_Z,    KC_X,   KC_C,   KC_V,    KC_B,            KC_N,   KC_M,  KC_ESC, KC_RALT,  WIN_APP, XXXXXXX,
  //|----------------------------------------------------|         |---------------------------------------------------|
                               _______, SYM_BSPC, NUM_TAB,        OS_SFT, NAV_SPC, _______
                                           //`--------------'  `--------------'
  ),

  [L_JPN] = LAYOUT_split_3x6_3(
  //|-------------------------------------------------------|         |--------------------------------------------------------|
      _______, _______, _______, _______, _______, _______,              _______,  _______, _______, _______,  _______, _______,
  //|-------------------------------------------------------|         |--------------------------------------------------------|
      _______, _______, _______, _______, _______, _______,              _______,  _______, _______, _______,  _______, _______,
  //|-------------------------------------------------------|         |--------------------------------------------------------|
      _______, _______, _______, _______, _______, _______,              _______,  _______, _______, _______,  _______, _______,
  //|-------------------------------------------------------|         |--------------------------------------------------------|
                                      _______, JSYM_BSPC, _______,    _______, _______, _______
                                               //`--------------'  `--------------'
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
  //|-------------------------------------------------------|      |-----------------------------------------------------------------|
      _______, _______, _______, _______, _______, L_DESK,          _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______,
  //|-------------------------------------------------------|      |-----------------------------------------------------------------|
      _______, KC_VOLU, XXXXXXX, KC_LCTL, KC_LSFT, KC_HOME,          KC_END,    KC_LEFT,    KC_DOWN,    KC_UP,     KC_RGHT, _______,
  //|-------------------------------------------------------|      |-----------------------------------------------------------------|
      _______, KC_VOLD, KC_MPLY, XXXXXXX, CW_TOGG, KC_MUTE,         _______,    KC_WH_L,    KC_WH_D,  KC_WH_U,     KC_WH_R, _______,
  //|-------------------------------------------------------|      |-----------------------------------------------------------------|
                                    _______, _______, _______,    _______, _______, _______
                                             //`--------------'  `--------------'
  ),
  [L_FUN] = LAYOUT_split_3x6_3(
  //|-------------------------------------------------------------------------------|      |----------------------------------------------------------------------------------|
      LALT(KC_F1), LALT(KC_F2), LALT(KC_F3), LALT(KC_F4), LALT(KC_F5), LALT(KC_F6),          LALT(KC_F7), LALT(KC_F8), LALT(KC_F9), LALT(KC_F10), LALT(KC_F11), LALT(KC_F12),
  //|-------------------------------------------------------------------------------|      |----------------------------------------------------------------------------------|
            KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,                KC_F7,       KC_F8,       KC_F9,       KC_F10,       KC_F11,       KC_F12,
  //|-------------------------------------------------------------------------------|      |----------------------------------------------------------------------------------|
      LCTL(KC_F1), LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5), LCTL(KC_F6),          LCTL(KC_F7), LCTL(KC_F8), LCTL(KC_F9), LCTL(KC_F10), LCTL(KC_F11), LCTL(KC_F12),
  //|-------------------------------------------------------------------------------|      |----------------------------------------------------------------------------------|
                                                            XXXXXXX, _______, _______,    _______, _______, XXXXXXX
                                                                     //`--------------'  `--------------'
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
  //|----------------------------------------------------------------|          |-----------------------------------------------|
      XXXXXXX, _______,  _______, _______, _______, _______,                         KC_ASTR, KC_7, KC_8, KC_9, KC_BSPC, XXXXXXX,
  //|----------------------------------------------------------------|          |-----------------------------------------------|
      XXXXXXX, KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                         KC_PLUS, KC_4, KC_5, KC_6,     KC_0, XXXXXXX,
  //|----------------------------------------------------------------|          |-----------------------------------------------|
      XXXXXXX, _______,  _______, _______, _______, _______,                         KC_SLSH, KC_1, KC_2, KC_3,  KC_DOT, XXXXXXX,
  //|----------------------------------------------------------------|          |-----------------------------------------------|
                                               _______, _______,  _______,     KC_PMNS, _______, _______
                                                        //`--------------'  `--------------'
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
  //|------------------------------------------------------|       |-------------------------------------------------------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______,
  //|------------------------------------------------------|       |-------------------------------------------------------|
      _______, KC_COLN, KC_LBRC, KC_LCBR, KC_LPRN, KC_DQUO,          KC_QUOT, KC_RPRN, KC_RCBR, KC_RBRC, KC_SCLN, _______,
  //|------------------------------------------------------|       |-------------------------------------------------------|
      _______, KC_QUES,   KC_LT,   KC_GT, KC_UNDS,  KC_EQL,          KC_TILD, KC_MINS, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|------------------------------------------------------|       |-------------------------------------------------------|
                                    XXXXXXX, _______, _______,    _______, _______, XXXXXXX
                                            //`--------------'   `--------------'
    ),
  [L_JSYM] = LAYOUT_split_3x6_3(
  //|------------------------------------------------------|       |-------------------------------------------------------|
      _______, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC,          JP_CIRC, JP_AMPR, JP_ASTR, JP_BSLS, JP_PIPE, _______,
  //|------------------------------------------------------|       |-------------------------------------------------------|
      _______, JP_COLN, JP_LBRC, JP_LCBR, JP_LPRN, JP_DQUO,          JP_QUOT, JP_RPRN, JP_RCBR, JP_RBRC, JP_SCLN, _______,
  //|------------------------------------------------------|       |-------------------------------------------------------|
      _______, JP_QUES, JP_LABK, JP_RABK, JP_UNDS,  JP_EQL,          JP_TILD, JP_MINS, JP_COMM,  JP_DOT, JP_SLSH, _______,
  //|------------------------------------------------------|       |-------------------------------------------------------|
                                    XXXXXXX, _______, _______,    _______, _______, XXXXXXX
                                            //`--------------'   `--------------'
    ),
  [L_KEEB] = LAYOUT_split_3x6_3(
  //|--------------------------------------------------------|      |-------------------------------------------------------|
      XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI,  JPN_TG,  RGB_TOG,          XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT, XXXXXXX,
  //|--------------------------------------------------------|      |-------------------------------------------------------|
      XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD, RGB_HUI,  RGB_MOD,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------|      |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------|      |-------------------------------------------------------|
									XXXXXXX, _______,  _______,    _______, _______, XXXXXXX
                                             //`--------------'  `--------------'
    )


};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// Only OLED on right side for now don't need to change things
//  if (is_keyboard_right()) {
	//return OLED_ROTATION_90;
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
//  }
/*  else {
	  return OLED_ROTATION_270;
  }
*/
//  return rotation;
}

void oled_render_layer_state(void) {

	oled_set_cursor(0, 0);

/*    oled_write_P(PSTR("Layer"), false);

	oled_set_cursor(0, 1);
*/
	switch (get_highest_layer(layer_state)) {
      case L_NAV:
            oled_write_ln_P(PSTR("Navi"), false);
            break;
		case L_NUM:
			oled_write_ln_P(PSTR("Num"),	false);
			break;
		case L_SYM:
			oled_write_ln_P(PSTR("Sym"),	false);
			break;
		case L_JSYM:
			oled_write_ln_P(PSTR("J-Sym"),  false);
			break;
		case L_FUN:
			oled_write_ln_P(PSTR("Funct"), false);
			break;
		case L_KEEB:
			oled_write_ln_P(PSTR("K-Fun"), false);
			break;
		default:
			oled_write_ln_P(PSTR("     "), false);
			break;
	}

    if(layer_state_is(L_KEEB))
    {
        oled_set_cursor(0,0);
        oled_write_ln_P(PSTR("Keeb"), false);
    }
	//Japanese mode display
 	oled_set_cursor(0,1);
	if(layer_state_is(L_JPN)) {
		oled_write_ln_P(PSTR("Japan"), false);
 	} else {
		oled_write_ln_P(PSTR("     "), false);
	}

	//Caps word status display (only works on master side, slave OLED needs different way of getting info!)
	oled_set_cursor(0, 2);
	if(is_caps_word_on()) {
		oled_write_ln_P(PSTR("CapWd"),	false);
	}
	else {
		oled_write_ln_P(PSTR("     "),	false);
	}

}

/*void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}
*/
bool oled_task_user(void) {

// Only right side OLED now so no change display
//    if (is_keyboard_right()) {
        oled_render_layer_state();
//    }
/*    else {
       oled_render_logo();
    }
*/    return false;
}
#endif // OLED Enable

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

	for(uint8_t i = led_min; i < led_max; i++) {
		if(g_led_config.flags[i] & LED_FLAG_INDICATOR) {
			if(i != 6 && i != 13 && i != 33 && i != 39) {
				rgb_matrix_set_color(i, RGB_OFF);
			}
		}
	}

	for(uint8_t i = led_min; i < led_max; i++) {
		if(g_led_config.flags[i] & LED_FLAG_INDICATOR) {
			if(i != 6 && i != 13 && i != 33 && i != 40) {
				rgb_matrix_set_color(i, RGB_OFF);
			}
		}
	}

	#ifdef UNDERGLOW_OFF
		for(uint8_t i = led_min; i < led_max; i++) {
			if(g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
				rgb_matrix_set_color(i, RGB_OFF);
			}
		}
	#endif
	return true;
}

#endif //RGB_MATRIX_ENABLE

#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active)
{
	#ifdef OLED_ENABLE
	oled_render_layer_state();
	#endif
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	switch (keycode) {
		case JPN_TG:
			if(!record->event.pressed) {
				if(bJpn) {
					layer_off(L_JPN);
				} else {
					layer_on(L_JPN);
				}
				bJpn = !bJpn;
                #ifdef OLED_ENABLE
				oled_task_user();
                #endif
				return false;
			}
			break;
		default:
			return true;
	}

	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	//update the tri layer state, hoping this will fix the timing problems
//	state = update_tri_layer_state(state, L_NAV, L_NUM, L_KEEB);
    if(IS_LAYER_ON(L_SYM))
    {
        state = update_tri_layer_state(state, L_SYM, L_NAV, L_KEEB);
    }
    else if(IS_LAYER_ON(L_JSYM))
    {
        state = update_tri_layer_state(state, L_JSYM, L_NAV, L_KEEB);
    }
    else
    {
        state = update_tri_layer_state(state, L_NUM, L_NAV, L_FUN);
        state = update_tri_layer_state(state, L_SYM, L_NAV, L_KEEB);
        state = update_tri_layer_state(state, L_JSYM, L_NAV, L_KEEB);
    }
    return state;
}
