#include QMK_KEYBOARD_H
#include "../custom_keycodes.h"  // Custom keycode definitions
#include "semantic_keys.h"
#include "os_control.h"

/*
 * Semantic Keys - Platform Independence Layer
 *
 * This implementation provides platform-independent editing commands
 * that automatically send the correct keystroke for Mac or Linux.
 */

// Semantic key data structure: holds platform-specific keycodes
typedef struct {
    uint16_t mac_keycode;
    uint16_t linux_keycode;
} semkey_map_t;

// Helper macros for semantic key management
// Using _SK_BEGIN_ and _SK_END_ markers from custom_keycodes.h
#define SK_beg (_SK_BEGIN_ + 1)  // First semantic key after the begin marker
#define SK_end (_SK_END_)         // Last semantic key (the end marker itself)
#define SK_count (SK_end - SK_beg)
#define SK_ndx(sk) ((sk) - SK_beg)
#define is_SemKey(sk) (((sk) >= (uint16_t)(SK_beg)) && ((sk) < (uint16_t)(SK_end)))

// Lookup table for semantic keys by platform
// Using designated initializers (C99) for clarity - order doesn't matter!
// Format: [SK_ndx(keycode)] = {mac_key, linux_key}
static const semkey_map_t semkey_table[SK_count] = {
    [SK_ndx(SK_UNDO)] = {G(KC_Z), C(KC_Z)},      // Undo
    [SK_ndx(SK_CUT)]  = {G(KC_X), C(KC_X)},      // Cut
    [SK_ndx(SK_COPY)] = {G(KC_C), C(KC_C)},      // Copy
    [SK_ndx(SK_PSTE)] = {G(KC_V), C(KC_V)},      // Paste
    [SK_ndx(SK_SALL)] = {G(KC_A), C(KC_A)},      // Select All
};

// Get the platform-specific keycode for a semantic key
static uint16_t get_SemKeyCode(uint16_t sk) {
    if (!is_SemKey(sk)) {
        return KC_NO;
    }

    uint16_t idx = SK_ndx(sk);
    if (idx >= SK_count) {
        return KC_NO;
    }

    const semkey_map_t *entry = &semkey_table[idx];

    if (get_os_platform() == OS_MacOS) {
        return entry->mac_keycode;
    } else {
        return entry->linux_keycode;
    }
}

// Track the registered semantic key for proper release
static uint16_t registered_semkey_code = KC_NO;

// Process semantic keys - call from process_record_user()
// Returns true to continue processing, false if handled
//
// IMPORTANT: Oneshot compatibility:
// - Reads modifier state with get_mods() to detect shift for morphing
// - Clears shift when consumed for the morph
// - Lets oneshot system clean up the physical key state
bool process_semkey(uint16_t keycode, keyrecord_t *record) {
    // Not a semantic key? Continue normal processing
    if (!is_SemKey(keycode)) {
        return true;
    }

    if (record->event.pressed) {
        // Check current modifier state for shift morphing
        uint8_t mods = get_mods();

        // Check for shift morphing: SK_COPY + Shift → SK_CUT
        uint16_t actual_keycode = keycode;
        if (keycode == SK_COPY && (mods & MOD_MASK_SHIFT)) {
            actual_keycode = SK_CUT;
            // Clear shift - we've consumed it for the morph
            // Don't restore it; let the oneshot system clean up
            del_mods(MOD_MASK_SHIFT);
        }

        // Get the platform-specific keycode
        uint16_t platform_keycode = get_SemKeyCode(actual_keycode);

        if (platform_keycode == KC_NO) {
            return false; // Invalid semantic key, consume it
        }

        // Send the platform-specific keycode
        register_code16(platform_keycode);
        registered_semkey_code = platform_keycode;
    } else {
        // Key release: unregister whatever we sent on keydown
        if (registered_semkey_code != KC_NO) {
            unregister_code16(registered_semkey_code);
            registered_semkey_code = KC_NO;
        }
    }

    // Don't process this key further
    return false;
}
