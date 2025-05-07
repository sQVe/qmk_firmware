#include QMK_KEYBOARD_H

#include "action.h"
#include "action_layer.h"
#include "charybdis.h"
#include "keymap_nordic.h"
#include "modifiers.h"
#include "report.h"
#include "timer.h"

static bool     pointing_device_enabled       = false;
static bool     force_pointing_device_enabled = false;
static uint16_t last_key_release_time         = 0;
static uint8_t  keys_pressed_down             = 0;

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOL,
    LAYER_MISC,
    LAYER_POINTER,
};

#define ASTR LSFT(NO_APOS)
#define BSLSH ALGR(NO_PLUS)

#define GUIESC LGUI_T(KC_ESC)
#define MISC OSL(LAYER_MISC)
#define POINTAE LT(LAYER_POINTER, NO_AE)
#define SFTAPOS MT(MOD_RSFT, NO_APOS)
#define SYMBENT LT(LAYER_SYMBOL, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, NO_PLUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   NO_AM,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_BSPC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, POINTAE, NO_OSLH,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, NO_MINS, SFTAPOS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   GUIESC,  KC_SPC,    MISC,    KC_ALGR, SYMBENT,
                                           KC_LCTL, KC_LALT,    KC_DEL
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, KC_EXLM, NO_QUO2, KC_HASH,  NO_DLR, KC_PERC,    NO_AMPR, NO_SLSH, NO_LPRN, NO_RPRN,  NO_EQL, NO_QUES,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, NO_LPRN, NO_RPRN,   NO_AT, NO_APOS,  NO_GRV,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, NO_TILD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, NO_LCBR, NO_RCBR, NO_AMPR, XXXXXXX,  NO_EQL,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, NO_CIRC,    ASTR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, NO_LBRC, NO_RBRC, NO_PIPE, NO_LESS, NO_GRTR,    NO_SLSH,   BSLSH, NO_SCLN, NO_COLN, NO_UNDS, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MISC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    KC_ALGR, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, KC_BTN3, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, KC_BTN1, DRGSCRL, KC_BTN2, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  )};
// clang-format on

// Force enable pointer device for pointer layer and enable sniping.
layer_state_t layer_state_set_user(layer_state_t state) {
    force_pointing_device_enabled = false;
    if (get_highest_layer(state) == LAYER_POINTER) {
        force_pointing_device_enabled = true;
        keys_pressed_down             = 0;
        last_key_release_time         = 0;
    }
    return state;
}

// Clear mouse report when the pointer device is disabled.
report_mouse_t pointing_device_task_user(report_mouse_t report) {
    if (force_pointing_device_enabled) {
        return report;
    }
    if (!pointing_device_enabled) {
        report = (report_mouse_t){0};
    }
    return report;
}

// Check timer on each matrix scan.
void matrix_scan_user(void) {
    pointing_device_enabled = keys_pressed_down == 0 && timer_elapsed(last_key_release_time) > POINTING_DEVICE_TIMEOUT;
}

// Track key presses and releases.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_mods() & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) {
        return true;
    }
    switch (keycode) {
        case KC_1 ... KC_0: // Numeric keys.
        case KC_A ... KC_Z: // Alphabet keys.
        case NO_AE:         // Special key Å.
        case NO_AM:         // Special key Ö.
        case NO_OSLH:       // Special key Ä.
            if (record->event.pressed) {
                keys_pressed_down++;
            } else {
                if (keys_pressed_down > 0) {
                    keys_pressed_down--;
                }
                last_key_release_time = timer_read();
            }
            break;
        default:
            break;
    }
    return true;
}
