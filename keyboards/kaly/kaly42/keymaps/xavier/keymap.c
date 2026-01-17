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
 */

#include "keymap_eurkey.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>

// Custom keycodes (must be included before feature_base_layer.h)
#include "custom_keycodes.h"

// Base layer switch
#include "feature_base_layer.h"

// Weak corners feature
#include "feature_weak_corners.h"

// Callum-style oneshot modifiers
#include "features/oneshot.h"

// Callum-style swapper
#include "features/swapper.h"

// Modifier morph (GUI/Ctrl toggle)
#include "features/mod_morph.h"

// OS control for platform-aware features
#include "features/os_control.h"

enum layers {
    BASE = 0,
    FAVS,
    NAV,
    NAV_FASTER,
    NAV_FASTEST,
    SYMBOLS
};

// Include semantic keys header
#include "features/semantic_keys.h"

// Include dead keys header
#include "features/dead_keys.h"

// Include alternative symbols header
#include "features/alt_symbols.h"
#include "features/alt_symbols_layer.h"

const uint16_t PROGMEM boot_combo[] = {KC_TAB, KC_BSPC, COMBO_END};  // Tab + Backspace
const uint16_t PROGMEM switch_os[] = {_04_, _28_, COMBO_END};  // R + V to toggle OS and mod morph
const uint16_t PROGMEM print_os[] = {_03_, _28_, _04_, COMBO_END};  // E + V + R to print OS name

combo_t key_combos[] = {
    COMBO_ACTION(switch_os),  // Handled in process_combo_event
    COMBO_ACTION(print_os),   // Handled in process_combo_event
    XC_WEAK_CORNERS_COMBOS
    COMBO(boot_combo, QK_BOOT),
};

// Key Overrides for alternative base symbols (custom keycodes)

