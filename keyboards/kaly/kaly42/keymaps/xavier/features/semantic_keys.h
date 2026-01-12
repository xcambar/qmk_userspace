#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"

/*
 * Semantic Keys - Platform Independence Layer
 *
 * This implementation provides platform-independent editing commands
 * that automatically send the correct keystroke for Mac or Linux.
 *
 * Design goals:
 * - Compatible with Callum-style oneshot modifiers
 * - Data-driven: keycodes stored in lookup table by platform
 * - Proper C file structure (no static variables in headers)
 *
 * Usage in keymap.c:
 * 1. Define semantic keys in custom_keycodes enum: SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_SALL
 * 2. Include this header in keymap.c
 * 3. Add semantic_keys.c to SRC in rules.mk
 * 4. Call process_semkey() in process_record_user()
 */

// Process semantic keys - call from process_record_user()
// Returns true to continue processing, false if handled
bool process_semkey(uint16_t keycode, keyrecord_t *record);
