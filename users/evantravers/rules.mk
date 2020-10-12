SRC += evantravers.c

TAP_DANCE_ENABLE = yes

ifeq ($(strip $(PROTOCOL)), VUSB)
  NKRO_ENABLE       = no
else
  NKRO_ENABLE       = yes
endif

BOOTMAGIC_ENABLE  = no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE   = yes # Mouse keys(+4700)
EXTRAKEY_ENABLE   = yes # Audio control and System control(+450)
CONSOLE_ENABLE    = no  # Console for debug(+400)
COMMAND_ENABLE    = no  # Commands for debug and configuration
MACROS_ENABLED    = no
