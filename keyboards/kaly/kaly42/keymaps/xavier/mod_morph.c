#include "mod_morph.h"

// State variable: true = GUI, false = Ctrl
static bool mod_morph_state = true;  // Default to GUI (for macOS)

// Oneshot state for the morphing modifier
static oneshot_state mm_state = os_up_unqueued;

void toggle_mod_morph(void) {
    // If modifier is currently active, unregister old and register new
    if (mm_state != os_up_unqueued) {
        unregister_code(mod_morph_state ? OS_LGUI : OS_LCTL);
        register_code(mod_morph_state ? OS_LCTL : OS_LGUI);
    }
    mod_morph_state = !mod_morph_state;
}

bool get_mod_morph_state(void) {
    return mod_morph_state;
}

oneshot_state* get_mod_morph_oneshot_state(void) {
    return &mm_state;
}

void update_mod_morph_oneshot(uint16_t keycode, keyrecord_t *record) {
    // Get the current modifier based on morph state
    uint16_t current_mod = mod_morph_state ? OS_LGUI : OS_LCTL;

    // Use the oneshot update logic
    update_oneshot(&mm_state, current_mod, MM_GUICTRL, keycode, record);
}
