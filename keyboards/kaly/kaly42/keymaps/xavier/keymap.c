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
    NUM,
    SYM,
    DEL
};

enum custom_keycodes {
    PLS_MIN = SAFE_RANGE,// + normally, - when shifted
    MUL_DIV,             // * normally, / when shifted
    DOT_COM,             // . normally, , when shifted
    PARENS,              // ( normally, ) when shifted
    BRACES,              // { normally, } when shifted
    BRACKETS,            // [ normally, ] when shifted
    ANGLES,              // < normally, > when shifted
    SLASHES,             // / normally, \ when shifted
    QUOTE_DBL,           // ' normally, " when shifted
    EQUAL_EXCL,          // = normally, ! when shifted
    TILDE_CARET,         // ~ normally, ^ when shifted
    AMP_DOLLAR,          // & normally, $ when shifted
    PIPE_TICK,           // | normally, ` when shifted
    MINUS_UNDER,         // - normally, _ when shifted
    BSP_DEL,             // Backspace normally, Delete when shifted
    SFT_LEAD,            // Shift on hold, Leader on tap
};

const uint16_t PROGMEM boot_combo[] = {_12_, _23_, COMBO_END};  // Tab + Quote
// Shift + D → SYM layer (works on all layers)
const uint16_t PROGMEM sft_d_combo_l0[] = {SFT_LEAD, _15_, COMBO_END};  // Base layer: Shift + D
const uint16_t PROGMEM sft_d_combo_l3[] = {KC_LSFT, KC_MINS, COMBO_END};  // NUM layer: Shift + -
const uint16_t PROGMEM sft_d_combo_l4[] = {KC_LSFT, KC_MINS, COMBO_END};  // SYM layer: Shift + -
// Space + K → NUM layer (works on all layers)
const uint16_t PROGMEM spc_k_combo_l0[] = {KC_SPC, _20_, COMBO_END};  // Base layer: Space + K
const uint16_t PROGMEM spc_k_combo_l3[] = {KC_SPC, KC_5, COMBO_END};  // NUM layer: Space + 5
const uint16_t PROGMEM spc_k_combo_l4[] = {KC_SPC, KC_UNDS, COMBO_END};  // SYM layer: Space + _

combo_t key_combos[] = {
    XC_WEAK_CORNERS_COMBOS
    COMBO(boot_combo, QK_BOOT),
    COMBO(sft_d_combo_l0, TO(SYM)),
    COMBO(sft_d_combo_l3, TO(SYM)),
    COMBO(sft_d_combo_l4, TO(SYM)),
    COMBO(spc_k_combo_l0, TO(NUM)),
    COMBO(spc_k_combo_l3, TO(NUM)),
    COMBO(spc_k_combo_l4, TO(NUM)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │[Q]│ W[Q]E │ R │ T │       │ Y │ U | I[P]O │[P]│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C[B]V │[B]│       │[N]│ M[N], │ . │ / │Alt│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤S/L├───┐   ┌───┤SPC├───┘   S/L=Shift/Leader
      *                   └───┤NAV│   │DEL├───┘       DEL=DEL layer
      *                       └───┘   └───┘
      * Weak corners: [Q] [P] [B] [N] - only when XC_WEAK_CORNERS enabled, else actual keys
      * Combos: S/L+D → SYM | SPC+K → NUM | W+E→Q I+O→P C+V→B M+,→N (when weak corners on)
      */
    [BASE] = LAYOUT_split_3x6_3(
        _00_,    _01_,    _02_,    _03_,    _04_,    _05_,                               _06_,    _07_,    _08_,    _09_,    _10_,    _11_,
        _12_,    _13_,    _14_,    _15_,    _16_,    _17_,                               _18_,    _19_,    _20_,    _21_,    _22_,    _23_,
        KC_LCTL, _25_,    _26_,    _27_,    _28_,    _29_,                               _30_,    _31_,    _32_,    _33_,    _34_,    KC_LALT,
                                            KC_NO,   SFT_LEAD, MO(NAV),            MO(DEL), KC_SPC,  KC_NO
    ),
#ifdef XC_HRM_LAYER
    #include "layer_hrm.h"
#endif
     /*
      * Navigation Layer (Layer 2)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │Esc│   │   │   │       │Rdo│Pst│Cpy│Cut│Udo│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │Alt│Ctl│Sft│   │       │ ← │ ↓ │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │Gui│Sft│Tab│   │       │Hom│PgD│PgU│End│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤///│   │   ├───┘
      *                       └───┘   └───┘
      */
    [NAV] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_ESC,  KC_NO,   KC_NO,   KC_NO,                              C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), KC_NO,
        KC_NO,   KC_NO,   OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_LGUI, KC_LSFT, KC_TAB, KC_NO,                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO
    ),
     /*
      * Layer 3 - Numpad
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ * │ + │   │   │       │   │ 7 │ 8 │ 9 │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ / │ - │ = │   │       │   │ 4 │ 5 │ 6 │ 0 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ % │ , │ . │   │       │   │ 1 │ 2 │ 3 │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤SPC├───┘
      *                   └───┤L#0│   │DEL├───┘
      *                       └───┘   └───┘
      * Combos: Sft+D → layer 4 | Spc+K → layer 3
      */
    [NUM] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_ASTR, KC_PLUS, KC_NO,   KC_NO,                              KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_SLSH, KC_MINS, KC_EQL,  KC_NO,                              KC_NO,   KC_4,    KC_5,    KC_6,    KC_0,    KC_NO,
        KC_NO,   KC_NO,   KC_PERC, KC_COMM, KC_DOT,   KC_NO,                              KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
                                            KC_NO,   KC_LSFT, TO(BASE),            MO(DEL), KC_SPC,  KC_NO
    ),
     /*
      * Layer 4 - Symbols (compact pairs)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │[/]│{/}│(/)│   │       │   │ @ │</>│   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ / │ - │ = │   │       │   │ ! │ _ │ \ │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ % │ ~ │ & │ | │   │       │   │ $ │ ^ │ ` │ # │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤   ├───┘
      *                   └───┤L#0│   │DEL├───┘
      *                       └───┘   └───┘
      * Combos: Sft+D → layer 4 | Spc+K → layer 3
      */
    [SYM] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   BRACKETS, BRACES, PARENS,  KC_NO,                              KC_NO,   KC_AT,   ANGLES,  KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_SLSH, KC_MINS, KC_EQL,   KC_NO,                              KC_NO,   KC_EXLM, KC_UNDS, KC_BSLS, KC_NO,   KC_NO,
        KC_NO,   KC_PERC, KC_TILD, KC_AMPR, KC_PIPE,  KC_NO,                              KC_NO,   KC_DLR,  KC_CIRC, KC_GRV,  KC_HASH, KC_NO,
                                            KC_NO,   KC_LSFT, TO(BASE),            MO(DEL), KC_SPC,  KC_NO
    ),
     /*
      * Layer 5 - DEL (Delete/Editing shortcuts)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │S-D│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │Alt│Ctl│Sft│   │       │   │Bsp│Ent│Del│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │Gui│   │       │   │C-B│   │C-D│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │///├───┘
      *                       └───┘   └───┘
      */
    [DEL] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, S(KC_DEL), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                            KC_TRNS, KC_BSPC, KC_ENT,  KC_DEL,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS,                            KC_TRNS, C(KC_BSPC), KC_TRNS, C(KC_DEL), KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// Macro to handle dual-function keys
