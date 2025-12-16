#include "GameHax.h"

#include <memory>

#include <utils/Logger.h>
#include <utils/xUtils.h>

#include <Link/FuncPatcher.h>
#include <minecraft/Minecraft.h>
#include <yuki/DrawHelper.h>

using namespace mc;

#include "luna/LunaCategory.h"
#include "luna/LunaSlider.h"
#include "luna/LunaToggle.h"
#include "luna/client/LunaCategoryClient.h"
#include "luna/misc/LunaCategoryMisc.h"
#include "luna/movement/LunaCategoryMovement.h"
#include "luna/render/LunaCategoryRender.h"
#include "luna/world/LunaCategoryWorld.h"

int32_t selectedIndex = 0;
int32_t inCategory    = -1;
xVector<std::unique_ptr<LunaCategory>> categories;

bool menuOpen = false;

void buttonChecks() {
    bool menuOpenButtons                = MC_PAD_L && MC_PAD_R;
    bool scrollDownButtons              = MC_PAD_DPAD_DOWN;
    bool scrollUpButtons                = MC_PAD_DPAD_UP;
    bool outOfCategoryButtons           = MC_PAD_ZL;
    bool pressModuleGoInCategoryButtons = MC_PAD_ZR;
    bool sliderDecreaseButtons          = MC_PAD_DPAD_LEFT;
    bool sliderIncreaseButtons          = MC_PAD_DPAD_RIGHT;

    MC_BUTTON_PRESSED(menuOpenButtons, { menuOpen = !menuOpen; });

    if (menuOpen) {
        MC_BUTTON_PRESSED(scrollDownButtons, {
            if (inCategory == -1) {
                if ((int32_t) categories.size() == 0) return;
                selectedIndex++;
                if (selectedIndex >= (int32_t) categories.size()) selectedIndex = 0;
            } else {
                if ((int32_t) categories[inCategory]->modules.size() == 0) return;
                categories[inCategory]->index++;
                if (categories[inCategory]->index >= (int32_t) categories[inCategory]->modules.size()) categories[inCategory]->index = 0;
            }
        });

        MC_BUTTON_PRESSED(scrollUpButtons, {
            if (inCategory == -1) {
                if ((int32_t) categories.size() == 0) return;
                if (selectedIndex == 0) selectedIndex = (int32_t) categories.size() - 1;
                else
                    selectedIndex--;
            } else {
                if ((int32_t) categories[inCategory]->modules.size() == 0) return;
                if (categories[inCategory]->index == 0) categories[inCategory]->index = (int32_t) categories[inCategory]->modules.size() - 1;
                else
                    categories[inCategory]->index--;
            }
        });

        MC_BUTTON_PRESSED(outOfCategoryButtons, { inCategory = -1; });

        MC_BUTTON_PRESSED(pressModuleGoInCategoryButtons, {
            if (inCategory == -1) inCategory = selectedIndex;
            else { categories[inCategory]->modules[categories[inCategory]->index]->_onPress(); }
        });

        MC_BUTTON_PRESSED(sliderDecreaseButtons, {
            if (inCategory == -1) return;
            if (!categories[inCategory]->modules[categories[inCategory]->index]->isSlider()) return;

            categories[inCategory]->modules[categories[inCategory]->index]->sliderDecrease();
        });

        MC_BUTTON_PRESSED(sliderIncreaseButtons, {
            if (inCategory == -1) return;
            if (!categories[inCategory]->modules[categories[inCategory]->index]->isSlider()) return;

            categories[inCategory]->modules[categories[inCategory]->index]->sliderIncrease();
        });
    }
}

