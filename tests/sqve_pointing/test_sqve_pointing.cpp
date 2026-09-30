#include "gtest/gtest.h"
#include "test_common.hpp"
#include "test_pointing_device_driver.h"
#include <cstring>

using testing::_;

extern "C" {
#include "bk_pointing_device.h"
#include "introspection.h"
#include "eeconfig.h"

static uint8_t saved_pointer_config[sizeof(bkpd_config_t)];
static uint16_t sensor_resolution;
static uint16_t saved_misc_keycode;
static uint8_t saved_misc_layer;
static uint8_t saved_misc_row;
static uint8_t saved_misc_column;

uint16_t dynamic_keymap_get_keycode(uint8_t layer, uint8_t row, uint8_t column) {
    return saved_misc_keycode;
}

void dynamic_keymap_set_keycode(uint8_t layer, uint8_t row, uint8_t column, uint16_t keycode) {
    saved_misc_keycode = keycode;
    saved_misc_layer = layer;
    saved_misc_row = row;
    saved_misc_column = column;
}

uint16_t pointing_device_driver_get_cpi(void) {
    return sensor_resolution;
}

void pointing_device_driver_set_cpi(uint16_t resolution) {
    sensor_resolution = resolution;
}

void argos_read_eeprom(uint16_t offset, void *buffer, uint16_t size) {
    memcpy(buffer, saved_pointer_config, size);
}

void argos_write_eeprom(uint16_t offset, const void *buffer, uint16_t size) {
    memcpy(saved_pointer_config, buffer, size);
}

void argos_keycode_down(uint16_t keycode) {
    register_code16(keycode);
}

void argos_keycode_up(uint16_t keycode) {
    unregister_code16(keycode);
}

void argos_keycode_tap(uint16_t keycode) {
    tap_code16(keycode);
}

void keyboard_post_init_bk_pointing_device(void);
bool process_record_bk_pointing_device(uint16_t keycode, keyrecord_t *record);
layer_state_t layer_state_set_bk_pointing_device(layer_state_t state);
report_mouse_t pointing_device_task_bk_pointing_device(report_mouse_t report);
void post_process_record_user(uint16_t keycode, keyrecord_t *record);
uint16_t sqve_test_misc_keycode(void);
void sqve_test_reset_layer_colors(void);
bool sqve_test_layer_has_color_overrides(uint8_t layer);

void keyboard_post_init_modules(void) {
    keyboard_post_init_bk_pointing_device();
}

bool process_record_modules(uint16_t keycode, keyrecord_t *record) {
    return process_record_bk_pointing_device(keycode, record);
}

layer_state_t layer_state_set_modules(layer_state_t state) {
    return layer_state_set_bk_pointing_device(state);
}

report_mouse_t pointing_device_task_modules(report_mouse_t report) {
    return pointing_device_task_bk_pointing_device(report);
}
}

static report_mouse_t pointer_movement(void) {
    report_mouse_t report = {};
    report.x = 10;
    report.y = 15;

    return report;
}

class SqvePointing : public TestFixture {
   protected:
    void SetUp() override {
        pd_clear_movement();
        pd_clear_all_buttons();
        clear_mods();
        layer_on(3);
        layer_clear();
        memset(saved_pointer_config, 0, sizeof(saved_pointer_config));
        eeconfig_update_user(0);
        sqve_test_reset_layer_colors();
        saved_misc_keycode = OSL(2);
        keyboard_post_init_bk_pointing_device();
        keyboard_post_init_user();
    }
};