const key_override_t* key_overrides[] = {
#ifdef XC_ALT_BASE_SYMBOLS
    ALT_SYMBOL_OVERRIDE(AS_QUOT, KC_QUOT, KC_DQUO), // ' → "
    ALT_SYMBOL_OVERRIDE(AS_COMM, KC_COMM, KC_QUES), // , → ?
    ALT_SYMBOL_OVERRIDE(AS_DOT,  KC_DOT,  KC_EXLM), // . → !
    ALT_SYMBOL_OVERRIDE(AS_MINS, KC_MINS, KC_SLSH), // - → /
    ALT_SYMBOL_OVERRIDE(AS_UNDS, KC_UNDS, KC_PIPE), // _ → |
#endif
#ifdef XC_ALT_SYMBOLS_LAYER
    SL_OVERRIDE(SL_1,    KC_1,    KC_AT),   // 1 → @
    SL_OVERRIDE(SL_2,    KC_2,    KC_DLR),  // 2 → $
    SL_OVERRIDE(SL_3,    KC_3,    KC_PERC), // 3 → %
    SL_OVERRIDE(SL_4,    KC_4,    KC_HASH), // 4 → #
    SL_OVERRIDE(SL_5,    KC_5,    KC_AMPR), // 5 → &
    SL_OVERRIDE(SL_6,    KC_6,    KC_PLUS), // 6 → +
    SL_OVERRIDE(SL_7,    KC_7,    KC_EQL),  // 7 → =
    SL_OVERRIDE(SL_9,    KC_9,    KC_UNDS), // 9 → _
    SL_OVERRIDE(SL_0,    KC_0,    KC_GRV),  // 0 → `
    SL_OVERRIDE(SL_BSLS, KC_BSLS, KC_CIRC), // \ → ^
    SL_OVERRIDE(SL_LPRN, KC_LPRN, KC_LT),   // ( → <
    SL_OVERRIDE(SL_RPRN, KC_RPRN, KC_GT),   // ) → >
    SL_OVERRIDE(SL_LBRC, KC_LCBR, KC_LBRC), // { → [ (inverted)
    SL_OVERRIDE(SL_RBRC, KC_RCBR, KC_RBRC), // } → ] (inverted)
    SL_OVERRIDE(SL_SCLN, KC_COLN, KC_SCLN), // : → ; (inverted)
    SL_OVERRIDE(SL_TILD, KC_PIPE, KC_TILD), // | → ~ (inverted)
#endif
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │[Q]│ W[Q]E │ R │ T │       │ Y │ U | I[P]O │[P]│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C[B]V │[B]│       │[N]│ M[N], │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤S/L├───┐   ┌───┤SPC├───┘
      *                   └───┤FAV│   │FAV├───┘       FAV=FAVS layer, S/L=Shift/Leader
      *                       └───┘   └───┘
      * Weak corners: [Q] [P] [B] [N] - only when XC_WEAK_CORNERS enabled, else actual keys
      * Combos: W+E→Q I+O→P C+V→B M+,→N (when weak corners on), Tab+Bsp→QK_BOOT
      * S/L=SFT_LEAD: Hold for Shift, Tap for Leader
      */
    [BASE] = LAYOUT_split_3x6_3(
        KC_NO,    _01_,    _02_,    _03_,    _04_,    _05_,                               _06_,    _07_,    _08_,    _09_,    _10_,    KC_NO,
        KC_TAB,  _13_,    _14_,    _15_,    _16_,    _17_,                               _18_,    _19_,    _20_,    _21_,    _22_,    KC_BSPC,
        KC_NO,   _25_,    _26_,    _27_,    _28_,    _29_,                               _30_,    _31_,    _32_,    _33_,    _34_,    KC_NO,
                                            KC_NO,   SFT_LEAD, MO(FAVS),               MO(FAVS), KC_SPC,  KC_NO
    ),
     /*
      * FAVS Layer (Layer 1) - Favorite shortcuts and modifiers
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│Alt│Gui│Ctl│G/C│SWn│       │Bsp│Del│Ent│   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤OSf├───┐   ┌───┤OSf├───┘
      *                   └───┤SYM│   │NAV├───┘
      *                       └───┘   └───┘
      * G/C=MM_GUICTRL (morphing GUI/Ctrl), SWn=Switch Window, OSf=Oneshot Shift
      * Alt/Gui/Ctl are oneshot modifiers
      */
    [FAVS] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  OS_ALT,  OS_GUI,  OS_CTRL, MM_GUICTRL, SW_WIN,                          KC_BSPC, KC_DEL,  KC_ENT,  KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   OS_SHFT, MO(SYMBOLS),            MO(NAV), OS_SHFT, KC_NO
    ),
     /*
      * Navigation Layer - Arrow keys and navigation
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │Udo│Cpy│Pst│C-A│       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │#BS│   │   │NFa│NF+│   │       │ ← │ ↓ │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤OSf├───┐   ┌───┤Sft├───┘
      *                   └───┤Lck│   │   ├───┘
      *                       └───┘   └───┘
      * #BS=To Base, Udo=Undo, Cpy=Copy, Pst=Paste, C-A=Select All, NF+=NAV_FASTER, NFa=NAV_FASTEST, Lck=Layer Lock, OSf=Oneshot Shift
      */
    [NAV] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   SK_UNDO, SK_COPY, SK_PSTE, SK_SALL,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(BASE), KC_NO,   KC_NO,   MO(NAV_FASTEST), MO(NAV_FASTER), KC_NO,              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   OS_SHFT, QK_LAYER_LOCK,          KC_NO, KC_LSFT, KC_NO
    ),
     /*
      * Navigation Faster Layer - Word and page navigation
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │W← │PgD│PgU│W→ │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      * W←=Word Left, W→=Word Right
      */
    [NAV_FASTER] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   MO(NAV_FASTEST),   KC_NO,   KC_NO,                    SK_WORDPRV, KC_PGDN, KC_PGUP, SK_WORDNXT, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_LSFT, KC_NO,                  KC_NO, KC_NO,   KC_NO
    ),
     /*
      * Navigation Fastest Layer - Document and line navigation
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │L← │D↓ │D↑ │L→ │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      * L←=Line Begin, L→=Line End, D↑=Doc Begin, D↓=Doc End
      */
    [NAV_FASTEST] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              SK_LINEBEG, SK_DOCEND, SK_DOCBEG, SK_LINEEND, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_LSFT, KC_NO,                  KC_NO, KC_NO,   KC_NO
    ),