void drawUI() {
    DrawHelper::setup();

    constexpr static uint32_t menuAccent       = 0xCD61FF; // Color of the menu outline, text when a toggle is enabled and the logo text
    constexpr static float32_t menuPosStartY   = 25.0f;    // Y position of where the menu starts, in this case where the top left corner of the menu is
    constexpr static float32_t menuSizeX       = 210.0f;   // The size X of the menu
    constexpr static float32_t menuSizeY       = MC_HEIGHT - (menuPosStartY * 2.0f); // The size Y of the menu
    constexpr static float32_t menuOutlineSize = 6.0f;                               // The outline size of the menu
    constexpr static float32_t menuPosStartX =
            (MC_WIDTH / 2.0f) - (menuSizeX / 2.0f);    // X position of where the menu starts, in this case where the top left corner of the menu is
    constexpr static float32_t logoTextX      = 10.0f; // Offset X from the top left corner of the logo text
    constexpr static float32_t logoTextY      = 10.0f; // Offset Y from the top left corner of the logo text
    constexpr static float32_t inMenuOffsetX  = 9.0f;  // Offset X that modules and categories have inside the menu
    constexpr static float32_t inMenuOffsetY  = 9.0f;  // Offset Y that modules and categories have inside the menu
    constexpr static float32_t inMenuSpacingY = 15.0f; // Spacing between modules and categories

    DrawHelper::text(L"Luna Client", 1.65f, logoTextX, logoTextY, (0xFF << 24) | (menuAccent & 0x00FFFFFF));
    DrawHelper::text(L"Placeholder Placeholder Placeholder", 1.65f, logoTextX, logoTextY * 2.0f, 0);

    if (menuOpen) {
        DrawHelper::box(menuPosStartX - menuOutlineSize, menuPosStartY - menuOutlineSize, menuSizeX + (menuOutlineSize * 2.0f), (menuSizeY) + (menuOutlineSize * 2.0f),
                        0xCD61FF, 0xFF);
        DrawHelper::box(menuPosStartX, menuPosStartY, menuSizeX, menuSizeY, 0x020202, 0xFF);

        for (int32_t i = 0; i < (int32_t) categories.size(); i++) {
            wchar_t buffer[0x40];

            if (inCategory != -1) {
                if (i != inCategory) continue;

                for (int32_t j = 0; j < (int32_t) categories[i]->modules.size(); j++) {
                    if (categories[i]->modules[j]->getId() == 0) {
                        mc_swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%s%s", categories[selectedIndex]->index == j ? "> " : "",
                                    categories[i]->modules[j]->name.c_str());
                        DrawHelper::text(buffer, 1.3f, menuPosStartX + inMenuOffsetX, menuPosStartY + inMenuOffsetY + (inMenuSpacingY * j), 0xFFFFFFFF);
                    } else if (categories[i]->modules[j]->getId() == 1) {
                        mc_swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%s%s", categories[selectedIndex]->index == j ? "> " : "",
                                    categories[inCategory]->modules[j]->name.c_str());
                        DrawHelper::text(buffer, 1.3f, menuPosStartX + inMenuOffsetX, menuPosStartY + inMenuOffsetY + (inMenuSpacingY * j),
                                         (0xFF << 24) | (((((LunaToggle *) categories[inCategory]->modules[j].get())->enabled ? menuAccent : 0xFFFFFF) & 0x00FFFFFF)));
                    } else if (categories[i]->modules[j]->getId() == 2) {
                        categories[inCategory]->modules[j]->composeLine(buffer, sizeof(buffer) / sizeof(wchar_t), categories[inCategory]->index == j);
                        DrawHelper::text(buffer, 1.3f, menuPosStartX + inMenuOffsetX, menuPosStartY + inMenuOffsetY + (inMenuSpacingY * j), 0xFFFFFFFF);
                    } else
                        DrawHelper::text(L"invalid module type", 1.3f, menuPosStartX + inMenuOffsetX, menuPosStartY + inMenuOffsetY + (inMenuSpacingY * j), 0xFFFF0000);
                }
            } else {
                mc_swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%s%s", selectedIndex == i ? "> " : "", categories[i]->name.c_str());
                DrawHelper::text(buffer, 1.3f, menuPosStartX + inMenuOffsetX, menuPosStartY + inMenuOffsetY + (inMenuSpacingY * i), 0xFFFFFFFF);
            }
        }
    }
}

void addCategory(std::unique_ptr<LunaCategory> category) {
    categories.push_back(std::move(category));
    DEBUG_FUNCTION_LINE("category \"%s\" added", categories.back()->name.c_str());
}

void luna() {
    buttonChecks();
    drawUI();
}

