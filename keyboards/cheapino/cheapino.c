#include "wait.h"
#include "quantum.h"

// This is to keep state between callbacks, when it is 0 the
// initial RGB flash is finished
<<<<<<< HEAD
static uint8_t hue_countdown = 50;
=======
uint8_t _hue_countdown = 50;
>>>>>>> tompi/cheapinov2

// These are to keep track of user selected color, so we
// can restore it after RGB flash
uint8_t _hue;
uint8_t _saturation;
uint8_t _value;

// Do a little 2.5 seconds display of the different colors
// Use the deferred executor so the LED flash dance does not
// stop us from using the keyboard.
// https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-executor-registration
uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
<<<<<<< HEAD
    rgblight_sethsv(hue_countdown * 5, 230, 70);
    hue_countdown--;
    if (hue_countdown == 0) {
=======
    rgblight_sethsv(_hue_countdown * 5, 230, 70);
    _hue_countdown--;
    if (_hue_countdown == 0) {
>>>>>>> tompi/cheapinov2
        // Finished, reset to user chosen led color
        rgblight_sethsv(_hue, _saturation, _value);
        return 0;
    } else {
        return 50;
    }
}

void keyboard_post_init_user(void) {
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

    // Store user selected rgb hsv:
    _hue = rgblight_get_hue();
    _saturation = rgblight_get_sat();
<<<<<<< HEAD
    //_value = rgblight_get_val();
    _value = 15; // set intentionally low because it is a bright little light
=======
    _value = rgblight_get_val();
>>>>>>> tompi/cheapinov2

    // Flash a little on start
    defer_exec(50, flash_led, NULL);
}

// Make the builtin RGB led show different colors per layer:
<<<<<<< HEAD
// Kanagawa color palette
// L_BASE (0): Wave Blue
// L_NAV (1): Spring Green
// L_NUM (2): Autumn Yellow
// L_MOUSE (3): Sakura Pink
// L_FUN (4): Winter Purple
uint8_t get_hue(uint8_t layer) {
    switch (layer) {
        case 4:  // L_FUN - Winter Purple
            return 135;  // ~270° in 0-255 scale
        case 3:  // L_MOUSE - Sakura Pink
            return 220;  // ~330° in 0-255 scale
        case 2:  // L_NUM - Autumn Yellow
            return 27;   // ~40° in 0-255 scale
        case 1:  // L_NAV - Spring Green
            return 80;   // ~120° in 0-255 scale
        default: // L_BASE - Wave Blue
            return 133;  // ~200° in 0-255 scale
=======
// This seemed like a good idea but turned out pretty annoying,
// to me at least... Uncomment the lines below to enable
/*
uint8_t get_hue(uint8_t layer) {
    switch (layer) {
        case 6:
            return 169;
        case 5:
            return 43;
        case 4:
            return 85;
        case 3:
            return 120;
        case 2:
            return 180;
        case 1:
            return 220;
        default:
            return 0;
>>>>>>> tompi/cheapinov2
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
<<<<<<< HEAD
    // Ignore layer color changes while the startup animation runs
    if (hue_countdown > 0) {
        return state;
    }

=======
>>>>>>> tompi/cheapinov2
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();
    uint8_t hue = get_hue(get_highest_layer(state));
    rgblight_sethsv(hue, sat, val);
    return state;
}
<<<<<<< HEAD
=======
*/
>>>>>>> tompi/cheapinov2
