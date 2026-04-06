// RADIAL Layout Key Definitions
// This file maps abstract key positions (_XX_) to actual RADIAL keycodes
// RADIAL is an optimized layout derived from FOCAL, designed for English typing efficiency
// Named "Radial" - relating to rays from a focal point

// RADIAL places alternative symbols at positions 23, 30, 32, 33, 34
#ifdef XC_ALT_BASE_SYMBOLS
    #define _30_ WC_CORNER(AS_MINS)  // - → /
    #define _32_ AS_COMM             // , → ?
    #define _33_ AS_DOT              // . → !
    #define _34_ AS_QUOT             // ' → "
#else
    #define _30_ WC_CORNER(KC_SCLN)  // ; / :
    #define _32_ KC_COMM             // , / <
    #define _33_ KC_DOT              // . / >
    #define _34_ KC_QUOT             // ' / "
#endif

#ifdef XC_WEAK_CORNERS
    #define WC_OUT_01 KC_X
    #define WC_OUT_10 KC_Y
    #define WC_OUT_29 KC_J
    #define WC_OUT_30 KC_SCLN
#endif

/*
 * RADIAL Layout - Actual Keycodes
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  X  │  W  │  H  │  M  │  Q  │       │  K  │  P  │  O  │  U  │  Y  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  C  │  R  │  N  │  S  │  V  │       │  G  │  T  │  E  │  A  │  I  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  Z  │  B  │  F  │  L  │  J  │       │  ;  │  D  │  ,  │  .  │  '  │     │
 * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
 *                     ┌─────┐                           ┌─────┐
 *                     │     ├─────┐               ┌─────┤     │
 *                     └─────┤     ├─────┐   ┌─────┤     ├─────┘
 *                           └─────┤     │   │     ├─────┘
 *                                 └─────┘   └─────┘
 */

// Row 0 (top row, columns 0-11)
#define _00_ KC_NO
#define _01_ WC_CORNER(KC_X)
#define _02_ KC_W
#define _03_ KC_H
#define _04_ KC_M
#define _05_ KC_Q
#define _06_ KC_K
#define _07_ KC_P
#define _08_ KC_O
#define _09_ KC_U
#define _10_ WC_CORNER(KC_Y)
#define _11_ KC_NO

// Row 1 (home row, columns 12-23)
// Position 23 is defined at top of file (alt symbols feature)
#define _12_ KC_NO
#define _13_ KC_C
#define _14_ KC_R
#define _15_ KC_N
#define _16_ KC_S
#define _17_ KC_V
#define _18_ KC_G
#define _19_ KC_T
#define _20_ KC_E
#define _21_ KC_A
#define _22_ KC_I
#define _23_ KC_NO

// Row 2 (bottom row, columns 24-35)
// Positions 30, 32, 33, 34 are defined at top of file (alt symbols feature)
#define _24_ KC_NO
#define _25_ KC_Z
#define _26_ KC_B
#define _27_ KC_F
#define _28_ KC_L
#define _29_ WC_CORNER(KC_J)
// _30_ defined above
#define _31_ KC_D
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
