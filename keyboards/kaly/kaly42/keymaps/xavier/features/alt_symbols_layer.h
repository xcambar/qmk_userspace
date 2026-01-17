// Alternative SYMBOLS layer feature
// Custom keycodes with non-standard shift behavior for SYMBOLS layer
//
// Design goals:
// - Clean API: macros hide complexity
// - Compile-time initialization: key overrides generated statically

#pragma once

#include <stdint.h>
#include "quantum.h"

#ifdef XC_ALT_SYMBOLS_LAYER

// Alternative symbols layer keycodes using CUSTOM_KEYCODES macro
#define ALT_SYMBOLS_LAYER_LIST CUSTOM_KEYCODES(ALT_SYMBOLS_LAYER, \
        SL_1, \
        SL_2, \
        SL_3, \
        SL_4, \
        SL_5, \
        SL_6, \
        SL_7, \
        SL_9, \
        SL_0, \
        SL_BSLS, \
        SL_LPRN, \
        SL_RPRN, \
        SL_LBRC, \
        SL_RBRC, \
        SL_SCLN, \
        SL_TILD \
    )

// Macro to generate a pair of key overrides for a symbols layer key
// Applied only to SYMBOLS layer (1 << SYMBOLS)
// Usage: SL_OVERRIDE(SL_1, KC_1, KC_AT)
#define SL_OVERRIDE(trigger, unshifted, shifted) \
    &ko_make_with_layers_and_negmods( \
        0, trigger, unshifted, 1 << SYMBOLS, MOD_MASK_SHIFT \
    ), \
    &ko_make_with_layers( \
        MOD_MASK_SHIFT, trigger, shifted, 1 << SYMBOLS \
    )

#endif // XC_ALT_SYMBOLS_LAYER
