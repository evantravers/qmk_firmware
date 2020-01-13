#pragma once

// TAPPING_TERM
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif

#if defined(KEYBOARD_planck_rev6)
#    define TAPPING_TERM 185
#else
#    define TAPPING_TERM 135
#endif

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define FORCE_NKRO
#define RGBLIGHT_SLEEP

#define FORCE_NKRO
