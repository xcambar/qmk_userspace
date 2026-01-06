// Copyright 2023 Kael Soares Augusto (@Dwctor)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Tapping term for mod-tap keys (in milliseconds)
#undef TAPPING_TERM
#define TAPPING_TERM 250

// Enable permissive hold for better mod-tap behavior
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Enable chordal hold for home row mods
#define CHORDAL_HOLD
// #define AUTO_SHIFT_TIMEOUT 200

// One-shot modifier timeout (in ms) - keeps OSM active after layer release
#define ONESHOT_TIMEOUT 3000

// Retro tapping - tap layer key when released without pressing other keys
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

// Tapping force hold - prevents accidental taps when rolling
#define TAPPING_FORCE_HOLD_PER_KEY
