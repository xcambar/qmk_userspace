// QWERTY Layout Key Definitions
// This file maps abstract key positions (_XX_) to actual QWERTY keycodes
// This is the STANDARD QWERTY layout for a 42-key split keyboard

/*
 * QWERTY Layout - Actual Keycodes
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ Tab │  Q  │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │ Bsp │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ Ctl │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  ;  │  '  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ Sft │  Z  │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │ Sft │
 * └─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┘
 *                     ┌─────┐                           ┌─────┐
 *                     │ Gui ├─────┐               ┌─────┤ Alt │
 *                     └─────┤ Bsp ├─────┐   ┌─────┤ Ent ├─────┘
 *                           └─────┤ Spc │   │ Spc ├─────┘
 *                                 └─────┘   └─────┘
 */

// Row 0 (top row, columns 0-11)
#define _00_ KC_TAB
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
#define _11_ KC_BSPC

// Row 1 (home row, columns 12-23)
#define _12_ KC_LCTL
#define _13_ KC_A
#define _14_ KC_S
#define _15_ KC_D
#define _16_ KC_F
#define _17_ KC_G
#define _18_ KC_H
#define _19_ KC_J
#define _20_ KC_K
#define _21_ KC_L
#define _22_ KC_SCLN
#define _23_ KC_QUOT

// Row 2 (bottom row, columns 24-35)
#define _24_ KC_LSFT
#define _25_ KC_Z
#define _26_ KC_X
#define _27_ KC_C
#define _28_ KC_V
#define _29_ KC_B
#define _30_ KC_N
#define _31_ KC_M
#define _32_ KC_COMM
#define _33_ KC_DOT
#define _34_ KC_SLSH
#define _35_ KC_RSFT

// Thumb cluster (keys 36-41)
#define _36_ KC_LGUI
#define _37_ KC_BSPC
#define _38_ KC_SPC
#define _39_ KC_SPC
#define _40_ KC_ENT
#define _41_ KC_RALT