#define PROCESS_DUAL_KEY(kc, normal, shifted) \
    case kc: { \
        uint8_t saved_mods = get_mods(); \
        if (saved_mods & MOD_MASK_SHIFT) { \
            if (record->event.pressed) { \
                unregister_code16(normal); \
                del_mods(MOD_MASK_SHIFT); \
                register_code16(shifted); \
            } else { \
                unregister_code16(shifted); \
            } \
            set_mods(saved_mods); \
        } else { \
            if (record->event.pressed) { \
                register_code16(normal); \
            } else { \
                unregister_code16(normal); \
            } \
        } \
        return false; \
    }

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
        PROCESS_DUAL_KEY(PLS_MIN,     KC_PLUS, KC_MINS)
        PROCESS_DUAL_KEY(MUL_DIV,     KC_ASTR, KC_SLSH)
        PROCESS_DUAL_KEY(DOT_COM,     KC_DOT,  KC_COMM)
        PROCESS_DUAL_KEY(PARENS,      KC_LPRN, KC_RPRN)
        PROCESS_DUAL_KEY(BRACES,      KC_LCBR, KC_RCBR)
        PROCESS_DUAL_KEY(BRACKETS,    KC_LBRC, KC_RBRC)
        PROCESS_DUAL_KEY(ANGLES,      KC_LT,   KC_GT)
        PROCESS_DUAL_KEY(SLASHES,     KC_SLSH, KC_BSLS)
        PROCESS_DUAL_KEY(QUOTE_DBL,   KC_QUOT, KC_DQUO)
        PROCESS_DUAL_KEY(EQUAL_EXCL,  KC_EQL,  KC_EXLM)
        PROCESS_DUAL_KEY(TILDE_CARET, KC_TILD, KC_CIRC)
        PROCESS_DUAL_KEY(AMP_DOLLAR,  KC_AMPR, KC_DLR)
        PROCESS_DUAL_KEY(PIPE_TICK,   KC_PIPE, KC_GRV)
        PROCESS_DUAL_KEY(MINUS_UNDER, KC_MINS, KC_UNDS)
        PROCESS_DUAL_KEY(BSP_DEL,     KC_BSPC, KC_DEL)
    }
    return true;
}

// Per-key hold on other key press - enable for NAV layer
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(NAV):
            return true;  // Immediately activate NAV on other key press
        default:
            return false;
    }
}

// Per-key retro tapping - disable for layer keys
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(NAV):
        case MO(DEL):
            return false;  // Don't retro tap layer keys
        default:
            return true;
    }
}

// Per-key tapping force hold - enable for layer keys
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(NAV):
            return true;  // Always commit to hold for NAV
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

