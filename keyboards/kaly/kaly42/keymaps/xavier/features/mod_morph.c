#include "mod_morph.h"

// State variable: true = GUI, false = Ctrl
static bool mod_morph_state = true;  // Default to GUI (for macOS)

// Oneshot state for the morphing modifier
oneshot_state mm_state = os_up_unqueued;

void toggle_mod_morph(void) {
    mod_morph_state = !mod_morph_state;
}

void update_mod_morph_oneshot(uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    // Get the current modifier based on morph state
    uint16_t current_mod = mod_morph_state ? KC_LGUI : KC_LCTL;

    // Use the oneshot update logic
    update_oneshot(&mm_state, current_mod, trigger, keycode, record);
}
