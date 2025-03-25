#include QMK_KEYBOARD_H
#include "keymap_nordic.h"

#define NO_ASTR LSFT(NO_APOS)
#define NO_BSLSH ALGR(NO_PLUS)

#define ALTDEL LALT_T(KC_DEL)
#define GUIESC LGUI_T(KC_ESC)

#define NUMBTAB LT(NUMB, KC_TAB)
#define SYMBENT LT(SYMB, KC_ENT)

enum layers {
    BASE = 0,
    SYMB,
    NUMB,
};

// TODO:
// - F1 - F12

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                                                                                                         Layout template.
                       _______,       _______,       _______,       _______,       _______,                                             _______,       _______,       _______,       _______,       _______,
        _______,       _______,       _______,       _______,       _______,       _______,                                             _______,       _______,       _______,       _______,       _______,       _______,
        _______,       _______,       _______,       _______,       _______,       _______,       _______,               _______,       _______,       _______,       _______,       _______,       _______,       _______,
                                                     _______,       _______,       _______,       _______,               _______,       _______,       _______,       _______
*/

    [BASE] = LAYOUT(
                       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                                KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,
        KC_BSPC,       KC_A,          KC_S,          KC_D,          KC_F,          KC_G,                                                KC_H,          KC_J,          KC_K,          KC_L,          NO_AE,         NO_AM,
        KC_LSFT,       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_MPLY,               KC_MUTE,       KC_N,          KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,       NO_OSLH,
                                                     GUIESC,        KC_SPC,        KC_LCTL,       _______,               _______,       ALTDEL,        SYMBENT,       NUMBTAB
    ),

    [SYMB] = LAYOUT(
                       NO_LPRN,       NO_RPRN,       NO_QUO2,       NO_APOS,       NO_GRV,                                              KC_EXLM,       KC_HASH,       NO_DLR,        KC_PERC,       NO_CIRC,
        _______,       NO_LCBR,       NO_RCBR,       NO_AMPR,       NO_AT,         NO_EQL,                                              KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       NO_TILD,       NO_QUES,
        _______,       NO_LBRC,       NO_RBRC,       NO_PIPE,       NO_LESS,       NO_GRTR,       _______,               _______,       NO_SLSH,       NO_BSLSH,      NO_SCLN,       NO_COLN,       NO_UNDS,       NO_ASTR,
                                                     _______,       _______,       _______,       _______,               _______,       _______,       _______,       _______
    ),

    [NUMB] = LAYOUT(

                       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,                                                KC_6,          KC_7,          KC_8,          KC_9,          KC_0,
        _______,       _______,       _______,       _______,       _______,       NO_EQL,                                              KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       NO_PLUS,       NO_QUES,
        _______,       _______,       _______,       _______,       _______,       _______,       _______,               _______,       NO_SLSH,       _______,       _______,       _______,       KC_SLSH,       NO_ASTR,
                                                     _______,       _______,       _______,       _______,               _______,       _______,       _______,       _______
    ),
};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [SYMB] = {ENCODER_CCW_CW(RM_HUEU, RM_HUED), ENCODER_CCW_CW(RM_VALU, RM_VALD)},
    [NUMB] = {ENCODER_CCW_CW(RM_SATU, RM_SATD), ENCODER_CCW_CW(RM_NEXT, RM_PREV)},
};
