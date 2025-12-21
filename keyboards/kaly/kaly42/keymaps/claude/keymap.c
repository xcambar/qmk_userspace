// Copyright 2025 Xavier (@xavier)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    BASE,     // QWERTY base layer
    GALLIUM,  // Gallium alternative layout
    CODE,     // Programming symbols and brackets
    NAV,      // Navigation and function keys
    NUM       // Numbers and special functions
};

// Custom keycodes
enum custom_keycodes {
    TOGGLE_LAYOUT = SAFE_RANGE,
};

// Combo definitions
const uint16_t PROGMEM boot_combo[] = {KC_TAB, KC_QUOT, COMBO_END};  // Tab + ' → Bootloader
const uint16_t PROGMEM toggle_layout_combo[] = {KC_ESC, KC_LSFT, KC_BSPC, KC_RSFT, COMBO_END};  // Esc + LSft + Bsp + RSft → Toggle QWERTY/Gallium

combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
    COMBO(toggle_layout_combo, TOGGLE_LAYOUT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer (QWERTY)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │ Esc │  Q  │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │ Bsp │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │ Tab │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  ;  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │ Sft │  Z  │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │ Sft │
     * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
     *                     ┌─────┐                           ┌─────┐
     *                     │ Ctl ├─────┐               ┌─────┤ Alt │
     *                     └─────┤ Spc ├─────┐   ┌─────┤ Spc ├─────┘
     *                           └─────┤CODE │   │ NAV ├─────┘
     *                                 └─────┘   └─────┘
     */
    [BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LCTL, KC_SPC,  MO(CODE),     MO(NAV), KC_SPC,  KC_RALT
    ),

    /*
     * Gallium Layer - Alternative layout optimized for typing
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │ Esc │  B  │  L  │  D  │  C  │  V  │       │  J  │  Y  │  O  │  U  │  ,  │ Bsp │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │ Tab │  N  │  R  │  T  │  S  │  G  │       │  P  │  H  │  A  │  E  │  I  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │ Sft │  Z  │  X  │  M  │  W  │  Q  │       │  K  │  F  │  ;  │  .  │  /  │ Sft │
     * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
     *                     ┌─────┐                           ┌─────┐
     *                     │ Ctl ├─────┐               ┌─────┤ Alt │
     *                     └─────┤ Spc ├─────┐   ┌─────┤ Spc ├─────┘
     *                           └─────┤CODE │   │ NAV ├─────┘
     *                                 └─────┘   └─────┘
     */
    [GALLIUM] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_B,    KC_L,    KC_D,    KC_C,    KC_V,         KC_J,    KC_Y,    KC_O,    KC_U,    KC_COMM, KC_BSPC,
        KC_TAB,  KC_N,    KC_R,    KC_T,    KC_S,    KC_G,         KC_P,    KC_H,    KC_A,    KC_E,    KC_I,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_W,    KC_Q,         KC_K,    KC_F,    KC_SCLN, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LCTL, KC_SPC,  MO(CODE),     MO(NAV), KC_SPC,  KC_RALT
    ),

    /*
     * CODE Layer - Programming Symbols
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │  `  │  !  │  @  │  #  │  $  │  %  │       │  ^  │  &  │  *  │  (  │  )  │ Del │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  {  │  }  │  [  │  ]  │  |  │       │  -  │  =  │  _  │  +  │  :  │  "  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  <  │  >  │  (  │  )  │  \  │       │     │     │  ,  │  .  │  ?  │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
     *                     ┌─────┐                           ┌─────┐
     *                     │     ├─────┐               ┌─────┤     │
     *                     └─────┤     ├─────┐   ┌─────┤ Ent ├─────┘
     *                           └─────┤ /// │   │ NUM ├─────┘
     *                                 └─────┘   └─────┘
     */
    [CODE] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,      KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO,
        _______, KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_BSLS,      XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_QUES, _______,
                                   _______, _______, _______,      MO(NUM), KC_ENT,  _______
    ),

    /*
     * NAV Layer - Navigation and Function Keys
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │       │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │       │ Left│ Down│ Up  │Right│     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │       │ Home│PgDn │PgUp │ End │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
     *                     ┌─────┐                           ┌─────┐
     *                     │     ├─────┐               ┌─────┤     │
     *                     └─────┤ NUM ├─────┐   ┌─────┤ /// ├─────┘
     *                           └─────┤     │   │     ├─────┘
     *                                 └─────┘   └─────┘
     */
    [NAV] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
                                   _______, MO(NUM), _______,      _______, _______, _______
    ),

    /*
     * NUM Layer - Numbers and Special Functions
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │     │       │  *  │  7  │  8  │  9  │  0  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │       │  +  │  4  │  5  │  6  │  -  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │       │  0  │  1  │  2  │  3  │  /  │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
     *                     ┌─────┐                           ┌─────┐
     *                     │     ├─────┐               ┌─────┤     │
     *                     └─────┤ /// ├─────┐   ┌─────┤ /// ├─────┘
     *                           └─────┤     │   │  .  ├─────┘
     *                                 └─────┘   └─────┘
     */
    [NUM] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_ASTR, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                                   _______, _______, _______,      KC_DOT,  _______, _______
    )
};

// Custom keycode handler
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOGGLE_LAYOUT:
            if (record->event.pressed) {
                // Toggle between BASE and GALLIUM
                if (get_highest_layer(default_layer_state) == BASE) {
                    default_layer_set(1UL << GALLIUM);
                } else {
                    default_layer_set(1UL << BASE);
                }
            }
            return false;
    }
    return true;
}
