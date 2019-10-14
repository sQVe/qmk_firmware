#include QMK_KEYBOARD_H
#include "keymap_nordic.h"

#define NO_ASTR LSFT(NO_APOS)
#define NO_BSLSH ALGR(NO_PLUS)

#define BASE 0
#define SYMB 1
#define MISC 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *  ,-----------------------------------------------------------------------------------.
   *  | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   +  |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  | BkSp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   _  | Shift|
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  | Ctrl | Meta |  Up  | Down | Space| Space| Enter| Left | Right AltG | Del  |   '  |
   *  `-----------------------------------------------------------------------------------'
   */

  [BASE] = LAYOUT_preonic_grid(
    KC_ESC,   KC_1,          KC_2,          KC_3,     KC_4,    KC_5,    KC_6,              KC_7,   KC_8,     KC_9,      KC_0,     NO_PLUS,
    KC_TAB,   KC_Q,          KC_W,          KC_E,     KC_R,    KC_T,    KC_Y,              KC_U,   KC_I,     KC_O,      KC_P,     NO_AM,
    KC_BSPC,  KC_A,          KC_S,          KC_D,     KC_F,    KC_G,    KC_H,              KC_J,   KC_K,     KC_L,      NO_AE,    LGUI_T(NO_OSLH),
    KC_LSFT,  LCTL_T(KC_Z),  LALT_T(KC_X),  KC_C,     KC_V,    KC_B,    KC_N,              KC_M,   KC_COMM,  KC_DOT,    NO_MINS,  KC_RSFT,
    KC_LCTL,  KC_LGUI,       KC_UP,         KC_DOWN,  KC_SPC,  KC_SPC,  LT(SYMB, KC_ENT),  KC_LEFT,  KC_RIGHT,  KC_ALGR,  KC_DEL,   LT(MISC, NO_APOS)
  ),

  /*
   *  ,-----------------------------------------------------------------------------------.
   *  |      |   !  |   "  |   #  |   $  |   %  |   &  |   /  |   (  |   )  |   =  |   ?  |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |   (  |   )  |   @  |   '  |   `  | Home | PgDn | PgUp | End  |   /  |   ~  |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |   {  |   }  |   &  |   ;  |   =  | Left | Down |  Up  | Right|   ^  |   *  |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |   [  |   ]  |   |  |   <  |   >  |   /  |   \  |   ;  |   :  |   _  |      |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |      |      |      |      |      |      |      |      |      |      |      |
   *  `-----------------------------------------------------------------------------------'
   */

  [SYMB] = LAYOUT_preonic_grid(
    KC_TRNS,  KC_EXLM,  NO_QUO2,  KC_HASH,  NO_DLR,   KC_PERC,  NO_AMPR,  NO_SLSH,        KC_LPRN,  NO_RPRN,  NO_EQL,   NO_QUES,
    KC_TRNS,  NO_LPRN,  NO_RPRN,  NO_AT,    NO_APOS,  NO_GRV,   KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   NO_SLSH,  NO_TILD,
    KC_TRNS,  NO_LCBR,  NO_RCBR,  NO_AMPR,  NO_SCLN,  NO_EQL,   KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  NO_CIRC,  NO_ASTR,
    KC_TRNS,  NO_LBRC,  NO_RBRC,  NO_PIPE,  NO_LESS,  NO_GRTR,  NO_SLSH,  ALGR(NO_PLUS),  NO_SCLN,  NO_COLN,  NO_UNDS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  /*
   *  ,-----------------------------------------------------------------------------------.
   *  |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |      |      | UI B | UI F |      |  F8  |  F10 |  F11 | S F11|  F9  |  F12 |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |      |      |      |      |      |      |      |      |      |      |      |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |      |      | Prev | Play | Next |      |      |      |      |      |      |
   *  |------+------+------+------+------+------+------+------+------+------+------+------|
   *  |      |      |      |      |      |      |      |      |      |      |      |      |
   *  `-----------------------------------------------------------------------------------'
   */

  [MISC] = LAYOUT_preonic_grid(
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,                KC_F4,                KC_F5,    KC_F6,    KC_F7,    KC_F8,      KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_NO,    KC_NO,    LCTL(LGUI(KC_LEFT)),  LCTL(LGUI(KC_RGHT)),  KC_NO,    KC_F8,    KC_F10,   KC_F11,   S(KC_F11),  KC_F9,    KC_F12,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,                KC_NO,                KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
    KC_TRNS,  KC_NO,    KC_NO,    KC_MPRV,              KC_MPLY,              KC_MNXT,  KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
};
