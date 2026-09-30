#include "argos_rgb.h"

static argos_rgb_t layer_colors[4][RGBLIGHT_LED_COUNT];

void sqve_test_reset_layer_colors(void) {
    for (uint8_t layer = 0; layer < 4; layer++) {
        for (uint8_t index = 0; index < RGBLIGHT_LED_COUNT; index++) {
            layer_colors[layer][index] = (argos_rgb_t){255, 0, 0, false, true, true};
        }
    }
}

bool sqve_test_layer_has_color_overrides(uint8_t layer) {
    for (uint8_t index = 0; index < RGBLIGHT_LED_COUNT; index++) {
        if (layer_colors[layer][index].custom) {
            return true;
        }
    }

    return false;
}

void argos_rgb_get_led_at_position(argos_rgb_t *entry, uint8_t layer, uint8_t index, uint8_t offset) {
    *entry = layer_colors[layer][index + offset];
}

void argos_rgb_handle_set_led_at_position(uint16_t index, uint8_t red, uint8_t green, uint8_t blue, bool passthrough, bool on, bool custom) {
    uint8_t layer = index / RGBLIGHT_LED_COUNT;
    uint8_t position = index % RGBLIGHT_LED_COUNT;

    layer_colors[layer][position] = (argos_rgb_t){red, green, blue, passthrough, on, custom};
}
