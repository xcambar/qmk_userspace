###################
# QMK OPTIONS
#

COMBO_ENABLE = yes
# Adjust combo timing if needed (default is 50ms)
# COMBO_TERM = 50

LAYER_LOCK_ENABLE = yes
LEADER_ENABLE = yes
#AUTO_SHIFT_ENABLE = yes

# Callum-style oneshot modifiers and swapper
SRC += oneshot.c
SRC += swapper.c
SRC += mod_morph.c


###################
# Custom options
#

# Layout selection: qwerty, gallium, focal, or graphite
XC_LAYOUT ?= qwerty

XC_WEAK_CORNERS = yes



###################
# This manipulates the options
#

# Pass the layout name to the preprocessor (uppercase for macro matching)
OPT_DEFS += -DXC_LAYOUT=$(shell echo $(XC_LAYOUT) | tr '[:lower:]' '[:upper:]')

ifeq ($(strip $(XC_WEAK_CORNERS)), yes)
    OPT_DEFS += -DXC_WEAK_CORNERS
endif
