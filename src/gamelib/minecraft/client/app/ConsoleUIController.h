#pragma once

namespace mc {
    class SoundEvent;

    class ConsoleUIController {
    public:
        static ConsoleUIController* getInstance();

        void PlayUISFX(SoundEvent* sound);
    };
}