#pragma once

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MIDI_BASIC
