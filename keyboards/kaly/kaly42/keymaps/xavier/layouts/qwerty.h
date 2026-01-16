// QWERTY Layout Key Definitions
// This file maps abstract key positions (_XX_) to actual QWERTY keycodes
// This is the STANDARD QWERTY layout for a 42-key split keyboard

// QWERTY places alternative symbols at positions 22, 23, 32, 33, 34
#ifdef XC_ALT_BASE_SYMBOLS
    #define _22_ AS_QUOT             // ' → "
    #define _23_ AS_UNDS             // _ → |
    #define _32_ AS_COMM             // , → ?
    #define _33_ AS_DOT              // . → !
    #define _34_ AS_MINS             // - → /
#else
    #define _22_ KC_SCLN             // ; / :
    #define _23_ KC_QUOT             // ' / "
    #define _32_ KC_COMM             // , / <
    #define _33_ KC_DOT              // . / >
    #define _34_ KC_SLSH             // / / ?
#endif

/*
 * QWERTY Layout - Actual Keycodes
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  Q  │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  ;  │  '  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  Z  │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │     │
 * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
 *                     ┌─────┐                           ┌─────┐
 *                     │     ├─────┐               ┌─────┤     │
 *                     └─────┤     ├─────┐   ┌─────┤     ├─────┘
 *                           └─────┤     │   │     ├─────┘
 *                                 └─────┘   └─────┘
 */

// Row 0 (top row, columns 0-11)
#define _00_ KC_NO
#define _01_ KC_Q
#define _02_ KC_W
#define _03_ KC_E
#define _04_ KC_R
#define _05_ KC_T
#define _06_ KC_Y
#define _07_ KC_U
#define _08_ KC_I
#define _09_ KC_O
#define _10_ KC_P
#define _11_ KC_NO

// Row 1 (home row, columns 12-23)
// Positions 22, 23 are defined at top of file (alt symbols feature)
#define _12_ KC_NO
#define _13_ KC_A
#define _14_ KC_S
#define _15_ KC_D
#define _16_ KC_F
#define _17_ KC_G
#define _18_ KC_H
#define _19_ KC_J
#define _20_ KC_K
#define _21_ KC_L
// _22_ defined above
// _23_ defined above

// Row 2 (bottom row, columns 24-35)
// Positions 32, 33, 34 are defined at top of file (alt symbols feature)
#define _24_ KC_NO
#define _25_ KC_Z
#define _26_ KC_X
#define _27_ KC_C
#define _28_ KC_V
#define _29_ KC_B
#define _30_ KC_N
#define _31_ KC_M
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
