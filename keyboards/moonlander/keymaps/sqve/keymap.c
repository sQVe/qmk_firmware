#include QMK_KEYBOARD_H
#include "keymap_nordic.h"

#define NO_ASTR LSFT(NO_APOS)
#define NO_BSLSH ALGR(NO_PLUS)

enum layers {
  BASE,
  SYMB,
  MISC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐           ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   *  │ Esc  │   1  │   2  │   3  │   4  │   5  │ Del  │           │   /  │   6  │   7  │   8  │   9  │   0  │   +  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │ Tab  │   Q  │   W  │   E  │   R  │   T  │ A CR │           │ C Spc│   Y  │   U  │   I  │   O  │   P  │   Å  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │ BkSp │   A  │   S  │   D  │   F  │   G  │ OSL M│           │ Esc  │   H  │   J  │   K  │   L  │   Ö  │   Ä  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┘           └──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │ Shift│   Z  │   X  │   C  │   V  │   B  │                         │   N  │   M  │   ,  │   .  │   -  │ Shift│
   *  ├──────┼──────┼──────┼──────┼──────┼──────┘                         └──────┼──────┼──────┼──────┼──────┼──────┤
   *  │ Ctrl │ Meta │ Alt  │  Up  │ Down │                                       │ Left │ Right│ AltG │ Del  │   '  │
   *  └──────┴──────┴──────┴──────┴──────┘                                       └──────┴──────┴──────┴──────┴──────┘
   *
   *                                         ┌─────────────┐       ┌─────────────┐
   *                                         │  RGB Mode   │       │ RGB Toggle  │
   *                                  ┌──────┼──────┬──────┤       ├──────┬──────┼──────┐
   *                                  │      │      │ RGB  │       │ RGB  │      │ LT   │
   *                                  │ Space│ Esc  │ Hue  │       │ Sat  │ OSM  │ Symb │
   *                                  │      │      │ +/-  │       │ +/-  │ Meta │ CR   │
   *                                  └──────┴──────┴──────┘       └──────┴──────┴──────┘
   */

  [BASE] = LAYOUT_moonlander(
    KC_ESC,   KC_1,          KC_2,          KC_3,   KC_4,     KC_5,     KC_DEL,                NO_SLSH,         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     NO_PLUS,
    KC_TAB,   KC_Q,          KC_W,          KC_E,   KC_R,     KC_T,     LALT_T(KC_ENT),        LCTL_T(KC_SPC),  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     NO_AM,
    KC_BSPC,  KC_A,          KC_S,          KC_D,   KC_F,     KC_G,     OSL(MISC),             KC_ESC,          KC_H,     KC_J,     KC_K,     KC_L,     NO_AE,    LGUI_T(NO_OSLH),
    KC_LSFT,  LCTL_T(KC_Z),  LALT_T(KC_X),  KC_C,   KC_V,     KC_B,                                             KC_N,     KC_M,     KC_COMM,  KC_DOT,   NO_MINS,  KC_RSFT,
    KC_LCTL,  KC_LGUI,       KC_LALT,       KC_UP,  KC_DOWN,            RGB_MOD,               RGB_TOG,                   KC_LEFT,  KC_RGHT,  KC_ALGR,  KC_DEL,   LT(MISC, NO_APOS),
                                                       KC_SPC,  KC_ESC, RGB_HUI,               RGB_SAI,  OSM(MOD_LGUI), LT(SYMB, KC_ENT)
    ),

