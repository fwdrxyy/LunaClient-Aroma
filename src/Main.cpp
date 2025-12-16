#include <wups.h>

#include <Globals.h>
#include <gamehax/GameHax.h>
#include <utils/Logger.h>
#include <utils/PluginInfo.h>

#include <coreinit/title.h>

WUPS_PLUGIN_NAME("LunaClient");
WUPS_PLUGIN_DESCRIPTION("");
WUPS_PLUGIN_VERSION("v0.1");
WUPS_PLUGIN_AUTHOR("@fwdrxyy_ / 657462 & @c0ldcut1e / jet2holiday");
WUPS_PLUGIN_LICENSE("EPL v2.0");

WUPS_USE_WUT_DEVOPTAB();
WUPS_USE_STORAGE("luna");

INITIALIZE_PLUGIN() {
    initLogging();
    DEBUG_FUNCTION_LINE("Hello from %s o/", getPluginName());
}

DEINITIALIZE_PLUGIN() {
    DEBUG_FUNCTION_LINE("Goodbye from %s o/", getPluginName());
    deinitLogging();
}

ON_APPLICATION_START() {
    gIsMinecraft = false;

    uint64_t titleId = OSGetTitleID();
    if (titleId == 0x00050000101DBE00 || titleId == 0x00050000101D9D00 || titleId == 0x00050000101D7500) {
        gIsMinecraft = true;

        DEBUG_FUNCTION_LINE("GameHax_Start()...");
        GameHax_Start();
    }
}
