#include "matrix.h"
#include "quantum.h"

#define COL_SHIFTER ((uint16_t)1)

#define ENC_ROW 3
#define ENC_A_COL 2
#define ENC_B_COL 4
#define ENC_BUTTON_COL 0

static bool colABPressed   = false;
static bool encoderPressed = false;

void clicked(void) {
    tap_code(KC_MPLY);
}

void turned(bool clockwise) {
    // L_FUN (4): Volume control
    if (IS_LAYER_ON(4)) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    }
    // L_MOUSE (3): Scroll up/down
    else if (IS_LAYER_ON(3)) {
        tap_code(clockwise ? KC_WH_U : KC_WH_D);
    }
    // L_NUM (2): Brightness control
    else if (IS_LAYER_ON(2)) {
        tap_code(clockwise ? KC_BRIU : KC_BRID);
    }
    // L_NAV (1): Tab switching
    else if (IS_LAYER_ON(1)) {
        tap_code16(clockwise ? LCTL(KC_TAB) : LCTL(LSFT(KC_TAB)));
    }
    // L_BASE (0): Volume control (default)
    else {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    }
}

void fix_encoder_action(matrix_row_t current_matrix[]) {
    matrix_row_t encoder_row = current_matrix[ENC_ROW];

    if (encoder_row & (COL_SHIFTER << ENC_BUTTON_COL)) {
        encoderPressed = true;
    } else {
        // Only trigger click on release
        if (encoderPressed) {
            encoderPressed = false;
            clicked();
        }
    }

    // Check which way the encoder is turned:
    bool colA = encoder_row & (COL_SHIFTER << ENC_A_COL);
    bool colB = encoder_row & (COL_SHIFTER << ENC_B_COL);

    if (colA && colB) {
        colABPressed = true;
    } else if (colA) {
        if (colABPressed) {
            // A+B followed by A means clockwise
            colABPressed = false;
            turned(true);
        }
    } else if (colB) {
        if (colABPressed) {
            // A+B followed by B means counter-clockwise
            colABPressed = false;
            turned(false);
        }
    }
    current_matrix[ENC_ROW] = 0;
}
