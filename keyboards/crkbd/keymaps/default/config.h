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

#pragma once

/* Select hand configuration */

//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

//Split functionality (All needed?)
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

//#define DYNAMIC_KEYMAP_LAYER_COUNT 7

#ifdef RGBLIGHT_ENABLE
//    #define RGBLIGHT_EFFECT_BREATHING
//    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
//    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 5
    #define RGBLIGHT_SAT_STEP 12
    #define RGBLIGHT_VAL_STEP 12
#endif

#ifdef RGB_MATRIX_ENABLE
//#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
//#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

#    define UNDERGLOW_OFF

/* Enable the animations you want/need.  You may need to enable only a small number of these because       *
 * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#    define ENABLE_RGB_MATRIX_SOLID
# undef ENABLE_RGB_MATRIX_ALPHAS_MODS
# undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
# undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
# undef ENABLE_RGB_MATRIX_BREATHING
# undef ENABLE_RGB_MATRIX_BAND_SAT
# undef ENABLE_RGB_MATRIX_BAND_VAL
# undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
# undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
# undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
# undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
# undef ENABLE_RGB_MATRIX_CYCLE_ALL
# undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
# undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
# undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
# undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
# undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
# undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
# undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
# undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
# undef ENABLE_RGB_MATRIX_RAINDROPS
# undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
# undef ENABLE_RGB_MATRIX_HUE_BREATHING
# undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
# undef ENABLE_RGB_MATRIX_PIXEL_RAIN
# undef ENABLE_RGB_MATRIX_PIXEL_FLOW
# undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
# undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
# undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
# undef ENABLE_RGB_MATRIX_SPLASH
# undef ENABLE_RGB_MATRIX_MULTISPLASH
# undef ENABLE_RGB_MATRIX_SOLID_SPLASH
# undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

//heatmap settings
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40
#define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32
# endif

#ifndef OLED_ENABLE
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif

#define CAPS_WORD_IDLE_TIMEOUT	3000

//#define TAPPING_TERM 180

//One shot
#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 3000

//keymap stuff
//Left hand layer controls
#define SYM_BSPC LT(L_SYM, KC_BSPC)
#define NUM_TAB LT(L_NUM, KC_TAB)
#define JSYM_BSPC LT(L_JSYM, KC_BSPC)

//Right hand layer controls
#define CTL_ENT MT(MOD_RCTL, KC_ENT)
#define CTL_A   MT(MOD_LCTL, KC_A)
#define NAV_SPC LT(L_NAV, KC_SPC)
#define OS_SFT OSM(MOD_RSFT)

#define WIN_APP RGUI_T(KC_APP)
#define WIN_Z   LGUI_T(KC_Z)
#define L_DESK LCTL(LGUI(KC_LEFT))
#define R_DESK LCTL(LGUI(KC_RIGHT))
#define COPY LCTL_T(KC_C)
#define PASTE LCTL_T(KC_V)

//Other funcs

//make some more space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

