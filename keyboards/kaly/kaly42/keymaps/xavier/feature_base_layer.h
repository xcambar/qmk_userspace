// Layout selection based on rules.mk configuration
// XC_LAYOUT is passed from rules.mk (e.g., -DXC_LAYOUT=QWERTY)
// Default value is set in rules.mk as "qwerty" and converted to uppercase

// Define layout constants for comparison
#define LAYOUT_QWERTY 1
#define LAYOUT_GALLIUM 2
#define LAYOUT_FOCAL 3
#define LAYOUT_GRAPHITE 4
#define LAYOUT_RADIAL 5

// Convert XC_LAYOUT token to a numeric constant
#define QWERTY LAYOUT_QWERTY
#define GALLIUM LAYOUT_GALLIUM
#define FOCAL LAYOUT_FOCAL
#define GRAPHITE LAYOUT_GRAPHITE
#define RADIAL LAYOUT_RADIAL

// Human-readable name for the primary layout
#if XC_LAYOUT == LAYOUT_QWERTY
    #define XC_LAYOUT_NAME "Qwerty"
#elif XC_LAYOUT == LAYOUT_GALLIUM
    #define XC_LAYOUT_NAME "Gallium"
#elif XC_LAYOUT == LAYOUT_FOCAL
    #define XC_LAYOUT_NAME "Focal"
#elif XC_LAYOUT == LAYOUT_GRAPHITE
    #define XC_LAYOUT_NAME "Graphite"
#elif XC_LAYOUT == LAYOUT_RADIAL
    #define XC_LAYOUT_NAME "Radial"
#else
    #define XC_LAYOUT_NAME "Unknown"
#endif

// Secondary (alternate base) layout — override in rules.mk with -DXC_SECONDARY_LAYOUT=RADIAL
#ifndef XC_SECONDARY_LAYOUT
    #define XC_SECONDARY_LAYOUT LAYOUT_GRAPHITE
#endif

// Human-readable name for the secondary layout (used in COMBO_PRINT_LAYOUT)
#if XC_SECONDARY_LAYOUT == LAYOUT_QWERTY
    #define XC_SECONDARY_LAYOUT_NAME "Qwerty"
#elif XC_SECONDARY_LAYOUT == LAYOUT_GALLIUM
    #define XC_SECONDARY_LAYOUT_NAME "Gallium"
#elif XC_SECONDARY_LAYOUT == LAYOUT_FOCAL
    #define XC_SECONDARY_LAYOUT_NAME "Focal"
#elif XC_SECONDARY_LAYOUT == LAYOUT_GRAPHITE
    #define XC_SECONDARY_LAYOUT_NAME "Graphite"
#elif XC_SECONDARY_LAYOUT == LAYOUT_RADIAL
    #define XC_SECONDARY_LAYOUT_NAME "Radial"
#else
    #define XC_SECONDARY_LAYOUT_NAME "Unknown"
#endif

#if XC_LAYOUT == LAYOUT_QWERTY
    #include "layouts/qwerty.h"
#elif XC_LAYOUT == LAYOUT_GALLIUM
    #include "layouts/gallium.h"
#elif XC_LAYOUT == LAYOUT_FOCAL
    #include "layouts/focal.h"
#elif XC_LAYOUT == LAYOUT_GRAPHITE
    #include "layouts/graphite.h"
#elif XC_LAYOUT == LAYOUT_RADIAL
    #include "layouts/radial.h"
#else
    #error "Unknown layout specified"
#endif

