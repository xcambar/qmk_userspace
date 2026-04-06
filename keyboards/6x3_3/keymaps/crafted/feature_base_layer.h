// XC_LAYOUT is a lowercase layout name token passed from rules.mk (e.g., qwerty, graphite)

// Display name lookup (token → title-case string)
#define _LAYOUT_NAME_qwerty   "Qwerty"
#define _LAYOUT_NAME_gallium  "Gallium"
#define _LAYOUT_NAME_focal    "Focal"
#define _LAYOUT_NAME_graphite "Graphite"
#define _LAYOUT_NAME_gallium_east "Gallium East"
#define _LAYOUT_NAME_x(n)    _LAYOUT_NAME_##n
#define LAYOUT_NAME(n)        _LAYOUT_NAME_x(n)

// Include path lookup (token → quoted path string)
#define _LAYOUT_FILE_qwerty   "layouts/qwerty.h"
#define _LAYOUT_FILE_gallium  "layouts/gallium.h"
#define _LAYOUT_FILE_focal    "layouts/focal.h"
#define _LAYOUT_FILE_graphite "layouts/graphite.h"
#define _LAYOUT_FILE_gallium_east "layouts/gallium_east.h"
#define _LAYOUT_FILE_x(n)    _LAYOUT_FILE_##n
#define LAYOUT_FILE(n)        _LAYOUT_FILE_x(n)

// Secondary layout default — override in rules.mk with XC_SECONDARY_LAYOUT=gallium_east
#ifndef XC_SECONDARY_LAYOUT
    #define XC_SECONDARY_LAYOUT gallium_east
#endif

#define XC_LAYOUT_NAME           LAYOUT_NAME(XC_LAYOUT)
#define XC_SECONDARY_LAYOUT_NAME LAYOUT_NAME(XC_SECONDARY_LAYOUT)

#include LAYOUT_FILE(XC_LAYOUT)
