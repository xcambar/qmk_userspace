// Alternative base layer symbols feature
// Table-driven key override generation for custom shift morphing

#pragma once

#ifdef XC_ALT_BASE_SYMBOLS

// Initialize the alternative symbol key overrides
void alt_symbols_init(void);

// Get the array of key override pointers
const key_override_t** get_alt_symbol_overrides(void);

#endif // XC_ALT_BASE_SYMBOLS
