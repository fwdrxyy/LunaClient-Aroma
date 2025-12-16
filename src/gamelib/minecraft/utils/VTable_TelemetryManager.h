#pragma once

#include <utils/Types.h>

#include "VTable.h"

namespace mc {
    class TelemetryManager;

    class VTable_TelemetryManager : public VTable {
    public:
        MC_VFUNC(void, TelemetryManager, __dt);
        MC_VFUNC(void, TelemetryManager, Init);
        MC_VFUNC(void, TelemetryManager, Tick);
        MC_VFUNC(void, TelemetryManager, Flush);
        MC_VFUNC(void, TelemetryManager, RecordPlayerSessionStart);
        MC_VFUNC(void, TelemetryManager, RecordPlayerSessionExit);
        MC_VFUNC(void, TelemetryManager, RecordHeartBeat);
        MC_VFUNC(void, TelemetryManager, RecordLevelStart);
        MC_VFUNC(void, TelemetryManager, RecordLevelExit);
        MC_VFUNC(void, TelemetryManager, RecordLevelSaveOrCheckpoint);
        MC_VFUNC(void, TelemetryManager, RecordLevelResume);
        MC_VFUNC(void, TelemetryManager, RecordPauseOrInactive);
        MC_VFUNC(void, TelemetryManager, RecordUnpauseOrActive);
        MC_VFUNC(void, TelemetryManager, RecordMenuShown, uint32_t, uint32_t, uint32_t);
        MC_VFUNC(void, TelemetryManager, RecordAchievementUnlocked);
        MC_VFUNC(void, TelemetryManager, RecordMediaShareUpload);
        MC_VFUNC(void, TelemetryManager, RecordUpsellPresented);
        MC_VFUNC(void, TelemetryManager, RecordUpsellResponded);
    };
} // namespace mc