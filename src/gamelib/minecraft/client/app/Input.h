#pragma once

#define MC_BUTTON            *(unsigned int *) 0x102EFA64

#define MC_PAD_A             MC_BUTTON & 0x8000
#define MC_PAD_B             MC_BUTTON & 0x4000
#define MC_PAD_X             MC_BUTTON & 0x2000
#define MC_PAD_Y             MC_BUTTON & 0x1000
#define MC_PAD_DPAD_LEFT     MC_BUTTON & 0x800
#define MC_PAD_DPAD_RIGHT    MC_BUTTON & 0x400
#define MC_PAD_DPAD_UP       MC_BUTTON & 0x200
#define MC_PAD_DPAD_DOWN     MC_BUTTON & 0x100
#define MC_PAD_ZL            MC_BUTTON & 0x80
#define MC_PAD_ZR            MC_BUTTON & 0x40
#define MC_PAD_L             MC_BUTTON & 0x20
#define MC_PAD_R             MC_BUTTON & 0x10
#define MC_PAD_PLUS          MC_BUTTON & 0x8
#define MC_PAD_MINUS         MC_BUTTON & 0x4
#define MC_PAD_HOME          MC_BUTTON & 0x2
#define MC_PAD_SYNC          MC_BUTTON & 0x1
#define MC_PAD_STICK_R       MC_BUTTON & 0x20000
#define MC_PAD_STICK_L       MC_BUTTON & 0x40000
#define MC_PAD_TV            MC_BUTTON & 0x10000

#define MC_PAD_STICK_R_LEFT  MC_BUTTON & 0x4000000
#define MC_PAD_STICK_R_RIGHT MC_BUTTON & 0x2000000
#define MC_PAD_STICK_R_UP    MC_BUTTON & 0x1000000
#define MC_PAD_STICK_R_DOWN  MC_BUTTON & 0x0800000

#define PAD_STICK_L_LEFT     MC_BUTTON & 0x40000000
#define PAD_STICK_L_RIGHT    MC_BUTTON & 0x20000000
#define PAD_STICK_L_UP       MC_BUTTON & 0x10000000
#define PAD_STICK_L_DOWN     MC_BUTTON & 0x8000000

#define MC_BUTTON_PRESSED(CONDITION, BLOCK)                                                                                                                              \
    do {                                                                                                                                                                 \
        static bool buttonFlag = false;                                                                                                                                  \
        if (!buttonFlag && CONDITION) {                                                                                                                                  \
            BLOCK                                                                                                                                                        \
            buttonFlag = true;                                                                                                                                           \
        } else if (buttonFlag && !(CONDITION))                                                                                                                           \
            buttonFlag = false;                                                                                                                                          \
    } while (0)

#define MC_BUTTON_PRESSED_TIMES(CONDITION, REQUIRED_PRESSES, FRAME_WINDOW, BLOCK)                                                                                        \
    do {                                                                                                                                                                 \
        static int pressCount   = 0;                                                                                                                                     \
        static int frameCounter = 0;                                                                                                                                     \
        static int lastTrigger  = -9999;                                                                                                                                 \
        static bool prevPressed = false;                                                                                                                                 \
                                                                                                                                                                         \
        bool currentlyPressed = (CONDITION);                                                                                                                             \
        frameCounter++;                                                                                                                                                  \
                                                                                                                                                                         \
        if (currentlyPressed && !prevPressed) {                                                                                                                          \
            if ((frameCounter - lastTrigger) <= (FRAME_WINDOW)) pressCount++;                                                                                            \
            else                                                                                                                                                         \
                pressCount = 1;                                                                                                                                          \
                                                                                                                                                                         \
            lastTrigger = frameCounter;                                                                                                                                  \
        }                                                                                                                                                                \
                                                                                                                                                                         \
        if (pressCount >= (REQUIRED_PRESSES)) {                                                                                                                          \
            pressCount = 0;                                                                                                                                              \
            BLOCK                                                                                                                                                        \
        }                                                                                                                                                                \
                                                                                                                                                                         \
        prevPressed = currentlyPressed;                                                                                                                                  \
    } while (0)
