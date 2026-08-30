// Luz — Compose combo
// ----------------------------------------------------------------------------
// Canonical file at keyboards/6x3_3/luz/compose.h, shared by every Luz variant.
//
// Compose is armed by a single cross-hand combo on BASE — the only combo in Luz.
// The MECHANISM is the contract; the OPERANDS are per-variant, because they depend
// on what each layout places at the combo positions.
//
// Luz uses positions 5 and 6 (the inner index column, top row): cross-hand, so no
// roll can trigger them, and every layout puts a low-frequency key there. A combo
// operand must be a key you never type in sequence with the other operand — this is
// why the historic Shift+Space worked (Shift is not a typed character) and why it
// could not survive Shift moving onto a letter.
//
//   Gallium     V + J
//   Enthium     X + =
//
// Usage in keymap.c, before key_combos[]:
//     LUZ_COMPOSE_COMBO(_05_, _06_);

#pragma once

#include "quantum.h"

#define LUZ_COMPOSE_COMBO(a, b) \
    const uint16_t PROGMEM compose_combo[] = {a, b, COMBO_END}
