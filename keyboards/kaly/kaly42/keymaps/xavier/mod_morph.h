#pragma once

#include QMK_KEYBOARD_H
#include "oneshot.h"

// Custom keycode that sends either GUI or Ctrl based on a toggle state
enum mod_morph_keycodes {
    MM_GUICTRL = SAFE_RANGE + 100,  // Morphing oneshot modifier key
};

// Toggle the modifier morph state
void toggle_mod_morph(void);

// Get the current morph state (true = GUI, false = Ctrl)
bool get_mod_morph_state(void);

// Get the oneshot state for the morphing modifier
oneshot_state* get_mod_morph_oneshot_state(void);

// Update the morphing oneshot modifier (called from process_record_user)
void update_mod_morph_oneshot(uint16_t keycode, keyrecord_t *record);
