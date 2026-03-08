// Weak Corners Feature
// This file contains combo definitions for weak corner keys
//
// When XC_WEAK_CORNERS is enabled:
//   - Layout files wrap _01_, _10_, _29_, _30_ with WC_CORNER(), expanding to KC_NO
//   - The corner keys are activated via combos (runtime lookup from wc_keycodes table):
//     * W+E → TL corner (position 01)
//     * I+O → TR corner (position 10)
//     * C+V → BL corner (position 29)
//     * M+, → BR corner (position 30)
//
// When XC_WEAK_CORNERS is disabled:
//   - WC_CORNER(key) expands to (key) — positions remain as normal keys
//   - No weak corner combos are active

#pragma once

#ifdef XC_WEAK_CORNERS
    #define WC_CORNER(key) KC_NO  // Blank corner on any layer; combo drives output via wc_keycodes table

    // WC_OUT_01/10/29/30 are defined in the active layout file (e.g. layouts/graphite.h)
    // Only one layout file is included per build, so the correct values are always set.

    const uint16_t PROGMEM weak_corner_l_tl_combo[] = {_02_, _03_, COMBO_END};  // → TL corner
    const uint16_t PROGMEM weak_corner_r_tr_combo[] = {_08_, _09_, COMBO_END};  // → TR corner
    const uint16_t PROGMEM weak_corner_l_br_combo[] = {_27_, _28_, COMBO_END};  // → BL corner
    const uint16_t PROGMEM weak_corner_r_bl_combo[] = {_31_, _32_, COMBO_END};  // → BR corner

    // COMBO_ACTION: output resolved at runtime via wc_keycodes table in keymap.c
    #define XC_WEAK_CORNERS_COMBOS \
        COMBO_ACTION(weak_corner_l_tl_combo), \
        COMBO_ACTION(weak_corner_r_tr_combo), \
        COMBO_ACTION(weak_corner_l_br_combo), \
        COMBO_ACTION(weak_corner_r_bl_combo),
#endif

#ifndef XC_WEAK_CORNERS
    #define WC_CORNER(key) (key)
    #define XC_WEAK_CORNERS_COMBOS
#endif
