// Alternative base layer symbols feature
// When enabled, replaces layout-specific symbols with alternative morphing pairs
// Controlled by XC_ALT_BASE_SYMBOLS flag in rules.mk
//
// This feature provides 5 alternative symbol pairs (in order):
// ALT_SYM1: ' → " (KC_QUOT)
// ALT_SYM2: , → . (comma primary, dot on shift via custom handler)
// ALT_SYM3: ? → ! (question mark primary, exclamation on shift via custom handler)
// ALT_SYM4: - → / (minus primary, slash on shift via custom handler)
// ALT_SYM5: _ → | (underscore primary, pipe on shift via custom handler)
//
// Each layout defines where these symbols are placed by mapping ALT_SYM1-5 to positions
// and providing default values for those positions.

#pragma once

#ifdef XC_ALT_BASE_SYMBOLS
    // Alternative symbols enabled
    #define ALT_SYM1 KC_QUOT         // ' / "
    #define ALT_SYM2 KC_COMM         // , (dot . on shift via custom handler)
    #define ALT_SYM3 KC_QUES         // ? (exclamation ! on shift via custom handler)
    #define ALT_SYM4 KC_MINS         // - (slash / on shift via custom handler)
    #define ALT_SYM5 KC_UNDS         // _ (pipe | on shift via custom handler)
#endif
