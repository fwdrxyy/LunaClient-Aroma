#include "ConsoleUIController.h"

#include <Link/Link.h>

namespace mc {
    ConsoleUIController* ConsoleUIController::getInstance() {
        return (ConsoleUIController*) 0x104F73E0;
    }

    void ConsoleUIController::PlayUISFX(SoundEvent* sound) {
        Link::Func<void, 0x02DA7918, ConsoleUIController*, SoundEvent*>()(this, sound);
    }
}