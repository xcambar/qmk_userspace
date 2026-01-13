#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"

/*
 * Dead Keys - Accent System
 *
 * This implementation provides dead key functionality for typing accented characters.
 * Press an accent key (e.g., DK_ACUTE) followed by a letter to produce an accented character.
 *
 * Design goals:
 * - Platform-independent using Unicode input
 * - Data-driven: accent combinations stored in lookup tables
 * - Compatible with oneshot modifiers and semantic keys
 *
 * Usage in keymap.c:
 * 1. Define dead keys in custom_keycodes enum: DK_ACUTE, DK_GRAVE, DK_CIRC, DK_DIAE, DK_TILDE
 * 2. Include this header in keymap.c
 * 3. Add dead_keys.c to SRC in rules.mk
 * 4. Call process_dead_key() in process_record_user() BEFORE process_semkey()
 * 5. Enable Unicode in config.h and rules.mk
 */

// Process dead keys - call from process_record_user() BEFORE process_semkey()
// Returns true to continue processing, false if handled
bool process_dead_key(uint16_t keycode, keyrecord_t *record);

// Tap the platform-specific dead key (for use in leader sequences, etc.)
void tap_deadkey_code(uint16_t dk);
