#pragma once

#include "quantum.h"

// Custom keycodes for the xavier keymap
enum custom_keycodes {
    SFT_LEAD = SAFE_RANGE,  // Shift on hold, Leader on tap
    OS_SHFT,                 // Oneshot shift
    OS_CTRL,                 // Oneshot control
    OS_ALT,                  // Oneshot alt
    OS_GUI,                  // Oneshot GUI
    SW_WIN,                  // Switch window (cmd-tab)
    MM_GUICTRL,              // Modifier swappable between GUI and Ctrl
    // Semantic keys (platform-independent editing commands)
    _SK_BEGIN_,              // Marker: start of semantic keys (not a real key)
    SK_UNDO,                 // Undo
    SK_CUT,                  // Cut
    SK_COPY,                 // Copy
    SK_PSTE,                 // Paste
    SK_SALL,                 // Select All
    _SK_END_                 // Marker: end of semantic keys (not a real key)
};
