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

// Layout selection based on rules.mk configuration
// XC_LAYOUT is passed from rules.mk (e.g., -DXC_LAYOUT=QWERTY)
// Default value is set in rules.mk as "qwerty" and converted to uppercase

// Define layout constants for comparison
#define LAYOUT_QWERTY 1
#define LAYOUT_GALLIUM 2

// Convert XC_LAYOUT token to a numeric constant
#define QWERTY LAYOUT_QWERTY
#define GALLIUM LAYOUT_GALLIUM

#if XC_LAYOUT == LAYOUT_QWERTY
    #include "layout_qwerty.h"
#elif XC_LAYOUT == LAYOUT_GALLIUM
    #include "layout_gallium.h"
#else
    #error "Unknown layout specified"
#endif


enum layers {
    BASE = 0,
    HRM,
    NAV,
    NUM,
    SYM,
    ACC,
    DEL
};

enum custom_keycodes {
    TO_NUM = SAFE_RANGE, // Tap to switch to layer 3 (numpad)
    TO_SYM,              // Tap to switch to layer 4 (symbols)
    TO_ACC,              // Tap to switch to layer 5 (compose)
    PLS_MIN,             // + normally, - when shifted
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
    CTL_ALT_L,           // LCtrl normally, LAlt when shifted (position 24)
    ALT_CTL_R,           // LAlt normally, Ctrl when shifted (position 35)
};

enum combo_events {
    WEAK_CORNERS_L_TL,
    WEAK_CORNERS_L_BR,
    WEAK_CORNERS_R_BL,
    WEAK_CORNERS_R_TR,
    BOOT_RESET,
    SFT_D_SYM_L0,
    SFT_D_SYM_L3,
    SFT_D_SYM_L4,
    SPC_K_NUM_L0,
    SPC_K_NUM_L3,
    SPC_K_NUM_L4,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM we_combo[] = {_02_, _03_, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {_27_, _28_, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {_31_, _32_, COMBO_END};
const uint16_t PROGMEM io_combo[] = {_08_, _09_, COMBO_END};
const uint16_t PROGMEM boot_combo[] = {_00_, _23_, COMBO_END};  // Tab + Quote
// Shift + D → SYM layer (works on all layers)
const uint16_t PROGMEM sft_d_combo_l0[] = {SFT_LEAD, _15_, COMBO_END};  // Base layer: Shift + D
const uint16_t PROGMEM sft_d_combo_l3[] = {KC_LSFT, KC_MINS, COMBO_END};  // NUM layer: Shift + -
const uint16_t PROGMEM sft_d_combo_l4[] = {KC_LSFT, KC_MINS, COMBO_END};  // SYM layer: Shift + -
// Space + K → NUM layer (works on all layers)
const uint16_t PROGMEM spc_k_combo_l0[] = {KC_SPC, _20_, COMBO_END};  // Base layer: Space + K
const uint16_t PROGMEM spc_k_combo_l3[] = {KC_SPC, KC_5, COMBO_END};  // NUM layer: Space + 5
const uint16_t PROGMEM spc_k_combo_l4[] = {KC_SPC, KC_UNDS, COMBO_END};  // SYM layer: Space + _

combo_t key_combos[] = {
    [WEAK_CORNERS_L_TL] = COMBO(we_combo, _01_),
    [WEAK_CORNERS_L_BR] = COMBO(cv_combo, _29_),
    [WEAK_CORNERS_R_BL] = COMBO(mcomm_combo, _30_),
    [WEAK_CORNERS_R_TR] = COMBO(io_combo, _10_),
    [BOOT_RESET] = COMBO(boot_combo, QK_BOOT),
    [SFT_D_SYM_L0] = COMBO(sft_d_combo_l0, TO(SYM)),
    [SFT_D_SYM_L3] = COMBO(sft_d_combo_l3, TO(SYM)),
    [SFT_D_SYM_L4] = COMBO(sft_d_combo_l4, TO(SYM)),
    [SPC_K_NUM_L0] = COMBO(spc_k_combo_l0, TO(NUM)),
    [SPC_K_NUM_L3] = COMBO(spc_k_combo_l3, TO(NUM)),
    [SPC_K_NUM_L4] = COMBO(spc_k_combo_l4, TO(NUM)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ W[Q]E │ R │ T │       │ Y │ U | I[P]O │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │C/A│ Z │ X │ C[B]V │   │       │   │ M[N], │ . │ / │A/C│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Esc├───┐           ┌───┤SPC│
      *               └───┤S/L├───┐   ┌───┤SPC├───┘   S/L=Shift/Leader
      *                   └───┤NAV│   │Bsp├───┘       Bsp=Backspace, hold for DEL layer
      *                       └───┘   └───┘
      * C/A=Ctrl (Alt when shifted) | A/C=Alt (Ctrl when shifted)
      * Combos: S/L+D → SYM | SPC+K → NUM
      */
    [BASE] = LAYOUT_split_3x6_3(
        KC_NO,     KC_NO,   _02_,    _03_,    _04_,    _05_,                               _06_,    _07_,    _08_,    _09_,    KC_NO,     KC_NO,
        _00_,      _13_,    _14_,    _15_,    _16_,    _17_,                               _18_,    _19_,    _20_,    _21_,    _22_,      _23_,
        CTL_ALT_L, _25_,    _26_,    _27_,    _28_,    KC_NO,                              KC_NO,   _31_,    _32_,    _33_,    _34_,      ALT_CTL_R,
                                            KC_ESC,  SFT_LEAD, MO(NAV),            LT(DEL, KC_BSPC), KC_SPC,  KC_SPC
    ),
#ifdef XC_HRM_LAYER
    #include "layer_hrm.h"
#endif
     /*
      * Navigation Layer (Layer 2)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ACC│NUM│SYM│   │       │Rdo│Pst│Cpy│Cut│Udo│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │Alt│Ctl│Sft│   │       │ ← │ ↓ │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │E/G│Sft│Tab│   │       │Hom│PgD│PgU│End│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤///│   │   ├───┘
      *                       └───┘   └───┘
      */
    [NAV] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   TO(ACC),   TO(NUM),   TO(SYM),   KC_NO,                              C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), KC_NO,
        KC_NO,   KC_NO,   KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   MT(MOD_LGUI, KC_ESC), KC_LSFT, KC_TAB, KC_NO,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
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
      * Layer 5 - Compose (dead keys and special characters)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │RA'│   │   │       │   │RA"│   │RA^│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │RA`│   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │RAç│   │   │       │   │RAñ│   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤L#0│   │   ├───┘
      *                       └───┘   └───┘
      */
    [ACC] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   RALT(KC_QUOT), KC_NO, KC_NO,                          KC_NO,   RALT(S(KC_QUOT)), KC_NO, RALT(S(KC_6)), KC_NO,   KC_NO,
        KC_NO,   RALT(KC_GRV), KC_NO, KC_NO,   KC_NO,   KC_NO,                           KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   RALT(KC_C),   KC_NO,   KC_NO,                         KC_NO,   RALT(KC_N), KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_NO,   KC_NO,   TO(BASE),            KC_NO,   KC_NO,   KC_NO
    ),
     /*
      * Layer 6 - DEL (Delete/Editing shortcuts)
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
        PROCESS_DUAL_KEY(CTL_ALT_L,   KC_LCTL, KC_LALT)
        PROCESS_DUAL_KEY(ALT_CTL_R,   KC_LALT, KC_LCTL)
    }
    return true;
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

