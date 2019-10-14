#include QMK_KEYBOARD_H
#include "keymap_nordic.h"

#define NO_ASTR LSFT(NO_APOS)
#define NO_BSLSH ALGR(NO_PLUS)

#define BASE 0
#define SYMB 1
#define MISC 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *  ,--------------------------------------------------.           ,--------------------------------------------------.
   *  | Esc    |   1  |   2  |   3  |   4  |   5  | Del  |           |   /  |   6  |   7  |   8  |   9  |   0  |   +    |
   *  |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   *  | Tab    |   Q  |   W  |   E  |   R  |   T  | Alt  |           | Ctrl |   Y  |   U  |   I  |   O  |   P  |   Å    |
   *  |--------+------+------+------+------+------| Enter|           | Space|------+------+------+------+------+--------|
   *  | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
   *  |--------+------+------+------+------+------| OSL  |           | Esc  |------+------+------+------+------+--------|
   *  | Shift  |   Z  |   X  |   C  |   V  |   B  | Misc |           |      |   N  |   M  |   ,  |   .  |   _  |  Shift |
   *  `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *    | Ctrl | Meta | Alt  |  Up  | Down |                                       | Left | Right| AltG | Del |   '   |
   *    `----------------------------------'                                       `----------------------------------'
   *
   *                                         ,-------------.       ,-------------.
   *                                         | Back | Forw |       | Home | End  |
   *                                  ,------|------|------|       |------+------+------.
   *                                  |      |      | MW U |       | PgUp |      | LT   |
   *                                  | Space| Esc  |------|       |------| OSM  | Symb |
   *                                  |      |      | MW D |       | PgDn | Meta | Enter|
   *                                  `--------------------'       `--------------------'
   */

  [BASE] = LAYOUT_ergodox(
    KC_ESC,   KC_1,           KC_2,           KC_3,     KC_4,     KC_5,   KC_DEL,
    KC_TAB,   KC_Q,           KC_W,           KC_E,     KC_R,     KC_T,   LALT_T(KC_ENT),
    KC_BSPC,  KC_A,           KC_S,           KC_D,     KC_F,     KC_G,
    KC_LSFT,  LCTL_T(KC_Z),   LALT_T(KC_X),   KC_C,     KC_V,     KC_B,   OSL(MISC),
    KC_LCTL,  KC_LGUI,        KC_LALT,        KC_UP,    KC_DOWN,


                                                                  KC_WBAK,  KC_WFWD,
                                                                            KC_WH_U,
                                                          KC_SPC, KC_ESC,   KC_WH_D,

    // -----------------------------------------------------------------------------------------------------------------

    NO_SLSH,         KC_6,  KC_7,     KC_8,     KC_9,     KC_0,     NO_PLUS,
    LCTL_T(KC_SPC),  KC_Y,  KC_U,     KC_I,     KC_O,     KC_P,     NO_AM,
                     KC_H,  KC_J,     KC_K,     KC_L,     NO_AE,    LGUI_T(NO_OSLH),
    KC_ESC,          KC_N,  KC_M,     KC_COMM,  KC_DOT,   NO_MINS,  KC_RSFT,
                            KC_LEFT,  KC_RGHT,  KC_ALGR,  KC_DEL,   LT(MISC, NO_APOS),


    KC_HOME,  KC_END,
    KC_PGUP,
    KC_PGDN,  OSM(MOD_LGUI),  LT(SYMB, KC_ENT)
  ),

  /*
   *  ,--------------------------------------------------.           ,--------------------------------------------------.
   *  |        |   !  |   "  |   #  |   $  |   %  |      |           |   \  |   &  |   /  |  (   |   )  |   =  |   ?    |
   *  |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   *  |        |  (   |   )  |   @  |   '  |   `  |      |           |      | Home | PgDn | PgUp | End  |   /  |   ~    |
   *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   *  |        |  {   |   }  |   &  |   ;  |   =  |------|           |------| Left | Down |  Up  | Right|   ^  |   *    |
   *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   *  |        |  [   |   ]  |   |  |   <  |   >  |      |           |      |   /  |   \  |   ;  |  :   |   _  |        |
   *  `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *    |      |      |      |      |      |                                       |      |      |      |      |      |
   *    `----------------------------------'                                       `----------------------------------'
   *
   *                                         ,-------------.       ,-------------.
   *                                         |      |      |       |      |      |
   *                                  ,------|------|------|       |------+------+------.
   *                                  |      |      |      |       |      |      |      |
   *                                  |      |      |------|       |------|      |      |
   *                                  |      |      |      |       |      |      |      |
   *                                  `--------------------'       `--------------------'
   */

  [SYMB] = LAYOUT_ergodox(
    KC_TRNS,  KC_EXLM,  NO_QUO2,  KC_HASH,  NO_DLR,   KC_PERC,  KC_TRNS,
    KC_TRNS,  NO_LPRN,  NO_RPRN,  NO_AT,    NO_APOS,  NO_GRV,   KC_TRNS,
    KC_TRNS,  NO_LCBR,  NO_RCBR,  NO_AMPR,  NO_SCLN,  NO_EQL,
    KC_TRNS,  NO_LBRC,  NO_RBRC,  NO_PIPE,  NO_LESS,  NO_GRTR,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,


                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,

    // -----------------------------------------------------------------------------------------------------------------

    ALGR(NO_PLUS),  NO_AMPR,  NO_SLSH,        NO_LPRN,  NO_RPRN,  NO_EQL,    NO_QUES,
    KC_TRNS,        KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   NO_SLSH,   NO_TILD,
                    KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  NO_CIRC,   NO_ASTR,
    KC_TRNS,        NO_SLSH,  ALGR(NO_PLUS),  NO_SCLN,  NO_COLN,  NO_UNDS,   KC_TRNS,
                              KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,


    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  /*
   *  ,--------------------------------------------------.           ,--------------------------------------------------.
   *  |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
   *  |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   *  |        |      |      | UI B | UI F |      |      |           |      |  F8  |  F10 | F11  | S F11|  F9  |  F12   |
   *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   *  |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
   *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   *  |        |      |      | Prev | Play | Next |      |           |      |      |      |      |      |      |        |
   *  `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *    |      |      |      |      |      |                                       |      |      |      |      |      |
   *    `----------------------------------'                                       `----------------------------------'
   *
   *                                         ,-------------.       ,-------------.
   *                                         |      |      |       |      |      |
   *                                  ,------|------|------|       |------+------+------.
   *                                  |      |      |      |       |      |      |      |
   *                                  |      |      |------|       |------|      |      |
   *                                  |      |      |      |       |      |      |      |
   *                                  `--------------------'       `--------------------'
   */

  [MISC] = LAYOUT_ergodox(
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,                KC_F4,                KC_F5,    KC_TRNS,
    KC_TRNS,  KC_NO,    KC_NO,    LCTL(LGUI(KC_LEFT)),  LCTL(LGUI(KC_RGHT)),  KC_NO,    KC_TRNS,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,                KC_NO,                KC_NO,
    KC_TRNS,  KC_NO,    KC_NO,    KC_MPRV,              KC_MPLY,              KC_MNXT,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,


                                                                              KC_TRNS,  KC_TRNS,
                                                                                        KC_TRNS,
                                                                    KC_TRNS,  KC_TRNS,  KC_TRNS,

    // -----------------------------------------------------------------------------------------------------------------

    KC_NO,    KC_F6,  KC_F7,   KC_F8,    KC_F9,      KC_F10,   KC_F11,
    KC_TRNS,  KC_F8,  KC_F10,  KC_F11,   S(KC_F11),  KC_F9,    KC_F12,
              KC_NO,  KC_NO,   KC_NO,    KC_NO,      KC_NO,    KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,    KC_NO,      KC_NO,    KC_TRNS,
                      KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,


    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
};

// Init.
void matrix_init_user(void) {
  wait_ms(500);
  ergodox_board_led_on();
  wait_ms(200);
  ergodox_right_led_1_on();
  wait_ms(200);
  ergodox_right_led_2_on();
  wait_ms(200);
  ergodox_right_led_3_on();
  wait_ms(200);
  ergodox_board_led_off();
  wait_ms(200);
  ergodox_right_led_1_off();
  wait_ms(200);
  ergodox_right_led_2_off();
  wait_ms(200);
  ergodox_right_led_3_off();
};

// LED background loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
};
