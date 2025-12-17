COMBO_ENABLE = yes
# Adjust combo timing if needed (default is 50ms)
# COMBO_TERM = 50

LAYER_LOCK_ENABLE = yes
LEADER_ENABLE = yes

XC_HRM = no
XC_HRM_LAYER = no

ifeq ($(strip $(XC_HRM)), yes)
    OPT_DEFS += -DXC_HRM
endif

ifeq ($(strip $(XC_HRM_LAYER)), yes)
    OPT_DEFS += -DXC_HRM_LAYER
endif
