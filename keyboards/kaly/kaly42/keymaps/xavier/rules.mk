###################
# QMK OPTIONS
#

COMBO_ENABLE = yes
# Adjust combo timing if needed (default is 50ms)
# COMBO_TERM = 50

LAYER_LOCK_ENABLE = yes
LEADER_ENABLE = yes



###################
# Custom options
#

# Layout selection: qwerty or gallium
XC_LAYOUT ?= qwerty

XC_HRM = yes
XC_HRM_LAYER = no



###################
# This manipulates the options
#

# Pass the layout name to the preprocessor (uppercase for macro matching)
OPT_DEFS += -DXC_LAYOUT=$(shell echo $(XC_LAYOUT) | tr '[:lower:]' '[:upper:]')

ifeq ($(strip $(XC_HRM)), yes)
    OPT_DEFS += -DXC_HRM
endif

ifeq ($(strip $(XC_HRM_LAYER)), yes)
    OPT_DEFS += -DXC_HRM_LAYER
endif
