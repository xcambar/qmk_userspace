// HRM Layer (Layer 1) - Optional Home Row Mods
// This layer is only included when XC_HRM_LAYER is enabled in rules.mk

     /*
      * Layer 1 - Home row mods
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │Alt│Ctl│Sft│   │       │   │Sft│Ctl│Alt│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   |   |   |   |   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │///├───┐           ┌───┤ACC│
      *               └───┤///├───┐   ┌───┤SYM├───┘
      *                   └───┤   │   │NUM├───┘
      *                       └───┘   └───┘
      */
    [HRM] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                              KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,            TO(3),   TO(4),   TO(5)
    ),
