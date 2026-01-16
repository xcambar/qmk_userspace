// Alternative base layer symbols feature
// Table-driven key override generation for custom shift morphing

#pragma once

#ifdef XC_ALT_BASE_SYMBOLS

// Alternative symbols list using CUSTOM_KEYCODES macro from custom_keycodes.h
// Expands to: _ALT_SYMBOLS_START, AS_QUOT, ..., _ALT_SYMBOLS_COUNT
#define ALT_SYMBOLS_LIST CUSTOM_KEYCODES(ALT_SYMBOLS, \
        AS_QUOT, \
        AS_COMM, \
        AS_DOT, \
        AS_MINS, \
        AS_UNDS \
    )

// Initialize the alternative symbol key overrides
void alt_symbols_init(void);

// Get the array of key override pointers
const key_override_t** get_alt_symbol_overrides(void);

#endif // XC_ALT_BASE_SYMBOLS
