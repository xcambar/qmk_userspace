// Copyright 2023 Kael Soares Augusto (@Dwctor)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Tap-hold tuning for bottom-row mod-taps + Chordal Hold
#undef TAPPING_TERM
#define TAPPING_TERM 240

// Chordal Hold: opposite-hands rule for mod-tap keys (QMK Feb 2025)
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD

// Flow Tap: disable hold during fast typing bursts (QMK May 2025)
#define FLOW_TAP_TERM 150

// Callum-style oneshot mod timeout (ms) - auto-cancel queued mods after delay
#define ONESHOT_MOD_TIMEOUT 2000

// Retro tapping - tap layer key when released without pressing other keys
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

// Tapping force hold - prevents accidental taps when rolling
#define TAPPING_FORCE_HOLD_PER_KEY

// Combos always reference layer 0 keycodes, so they work regardless of active base layer
#define COMBO_ONLY_FROM_LAYER 0
