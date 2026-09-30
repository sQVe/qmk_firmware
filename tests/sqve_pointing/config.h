#pragma once

#include "test_common.h"
#include "../../keyboards/bastardkb/charybdis/4x6/keymaps/sqve/config.h"

#undef NKRO_ENABLE

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define COMMUNITY_MODULE_ARGOS_ENABLE
#define BK_HAS_POINTING_DEVICE 1
#define ARGOS_OFFSET_POINTER_CONFIG 0
#define RGB_MATRIX_LED_COUNT 58
#define ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(major, minor, patch)
