POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
MOUSEKEY_ENABLE = no

VPATH += modules/bastardkb/bk_pointing_device modules/bastardkb/argos quantum/split_common
OPT_DEFS += -DQMK_KEYBOARD_H=\"quantum.h\"
SRC += modules/bastardkb/bk_pointing_device/bk_pointing_device.c
SRC += modules/bastardkb/bk_pointing_device/bk_pointing_modes.c
SRC += tests/sqve_pointing/rgb_test_support.c
