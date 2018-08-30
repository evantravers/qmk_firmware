TAP_DANCE_ENABLE = yes

ifeq ($(strip $(PROTOCOL)), VUSB)
  NKRO_ENABLE       = no
else
  NKRO_ENABLE       = yes
endif
