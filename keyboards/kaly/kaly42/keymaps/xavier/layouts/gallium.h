// Gallium Layout Key Definitions
// This file maps abstract key positions (_XX_) to actual Gallium keycodes
// Gallium is an optimized layout designed for English typing efficiency

// GALLIUM places alternative symbols at positions 10, 23, 32, 33, 34
#ifdef XC_ALT_BASE_SYMBOLS
    #define _10_ AS_UNDS             // _ → |
    #define _23_ AS_QUOT             // ' → "
    #define _32_ AS_COMM             // , → ?
    #define _33_ AS_DOT              // . → !
    #define _34_ AS_MINS             // - → /
#else
    #define _10_ KC_COMM             // , (default)
    #define _23_ KC_QUOT             // ' (default)
    #define _32_ KC_SCLN             // ; / :
    #define _33_ KC_DOT              // . / >
    #define _34_ KC_SLSH             // / / ?
#endif

/*
 * Gallium Layout - Actual Keycodes
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  B  │  L  │  D  │  C  │  V  │       │  J  │  Y  │  O  │  U  │  ,  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  N  │  R  │  T  │  S  │  G  │       │  P  │  H  │  A  │  E  │  I  │  '  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  X  │  Q  │  M  │  W  │  Z  │       │  K  │  F  │  ;  │  .  │  /  │     │
 * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
 *                     ┌─────┐                           ┌─────┐
 *                     │     ├─────┐               ┌─────┤     │
 *                     └─────┤     ├─────┐   ┌─────┤     ├─────┘
 *                           └─────┤     │   │     ├─────┘
 *                                 └─────┘   └─────┘
 */

// Row 0 (top row, columns 0-11)
// Position 10 is defined at top of file (alt symbols feature)
#define _00_ KC_NO
#define _01_ KC_B
#define _02_ KC_L
#define _03_ KC_D
#define _04_ KC_C
#define _05_ KC_V
#define _06_ KC_J
#define _07_ KC_Y
#define _08_ KC_O
#define _09_ KC_U
// _10_ defined above
#define _11_ KC_NO

// Row 1 (home row, columns 12-23)
// Position 23 is defined at top of file (alt symbols feature)
#define _12_ KC_NO
#define _13_ KC_N
#define _14_ KC_R
#define _15_ KC_T
#define _16_ KC_S
#define _17_ KC_G
#define _18_ KC_P
#define _19_ KC_H
#define _20_ KC_A
#define _21_ KC_E
#define _22_ KC_I
// _23_ defined above

// Row 2 (bottom row, columns 24-35)
// Positions 32, 33, 34 are defined at top of file (alt symbols feature)
#define _24_ KC_NO
#define _25_ KC_X
#define _26_ KC_Q
#define _27_ KC_M
#define _28_ KC_W
#define _29_ KC_Z
#define _30_ KC_K
#define _31_ KC_F
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