#ifdef XC_ALT_SYMBOLS_LAYER
     /*
      * Layer 3 - Symbols (Alternative Layout)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │L#0│ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │Bsp│
      * │   │ @ │ $ │ % │ # │ & │       │ + │ = │ * │ _ │ ` │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ \ │ ( │ { │   │       │   │ } │ ) │ : │ | │   │
      * │   │   │ ^ │ < │ [ │   │       │   │ ] │ > │ ; │ ~ │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤Sft├───┘
      *                   └───┤   │   │Lck├───┘    L#0=To Base, Lck=Layer Lock
      *                       └───┘   └───┘
      * Note: {/[, }/], :/;, |/~ are inverted (shifted symbol is default)
      */
    [SYMBOLS] = LAYOUT_split_3x6_3(
        KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_8,     KC_NO,    KC_NO,    KC_NO,
        TO(BASE),  SL_1,     SL_2,     SL_3,     SL_4,    SL_5,                               SL_6,    SL_7,    KC_ASTR,  SL_9,     SL_0,     KC_BSPC,
        KC_NO,     KC_NO,    SL_BSLS,  SL_LPRN,  SL_LBRC, KC_NO,                              KC_NO,   SL_RBRC, SL_RPRN,  SL_SCLN,  SL_TILD,  KC_NO,
                                                  KC_NO,   KC_LSFT, KC_NO,                  QK_LAYER_LOCK,   KC_LSFT, KC_NO
    )
#else
     /*
      * Layer 3 - Easy Symbols and Numbers (Default)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │L#0│ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ ` │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ; │ = │ \ │ ' │ [ │       │ ] │ - │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤Sft├───┐   ┌───┤Sft├───┘
      *                   └───┤   │   │Lck├───┘    L#0=To Base, Lck=Layer Lock
      *                       └───┘   └───┘
      */
    [SYMBOLS] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(BASE),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_NO,   KC_SCLN, KC_EQL,  KC_BSLS, KC_QUOT, KC_LBRC,                            KC_RBRC, KC_MINS, KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                            KC_NO,   KC_LSFT, KC_NO,                  QK_LAYER_LOCK,   KC_LSFT, KC_NO
    )
#endif
};

// Variables for SFT_LEAD tap-hold behavior
static bool sft_lead_held = false;
static uint16_t sft_lead_timer = 0;

// Oneshot modifier states
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

// Swapper state
static bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process dead keys FIRST (before semantic keys and oneshots)
    if (!process_dead_key(keycode, record)) {
        return false;  // Dead key was handled
    }

    // Process semantic keys (platform-independent editing commands)
    if (!process_semkey(keycode, record)) {
        return false;  // Semantic key was handled
    }

    // Update swapper
    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);

    // Update oneshot modifiers
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);

    // Update oneshot morphing modifier
    update_mod_morph_oneshot(MM_GUICTRL, keycode, record);

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

// Define keys that cancel oneshot modifiers
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case KC_ESC:
            return true;
        default:
            return false;
    }
}

// Define keys that should be ignored by oneshot logic (allows stacking modifiers)
bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
        case MM_GUICTRL:
        case KC_LSFT:
        case KC_RSFT:
        case KC_LCTL:
        case KC_RCTL:
        case KC_LALT:
        case KC_RALT:
        case KC_LGUI:
        case KC_RGUI:
        case MO(NAV):
        case MO(NAV_FASTER):
        case MO(NAV_FASTEST):
        case MO(FAVS):
        case MO(SYMBOLS):
        case QK_LAYER_LOCK:
        case TO(BASE):
            return true;
        default:
            return false;
    }
}

// Define keys that should be ignored by swapper (allows changing direction)
bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SHFT:
        case KC_LSFT:
        case KC_RSFT:
            return true;
        default:
            return false;
    }
}

// Combo event handler
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case 0:  // switch_os combo (R + V)
            if (pressed) {
                toggle_os_platform();
            }
            break;
        case 1:  // print_os combo (Shift + V + R)
            if (pressed) {
                send_string(get_os_platform_name());
            }
            break;
    }
}

// Leader key sequences for special characters and dead keys
// W = Euro (€), C = Cedilla (ç), N = Ñ
// E = acute (é), A = grave (à), U = diaeresis (ü), O = circumflex (ô)
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_W)) {
        // Euro: €
        tap_semkey_code(SK_EURO);
    } else if (leader_sequence_one_key(KC_C)) {
        // Cedilla: ç
        tap_semkey_code(SK_CEDIL);
    } else if (leader_sequence_one_key(KC_M)) {
        // N with tilde: ñ
        tap_semkey_code(SK_NTILDE);
    } else if (leader_sequence_one_key(KC_E)) {
        // Acute: é
        tap_deadkey_code(DK_ACUTE);
    } else if (leader_sequence_one_key(KC_A)) {
        // Grave: à
        tap_deadkey_code(DK_GRAVE);
    } else if (leader_sequence_one_key(KC_U)) {
        // Diaeresis: ü
        tap_deadkey_code(DK_DIAE);
    } else if (leader_sequence_one_key(KC_O)) {
        // Circumflex: ô
        tap_deadkey_code(DK_CIRC);
    }
}
