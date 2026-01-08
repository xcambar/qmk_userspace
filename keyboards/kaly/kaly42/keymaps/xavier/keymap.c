// Copyright 2023 Kael Soares Augusto (@Dwctor)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
 * Keyboard Layout - Abstract Key Positions (_XX_)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ _00_│ _01_│ _02_│ _03_│ _04_│ _05_│       │ _06_│ _07_│ _08_│ _09_│ _10_│ _11_│
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ _12_│ _13_│ _14_│ _15_│ _16_│ _17_│       │ _18_│ _19_│ _20_│ _21_│ _22_│ _23_│
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ _24_│ _25_│ _26_│ _27_│ _28_│ _29_│       │ _30_│ _31_│ _32_│ _33_│ _34_│ _35_│
 * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
 *                     ┌─────┐                           ┌─────┐
 *                     │ _36_├─────┐               ┌─────┤ _41_│
 *                     └─────┤ _37_├─────┐   ┌─────┤ _40_├─────┘
 *                           └─────┤ _38_│   │ _39_├─────┘
 *                                 └─────┘   └─────┘
 *
 * Home row mods (when XC_HRM is enabled):
 *   Left hand:  _14_=Alt  _15_=Ctrl  _16_=Shift  _28_=GUI
 *   Right hand: _19_=Shift  _20_=Ctrl  _21_=Alt  _31_=GUI
 */

#include "keymap_eurkey.h"
#include QMK_KEYBOARD_H

// Base layer switch
#include "feature_base_layer.h"

// Weak corners feature
#include "feature_weak_corners.h"

enum layers {
    BASE = 0,
    HRM,
    NAV,
    SYMBOLS
};

enum custom_keycodes {
    SFT_LEAD = SAFE_RANGE,  // Shift on hold, Leader on tap
};

const uint16_t PROGMEM boot_combo[] = {_12_, _23_, COMBO_END};  // Tab + Quote

combo_t key_combos[] = {
    XC_WEAK_CORNERS_COMBOS
    COMBO(boot_combo, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │[Q]│ W[Q]E │ R │ T │       │ Y │ U | I[P]O │[P]│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C[B]V │[B]│       │[N]│ M[N], │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤S/L├───┐   ┌───┤SPC├───┘   S/L=Shift/Leader
      *                   └───┤SYM│   │NAV├───┘       SYM=SYMBOLS layer, NAV=NAV layer
      *                       └───┘   └───┘
      * Weak corners: [Q] [P] [B] [N] - only when XC_WEAK_CORNERS enabled, else actual keys
      * Combos: W+E→Q I+O→P C+V→B M+,→N (when weak corners on)
      */
    [BASE] = LAYOUT_split_3x6_3(
        _00_,    _01_,    _02_,    _03_,    _04_,    _05_,                               _06_,    _07_,    _08_,    _09_,    _10_,    _11_,
        _12_,    _13_,    _14_,    _15_,    _16_,    _17_,                               _18_,    _19_,    _20_,    _21_,    _22_,    _23_,
        KC_NO,   _25_,    _26_,    _27_,    _28_,    _29_,                               _30_,    _31_,    _32_,    _33_,    _34_,    KC_NO,
                                            KC_NO,   SFT_LEAD, OSL(SYMBOLS),            OSL(NAV), KC_SPC,  KC_NO
    ),
#ifdef XC_HRM_LAYER
    #include "layer_hrm.h"
#endif
     /*
      * Navigation Layer (Layer 2)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │Udo│Cpy│Pst│       │C-A│Bsp│Ent│Del│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │L#0│   │Alt│Ctl│Sft│   │       │ ← │ ↓ │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │Gui│Sft│Tab│   │       │Hom│PgD│PgU│End│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤Sft├───┘
      *                   └───┤SYM│   │Lck├───┘    L#0=To Base, Cpy=Copy (Cut when shifted), Lck=Layer Lock, OSM=One Shot Mods
      *                       └───┘   └───┘
      */
    [NAV] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   C(KC_Z), C(KC_C), C(KC_V),                            C(KC_A), KC_BSPC, KC_ENT,  KC_DEL,  KC_NO,   KC_NO,
        TO(BASE),   KC_NO,   OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   OSM(MOD_LGUI), OSM(MOD_LSFT), KC_TAB, KC_NO,                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
                                            KC_NO,   KC_LSFT,   OSL(SYMBOLS),            QK_LAYER_LOCK,   KC_LSFT,   KC_NO
    ),
     /*
      * Layer 3 - Easy Symbols and Numbers
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │L#0│ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ ` │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ - │ = │ \ │ ' │ [ │       │ ] │ ; │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤Sft├───┘
      *                   └───┤Lck│   │NAV├───┘    L#0=To Base, Lck=Layer Lock
      *                       └───┘   └───┘
      */
    [SYMBOLS] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(BASE),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_NO,   KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT, KC_LBRC,                            KC_RBRC, KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                            KC_NO,   KC_LSFT, QK_LAYER_LOCK,            OSL(NAV),   KC_LSFT, KC_NO
    )
};

// Variables for SFT_LEAD tap-hold behavior
static bool sft_lead_held = false;
static uint16_t sft_lead_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_LEAD:
            if (record->event.pressed) {
                sft_lead_timer = timer_read();
                sft_lead_held = true;
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                if (sft_lead_held && timer_elapsed(sft_lead_timer) < TAPPING_TERM) {
                    // Tap detected - trigger Leader
                    leader_start();
                }
                sft_lead_held = false;
            }
            return false;
    }
    return true;
}

// Per-key hold on other key press - enable for layer keys
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL(NAV):
        case OSL(SYMBOLS):
            return true;  // Immediately activate layer on other key press
        default:
            return false;
    }
}

// Per-key retro tapping - disable for layer keys
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL(NAV):
        case OSL(SYMBOLS):
            return false;  // Don't retro tap layer keys
        default:
            return true;
    }
}

// Per-key tapping force hold - enable for layer keys
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL(NAV):
        case OSL(SYMBOLS):
            return true;  // Always commit to hold for layer keys
        default:
            return false;
    }
}

// Leader key sequences
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_E)) {
        tap_code16(RALT(KC_QUOT));
    } else if (leader_sequence_one_key(KC_A)) {
        tap_code16(RALT(KC_GRV));
    } else if (leader_sequence_one_key(KC_U)) {
        tap_code16(RALT(S(KC_QUOT)));
    } else if (leader_sequence_one_key(KC_O)) {
        tap_code16(RALT(S(KC_6)));
    } else if (leader_sequence_one_key(KC_C)) {
        tap_code16(RALT(KC_COMMA));
        tap_code(KC_C);
    } else if (leader_sequence_one_key(KC_M)) {
        tap_code16(RALT(KC_TILD));
        tap_code(KC_N);
    }
}

