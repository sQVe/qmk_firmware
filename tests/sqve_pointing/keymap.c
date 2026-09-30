#include "quantum.h"
#include "introspection.h"

#define LAYOUT(...) {{KC_NO}}
#include "../../keyboards/bastardkb/charybdis/4x6/keymaps/sqve/keymap.c"

uint16_t sqve_test_misc_keycode(void) {
    return MISC;
}
