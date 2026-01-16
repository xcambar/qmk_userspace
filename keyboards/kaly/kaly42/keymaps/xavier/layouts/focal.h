// FOCAL Layout Key Definitions
// This file maps abstract key positions (_XX_) to actual FOCAL keycodes
// FOCAL is an optimized layout designed for English typing efficiency
// Source: https://github.com/Keyhabit/Focal-keyboard-layout

// FOCAL places alternative symbols at positions 23, 30, 32, 33, 34
#ifdef XC_ALT_BASE_SYMBOLS
    #define _23_ ALT_SYM5            // _ / |
    #define _30_ ALT_SYM1            // ' / "
    #define _32_ ALT_SYM2            // , / .
    #define _33_ ALT_SYM3            // ? / !
    #define _34_ ALT_SYM4            // - / /
#else
    #define _23_ KC_SLSH             // / / ? (default)
    #define _30_ KC_QUOT             // ' / " (default)
    #define _32_ KC_DOT              // . / >
    #define _33_ KC_SCLN             // ; / :
    #define _34_ KC_COMM             // , / <
#endif

/*
 * FOCAL Layout - Actual Keycodes
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  V  │  L  │  H  │  G  │  K  │       │  Q  │  F  │  O  │  U  │  J  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  S  │  R  │  N  │  T  │  B  │       │  Y  │  C  │  A  │  E  │  I  │  /  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  Z  │  X  │  M  │  D  │  P  │       │  '  │  W  │  .  │  ;  │  ,  │     │
 * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
 *                     ┌─────┐                           ┌─────┐
 *                     │     ├─────┐               ┌─────┤     │
 *                     └─────┤     ├─────┐   ┌─────┤     ├─────┘
 *                           └─────┤     │   │     ├─────┘
 *                                 └─────┘   └─────┘
 */

// Row 0 (top row, columns 0-11)
#define _00_ KC_NO
#define _01_ KC_V
#define _02_ KC_L
#define _03_ KC_H
#define _04_ KC_G
#define _05_ KC_K
#define _06_ KC_Q
#define _07_ KC_F
#define _08_ KC_O
#define _09_ KC_U
#define _10_ KC_J
#define _11_ KC_NO

// Row 1 (home row, columns 12-23)
// Position 23 is defined at top of file (alt symbols feature)
#define _12_ KC_NO
#define _13_ KC_S
#define _14_ KC_R
#define _15_ KC_N
#define _16_ KC_T
#define _17_ KC_B
#define _18_ KC_Y
#define _19_ KC_C
#define _20_ KC_A
#define _21_ KC_E
#define _22_ KC_I
// _23_ defined above

// Row 2 (bottom row, columns 24-35)
// Positions 30, 32, 33, 34 are defined at top of file (alt symbols feature)
#define _24_ KC_NO
#define _25_ KC_Z
#define _26_ KC_X
#define _27_ KC_M
#define _28_ KC_D
#define _29_ KC_P
// _30_ defined above
#define _31_ KC_W
// _32_ defined above
// _33_ defined above
// _34_ defined above
#define _35_ KC_NO

// Thumb cluster (keys 36-41)
#define _36_ KC_NO
#define _37_ KC_NO
#define _38_ KC_NO
#define _39_ KC_NO
#define _40_ KC_NO
#define _41_ KC_NO
