#pragma once

// TAPPING_TERM
#ifdef TAPPING_TERM
#  undef TAPPING_TERM
#  define TAPPING_TERM 100
#endif

// miryoku style
#define TAPPING_FORCE_HOLD

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define FORCE_NKRO
#define RGBLIGHT_SLEEP

#define FORCE_NKRO

#define USB_POLLING_INTERVAL_MS 1

#ifndef USB_MAX_POWER_CONSUMPTION
#  define USB_MAX_POWER_CONSUMPTION 100
#endif
