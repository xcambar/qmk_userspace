#pragma once

#include "quantum.h"

// Token concatenation helper macros for custom keycodes
#define X_CONCAT_IMPL(a, b) a ## b
#define X_CONCAT(a, b) X_CONCAT_IMPL(a, b)

#define LIST_START_MARKER(PREFIX) X_CONCAT(X_CONCAT(_, PREFIX), _START)
#define LIST_LENGTH(PREFIX) X_CONCAT(X_CONCAT(_, PREFIX), _COUNT)

#define CUSTOM_KEYCODES(PREFIX, ...) \
    LIST_START_MARKER(PREFIX), \
    X_FIRST(__VA_ARGS__), \
    X_REST(__VA_ARGS__), \
    LIST_LENGTH(PREFIX)

// Helper macros to extract first and rest of arguments
#define X_FIRST(first, ...) first
#define X_REST(first, ...) __VA_ARGS__

#include "features/semantic_keys.h"

// Custom keycodes for the xavier keymap
enum custom_keycodes {
    SFT_LEAD = SAFE_RANGE,  // Shift on hold, Leader on tap
    OS_SHFT,                 // Oneshot shift
    OS_CTRL,                 // Oneshot control
    OS_ALT,                  // Oneshot alt
    OS_GUI,                  // Oneshot GUI
    SW_WIN,                  // Switch window (cmd-tab)
    MM_GUICTRL,              // Modifier swappable between GUI and Ctrl

    // Semantic keys (expanded from SEMANTIC_KEYS_LIST macro)
    SEMANTIC_KEYS_LIST,
    // Dead keys (accent keys)
    _DK_BEGIN_ = _SEMANTIC_KEYS_COUNT,              // Marker: start of dead keys (not a real key)
    DK_ACUTE,                // Acute accent (´) - for á é í ó ú ý
    DK_GRAVE,                // Grave accent (`) - for à è ì ò ù
    DK_CIRC,                 // Circumflex (^) - for â ê î ô û
    DK_DIAE,                 // Diaeresis/Umlaut (¨) - for ä ë ï ö ü ÿ
    DK_TILDE,                // Tilde (~) - for ã ñ õ
    _DK_END_,                // Marker: end of dead keys (not a real key)
    // Alternative symbols (custom shift morphing)
    _AS_BEGIN_,              // Marker: start of alt symbols (not a real key)
    AS_QUOT,                 // Alternative quote: ' → " (on shift)
    AS_COMM,                 // Alternative comma: , → . (on shift)
    AS_DOT,                 // Alternative question: ? → ! (on shift)
    AS_MINS,                 // Alternative minus: - → / (on shift)
    AS_UNDS,                 // Alternative underscore: _ → | (on shift)
    _AS_END_                 // Marker: end of alt symbols (not a real key)
};
