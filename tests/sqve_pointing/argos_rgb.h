#pragma once

#include "../../modules/bastardkb/argos/argos.h"

void argos_rgb_get_led_at_position(argos_rgb_t *entry, uint8_t layer, uint8_t index, uint8_t offset);
void argos_rgb_handle_set_led_at_position(uint16_t index, uint8_t red, uint8_t green, uint8_t blue, bool passthrough, bool on, bool custom);