void mc__MenuFrameHook__ConsoleUIController__renderScenes() { luna(); }
void mc__GameFrameHook__ConsoleUIController__renderScenes() { luna(); }

void GameHax_Start() {
    // Anti-Crashes
    {
        Poke32(0x02B563FC, 0x4E800020); // Anti Crash-Arrow
        Poke32(0x0206A37C, 0x49F96084); // Anti Spawner Crash
        Poke32(0x04000400, 0x80C10018); // Anti Spawner Crash
        Poke32(0x04000404, 0x28060000); // Anti Spawner Crash
        Poke32(0x04000408, 0x40A20054); // Anti Spawner Crash
        Poke32(0x0400040C, 0xBA2100D4); // Anti Spawner Crash
        Poke32(0x04000410, 0xC3C10168); // Anti Spawner Crash
        Poke32(0x04000414, 0xC3810148); // Anti Spawner Crash
        Poke32(0x04000418, 0xCBC10160); // Anti Spawner Crash
        Poke32(0x0400041C, 0xC3610138); // Anti Spawner Crash
        Poke32(0x04000420, 0xCB810140); // Anti Spawner Crash
        Poke32(0x04000424, 0xCB610130); // Anti Spawner Crash
        Poke32(0x04000428, 0xC3410128); // Anti Spawner Crash
        Poke32(0x0400042C, 0xC3A10158); // Anti Spawner Crash
        Poke32(0x04000430, 0xCB410120); // Anti Spawner Crash
        Poke32(0x04000434, 0xCBA10150); // Anti Spawner Crash
        Poke32(0x04000438, 0xC3210118); // Anti Spawner Crash
        Poke32(0x0400043C, 0xC3E10178); // Anti Spawner Crash
        Poke32(0x04000440, 0xCB210110); // Anti Spawner Crash
        Poke32(0x04000444, 0xCBE10170); // Anti Spawner Crash
        Poke32(0x04000448, 0x4C00012C); // Anti Spawner Crash
        Poke32(0x0400044C, 0x80010184); // Anti Spawner Crash
        Poke32(0x04000450, 0x7C0803A6); // Anti Spawner Crash
        Poke32(0x04000454, 0x38210180); // Anti Spawner Crash
        Poke32(0x04000458, 0x4E800020); // Anti Spawner Crash
        Poke32(0x0400045C, 0x4A069F24); // Anti Spawner Crash
        Poke32(0x04101D50, 0x2C030000); // Anti Piston-Door Crash
        Poke32(0x04101D54, 0x40820014); // Anti Piston-Door Crash
        Poke32(0x04101D58, 0x3D80022B); // Anti Piston-Door Crash
        Poke32(0x04101D5C, 0x618C50C4); // Anti Piston-Door Crash
        Poke32(0x04101D60, 0x7D8903A6); // Anti Piston-Door Crash
        Poke32(0x04101D64, 0x4E800420); // Anti Piston-Door Crash
        Poke32(0x04101D68, 0x80A30004); // Anti Piston-Door Crash
        Poke32(0x04101D6C, 0x4E800020); // Anti Piston-Door Crash
        Poke32(0x022B4E00, 0x49E4CF51); // Anti Piston-Door Crash
        Poke32(0x0256CB5C, 0x49B93908); // Anti Level-Gen Crash
        Poke32(0x04100464, 0x2C030000); // Anti Level-Gen Crash
        Poke32(0x04100468, 0x4182000C); // Anti Level-Gen Crash
        Poke32(0x0410046C, 0x81830000); // Anti Level-Gen Crash
        Poke32(0x04100470, 0x4A46C6F0); // Anti Level-Gen Crash
        Poke32(0x04100474, 0x4A46C70C); // Anti Level-Gen Crash
        Poke32(0x032F95F8, 0x48E06EC4); // Anti Vote-Kick Crash
        Poke32(0x041004BC, 0x2C190000); // Anti Vote-Kick Crash
        Poke32(0x041004C0, 0x38600000); // Anti Vote-Kick Crash
        Poke32(0x041004C4, 0x4081000C); // Anti Vote-Kick Crash
        Poke32(0x041004C8, 0x807900C0); // Anti Vote-Kick Crash
        Poke32(0x041004CC, 0x4B1F9130); // Anti Vote-Kick Crash
        Poke32(0x041004D0, 0x4B1F9378); // Anti Vote-Kick Crash
        Poke32(0x04100590, 0x83C40000); // Anti Take Everything Crash
        Poke32(0x04100594, 0x801E002C); // Anti Take Everything Crash
        Poke32(0x04100598, 0x2C000000); // Anti Take Everything Crash
        Poke32(0x0410059C, 0x4C810020); // Anti Take Everything Crash
        Poke32(0x041005A0, 0x9421FF08); // Anti Take Everything Crash
        Poke32(0x041005A4, 0x4B1E9570); // Anti Take Everything Crash
        Poke32(0x032E9B10, 0x48E16A80); // Anti Take Everything Crash
        Poke32(0x04AB0000, 0x81840000); // Anti Invalid Craft Crash
        Poke32(0x04AB0004, 0x818C001C); // Anti Invalid Craft Crash
        Poke32(0x04AB0008, 0x818C0000); // Anti Invalid Craft Crash
        Poke32(0x04AB000C, 0x2C0C0007); // Anti Invalid Craft Crash
        Poke32(0x04AB0010, 0x4D800020); // Anti Invalid Craft Crash
        Poke32(0x04AB0014, 0x9421FF68); // Anti Invalid Craft Crash
        Poke32(0x04AB0018, 0x4A842054); // Anti Invalid Craft Crash
        Poke32(0x032F2068, 0x497BDF98); // Anti Invalid Craft Crash
        Poke32(0x032F98E4, 0x48E069BC); // Anti Ready Crash
        Poke32(0x041002A0, 0x2C1C0000); // Anti Ready Crash
        Poke32(0x041002A4, 0x40820008); // Anti Ready Crash
        Poke32(0x041002A8, 0x4B1F965C); // Anti Ready Crash
        Poke32(0x041002AC, 0x819E0000); // Anti Ready Crash
        Poke32(0x041002B0, 0x4B1F9638); // Anti Ready Crash
        Poke32(0x02376924, 0x49D89954); // Anti Invalid Fish Crash
        Poke32(0x02376928, 0x60000000); // Anti Invalid Fish Crash
        Poke32(0x04100278, 0x2C000003); // Anti Invalid Fish Crash
        Poke32(0x0410027C, 0x40810008); // Anti Invalid Fish Crash
        Poke32(0x04100280, 0x38000000); // Anti Invalid Fish Crash
        Poke32(0x04100284, 0x4A2766A4); // Anti Invalid Fish Crash
        Poke32(0x02032E58, 0x7C1B0378); // Anti Invalid Inventory Slot Crash
        Poke32(0x02032E5C, 0x3BBBFFFF); // Anti Invalid Inventory Slot Crash
        Poke32(0x02032E60, 0x48000120); // Anti Invalid Inventory Slot Crash
    }

    // Misc
    {
        Poke32(0x0340A760, 0x39200001); // Allow Copy & Paste SWKBD
        Poke32(0x0340A768, 0x91230000); // Allow Copy & Paste SWKBD
        Poke32(0x0340A788, 0x9923001E); // Allow Copy & Paste SWKBD
        Poke32(0x0340A968, 0x60000000); // Allow Copy & Paste SWKBD
        Poke32(0x0340AA78, 0x60000000); // Allow Newline SWKBD
        Poke32(0x02F88110, 0x39400002); // Unlock full SWKBD
    }

    DEBUG_FUNCTION_LINE("add hooks");

    MC_HOOK(0x02D9C8B0, mc__MenuFrameHook__ConsoleUIController__renderScenes);
    MC_HOOK(0x02D9CAD0, mc__GameFrameHook__ConsoleUIController__renderScenes);

    DEBUG_FUNCTION_LINE("add luna categories");

    addCategory(std::make_unique<LunaCategoryClient>());
    addCategory(std::make_unique<LunaCategoryRender>());
    addCategory(std::make_unique<LunaCategoryMovement>());
    addCategory(std::make_unique<LunaCategoryWorld>());
    addCategory(std::make_unique<LunaCategoryMisc>());

    DEBUG_FUNCTION_LINE("done");
}
