/**
 * Minimal debug keymap for LED index testing (Charybdis).
 * - Hold LOWER layer and press number keys to enter LED index (0–57).
 * - Only that LED will light up (white), all others off.
 */

#include QMK_KEYBOARD_H

// ------------------------------------------------------------
// Layers
// ------------------------------------------------------------
enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

// ------------------------------------------------------------
// Custom Keycodes
// ------------------------------------------------------------
enum custom_keycodes {
    // Old macro keycodes (left here so keymap compiles, but unused)
    MACRO_0 = SAFE_RANGE,
    MACRO_1,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MACRO_6,
    MACRO_7,
    MACRO_8,
    MACRO_9,
    MACRO_10,
    MACRO_11,
    MACRO_12,
    MACRO_13,
    MACRO_14,
    MACRO_15,

    // LED debug input keycodes (used on LOWER layer number row)
    LED_ID_0,
    LED_ID_1,
    LED_ID_2,
    LED_ID_3,
    LED_ID_4,
    LED_ID_5,
    LED_ID_6,
    LED_ID_7,
    LED_ID_8,
    LED_ID_9,
    LED_CLEAR,
};

// ------------------------------------------------------------
// Keymaps
// (unchanged layout, just modified LOWER top row for LED input)
// ------------------------------------------------------------

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
                   KC_ESC,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                 KC_6,              KC_7,              KC_8,              KC_9,              KC_0,           KC_MINS,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                   KC_TAB,              KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                 KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,           KC_BSLS,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
         MT(MOD_LSFT,KC_CAPS),             KC_A,             KC_S,             KC_D,       LT(2,KC_F),              KC_G,                 KC_H,        LT(1,KC_J),              KC_K,              KC_L,           KC_SCLN,           KC_QUOT,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                  KC_LCTL,        LT(1,KC_Z),              KC_X,              KC_C,              KC_V,              KC_B,                 KC_N,              KC_M,           KC_COMM,            KC_DOT,     LT(2,KC_SLSH),           KC_LALT,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                           KC_LGUI,            KC_SPC,        KC_MS_BTN8,             MO(2),            KC_ENT,
                                                                                                MO(1),           KC_BSPC,           KC_BSPC
  //                                                                    ╰────────────────────────────────────────────────╯ ╰────────────────────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
                  RGB_TOG,          LED_ID_1,          LED_ID_2,          LED_ID_3,          LED_ID_4,          LED_ID_5,             LED_ID_6,          LED_ID_7,          LED_ID_8,          LED_ID_9,          LED_ID_0,         LED_CLEAR,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                  XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,           XXXXXXX,           KC_LPRN,           KC_RPRN,           KC_QUOT,           KC_PPLS,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
         MT(MOD_LSFT,KC_CAPS),          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,           XXXXXXX,              XXXXXXX,           XXXXXXX,           KC_LBRC,           KC_RBRC,        S(KC_QUOT),           KC_PEQL,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                 MACRO_5,           MACRO_3,           MACRO_4,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,           XXXXXXX,        S(KC_LBRC),        S(KC_RBRC),           XXXXXXX,           XXXXXXX,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                           KC_LGUI,            KC_SPC,        KC_MS_BTN8,           KC_VOLD,           KC_VOLU,
                                                                                                MO(1),           KC_BSPC,           KC_BSPC
  //                                                                    ╰────────────────────────────────────────────────╯ ╰────────────────────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
                  RGB_TOG,           XXXXXXX,           DPI_MOD,          DPI_RMOD,           S_D_MOD,          S_D_RMOD,              KC_MPLY,           KC_MNXT,           KC_MPRV,           KC_MUTE,           KC_VOLD,           KC_VOLU,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                  XXXXXXX,           G(KC_Q),           XXXXXXX,           G(KC_A),           XXXXXXX,           XXXXXXX,              MACRO_2,           G(KC_C),             KC_UP,           G(KC_V),           KC_BRID,           KC_BRIU,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
         MT(MOD_LSFT,KC_CAPS),          KC_LGUI,          KC_LALT,          G(KC_C),            MO(2),           XXXXXXX,              MACRO_1,           KC_LEFT,           KC_DOWN,           KC_RGHT,        KC_MS_BTN3,           XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                  KC_LCTL,           G(KC_Z),           G(KC_X),           G(KC_V),           XXXXXXX,           XXXXXXX,              MACRO_0,        KC_MS_BTN1,        KC_MS_BTN2,        KC_MS_BTN8,           XXXXXXX,           KC_RALT,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                           KC_LGUI,            KC_SPC,        KC_MS_BTN8,           KC_LALT,            KC_ENT,
                                                                                                MO(1),           KC_BSPC,           KC_BSPC
  //                                                                    ╰────────────────────────────────────────────────╯ ╰────────────────────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
                  XXXXXXX,           XXXXXXX,           DPI_MOD,          DPI_RMOD,           S_D_MOD,          S_D_RMOD,              XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                  XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
         MT(MOD_LSFT,KC_CAPS),          XXXXXXX,          XXXXXXX,          XXXXXXX,          _______,           XXXXXXX,              XXXXXXX,           XXXXXXX,        KC_MS_BTN3,           XXXXXXX,        KC_MS_BTN3,           XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                  XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              SNP_TOG,        KC_MS_BTN1,        KC_MS_BTN2,        KC_MS_BTN8,           _______,           KC_RALT,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                           KC_LGUI,           XXXXXXX,        KC_MS_BTN8,           KC_LALT,            KC_ENT,
                                                                                              XXXXXXX,           XXXXXXX,           KC_BSPC
  //                                                                    ╰────────────────────────────────────────────────╯ ╰────────────────────────────────────────────────╯
  ),
};
// clang-format on