TEST_F(SqvePointing, TappingMiscSendsSpaceWithoutChangingLayer) {
    TestDriver driver;
    testing::InSequence sequence;
    uint16_t misc_keycode = sqve_test_misc_keycode();
    auto misc = KeymapKey(0, 0, 0, misc_keycode);
    set_keymap({misc});

    EXPECT_REPORT(driver, (KC_SPC));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(misc, 20);

    EXPECT_EQ(get_highest_layer(layer_state), 0);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(SqvePointing, HoldingMiscEnablesLayerOnlyUntilRelease) {
    TestDriver driver;
    uint16_t misc_keycode = sqve_test_misc_keycode();
    auto misc = KeymapKey(0, 0, 0, misc_keycode);
    auto misc_on_layer = KeymapKey(2, 0, 0, KC_TRNS);
    set_keymap({misc, misc_on_layer});

    EXPECT_NO_REPORT(driver);
    misc.press();
    idle_for(TAPPING_TERM + 1);

    EXPECT_EQ(get_highest_layer(layer_state), 2);

    misc.release();
    run_one_scan_loop();

    EXPECT_EQ(get_highest_layer(layer_state), 0);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(SqvePointing, UpdatesSavedMiscKeyWithoutResettingPointerSettings) {
    saved_misc_keycode = OSL(2);
    bkpd_mode_change_dpi(MODE_NORMAL, 600);
    keyboard_post_init_user();

    EXPECT_EQ(saved_misc_keycode, LT(2, KC_SPC));
    EXPECT_EQ(saved_misc_layer, 0);
    EXPECT_EQ(saved_misc_row, 4);
    EXPECT_EQ(saved_misc_column, 1);
    EXPECT_EQ(bkpd_mode_get_dpi(MODE_NORMAL), 600);
}

TEST_F(SqvePointing, RemovesLayerColorOverridesWithoutChangingBaseColors) {
    EXPECT_TRUE(sqve_test_layer_has_color_overrides(0));
    EXPECT_FALSE(sqve_test_layer_has_color_overrides(1));
    EXPECT_FALSE(sqve_test_layer_has_color_overrides(2));
    EXPECT_FALSE(sqve_test_layer_has_color_overrides(3));
}

TEST_F(SqvePointing, RemovesLayerColorOverridesWhenPointerSettingsAlreadyExist) {
    sqve_test_reset_layer_colors();
    bkpd_mode_change_dpi(MODE_NORMAL, 600);
    keyboard_post_init_user();

    EXPECT_FALSE(sqve_test_layer_has_color_overrides(2));
    EXPECT_EQ(bkpd_mode_get_dpi(MODE_NORMAL), 600);
}

TEST_F(SqvePointing, InitializesNormalPointerAt400Dpi) {
    EXPECT_EQ(bkpd_mode_get_dpi(MODE_NORMAL), 400);
    EXPECT_EQ(pointing_device_get_cpi(), 400);
}

TEST_F(SqvePointing, PreservesPointerSettingsAfterReconnect) {
    bkpd_mode_change_dpi(MODE_NORMAL, 600);
    keyboard_post_init_bk_pointing_device();
    keyboard_post_init_user();

    EXPECT_EQ(bkpd_mode_get_dpi(MODE_NORMAL), 600);
    EXPECT_TRUE(bkpd_mode_get_invert(MODE_DRAGSCROLL, 1));
}

TEST_F(SqvePointing, KeepsAutomaticMouseLayerAndPrecisionDisabled) {
    EXPECT_FALSE(get_auto_mouse_enable());
    EXPECT_FALSE(bkpd_get_auto_precision_on_mouse_layer_enabled());
}

TEST_F(SqvePointing, HoldingScrollConvertsMovementAndReleasingRestoresPointer) {
    layer_on(3);
    keyrecord_t record = {};
    record.event.pressed = true;
    process_record_modules(DRGSCRL, &record);
    report_mouse_t movement = {};
    movement.y = 31;

    report_mouse_t scroll = pointing_device_task_modules(movement);

    EXPECT_EQ(bkpd_mode_get_active_id(), MODE_DRAGSCROLL);
    EXPECT_EQ(pointing_device_get_cpi(), 500);
    EXPECT_EQ(scroll.y, 0);
    EXPECT_EQ(scroll.v, -1);

    record.event.pressed = false;
    process_record_modules(DRGSCRL, &record);
    report_mouse_t pointer = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(bkpd_mode_get_active_id(), MODE_NORMAL);
    EXPECT_EQ(pointing_device_get_cpi(), 400);
    EXPECT_EQ(pointer.x, 10);
    EXPECT_EQ(pointer.y, 15);
}

TEST_F(SqvePointing, KeepsHeldScrollActiveAcrossLayerChanges) {
    TestDriver driver;
    auto scroll_key = KeymapKey(3, 0, 0, DRGSCRL);
    set_keymap({scroll_key});
    layer_on(3);

    EXPECT_NO_REPORT(driver);
    scroll_key.press();
    run_one_scan_loop();
    layer_on(2);
    report_mouse_t movement = {};
    movement.y = 31;
    report_mouse_t scroll = pointing_device_task_modules(movement);

    EXPECT_EQ(bkpd_mode_get_active_id(), MODE_DRAGSCROLL);
    EXPECT_EQ(pointing_device_get_cpi(), 500);
    EXPECT_EQ(scroll.y, 0);
    EXPECT_EQ(scroll.v, -1);

    layer_off(2);

    EXPECT_EQ(bkpd_mode_get_active_id(), MODE_DRAGSCROLL);
    EXPECT_EQ(pointing_device_get_cpi(), 500);

    scroll_key.release();
    run_one_scan_loop();
    layer_on(2);
    report_mouse_t pointer = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(bkpd_mode_get_active_id(), MODE_NORMAL);
    EXPECT_EQ(pointing_device_get_cpi(), 400);
    EXPECT_EQ(pointer.x, 10);
    EXPECT_EQ(pointer.y, 15);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(SqvePointing, PointerLayerAllowsMovementWhileTyping) {
    keyrecord_t record = {};
    record.event.pressed = true;
    process_record_modules(KC_A, &record);
    process_record_kb(KC_A, &record);
    post_process_record_user(KC_A, &record);
    matrix_scan_user();

    layer_on(3);
    report_mouse_t report = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(report.x, 10);
    EXPECT_EQ(report.y, 15);
}

TEST_F(SqvePointing, ReleasesTypingBlockWhenKeyIsReleasedWithControlHeld) {
    TestDriver driver;
    testing::InSequence sequence;
    auto letter = KeymapKey(0, 0, 0, KC_A);
    auto control = KeymapKey(0, 1, 0, KC_LCTL);
    set_keymap({letter, control});

    EXPECT_REPORT(driver, (KC_A));
    EXPECT_REPORT(driver, (KC_LCTL, KC_A));
    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_EMPTY_REPORT(driver);
    letter.press();
    run_one_scan_loop();
    control.press();
    run_one_scan_loop();
    letter.release();
    run_one_scan_loop();
    control.release();
    run_one_scan_loop();
    wait_ms(401);
    matrix_scan_user();
    report_mouse_t resumed = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(resumed.x, 10);
    EXPECT_EQ(resumed.y, 15);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(SqvePointing, ShortcutReleaseDoesNotClearAnotherKeysTypingBlock) {
    TestDriver driver;
    testing::InSequence sequence;
    auto shortcut_letter = KeymapKey(0, 0, 0, KC_A);
    auto typing_letter = KeymapKey(0, 1, 0, KC_B);
    auto control = KeymapKey(0, 2, 0, KC_LCTL);
    set_keymap({shortcut_letter, typing_letter, control});

    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_REPORT(driver, (KC_LCTL, KC_A));
    EXPECT_REPORT(driver, (KC_A));
    EXPECT_REPORT(driver, (KC_A, KC_B));
    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    control.press();
    run_one_scan_loop();
    shortcut_letter.press();
    run_one_scan_loop();
    control.release();
    run_one_scan_loop();
    typing_letter.press();
    run_one_scan_loop();
    shortcut_letter.release();
    run_one_scan_loop();
    wait_ms(401);
    matrix_scan_user();
    report_mouse_t held = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(held.x, 0);
    EXPECT_EQ(held.y, 0);

    typing_letter.release();
    run_one_scan_loop();
    wait_ms(401);
    matrix_scan_user();
    report_mouse_t resumed = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(resumed.x, 10);
    EXPECT_EQ(resumed.y, 15);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(SqvePointing, BlocksPointerUntil400MillisecondsAfterTyping) {
    keyrecord_t record = {};
    record.event.pressed = true;
    process_record_modules(KC_A, &record);
    process_record_kb(KC_A, &record);
    post_process_record_user(KC_A, &record);
    matrix_scan_user();
    report_mouse_t held = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(held.x, 0);
    EXPECT_EQ(held.y, 0);

    record.event.pressed = false;
    process_record_modules(KC_A, &record);
    process_record_kb(KC_A, &record);
    post_process_record_user(KC_A, &record);
    wait_ms(400);
    matrix_scan_user();
    report_mouse_t delayed = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(delayed.x, 0);
    EXPECT_EQ(delayed.y, 0);

    wait_ms(1);
    matrix_scan_user();
    report_mouse_t resumed = pointing_device_task_modules(pointer_movement());

    EXPECT_EQ(resumed.x, 10);
    EXPECT_EQ(resumed.y, 15);
}
