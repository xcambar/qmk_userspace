// Layout selection based on rules.mk configuration
// XC_LAYOUT is passed from rules.mk (e.g., -DXC_LAYOUT=QWERTY)
// Default value is set in rules.mk as "qwerty" and converted to uppercase

// Define layout constants for comparison
#define LAYOUT_QWERTY 1
#define LAYOUT_GALLIUM 2
#define LAYOUT_FOCAL 3
#define LAYOUT_GRAPHITE 4

// Convert XC_LAYOUT token to a numeric constant
#define QWERTY LAYOUT_QWERTY
#define GALLIUM LAYOUT_GALLIUM
#define FOCAL LAYOUT_FOCAL
#define GRAPHITE LAYOUT_GRAPHITE

#if XC_LAYOUT == LAYOUT_QWERTY
    #include "layout_qwerty.h"
#elif XC_LAYOUT == LAYOUT_GALLIUM
    #include "layout_gallium.h"
#elif XC_LAYOUT == LAYOUT_FOCAL
    #include "layout_focal.h"
#elif XC_LAYOUT == LAYOUT_GRAPHITE
    #include "layout_graphite.h"
#else
    #error "Unknown layout specified"
#endif