// ------------------------------------------------------------
// Pointing Device safe defaults (so DPI_MOD etc. compile even
// if POINTING_DEVICE_ENABLE is off)
// ------------------------------------------------------------
#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#    define SNP_TOG KC_NO
#endif

// ------------------------------------------------------------
// LED Debug State + Helper
// ------------------------------------------------------------
#ifdef RGB_MATRIX_ENABLE
static bool    led_debug_mode  = false;
static int16_t led_input_value = -1; // -1 = no active input
static uint8_t debug_led_index = 0;

static void led_input_add_digit(uint8_t digit) {
    if (led_input_value < 0) {
        led_input_value = digit;
    } else {
        int16_t new_val = led_input_value * 10 + digit;
        if (new_val < RGB_MATRIX_LED_COUNT) {
            led_input_value = new_val;
        } else {
            // If overflow (> max LED), restart from this digit
            led_input_value = digit;
        }
    }

    if (led_input_value >= 0 && led_input_value < RGB_MATRIX_LED_COUNT) {
        debug_led_index = (uint8_t)led_input_value;
        led_debug_mode  = true;
    }
}
#endif

// ------------------------------------------------------------
// process_record_user: handle LED_ID_* + LED_CLEAR
// ------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case LED_ID_0:
        case LED_ID_1:
        case LED_ID_2:
        case LED_ID_3:
        case LED_ID_4:
        case LED_ID_5:
        case LED_ID_6:
        case LED_ID_7:
        case LED_ID_8:
        case LED_ID_9:
#ifdef RGB_MATRIX_ENABLE
        {
            uint8_t digit = 0;
            switch (keycode) {
                case LED_ID_0:
                    digit = 0;
                    break;
                case LED_ID_1:
                    digit = 1;
                    break;
                case LED_ID_2:
                    digit = 2;
                    break;
                case LED_ID_3:
                    digit = 3;
                    break;
                case LED_ID_4:
                    digit = 4;
                    break;
                case LED_ID_5:
                    digit = 5;
                    break;
                case LED_ID_6:
                    digit = 6;
                    break;
                case LED_ID_7:
                    digit = 7;
                    break;
                case LED_ID_8:
                    digit = 8;
                    break;
                case LED_ID_9:
                    digit = 9;
                    break;
            }
            led_input_add_digit(digit);
        }
#endif
            return false;

        case LED_CLEAR:
#ifdef RGB_MATRIX_ENABLE
            led_input_value = -1;
            led_debug_mode  = false;
#endif
            return false;
    }

    return true;
}

// ------------------------------------------------------------
// RGB Matrix: one-LED debug override
// ------------------------------------------------------------
#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // If we're in LED debug mode: show exactly one LED and override everything.
    if (led_debug_mode) {
        // Turn all LEDs off
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }

        // Light just the chosen LED
        if (debug_led_index < RGB_MATRIX_LED_COUNT) {
            rgb_matrix_set_color(debug_led_index, 255, 255, 255); // bright white
        }

        return true; // we handled all LEDs
    }

    // Not in debug mode → let normal effects run
    return false;
}
#endif