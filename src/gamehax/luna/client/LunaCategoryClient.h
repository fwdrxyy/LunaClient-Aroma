#pragma once

#include "../LunaButton.h"
#include "../LunaCategory.h"

class LunaCategoryClient : public LunaCategory {
public:
    LunaCategoryClient() : LunaCategory("Client") {
        this->addModule(std::make_unique<LunaButton>("Luna Client"));
        this->addModule(std::make_unique<LunaButton>("--------------------------"));
        this->addModule(std::make_unique<LunaButton>("Made by 657462 (PNID)"));
        this->addModule(std::make_unique<LunaButton>("  @fwdrxyy_ (Discord)"));
        this->addModule(std::make_unique<LunaButton>("With help from jet2holiday (PNID)"));
        this->addModule(std::make_unique<LunaButton>("  @c0ldcut1e (Discord)"));
        this->addModule(std::make_unique<LunaButton>("--------------------------"));
        this->addModule(std::make_unique<LunaButton>("https://discord.gg/T43zRjMEBY"));
    }
};