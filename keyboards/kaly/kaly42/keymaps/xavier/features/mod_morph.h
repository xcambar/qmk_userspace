#pragma once

#include QMK_KEYBOARD_H
#include "oneshot.h"

// Update the morphing oneshot modifier (called from process_record_user)
void update_mod_morph_oneshot(uint16_t trigger, uint16_t keycode, keyrecord_t *record);
