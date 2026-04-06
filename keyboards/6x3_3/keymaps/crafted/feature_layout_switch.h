// Layout macro switch helper — intentionally has NO #pragma once.
// Re-include this file to switch the active _XX_ macro set.
//
// Usage:
//   #define XC_LAYOUT_SWITCH_TARGET graphite   // or XC_LAYOUT / XC_SECONDARY_LAYOUT
//   #include "feature_layout_switch.h"
// After: _XX_ (and WC_OUT_* when XC_WEAK_CORNERS) reflect the target layout.

// Step 1: Clear all position macros
#undef _00_
#undef _01_
#undef _02_
#undef _03_
#undef _04_
#undef _05_
#undef _06_
#undef _07_
#undef _08_
#undef _09_
#undef _10_
#undef _11_
#undef _12_
#undef _13_
#undef _14_
#undef _15_
#undef _16_
#undef _17_
#undef _18_
#undef _19_
#undef _20_
#undef _21_
#undef _22_
#undef _23_
#undef _24_
#undef _25_
#undef _26_
#undef _27_
#undef _28_
#undef _29_
#undef _30_
#undef _31_
#undef _32_
#undef _33_
#undef _34_
#undef _35_
#undef _36_
#undef _37_
#undef _38_
#undef _39_
#undef _40_
#undef _41_

// Step 2: Clear WC_OUT_* (layout files define these when XC_WEAK_CORNERS is set)
#undef WC_OUT_01
#undef WC_OUT_10
#undef WC_OUT_29
#undef WC_OUT_30

// Step 3: Include the target layout (re-defines _XX_ and WC_OUT_*)
// LAYOUT_FILE is defined in feature_base_layer.h; identical redefinition is safe
#define _LAYOUT_FILE_x(n) _LAYOUT_FILE_##n
#define LAYOUT_FILE(n)    _LAYOUT_FILE_x(n)
#include LAYOUT_FILE(XC_LAYOUT_SWITCH_TARGET)

#undef XC_LAYOUT_SWITCH_TARGET
