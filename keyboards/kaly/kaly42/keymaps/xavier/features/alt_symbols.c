// Alternative base layer symbols feature implementation
// Provides table-driven key override generation for custom shift morphing

#include "quantum.h"
#include "../custom_keycodes.h"

#ifdef XC_ALT_BASE_SYMBOLS

// Helper macros for alt symbol management
#define AS_beg (LIST_START_MARKER(ALT_SYMBOLS))
#define AS_end (LIST_LENGTH(ALT_SYMBOLS))
#define AS_count (AS_end - AS_beg)
#define AS_ndx(as) ((as) - AS_beg)

// Alternative symbol data structure
typedef struct {
    uint16_t trigger;    // Custom keycode trigger
    uint16_t unshifted;  // Normal key behavior
    uint16_t shifted;    // Shifted key behavior
} alt_symbol_map_t;

// Lookup table for alternative symbols using designated initializers
static const alt_symbol_map_t alt_symbol_table[AS_count] = {
    [AS_ndx(AS_QUOT)]   = {AS_QUOT, KC_QUOT, KC_DQUO},  // ' → "
    [AS_ndx(AS_COMM)]   = {AS_COMM, KC_COMM, KC_QUES},   // , → ?
    [AS_ndx(AS_DOT)]    = {AS_DOT,  KC_DOT, KC_EXLM},  // . → !
    [AS_ndx(AS_MINS)]   = {AS_MINS, KC_MINS, KC_SLSH},  // - → /
    [AS_ndx(AS_UNDS)]   = {AS_UNDS, KC_UNDS, KC_PIPE},  // _ → |
};

// Generate key overrides array dynamically
// We need 2 overrides per symbol: unshifted (with negmods) and shifted
// Total: AS_count * 2 + 1 (NULL terminator)
static key_override_t alt_symbol_overrides_unshifted[AS_count];
static key_override_t alt_symbol_overrides_shifted[AS_count];
static const key_override_t* alt_symbol_override_ptrs[AS_count * 2 + 1];

// Initialize key overrides from the table
void alt_symbols_init(void) {
    for (uint8_t i = 0; i < AS_count; i++) {
        const alt_symbol_map_t* entry = &alt_symbol_table[i];

        // Create unshifted override (with negmods to prevent firing when shift held)
        alt_symbol_overrides_unshifted[i] = (key_override_t){
            .trigger_mods = 0,
            .layers = ~0,
            .suppressed_mods = 0,
            .options = ko_option_no_reregister_trigger,
            .negative_mod_mask = MOD_MASK_SHIFT,
            .custom_action = NULL,
            .context = NULL,
            .trigger = entry->trigger,
            .replacement = entry->unshifted,
            .enabled = NULL
        };

        // Create shifted override
        alt_symbol_overrides_shifted[i] = (key_override_t){
            .trigger_mods = MOD_MASK_SHIFT,
            .layers = ~0,
            .suppressed_mods = MOD_MASK_SHIFT,
            .options = ko_option_no_reregister_trigger,
            .negative_mod_mask = 0,
            .custom_action = NULL,
            .context = NULL,
            .trigger = entry->trigger,
            .replacement = entry->shifted,
            .enabled = NULL
        };

        // Add pointers to the array
        alt_symbol_override_ptrs[i * 2] = &alt_symbol_overrides_unshifted[i];
        alt_symbol_override_ptrs[i * 2 + 1] = &alt_symbol_overrides_shifted[i];
    }

    // NULL terminator
    alt_symbol_override_ptrs[AS_count * 2] = NULL;
}

// Export the override array pointer
const key_override_t** get_alt_symbol_overrides(void) {
    return alt_symbol_override_ptrs;
}

#endif // XC_ALT_BASE_SYMBOLS
