// Weak Corners Feature
// This file contains combo definitions for weak corner keys
//
// When XC_WEAK_CORNERS is enabled:
//   - Positions _01_, _10_, _29_, _30_ are redefined as KC_NO
//   - The original keys (Q, P, B, N in QWERTY) are activated via combos:
//     * W+E → Q (position 1)
//     * I+O → P (position 10)
//     * C+V → B (position 29)
//     * M+, → N (position 30)
//
// When XC_WEAK_CORNERS is disabled:
//   - Positions remain as defined in the layout file (normal keys)
//   - No weak corner combos are active

#pragma once

#ifdef XC_WEAK_CORNERS
    // Define weak corner output keys based on layout
    // These must be compile-time constants since they're used in static array initializers
    #if XC_LAYOUT == LAYOUT_QWERTY
        #define WC_OUT_01 KC_Q
        #define WC_OUT_10 KC_P
        #define WC_OUT_29 KC_B
        #define WC_OUT_30 KC_N
    #elif XC_LAYOUT == LAYOUT_GALLIUM
        #define WC_OUT_01 KC_B
        #define WC_OUT_10 KC_COMM
        #define WC_OUT_29 KC_Z
        #define WC_OUT_30 KC_K
    #endif

    const uint16_t PROGMEM weak_corner_l_tl_combo[] = {_02_, _03_, COMBO_END};  // W+E → Q/B
    const uint16_t PROGMEM weak_corner_r_tr_combo[] = {_08_, _09_, COMBO_END};  // I+O → P/,
    const uint16_t PROGMEM weak_corner_l_br_combo[] = {_27_, _28_, COMBO_END};  // C+V → B/Z
    const uint16_t PROGMEM weak_corner_r_bl_combo[] = {_31_, _32_, COMBO_END};  // M+, → N/K

    #define XC_WEAK_CORNERS_COMBOS \
        COMBO(weak_corner_l_tl_combo, WC_OUT_01), \
        COMBO(weak_corner_r_tr_combo, WC_OUT_10), \
        COMBO(weak_corner_l_br_combo, WC_OUT_29), \
        COMBO(weak_corner_r_bl_combo, WC_OUT_30),

    #undef _01_
    #undef _10_
    #undef _29_
    #undef _30_
    #define _01_ KC_NO
    #define _10_ KC_NO
    #define _29_ KC_NO
    #define _30_ KC_NO
#endif

# ifndef XC_WEAK_CORNERS
    #define XC_WEAK_CORNERS_COMBOS
#endif