  /*
   *  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐           ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   *  │      │   !  │   "  │   #  │   $  │   %  │      │           │   \  │   &  │   /  │   (  │   )  │   =  │   ?  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │   (  │   )  │   @  │   '  │   `  │      │           │      │ Home │ PgDn │ PgUp │  End │   /  │   ~  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │   {  │   }  │   &  │   ;  │   =  │      │           │      │ Left │ Down │  Up  │ Right│   ^  │   *  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┘           └──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │   [  │   ]  │   |  │   <  │   >  │                         │   /  │   \  │   ;  │   :  │   _  │      │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┘                         └──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │      │      │      │      │                                       │      │      │      │      │      │
   *  └──────┴──────┴──────┴──────┴──────┘                                       └──────┴──────┴──────┴──────┴──────┘
   *
   *                                         ┌─────────────┐       ┌─────────────┐
   *                                         │             │       │             │
   *                                  ┌──────┼──────┬──────┤       ├──────┬──────┼──────┐
   *                                  │      │      │ RGB  │       │ RGB  │      │      │
   *                                  │      │      │ Str  │       │ Spd  │      │      │
   *                                  │      │      │ +/-  │       │ +/-  │      │      │
   *                                  └──────┴──────┴──────┘       └──────┴──────┴──────┘
   */


  [SYMB] = LAYOUT_moonlander(
        _______,  KC_EXLM,  NO_QUO2,  KC_HASH,  NO_DLR,   KC_PERC,  _______,           ALGR(NO_PLUS),  NO_AMPR,  NO_SLSH,        NO_LPRN,  NO_RPRN,  NO_EQL,   NO_QUES,
        _______,  NO_LPRN,  NO_RPRN,  NO_AT,    NO_APOS,  NO_GRV,   _______,           _______,        KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   NO_SLSH,  NO_TILD,
        _______,  NO_LCBR,  NO_RCBR,  NO_AMPR,  NO_SCLN,  NO_EQL,   _______,           _______,        KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  NO_CIRC,  NO_ASTR,
        _______,  NO_LBRC,  NO_RBRC,  NO_PIPE,  NO_LESS,  NO_GRTR,                                     NO_SLSH,  ALGR(NO_PLUS),  NO_SCLN,  NO_COLN,  NO_UNDS,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,           _______,                  _______,        _______,  _______,  _______,  _______,
                                                _______,  _______,  RGB_VAI,           RGB_SPI,  _______,  _______
    ),

  /*
   *  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐           ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   *  │      │  F1  │  F2  │  F3  │  F4  │  F5  │      │           │      │  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │      │      │ UI B │ UI F │      │      │           │      │  F8  │  F10 │  F11 │ S F11│  F9  │ F12  │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │      │      │      │      │      │      │           │      │      │      │      │      │      │      │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┘           └──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │      │      │ Prev │ Play │ Next │                         │      │      │      │      │      │      │
   *  ├──────┼──────┼──────┼──────┼──────┼──────┘                         └──────┼──────┼──────┼──────┼──────┼──────┤
   *  │      │      │      │      │      │                                       │      │      │      │      │      │
   *  └──────┴──────┴──────┴──────┴──────┘                                       └──────┴──────┴──────┴──────┴──────┘
   *
   *                                         ┌─────────────┐       ┌─────────────┐
   *                                         │             │       │             │
   *                                  ┌──────┼──────┬──────┤       ├──────┬──────┼──────┐
   *                                  │      │      │      │       │      │      │      │
   *                                  │      │      │      │       │      │      │      │
   *                                  │      │      │      │       │      │      │      │
   *                                  └──────┴──────┴──────┘       └──────┴──────┴──────┘
   */



  [MISC] = LAYOUT_moonlander(
        _______,  KC_F1,    KC_F2,    KC_F3,               KC_F4,                KC_F5,    _______,             KC_NO,    KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,   KC_F11,
        _______,  KC_NO,    KC_NO,    LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)),  KC_NO,    _______,             _______,  KC_F8,    KC_F10,   KC_F11,   S(KC_F11),  KC_F9,    KC_F12,
        _______,  KC_NO,    KC_NO,    KC_NO,               KC_NO,                KC_NO,    _______,             _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,
        _______,  KC_NO,    KC_NO,    KC_MPRV,             KC_MPLY,              KC_MNXT,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    _______,
        _______,  _______,  _______,  _______,             _______,                        _______,             _______,            _______,  _______,  _______,    _______,  _______,
                                                                       _______,  _______,  _______,             _______,  _______,  _______
    ),
};

