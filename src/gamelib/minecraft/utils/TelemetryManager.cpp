#include "TelemetryManager.h"

namespace mc {
    TelemetryManager* TelemetryManager::getManager() {
        return *(TelemetryManager**) 0x104f6970;
    }
}