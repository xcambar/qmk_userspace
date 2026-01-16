// Alternative base layer symbols feature
// When enabled, replaces layout-specific symbols with alternative morphing pairs
// Controlled by XC_ALT_BASE_SYMBOLS flag in rules.mk
//
// This feature provides 5 alternative symbol pairs (in order):
// ALT_SYM1: ' → " (AS_QUOT custom keycode)
// ALT_SYM2: , → . (AS_COMM custom keycode)
// ALT_SYM3: ? → ! (AS_QUES custom keycode)
// ALT_SYM4: - → / (AS_MINS custom keycode)
// ALT_SYM5: _ → | (AS_UNDS custom keycode)
//
// Each layout defines where these symbols are placed by mapping ALT_SYM1-5 to positions
// and providing default values for those positions.
//
// Note: AS_QUOT, AS_COMM, AS_QUES, AS_MINS, AS_UNDS are defined in custom_keycodes.h

#pragma once

#ifdef XC_ALT_BASE_SYMBOLS
    // Alternative symbols enabled
    #define ALT_SYM1 AS_QUOT         // ' → " (custom shift morphing)
    #define ALT_SYM2 AS_COMM         // , → . (custom shift morphing)
    #define ALT_SYM3 AS_QUES         // ? → ! (custom shift morphing)
    #define ALT_SYM4 AS_MINS         // - → / (custom shift morphing)
    #define ALT_SYM5 AS_UNDS         // _ → | (custom shift morphing)
#endif
