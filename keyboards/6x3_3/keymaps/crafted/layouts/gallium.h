// Gallium v2 Layout Key Definitions
// This file maps abstract key positions (_XX_) to actual Gallium v2 keycodes
// Gallium v2 (Rowstag) is optimized for row-staggered keyboards
// https://github.com/GalileoBlues/Gallium

// GALLIUM places alternative symbols at positions 10, 23, 32, 33, 34
#ifdef XC_ALT_BASE_SYMBOLS
    #define _10_ WC_CORNER(AS_UNDS)  // _ → |
    #define _23_ AS_QUOT             // ' → "
    #define _32_ AS_COMM             // , → ?
    #define _33_ AS_DOT              // . → !
    #define _34_ AS_MINS             // - → /
#else
    #define _10_ WC_CORNER(KC_COMM)  // , (default)
    #define _23_ KC_QUOT             // ' (default)
    #define _32_ KC_SCLN             // ; / :
    #define _33_ KC_DOT              // . / >
    #define _34_ KC_SLSH             // / / ?
#endif

#ifdef XC_WEAK_CORNERS
    #define WC_OUT_01 KC_B
    #define WC_OUT_10 KC_COMM
    #define WC_OUT_29 KC_Z
    #define WC_OUT_30 KC_K
#endif

/*
 * Gallium v2 Layout - Actual Keycodes
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  B  │  L  │  D  │  C  │  V  │       │  J  │  F  │  O  │  U  │  ,  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  N  │  R  │  T  │  S  │  G  │       │  Y  │  H  │  A  │  E  │  I  │  '  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  X  │  Q  │  M  │  W  │  Z  │       │  K  │  P  │  ;  │  .  │  /  │     │
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
#define _01_ WC_CORNER(KC_B)
#define _02_ KC_L
#define _03_ KC_D
#define _04_ KC_C
#define _05_ KC_V
#define _06_ KC_J
#define _07_ KC_F
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
#define _18_ KC_Y
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
#define _29_ WC_CORNER(KC_Z)
#define _30_ WC_CORNER(KC_K)
#define _31_ KC_P
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
